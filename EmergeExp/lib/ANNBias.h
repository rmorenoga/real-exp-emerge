#include <project.h>
#include <math.h>

#define ANN_INPUT_SIZE (12)
#define ANN_HIDDEN_SIZE (12)
#define ANN_OUTPUT_SIZE (6)

float input[ANN_INPUT_SIZE];
float sumH[ANN_HIDDEN_SIZE+1];
float hidden[ANN_HIDDEN_SIZE];
float sumO[ANN_OUTPUT_SIZE+1];
float output[ANN_OUTPUT_SIZE];

float weightIH[ANN_INPUT_SIZE+1][ANN_HIDDEN_SIZE];
float weightHO[ANN_HIDDEN_SIZE+1][ANN_OUTPUT_SIZE];

void propagateANN(float input[],float output[]);