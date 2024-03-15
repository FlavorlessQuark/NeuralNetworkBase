#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "nn.h"

# define TRAIN_COUNT 5

int train_data[TRAIN_COUNT][2] = {
    {1,2},
    {2,4},
    {4,8},
    {8,16},
    {16,32}
};

float eval_loss(float w)
{

    float loss = 0;
    float val;

    for (int x = 0; x < TRAIN_COUNT; ++x)
    {
        val = w * train_data[x][0];
        // float diff = node->value - train[x][1];
        float fdiff = val - train_data[x][1];
        loss += fdiff * fdiff;
    }
    return loss / TRAIN_COUNT;
}

#define TRAIN_LOOP 600
void train(Node *node)
{
    float loss;
    float fdiff;

    float eps = 0.001;

    for (int x = 0; x < TRAIN_LOOP; ++x)
    {
        loss = eval_loss(node->weight);
        fdiff = (eval_loss(node->weight + eps) - loss) / eps;

        node->weight -= fdiff * eps;
        printf("Current loss %f  | weight %f\n", fdiff, node->weight);
    }
}



int main()
{

    Node node;

    srand(time(NULL));
    node.weight = rand() % 10;

    train(&node);
    printf("\n---------------_AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA_---------------------\n");
    for (int i = 0; i < TRAIN_COUNT; ++i)
    {
        printf("Input %d -> Expected %d | Actual %f\n", train_data[i][0], train_data[i][1], node.weight * train_data[i][0]);
    }

}
