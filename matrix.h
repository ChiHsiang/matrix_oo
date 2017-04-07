#ifndef __MATRIX__
#define __MATRIX__
#include <stdbool.h>

#define EPSILON 1 / 10000.0

typedef struct __MATRIX_IMPL_T {
    float values[4][4];

    /* operations */
    bool (*ftpr_equal)(struct __MATRIX_IMPL_T *, struct __MATRIX_IMPL_T *);
    struct __MATRIX_IMPL_T *(*ftpr_mul)(struct __MATRIX_IMPL_T *, struct __MATRIX_IMPL_T *);

} Matrix_t;
typedef Matrix_t *ptrMatrix_t;

ptrMatrix_t matrix_init();

void matrix_free(ptrMatrix_t);

bool equal(ptrMatrix_t, ptrMatrix_t);

ptrMatrix_t mul(ptrMatrix_t, ptrMatrix_t);

#endif
