#pragma once

// typdef

typedef struct Node
{
    float weight;
    float value;
    float bias;
}               Node;

typedef struct NN_Layer
{
    int node_count;
    Node *nodes;
}               NN_Layer;

typedef struct NN
{
    int layer_count;
    NN_Layer *layers;
}               NN;


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
