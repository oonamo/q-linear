/**
 * @file matrix.h
 * @brief contains matrix creation, deletion, and operations
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Macro to destory matrix from memory
 *
 * This macro deletes the matrix pointer if m is not a pointer.
 * If m is a pointer, it also deletes m
 *
 * @param m Either a matrix or matrix pointer to destroy
 */
#define delete_matrix(m)

/**
 * @brief Macro to create identity matrix
 *
 * Creates an identity matrix with dimensions size x size
 *
 * @param size Size of identity matrix
 */
#define IDENTITY_MATRIX(size)

enum Identies
{
    None,
    Identity,
    Triangular,
};

/**
 * @brief A structure representing a Matrix
 */
typedef struct matrix
{
    int rows;     /**< Number of rows in the matrix. */
    int cols;     /**< Number of columns in the matrix */
    int **matrix; /**< Pointer to the matrix */
} matrix;

/**
 * @brief create an empty matrix
 *
 * @param rows number of rows for the matrix
 * @param cols number of columns for the matrix
 * @return matrix with provided rows and columns
 */
matrix create_matrix(int rows, int cols);

/**
 * @brief create a matrix from a 2d pointer array
 *
 * @param m 2d pointer array
 * @param rows number of rows for the matrix
 * @param cols number of columns for the matrix
 * @return matrix with the values from 2d array
 */
matrix set_matrix(int *m, int rows, int cols);

/**
 * @brief deletes matrix pointer from heap
 *
 * @param m matrix pointer
 */
void delete_matrix_ptr(matrix *m);

/**
 * @brief deletes matrix from heap
 *
 * @param m matrix
 */
void delete_matrix_literal(matrix m);

/**
 * @brief set the value at the given row and column of a matrix
 *
 * @param m Pointer to a matrix
 * @param row Row
 * @param col Column
 * @param value Value to set at the row and column
 */
void matrix_set_row_col(matrix *m, int row, int col, int value);

/**
 * @brief get the value at the given row and column of a matrix
 *
 * @param m Pointer to a matrix
 * @param row Row
 * @param col Column
 */
int matrix_get_row_col(const matrix *m, int row, int col);

/**
 * @brief printf matrix to stdout
 *
 * @param n Pointer to matrix
 */
void matrix_display(const matrix *n);

/**
 * @brief multilpy two matrices of valid size
 *
 * Multiply two matrices of if the number of rows in LHS are equal
 * to the number of columns in the RHS.
 * Returns NULL if this is not the case.
 *
 * @param LHS Pointer to the left-hand side  matrix
 * @param RHS Pointer to the right-hand side matrix
 * @return A Pointer to a matrix of NULL if rows of LHS are not eqaul to cols of
 * RHS
 */
matrix *matrix_multiply(const matrix *LHS, const matrix *RHS);

/**
 * @brief verify if two matrices are equal
 *
 * Checks if the two matrices have the same number or rows and columns.
 * If they are, it verifies that for every row and column, they have the same
 * value.
 *
 * @param LHS Pointer to the left-hand side  matrix
 * @param RHS Pointer to the right-hand side matrix
 * @return bool, true if the matrices are equal
 */
bool matrix_are_equal(const matrix *LHS, const matrix *RHS);

#endif
