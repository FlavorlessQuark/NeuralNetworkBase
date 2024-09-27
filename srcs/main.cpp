
#include "nn_builder.hpp"


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
    NN_BUILDER *builder = new NN_BUILDER;

    builder->add(builder->layer.add());
}
