#include <math.h>
#include "nn.h"
#include "nn_math.h"

// z is a vector
// w is a matrix
// L -> output layer
// a is the neuron input vector for layer l = (o'(zˡ⁻¹))

// EQ 1 : Error in output layer
// δᴸⱼ = ∂C /∂aᴸⱼ * σ′(zᴸⱼ)
// ∂C /∂aᴸⱼ -> rate of change of cost at the Jth neuron input.
//  σ′(zᴸⱼ) -> rate of change of activation function

// ∂C/∂aLj=(aLj−yj)

// EQ2 : Error in layer l in terms of δˡ⁺¹
// δˡ=((wˡ⁺¹)Tδˡ⁺¹) * σ′(zˡ)
// (wˡ⁺¹)T
// Transposing the wight matrix w makes it the correct shape for dot product
// (it makes sense if you think of a matrix as an array of vectors)
// Before T:     After T
//                N1   N2
// N1 w0 , w2     w0   w1
// N2 w1 , w3     w2   w3
// * δˡ⁺¹
// weights are adjusted based on the error from l+1
// * σ′(zˡ)
// δᴸ is the output of layer l adjusted by the weights

// EQ3 : Rate of change of cost in function of bias
//  ∂C /∂bᴸⱼ = δˡⱼ
// lol

// EQ4 : Rate of chnage of cost in function of weight
// ∂C/∂wˡₖⱼ = aˡ−¹ₖ * δˡⱼ
// The partial derivative in layer l at weight kj
//  ∂C/∂w = a * δ
// δ is the error in the output

// TRAINING:
//  Foward data - compute w, z, o'(z)
//  Compute δᴸ with EQ1
//  The actual backprop with EQ2 to propagate error backwards
//  Compute the gradient at each weigth and bias with EQ3 and EQ4


void out_error(Matrix *actual, Matrix *expected, Matrix *err)
{
    // for (int i = 0; i < actual->n; ++i)
        // actual->mat[i] = sigmoid(actual->mat[i]);
    // M_sub(   actual, expected, err);
    for (int i = 0; i < err->n; ++i)
    {
        err->mat[err->m - 1 * err->n + i] = (expected->mat[i] - actual->mat[i]) *  sigmoid(actual->mat[i]);
    }

    return ;
}

void backprop(NN *net)
{
    for (int l = net->layer_count - 2; l >= 0; --l)
    {
        M_transpose(net->weights[l].mat, net->_errors->mat);
        M_dot(net->_errors[l].mat, net->errors[l + 1].mat, net->errors[l].mat);
        M_Product(net->errors[l].mat, net->values[l].mat, net->errors[l].mat);

        // Compute weight gradient
        for (int k = 0; k < net->weights[l].m; k++)//x
        {
            for (int j = 0; j < net->weights[l].n; j++)//y
            {
                net->weights[l].mat[j * net->weights[l].n + k] += (net->activations[l - 1].mat[k] * net->errors[l].mat[j]) * __FLT_EPSILON__;
            }
        }
        // Compute bias gradient
        for (int b = 0; b < net->biases[l].n; ++b)
            net->biases[l].mat[b] += (net->errors[l].mat[b]) * __FLT_EPSILON__;
    }
}


void forward(NN *net, TData *data)
{
    for (int i = 0; i < net->layer_count - 1; ++i)
    {
        M_dot(&net->values[i], &net->weights[i], &net->values[i + 1]);
        M_add(&net->values[i + 1], &net->biases[i], &net->values[i + 1]);
        for (int x = 0; x < net->values[i + 1].n * net->values[i + 1].m; ++ i)
        {
            net->activations[i].mat[x] = net->values[i + 1].mat[x];
            net->values[i + 1].mat[x] = sigmoid(net->values[i + 1].mat[x]);
        }
    }
}

#define TRAIN_LOOP 900
void train(NN *net, TDataSet *data)
{
    double loss;
    double w_fdiff;
    double b_fdiff;

    double eps = 0.001;

    for (int x = 0; x < TRAIN_LOOP; ++x)
    {
        forward(net, data);
        out_error(&net->output, data->sets, net->_errors);
        backprop(net);
    }
}
