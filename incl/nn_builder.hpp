#ifndef NN_BUILDER_CLASS
#define NN_BUILDER_CLASS

#include "nn_header.hpp"
#include "Eigen/Core"

 typedef struct _INTERN_LAYER_DATA {
    int inputs;
    int outputs;
    int m;
    int n;
    int type;
    activation_fn activation;
} _INTERN_LAYER_DATA;

class NN_BUILDER {


    typedef _INTERN_LAYER_DATA (layer_fn (void *));
    typedef struct _generic_args {
        layer_fn *fn;
        void *data;
    }   _generic_args;
    private:

        std::vector<_INTERN_LAYER_DATA> _layers;

    public:

        class LAYER_BUILDER {

            public :

                static _INTERN_LAYER_DATA add();
                static void *dense(const Eigen::VectorX<int> *inputShape = NULL, int units = 1, activation_fn activation = NULL);
                static _INTERN_LAYER_DATA dot();
                static _INTERN_LAYER_DATA sub();
        };
        LAYER_BUILDER layer;
        NN_BUILDER();
        NN_BUILDER(const std::vector<_generic_args> &list);
        ~NN_BUILDER();


        int add(_generic_args layer_data);
        NN_Model compile();

};

#endif
