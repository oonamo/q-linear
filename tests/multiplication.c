#include "assertions.c"

int tests(void)
{
    int m_arr1[3][3] = {
        {3, 6, 2},
        {1, 0, 2},
        {5, 0, 3},
    };
    int m_arr2[3][1] = {{2}, {5}, {6}};

    create_matrix(2, 2);
    bool result = false;
    matrix m1 = set_matrix((int *)m_arr1, 3, 3);
    matrix m2 = set_matrix((int *)m_arr2, 3, 1);

    display_matrix(&m1);
    display_matrix(&m2);

    result |= array_is_of_matrix((int *)m_arr1, &m1, 3, 3);
    result |= array_is_of_matrix((int *)m_arr2, &m2, 3, 1);

    if (!result)
    {
        printf("array and matrices are not equal\n");
        delete_matrix(m1);
        delete_matrix(m2);
        return -1;
    }
    printf("LHS == RHS");

    int mul_result[3][1] = {{48}, {14}, {28}};
    matrix *m_of_1_2 = matrix_multiply(&m1, &m2);

    if (m_of_1_2 == NULL)
    {
        printf("size of matrixx is ok, but throws NULL\n");
        delete_matrix(m1);
        delete_matrix(m2);
        return -1;
    }

    result |= array_is_of_matrix((int *)mul_result, m_of_1_2, 3, 1);
    if (!result)
    {
        printf("matrices are not equal to the array");
        delete_matrix(m1);
        delete_matrix(m2);
        delete_matrix(m_of_1_2);
        return -1;
    }
    matrix mat_result = set_matrix((int *)mul_result, 3, 1);

    result |= matrix_are_equal(m_of_1_2, &mat_result);
    if (!result)
    {
        printf("matrices are not equal to the array");
        delete_matrix(m1);
        delete_matrix(m2);
        delete_matrix(m_of_1_2);
        delete_matrix(mat_result);
        return -1;
    }

    delete_matrix(m1);
    delete_matrix(m2);
    delete_matrix(m_of_1_2);
    delete_matrix(mat_result);

    printf("passed all tests");
    return 0;
}

int main()
{
    printf("running tests\n");
    tests();
}
