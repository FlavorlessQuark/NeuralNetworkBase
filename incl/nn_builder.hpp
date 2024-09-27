#ifndef NN_BUILDER_CLASS
#define NN_BUILDER_CLASS

#include "nn_header.hpp"



class NN_BUILDER {
    typedef struct _INTERN_LAYER_DATA {
        int inputs;
        int outputs;
        activation_fn activation;
    } _INTERN_LAYER_DATA;
    private:
        int m;
        int n;
        int type;

        std::vector<_INTERN_LAYER_DATA> layers;

    public:
        class LAYER_BUILDER {

            public :

                static _INTERN_LAYER_DATA add() {};
                static _INTERN_LAYER_DATA dense();
                static _INTERN_LAYER_DATA dot();
                static _INTERN_LAYER_DATA sub();
        };
        LAYER_BUILDER layer;
        NN_BUILDER() {};
        NN_BUILDER(std::vector<_INTERN_LAYER_DATA>) {};
       ~NN_BUILDER() {};


        int add(_INTERN_LAYER_DATA layer_data) {return 0;};
        NN_Model compile();

};

#endif
