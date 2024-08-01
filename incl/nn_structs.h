#pragma once

typedef double (*ActFn)(double);

enum LAYER_TYPE {
    VEC,
    DENSE,
    SPARSE
};

typedef struct Matrix
{
    int n;//rows
    int m;//cols
    double *mat;
}           Matrix;

typedef struct Node
{
    double *weights;
    double *biases;
    double value;
}               Node;


typedef struct NN
{
    int layer_count;
    Matrix *weights;
    Matrix *biases;
    Matrix *values;

    Matrix *errors;
    Matrix *_errors;
    Matrix output;
    Matrix *activations;
    ActFn  *act_fn;
}               NN;

typedef struct s_builder_data_{
    layer_info *info;
    long total_alloc;
}              _builder_data_;


typedef struct _layer_info{
    int m;
    int n;
    int type;
    ActFn fn;
}           layer_info;

typedef struct NN_BUILDER
{
    int layer_count;
    char *train_data;
    layer_info *info;
    long total_alloc;
    void *activations;
}           NN_BUILDER;

typedef struct TData
{
    int *input;
    int *output;
}               TData;

typedef struct TDataSet
{
    int set_count;
    int i_count;
    int o_count;
    TData *sets;
}           TDataSet;
