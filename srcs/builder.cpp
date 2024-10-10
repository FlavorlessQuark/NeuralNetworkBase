#include "../incl/nn_builder.hpp"


typedef struct _dense_args {
    const Eigen::VectorX<int> *inputShape;
    int units;
    activation_fn *activation;
} _dense_args;


COMPILED_LAYER _compile_dense(_INTERN_LAYER_DATA prev, _INTERN_LAYER_DATA curr) {

}

NN_BUILDER::NN_BUILDER () {

};



NN_BUILDER::~NN_BUILDER() {};

_INTERN_LAYER_DATA *NN_BUILDER::LAYER_BUILDER::dense(const std::vector<int> &inputShape = {}, const std::vector<int> units = {1}, activation_fn activation = NULL)
{
    _INTERN_LAYER_DATA layer = {
        .data = new _dense_data(),
        .activation = activation,
        .inShape = inputShape,
        .outShape = inputShape,
        .layer_ID = DENSE,
        .layer_fn = _compile_dense,
    };

    return layer;
};

// builder ({
//     dense(srgs for the functions),
//     dense(srgs for the functions),
//     dense(srgs for the functions),
// })

NN_BUILDER::NN_BUILDER(const std::vector<_INTERN_LAYER_DATA> &list) {
    for (const auto& item: list) {
        this->add(item);
    }
};

int NN_BUILDER::add(const _INTERN_LAYER_DATA &layer_data) {
    if (this->_layers.size() == 0) {
        if (!layer_data.inShape.size())
            throw "First layer require an input shape";

        this->_layers.push_back((_INTERN_LAYER_DATA){
            .data = nullptr,
            .inShape = layer_data.inShape,
            .outShape = layer_data.inShape,
            .layer_ID = 0,
            .activation = nullptr
        });
    }
    this->_layers.push_back((_INTERN_LAYER_DATA) {
        .data = layer_data.data,
        .inShape = this->_layers[this->_layers.size() - 1].outShape,
        .outShape = layer_data.outShape,
        .layer_ID = layer_data.layer_ID,
        .activation = layer_data.activation
    });
};

NN_Model *NN_BUILDER::compile() {
    std::vector<COMPILED_LAYER> compiled;

    for (int i = 1; i < this->_layers.size(); i++) {
        compiled.push_back(this->_layers[i].compile_fn(this->_layers[i - 1], this->_layers[i]));
    }

    return new NN_Model(compiled);
};
