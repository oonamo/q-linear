#include "matrix.c"

int main()
{
    matrix m = create_matrix(3, 3);

    display_matrix(&m);
    matrix_set_row_col(&m, 2, 2, 5);

    int _row = matrix_get_row_col(&m, 2, 2);
    display_matrix(&m);

    int m_arr[3][3] = {
        {3, 6, 2},
        {1, 0, 2},
        {5, 0, 3},
    };
    int m_arr2[3][1] = {{2}, {5}, {6}};
    int **ptr = (int **)malloc(3 * sizeof(int *));

    matrix m2 = set_matrix((int *)m_arr, 3, 3);
    matrix m3 = set_matrix((int *)m_arr2, 3, 1);
    display_matrix(&m2);
    display_matrix(&m2);

    matrix *m2_3 = matrix_multiply(&m2, &m3);
    if (m2_3 == NULL)
        printf("invalid size of matrixes 2 and 3\n");

    matrix *m_2_2 = matrix_multiply(&m2, &m2);
    matrix_delete(m);
    matrix_delete(m_2_2);
    matrix_delete(m2);
    matrix_delete(m3);
    printf("finished...\n");
    return 0;
}
