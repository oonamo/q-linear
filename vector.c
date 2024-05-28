#include "vector.h"

vec create_vector(int size)
{
    vec v = {
        .size = size,
        .vector = (int *)malloc(size * sizeof(int)),
        .vec_type = Column,
    };
    return v;
}

vec set_vector(int *v, enum VecType v_type)
{
    vec new_v = {
        .size = sizeof(&v) / sizeof(int), .vector = v, .vec_type = v_type};
    return new_v;
}

vec *vec_from_matrix(const matrix *m)
{
    if (m->cols != 1 || m->rows != 1)
        return NULL;
    vec *v = (vec *)malloc(sizeof(vec));
    v->vector = (int *)malloc(sizeof(int));
    if (m->rows == 1)
    {
        for (int i = 0; i < m->cols; i++)
        {
            v->vector[i] = m->matrix[0][i];
        }
    }
    else
    {

        for (int i = 0; i < m->rows; i++)
        {
            v->vector[i] = m->matrix[i][0];
        }
    }
    return v;
}

vec vec_add(const vec *LHS, const vec *RHS);

vec vec_dot_prod(const vec *LHS, const vec *RHS);

vec vec_cross_prod(const vec *LHS, const vec *RHS);
