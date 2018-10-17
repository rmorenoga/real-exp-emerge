#include <..\lib\ANNBias.h>

void propagateANN(float input [],float output[]){
    int i,j,k;
    for( j = 0 ; j < ANN_HIDDEN_SIZE ; j++ ) {         /* j loop computes hidden unit activations */
        
        sumH[j] = weightIH[0][j];
        for( i = 1 ; i < ANN_INPUT_SIZE + 1 ; i++ ) {
            sumH[j] += input[i] * weightIH[i][j] ;
        }
        hidden[j] = 1.0/(1.0 + exp(-sumH[j])) ;
    }
    
    for( k = 0 ; k < ANN_OUTPUT_SIZE ; k++ ) {         /* k loop computes output unit activations */

        sumO[k] = weightHO[0][k];
        for( j = 1 ; j < ANN_HIDDEN_SIZE + 1  ; j++ ) {
            sumO[k] += hidden[j] * weightHO[j][k] ;
        }
        output[k] = 1.0/(1.0 + exp(-sumO[k])) ;

    } 
      
}
    
