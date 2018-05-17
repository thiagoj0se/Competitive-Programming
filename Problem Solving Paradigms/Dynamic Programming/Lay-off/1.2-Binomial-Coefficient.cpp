// Compute the binomial coefficent indexed by n and denoted by
// (n k) using dynamic programming.

#include <bits/stdc++.h>

#define MAX_SIZE (1 << 20)
typedef long long int Integer;

typedef struct Matrix {
    Integer table[MAX_SIZE + 1][MAX_SIZE + 1];
} Matrix;

Integer getBinomialCoefficient(Integer n, Integer k, Matrix *matrix) {
    if(n == 0)
        return 0;
    if(matrix->table[n][k])
        return matrix->table[n][k];
    if(!matrix->table[n-1][k-1])
        matrix->table[n-1][k-1] = getBinomialCoefficient(n-1, k-1, matrix);
    if(!matrix->table[n-1][k])
        matrix->table[n-1][k] = getBinomialCoefficient(n-1, k, matrix);
    return matrix->table[n-1][k-1];
}

int main() {

}
