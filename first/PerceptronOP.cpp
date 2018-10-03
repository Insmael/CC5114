#include <iostream>
#include "Perceptron.h"

class PerceptronOP: public Perceptron {
private:
  Perceptron * input1;
  Perceptron * input2;
  int W[2];
  int b;
public:
  void setValues(int w0, int w1, int bias){
    W[0]=w0;
    W[1]=w1;
    b=bias;
}
  void setInputs(Perceptron * in1, Perceptron * in2){
    input1=in1;
    input2=in2;
}
  int getOutput() {
  return ((input1->getOutput()*W[0]+input2->getOutput()*W[1]+b)>0);
}

};
