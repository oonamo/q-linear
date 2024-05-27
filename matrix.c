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
        return NULL;
    matrix n = create_matrix(LHS->rows, RHS->cols);
    int n_ops = LHS->cols * RHS->rows;
    printf("number of operations: %d\n", n_ops);
    int real_ops = 0;
    for (int l_row = 0; l_row < LHS->rows; l_row++)
    {
        int col_sum = 0;
        for (int l_col = 0; l_col < LHS->cols; l_col++)
        {
            int lhs = matrix_get_row_col(LHS, l_row, l_col);
            int rhs = matrix_get_row_col(LHS, l_row, l_col);
        }
        for (int r_col = 0; r_col < RHS->cols; r_col++)
        {
        }
    }
    printf("performed %d operations\n", real_ops);
    display_matrix(&n);
    return &n;
}
