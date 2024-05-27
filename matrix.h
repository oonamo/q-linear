#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define delete_matrix

typedef struct matrix
{
    int rows;
    int cols;
    int **matrix;
} matrix;

matrix create_matrix(int rows, int cols);
matrix set_matrix(int *m, int rows, int cols);

void delete_matrix_ptr(matrix *m);

void delete_matrix_literal(matrix m);

void matrix_set_row_col(matrix *m, int row, int col, int value);

int matrix_get_row_col(const matrix *m, int row, int col);

void matrix_display(const matrix *n);

matrix *matrix_multiply(const matrix *LHS, const matrix *RHS);

#endif
