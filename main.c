#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    ptrMatrix_t m;
    ptrMatrix_t n;
    ptrMatrix_t o;
    ptrMatrix_t result_matrix;
    bool result;

    m = matrix_init();
    n = matrix_init();
    result_matrix = matrix_init();

    float test[4][4] = {
        { 1, 2, 3, 4, },
        { 5, 6, 7, 8, },
        { 1, 2, 3, 4, },
        { 5, 6, 7, 8, },
    };

    float test_result[4][4] = {
        { 34,  44,  54,  64, },
        { 82, 108, 134, 160, },
        { 34,  44,  54,  64, },
        { 82, 108, 134, 160, },
    };

    memcpy(m->values, test, sizeof(test));
    memcpy(n->values, test, sizeof(test));
    memcpy(result_matrix->values, test_result, sizeof(test_result));

    o = mul(m, n);
    result = equal(o, result_matrix);

    printf("Mul matrix o & matrix result is the same ? %s\n", result ? "true" : "false");

    matrix_free(m);
    matrix_free(n);
    matrix_free(o);
    matrix_free(result_matrix);

    return 0;
}
