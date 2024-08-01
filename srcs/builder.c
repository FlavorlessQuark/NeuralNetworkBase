#include "../incl/nn.h"

NN_BUILDER *NN_Build_New(char *train_filename, int entries)
{
    NN_BUILDER *result;

    result = calloc(1, sizeof(*result));
    // TODO: NOT SAFE LOL
    result->train_data = malloc(strlen(train_filename));
    strcpy(train_filename);




}

void NN_Build_AddLayer(NN_BUILDER *builder, int n, int data, int type, ActFn *actfn);

NN *NN_Build_Finalize(NN_BUILDER *builder)
{
    NN *result;

    result = calloc(builder->total_alloc);

}

NN *NN_Build_FromFile(char *filename);
