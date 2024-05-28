#ifndef VECTOR_H
#define VECTOR_H
#include "matrix.h"

enum VecType
{
    Column = 1 << 0,
    Row = 1 << 1,
};

typedef struct vec
{
    int size;
    int *vector;
    enum VecType vec_type;
} vec;

vec create_vector(int size);

vec set_vector(int *v, enum VecType v_type);

vec *vec_from_matrix(const matrix *m);

vec vec_add(const vec *LHS, const vec *RHS);

vec vec_dot_prod(const vec *LHS, const vec *RHS);

vec vec_cross_prod(const vec *LHS, const vec *RHS);

#endif
