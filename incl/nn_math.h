#pragma once

#include "nn_structs.h"
// typedef struct Vec {
//     int len;
//     double *vec;
// }       Vec;


Matrix M_dot(Matrix *a, Matrix *b, Matrix *res);
Matrix M_add(Matrix *a, Matrix *b, Matrix *res);
Matrix M_sub(Matrix *a, Matrix *b, Matrix *res);
Matrix M_transpose(Matrix *m, Matrix *res);
Matrix M_Scale(Matrix *m, Matrix *res, double s);
void   M_Product(Matrix *a,  Matrix *b, Matrix *res);
