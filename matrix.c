#include "matrix.h"

matrix create_matrix(int rows, int cols)
{
    matrix m = {.rows = rows,
                .cols = cols,
                .matrix = (int **)malloc(rows * sizeof(int *))};
    for (int i = 0; i < rows; i++)
    {
        m.matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
            m.matrix[i][j] = 0;
    }
    return m;
}
matrix set_matrix(int *m, int rows, int cols)
{
    matrix mat = {.rows = rows,
                  .cols = cols,
                  .matrix = (int **)malloc(rows * sizeof(int *))};
    for (int i = 0; i < rows; i++)
    {
        mat.matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            mat.matrix[i][j] = m[i * cols + j];
        }
    }
    return mat;
}

void matrix_set_row_col(matrix *m, int row, int col, int value)
{
    m->matrix[row][col] = value;
}

int matrix_get_row_col(const matrix *m, int row, int col)
{
    return m->matrix[row][col];
}

void delete_matrix_ptr(matrix *m) { free(m); }

void delete_matrix_literal(matrix m) { free(m.matrix); }

#define matrix_delete(m)                                                       \
    _Generic(m, matrix *: delete_matrix_ptr, matrix: delete_matrix_literal)(m)

void display_matrix(const matrix *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
            printf("%d |", m->matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

matrix *matrix_multiply(const matrix *LHS, const matrix *RHS)
{
    if (LHS->cols != RHS->rows)
    {
        printf("retuning null\n");
        return NULL;
    }
    matrix *n = (matrix *)malloc(sizeof(matrix));
    *n = create_matrix(LHS->rows, RHS->cols);
    int n_ops = LHS->cols * RHS->rows;
    for (int l_row = 0; l_row < LHS->rows; l_row++)
    {
        for (int r_row = 0; r_row < RHS->rows; r_row++)
        {
            int sum = 0;
            for (int l_col = 0; l_col < LHS->cols; l_col++)
            {
                int lhs = matrix_get_row_col(LHS, l_row, l_col);
                int rhs = matrix_get_row_col(RHS, l_col, r_row);
                sum += lhs * rhs;
            }
            matrix_set_row_col(n, l_row, r_row, sum);
        }
    }
    display_matrix(n);
    return n;
}

bool matrix_are_equal(const matrix *LHS, const matrix *RHS)
{
    if (LHS->cols != RHS->cols || LHS->rows != RHS->rows)
        return false;
    for (int rows = 0; rows < LHS->rows; rows++)
    {
        for (int cols = 0; cols < LHS->cols; cols++)
        {
            if (matrix_get_row_col(LHS, rows, cols) !=
                matrix_get_row_col(RHS, rows, cols))
                return false;
        }
    }
    return true;
}
