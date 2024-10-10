#ifndef NN_BUILDER_CLASS
#define NN_BUILDER_CLASS

#include "nn_header.hpp"
#include "Eigen/Core"



typedef COMPILED_LAYER (layer_fn (const struct _INTERN_LAYER_DATA &, const struct _INTERN_LAYER_DATA &));
typedef enum LAYER_IDS {
    INPUT = 0,
    DENSE,
};
 typedef struct _INTERN_LAYER_DATA {
    void *data;
    int layer_ID;
    std::vector<double> inShape;
    std::vector<double> outShape;
    activation_fn *activation;
    layer_fn *compile_fn;
} _INTERN_LAYER_DATA;

typedef struct _dense_data {
    int units;
}   _dense_data;

class NN_BUILDER {


    typedef _INTERN_LAYER_DATA (layer_fn (void *));
    private:

        std::vector<_INTERN_LAYER_DATA> _layers;

    public:

        class LAYER_BUILDER {
            protected:
            int test1;
            private :
                int test;
            public :

                static _INTERN_LAYER_DATA add();
                static _INTERN_LAYER_DATA *dense(const std::vector<int> &inputShape = {}, std::vector<int> units = {1}, activation_fn activation = NULL);
                static _INTERN_LAYER_DATA dot();
                static _INTERN_LAYER_DATA sub();
        };
        LAYER_BUILDER layer;
        NN_BUILDER();
        NN_BUILDER(const std::vector<_INTERN_LAYER_DATA> &list);
        ~NN_BUILDER();


        int add(const _INTERN_LAYER_DATA &layer_data);
        NN_Model *compile();

};

#endif
