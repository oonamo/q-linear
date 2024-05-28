#ifndef ASSERTIONS_H
#define ASSERTIONS_H
#ifndef MATRIX_H
#include "../matrix.h"
#endif
#include <assert.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

// #define PRINT_TEST_SUCCESS()
// #define PRINT_TEST_INFO()

// #define test()

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
void test_eq(bool eq, char *debug, unsigned line, char *file);
#endif
