#include "Perceptron.h"

class PerceptronInput: public Perceptron {
private:
  int output;
public:
  ~PerceptronInput(){};
  void setOutput(int n){
    if (n>0)
      output=1;
    else
      output=0;
}
  int getOutput() {
    return output;
}
};
