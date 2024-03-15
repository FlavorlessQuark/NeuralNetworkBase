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
    int count;
    int *input;
    int *output;
    float rate;
}           TData;
