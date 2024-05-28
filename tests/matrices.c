#include "assertions.c"

void test_matrix_are_equal()
{
    PRINT_TEST_INFO();
    matrix m1 = create_matrix(5, 5);
    matrix m2 = create_matrix(5, 5);

    test(matrix_are_equal(&m1, &m2));

    matrix_set_row_col(&m1, 3, 3, 20);

    matrix_set_row_col(&m2, 3, 3, 20);
    test(matrix_are_equal(&m1, &m2));

    delete_matrix(m1);
    delete_matrix(m2);
    PRINT_TEST_SUCCESS();
}

void test_create_matrix(void)
{
    PRINT_TEST_INFO();
    matrix m1 = create_matrix(2, 2);
    test((matrix_get_rows(&m1) == 2));

    matrix m2 = create_matrix(25, 16);
    test((matrix_get_cols(&m2) == 16));

    matrix m3 = create_matrix(-12, -124);
    test((matrix_get_rows(&m3) == 1));
    test((matrix_get_cols(&m3) == 1));

    delete_matrix(m1);
    delete_matrix(m2);
    delete_matrix(m3);
    PRINT_TEST_SUCCESS();
}

void test_set_matrix(void)
{
    PRINT_TEST_INFO();
    int m_arr1[3][3] = {
        {3, 6, 2},
        {1, 0, 2},
        {5, 0, 3},
    };
    matrix m = set_matrix((int *)m_arr1, 3, 3);
    test(array_is_of_matrix((int *)m_arr1, &m, 3, 3));
    PRINT_TEST_SUCCESS();
}

void test_matrix_multiply(void)
{
    PRINT_TEST_INFO();
    int m_arr1[3][3] = {
        {3, 6, 2},
        {1, 0, 2},
        {5, 0, 3},
    };
    int m_arr2[3][1] = {{2}, {5}, {6}};
    int mul_result[3][1] = {{48}, {14}, {28}};

    matrix m1 = set_matrix((int *)m_arr1, 3, 3);
    matrix m2 = set_matrix((int *)m_arr2, 3, 1);

    matrix *result = matrix_multiply(&m1, &m2);
    test(result != NULL);
    test(array_is_of_matrix((int *)mul_result, result, 3, 1));

    PRINT_TEST_SUCCESS();
}

void test_matrix_addition(void)
{
    PRINT_TEST_INFO();
    int lhs[2][6] = {
        {4, 2, 4, 0, 9, 12},
        {5, 0, 9, 13, 2, 5},
    };
    int rhs[2][6] = {
        {0, 12, 4, 1, 5, 7},
        {1, 0, 0, 5, 12, 9},
    };

    int arr_result[2][6] = {{4, 14, 8, 1, 14, 19}, {6, 0, 9, 18, 14, 14}};

    matrix m1 = set_matrix((int *)lhs, 2, 6);
    matrix m2 = set_matrix((int *)rhs, 2, 6);
    matrix result = set_matrix((int *)arr_result, 2, 6);

    matrix *r = matrix_addition(&m1, &m2);
    test(r != NULL);
    test(matrix_are_equal(r, &result));
    PRINT_TEST_SUCCESS();
}

void test_matrix_scalar()
{
    PRINT_TEST_INFO();
    int arr[2][2] = {{2, 5}, {8, 12}};
    int arr_res[2][2] = {{4, 10}, {16, 24}};
    int scalar = 2;

    matrix m = set_matrix((int *)arr, 2, 2);
    matrix *res = matrix_scalar(scalar, &m);

    test(array_is_of_matrix((int *)arr_res, res, 2, 2));
    PRINT_TEST_SUCCESS();
}

int main(void)
{
    printf(ANSI_COLOR_YELLOW "running matrix tests..." ANSI_COLOR_RESET "\n");
    test_matrix_are_equal();
    test_create_matrix();
    test_set_matrix();
    test_matrix_multiply();
    test_matrix_addition();
    test_matrix_scalar();
    return 0;
}
