#ifndef ASSERTIONS_H
#define ASSERTIONS_H
#ifndef MATRIX_H
#include "../matrix.h"
#endif
#include <assert.h>

/**
 * @brief Asserts that a Pointer to a 2d matrix is the same as a matrix
 *
 * Asserts that the creation of the matrix is the same as a pointer to a 2d
 * array
 * Requires rows and columns to correctly traverse the pointer
 *
 * @param arr Pointer to 2d array
 * @param m Pointer to matrix
 * @param rows Number of rows of both 2d pointer and Matrix
 * @param cols Number of columns of both 2d pointer and Matrix
 */
bool array_is_of_matrix(const int *arr, const matrix *m, int rows, int cols);
#endif
