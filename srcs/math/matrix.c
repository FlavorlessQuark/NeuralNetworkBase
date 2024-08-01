#include "nn_math.h"

void M_Print(Matrix *matrix)
{
    for (int m = 0; m < matrix->m; ++m)
    {
        for (int n = 0; n < matrix->n; ++n)
        {
            printf();
        }
    }
}

void M_Product(Matrix *a,  Matrix *b, Matrix *res)
{
    for (int i = 0; i < a->m * a->n; ++i)
    {
        res->mat[i] = a->mat[i] * b->mat[i];
    }
}

void M_dot(Matrix *a, Matrix *b, Matrix *res)
{
    res->n = a->m;
    res->m = b->n;
    for (int row = 0; row < a->m; ++row)
    {
        for (int col = 0; col < b->n; ++col)
        {
            for (int i = 0; i < b->n; ++i)
                res->mat[row * b->n + col] += a->mat[row * a->n + i] * b->mat[i * b->n + col];
        }
    }
}

Matrix M_add(Matrix *a, Matrix *b, Matrix *res)
{
    Matrix res;

    res->n = a->n;
    res->m = a->m;
    for (int n = 0; n < a->n; ++n)
    {
        for (int m = 0; m < a->m; ++m)
            res->mat[n * a->m + m] = \
                a->mat[n * a->m + m] + \
                b->mat[n * a->m + m];
    }
}

Matrix M_sub(Matrix *a, Matrix *b, Matrix *res)
{
    Matrix res;

    res->n = a->n;
    res->m = a->m;
    for (int n = 0; n < a->n; ++n)
    {
        for (int m = 0; m < a->m; ++m)
            res->mat[n * a->m + m] = \
                a->mat[n * a->m + m] - \
                b->mat[n * a->m + m];
    }
}

Matrix M_transpose(Matrix *mat, Matrix *res)
{
    Matrix res;

    res->n = mat->n;
    res->m = mat->m;
    for (int x = 0; x < mat->n; ++x)
    {
        for (int y = 0; y < mat->m; ++y)
        {
            res->mat[y * res->m + x] = res->mat[x * res->n + y];
        }
    }
}

Matrix M_Scale(Matrix *m, Matrix *res,  double s)
{
    Matrix res;

    res->n = m->n;
    res->m = m->m;
    for (int n = 0; n < m->n; ++n)
    {
        res->mat[n * m->m + n] = \
            m->mat[n * m->m + n] * s;
    }
}
