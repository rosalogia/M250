#include <iostream>
#include "base.h"

mat randomMatrix(int n, int m) {
    mat a(n, vl(m));

    // Set up the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    //std::uniform_int_distribution<ll> distrib(0, LLONG_MAX);
    std::uniform_int_distribution<ll> distrib(0, 9);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll tmp = distrib(gen);

            // a[i][j] = (tmp % 2 != 0 ? -tmp : tmp) / 2;
            a[i][j] = tmp;
        }
    }

    return a;
}

mat matrixVectorProduct(mat a, vl x) {
    mat b(a.size(), vl(x.size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < x.size(); j++) {
            b[i][j] = a[i][j] * x[j];
        }
    }

    return b;
}

vl rowByMatrix(vl x, mat a) {
    vl r(a[0].size());

    for (int i = 0; i < a[0].size(); i++) {
        ll sum = 0;

        for (int j = 0; j < a.size(); j++) {
            sum += x[j] * a[j][i];
        }

        r[i] = sum;
    }

    return r;
}

mat compose(mat a, mat b) {
    mat c(a.size(), vl(b[0].size()));

    for (int i = 0; i < a.size(); i++) {
        vl r = rowByMatrix(a[i], b);
        c[i] = r;
    }

    return c;
}

void printMatrix(mat a) {
    int n = a.size(), m = a[0].size();
    
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            std::cout << "┌   ";
        } else if (i == m - 1) {
            std::cout << "  ┐";
        } else {

            std::cout << " ";
        }
    }

    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0) {
                std::cout << "│ " << a[i][j] << " ";
            } else if (j == m - 1) {
                std::cout << a[i][j] << " │";
            } else {
                std::cout << a[i][j] << " ";
            }
        }

        std::cout << std::endl;
    }

    for (int i = 0; i < m; i++) {
        if (i == 0) {
            std::cout << "└   ";
        } else if (i == m - 1) {
            std::cout << "  ┘";
        } else {
            std::cout << "  ";
        }
    }

    std::cout << std::endl;
}

int main() {
    mat A{ vl{1, 2, 3}, vl{4, 5, 6}, vl{7, 8, 9} };
    mat B{ vl{9, 8, 7}, vl{6, 5, 4}, vl{3, 2, 1} };

    printMatrix(compose(A, B));
}
