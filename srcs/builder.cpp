#include "../incl/nn_builder.hpp"


typedef struct _dense_args {
    const Eigen::VectorX<int> *inputShape;
    int units;
    activation_fn *activation;
} _dense_args;


_INTERN_LAYER_DATA _dense(void * args) {

}

NN_BUILDER::NN_BUILDER () {

}



NN_BUILDER::~NN_BUILDER() {}

void *NN_BUILDER::LAYER_BUILDER::dense(const Eigen::VectorX<int> *inputShape = NULL, int units = 1, activation_fn activation = NULL)
{
    _dense_args args = {
        .inputShape = inputShape,
        .units = units,
        .activation = activation,
    };
    _generic_args gen_args;

    gen_args.fn = _dense;
    gen_args.data = &args;
    return &gen_args;
}

// builder ({
//     dense(srgs for the functions),
//     dense(srgs for the functions),
//     dense(srgs for the functions),
// })

NN_BUILDER::NN_BUILDER(const std::vector<_generic_args> &list) {
    _gen_core_args *args;
    for (const auto& item: list) {
        args = (_gen_core_args *)item.data;
        args->inputShape = this->layer[i - 1].output;
        item.fn(item.data);
    }
}

int NN_BUILDER::add(_generic_args layer_data) {

}

NN_Model NN_BUILDER::compile();
