#include "assertions.h"
#include "../matrix.c"

// https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
#define PRINT_TEST_INFO()                                                      \
    printf(ANSI_COLOR_BLUE "testing %s" ANSI_COLOR_RESET "...\n", __FUNCTION__)
#define PRINT_TEST_SUCCESS()                                                   \
    printf("\t" ANSI_COLOR_GREEN "passed %s." ANSI_COLOR_RESET "\n\n",         \
           __FUNCTION__)

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

void test_eq(bool eq, char *debug, unsigned line, char *file)
{
    if (!eq)
    {
        printf(ANSI_COLOR_RED "Failed assertion: " ANSI_COLOR_CYAN
                              "%s in line %d" ANSI_COLOR_RESET "\n",
               debug, line);
        exit(3);
    }
}

#define test(expression)                                                       \
    test_eq(expression, #expression, (unsigned)__LINE__, __FILE__)
