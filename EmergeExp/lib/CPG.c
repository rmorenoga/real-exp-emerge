#include <..\lib\CPG.h>

float teta[5] = {0.0,-1,-1,-1,-1};
float ampli = 0.0;
float dampli = 0.0;
float offset = (0.3333)*M_PI;
float doffset = 0.0;
float output = 0.0;
float ampliSet = 0.0;
float offsetSet = 0.0;
float phaseDiffSet[2] = {M_PI/3,-M_PI/3};
float dt = 0.3;

float dteta(float teta[], float phaseDiffSet[]){
    float wij = 0.8; 
    float v = 0.3;
    float component = 0;
    int i;
    float sum = 2*M_PI*v;
    
    for (i = 1; i < 5 ; i++){
        if (teta[i] != -1){
            component = (wij*sin(teta[i]-teta[0]-phaseDiffSet[i-1]));
        }else{
            component = 0;   
        }
        sum = sum + component;
    }
    
    return sum;
}

float ddampli(float dampli, float ampli, float amp){
  int ar = 8;
  return ar*(((ar/4)*(amp-ampli))-dampli);
}

float ddoffset(float doffset, float offset, float of){
 int ax = 8;
return ax*(((ax/4)*(of-offset))-doffset); 
}

void updateCPG(float teta[]){
	float tetaNew = teta[0] + dteta(teta,phaseDiffSet)*dt;
	float ampliNew = ampli + dampli*dt;
	float dampliNew = dampli + ddampli(dampli,ampli,ampliSet)*dt;
	float offsetNew = offset + doffset*dt;
	float doffsetNew = doffset + ddoffset(doffset,offset,offsetSet)*dt;  
    
    teta[0] = tetaNew;
    ampli = ampliNew;
    dampli = dampliNew;
    offset = offsetNew;
    doffset = doffsetNew;
}




