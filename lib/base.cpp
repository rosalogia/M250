#include <iostream>
#include "base.h"

mat randomMatrix(int n, int m) {
    mat a(n, vl(m));

    // Set up the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<ll> distrib(0, LLONG_MAX);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll tmp = distrib(gen);

            a[i][j] = (tmp % 2 != 0 ? -tmp : tmp) / 2;
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

void printMatrix(mat a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            std::cout << a[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

int main() {
    mat a = randomMatrix(2, 3);
    printMatrix(a);
}
