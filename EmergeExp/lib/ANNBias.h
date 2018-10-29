#include <project.h>
#include <math.h>

#define ANN_INPUT_SIZE (12)
#define ANN_HIDDEN_SIZE (12)
#define ANN_OUTPUT_SIZE (6)

//float input[ANN_INPUT_SIZE];
//float output[ANN_OUTPUT_SIZE];

const float weightIH[ANN_INPUT_SIZE+1][ANN_HIDDEN_SIZE];
const float weightHO[ANN_HIDDEN_SIZE+1][ANN_OUTPUT_SIZE];

void propagateANN(float input[],float output[]);
