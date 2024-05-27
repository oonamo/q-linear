#include "assertions.h"
#include "../matrix.c"

bool array_is_of_matrix(const int *arr, const matrix *m, int rows, int cols)
{
    if (rows != m->rows || cols != m->cols)
        return false;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix_get_row_col(m, i, j) != arr[i * cols + j])
                return false;
        }
    }
    return true;
}
