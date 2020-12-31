from random import uniform
from copy import deepcopy

# Helper functions
def indexed(l):
    return range(len(l))

def zinit(n, m):
    """Returns an n by m matrix initialised to 0"""
    return [[0] * m] * n

def dimensions(m):
    """Returns the dimensions of a matrix in a tuple"""
    return (len(m), len(m[0]))

def elem_wise(f, a, b):
    """Applies f to lists a and b element-wise"""
    return [f(x, y) for x, y in zip(a, b)]

def ew_product(a, b):
    return elem_wise(lambda x, y: x * y, a, b)

def ew_sum(a, b):
    return elem_wise(lambda x, y: x + y, a, b)

def random_matrix(n, m):
    mat = zinit(n, m)

    for i in range(n):
        for j in range(m):
            mat[i][j] = uniform(-1000, 1000)

    return mat

def print_matrix(m):
    for row in m:
        print(row, sep=" ")

def matrix_column_product(m, v):
    return [sum(elem_wise(v, r)) for r in m]

def transpose(m):
    m_1 = []
    for i in indexed(m[0]):
        row = []
        for j in indexed(m):
            row.append(m[j][i])
        m_1.append(row)

    return m_1

def row_matrix_product(v, m):
    mt = transpose(m)
    return [sum(elem_wise(v, r)) for r in mt]

def compose(A, B):
    return [row_matrix_product(A[i], B) for i in indexed(A)]

# Row operations
def interchange(m, i, j):
    tmp = m[i]
    m[i] = m[j]
    m[j] = tmp
    return m

def scale(m, c, i):
    m[i] = [c * x for x in m[i]]
    return m

def row_addition(m, c, i, j):
    tmp = [c * x for x in m[i]]
    m[j] = ew_sum(tmp, m[j])
    return m

def rref(A_s):
    """Returns the input matrix in reduced row echelon form"""
    A = deepcopy(A_s)
    # Pivot Column
    pc = 0

    n, m = dimensions(A)

    # Each iteration "fixes" one row
    for r in range(n):
        i = r

        while A[i][pc] == 0:
            i += 1
            # The entire column is 0s; can't be pivot column
            if i == n:
                i = r
                pc += 1

                # No remaining columns to check
                if m == pc:
                    return

        # Swap the correct pivot row with the current row
        interchange(A, i, r)

        # Scale the pivot row so that 1 is in the pivot position
        if A[r][pc] != 0:
            scale_factor = 1/A[r][pc]
            scale(A, scale_factor, r)

        # Manipulate all the other rows so that 0 is in the current
        # pivot column
        for k in range(n):
            if k != r:
                scale_factor = -1 * A[k][pc]
                row_addition(A, scale_factor, r, k)
        
        pc += 1

    return A

def rank(A):
    A_rref = rref(A)

    counter = 0

    for row in A_rref:
        if not all([x == 0 for x in row]):
            counter += 1

    return counter

def nullity(A):
    rows, cols = dimensions(A)

    return rows - rank(A)
