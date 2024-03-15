#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "nn.h"

float eval_loss(float w, float bias, TDataSet *train_data)
{
    float loss = 0;
    float val;

    for (int x = 0; x < train_data->set_count; ++x)
    {
        val = w * train_data->sets[x].input[0] + bias;
        // float diff = node->value - train[x][1];
        float fdiff = val - train_data->sets[x].output[0];
        loss += fdiff * fdiff;
    }
    return loss / train_data->set_count;
}

#define TRAIN_LOOP 600
void train(Node *node, TDataSet *data)
{
    float loss;
    float w_fdiff;
    float b_fdiff;

    float eps = 0.001;

    for (int x = 0; x < TRAIN_LOOP; ++x)
    {
        loss = eval_loss(node->weight, node->bias, data);
        w_fdiff = (eval_loss(node->weight + eps, node->bias + 0  , data) - loss) / eps;
        b_fdiff = (eval_loss(node->weight + 0  , node->bias + eps, data) - loss) / eps;

        node->weight -= w_fdiff * eps;
        node->bias -= b_fdiff * eps;
        printf("Current loss (w: %f, b: %f) | weight %f\n", w_fdiff, b_fdiff, node->weight);
    }
}


void print_data_and_result(Node * node, TDataSet *data)
{
    for (int i = 0; i < data->set_count; ++i)
    {
        printf("Input %d -> Expected %d | Actual %f \n",
        data->sets[i].input[0],
        data->sets[i].output[0],
        node->weight * data->sets[i].input[0] + node->bias
        );
    }
}

int main()
{
    TDataSet train_data;
    Node node;

    srand(time(NULL));
    node.weight = rand() % 10;
    node.bias = rand() % 2;

    parse_input("train_data", &train_data);
    train(&node, &train_data);
    printf("\n---------------_AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA_---------------------\n");

    printf("Weight : %f, Bias %f\n", node.weight, node.bias);

    print_data_and_result(&node, &train_data);
    // for (int i = 0; i < train_data.set_count; ++i)
    // {
    //     printf("Input %d -> Expected %d | Actual %f \n", train_data[i][0], train_data[i][1], node.weight * train_data[i][0]);
    // }

}
