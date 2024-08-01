#pragma once

#include <math.h>
#include "nn_structs.h"


void parse_input(char *filename, TDataSet *training_data);

NN_BUILDER *NN_Build_New();

void NN_Build_AddLayer(NN_BUILDER *builder, int n, int data, int type, ActFn *actfn);

NN *NN_Build_Finalize(NN_BUILDER *builder);
// Math
double sigmoid(double num);
