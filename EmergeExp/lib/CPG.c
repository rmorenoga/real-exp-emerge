#include <..\lib\CPG.h>

float teta = 0.0;
float ampli = 0.0;
float dampli = 0.0;
float offset = (0.8333)*M_PI;
float doffset = 0.0;
float output = 0.0;
float ampliSet = 0.0;
float offsetSet = 0.0;
float phaseDiffSet = 0.0;
float dt = 0.3;
int Seleccion = 4;

float dteta(float tetaOwn, float teta2, float teta3, float phaseDiffSet){
    float wij = 0.8; 
    float v = 0.3;
    switch (Seleccion){
        case 1:
            return (2*M_PI*v)+(wij*sin(teta2-tetaOwn-phaseDiffSet));
        break;
        case 2:
            return (2*M_PI*v)+(wij*sin(teta3-tetaOwn+phaseDiffSet));
        break;
        case 3:
            return (2*M_PI*v)+(wij*sin(teta2-tetaOwn-phaseDiffSet))+(wij*sin(teta3-tetaOwn+phaseDiffSet));
        break;    
        default:
            return 2*M_PI*v;
        break;
            }
}

float ddampli(float dampli, float ampli, float amp){
  float ar = 30;
  return ar*((ar/4)*(amp-ampli)-dampli);
}

float ddoffset(float doffset, float offset, float of){
 float ax = 30;
return ax*((ax/4)*(of-offset)-doffset); 
}

void updateCPG(float teta1,float teta2){
	teta = teta + dteta(teta,teta1,teta2,phaseDiffSet)*dt;
	ampli = ampli + dampli*dt;
	dampli = dampli + ddampli(dampli,ampli,ampliSet)*dt;
	offset = offset + doffset*dt;
	doffset = doffset + ddoffset(doffset,offset,offsetSet)*dt;  
	output = offset + ampli*cos(teta);
}




