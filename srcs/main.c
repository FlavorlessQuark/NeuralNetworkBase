#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "nn.h"


// void print_data_and_result(Node * node, TDataSet *data)
// {
//     for (int i = 0; i < data->set_count; ++i)
//     {
//         printf("Input %d -> Expected %d | Actual %f \n",
//         data->sets[i].input[0],
//         data->sets[i].output[0],
//         node->weight * data->sets[i].input[0] + node->bias
//         );
//     }
// }

int main()
{
    TDataSet train_data;
    NN_BUILDER *builder;
    NN *net;

    srand(time(NULL));
    parse_input("train_data", &train_data);

    builder = NN_Build_New("train_data");
    NN_Build_AddLayer(builder, 2, 0, DENSE, NULL);
    NN_Build_AddLayer(builder, 2, 0, DENSE, NULL);
    net = NN_Build_Finalize(builder);
    printf("\n---------------_AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA_---------------------\n");
}
