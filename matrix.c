#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

ptrMatrix_t matrix_init()
{
    ptrMatrix_t matrix;

    matrix = malloc(sizeof(Matrix_t));

    //for (int i = 0; i < 4; i++) {
    //    for (int j = 0; j < 4; j++) {
    //        matrix->values[i][j] = i * j + j;
    //    }
    //}

    matrix->ftpr_equal = &equal;
    matrix->ftpr_mul = &mul;

    return matrix;
}

void matrix_free(ptrMatrix_t m)
{
    free(m);
}

bool equal(ptrMatrix_t a, ptrMatrix_t b)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (a->values[i][j] + EPSILON < b->values[i][j]
                    || b->values[i][j] + EPSILON < a->values[i][j])
                return false;

    return true;
}

ptrMatrix_t mul(ptrMatrix_t a, ptrMatrix_t b)
{
    int i, j, k;
    ptrMatrix_t matrix;

    matrix = malloc(sizeof(Matrix_t));

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            for (k = 0; k < 4; k++)
                matrix->values[i][j] += a->values[i][k] * b->values[k][j];

    return matrix;
}
