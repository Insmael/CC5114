#include <iostream>
#include <string>
#include "Perceptron.h"
#include "PerceptronOP.cpp"
#include "PerceptronInput.cpp"

int main() {
  std::cout << "Test para comprobar el correcto funcionamiento de los perceptrones" << std::endl<<std::endl;
  std::string sep5 = "-----";

  PerceptronInput cero,uno;
  cero.setOutput(0);
  uno.setOutput(1);
  
  std::cout <<sep5<< "PERCEPTRON AND"<<sep5<< std::endl;
  std::cout << "perceptron: w=[1 1] b=-1"<<std::endl;
  PerceptronOP AND;
  AND.setValues(1,1,-1);
  AND.setInputs(&cero, &cero); 
  std::cout << "input: 0 0 | output: 0 | result: " << AND.getOutput() << std::endl;
  AND.setInputs(&cero, &uno); 
  std::cout << "input: 0 1 | output: 0 | result: " << AND.getOutput() << std::endl;
  AND.setInputs(&uno, &cero); 
  std::cout << "input: 1 0 | output: 0 | result: " << AND.getOutput() << std::endl;
  AND.setInputs(&uno, &uno); 
  std::cout << "input: 1 1 | output: 1 | result: " << AND.getOutput() << std::endl;


  std::cout <<sep5<< "PERCEPTRON OR"<<sep5<< std::endl;
  std::cout << "perceptron: w=[1 1] b=0"<<std::endl;
  PerceptronOP OR;
  OR.setValues(1,1,0);
  OR.setInputs(&cero, &cero); 
  std::cout << "input: 0 0 | output: 0 | result: " << OR.getOutput() << std::endl;
  OR.setInputs(&cero, &uno); 
  std::cout << "input: 0 1 | output: 1 | result: " << OR.getOutput() << std::endl;
  OR.setInputs(&uno, &cero); 
  std::cout << "input: 1 0 | output: 1 | result: " << OR.getOutput() << std::endl;
  OR.setInputs(&uno, &uno); 
  std::cout << "input: 1 1 | output: 1 | result: " << OR.getOutput() << std::endl;


  
  std::cout <<sep5<< "PERCEPTRON NAND"<<sep5<< std::endl;
  std::cout << "perceptron: w=[-2 -2] b=3"<<std::endl;
  PerceptronOP NAND;
  NAND.setValues(-2,-2,3);
  NAND.setInputs(&cero, &cero); 
  std::cout << "input: 0 0 | output: 1 | result: " << NAND.getOutput() << std::endl;
  NAND.setInputs(&cero, &uno); 
  std::cout << "input: 0 1 | output: 1 | result: " << NAND.getOutput() << std::endl;
  NAND.setInputs(&uno, &cero); 
  std::cout << "input: 1 0 | output: 1 | result: " << NAND.getOutput() << std::endl;
  NAND.setInputs(&uno, &uno); 
  std::cout << "input: 1 1 | output: 0 | result: " << NAND.getOutput() << std::endl;

  

  std::cout <<sep5<< "NETWORK SUMA"<<sep5<< std::endl;
  std::cout<<"estructura de la network: (carry y sum son perceptrones nand)"<<std::endl;
  std::cout<<"        _________                                            "<<std::endl;
  std::cout<<" in1___/         \\nand2______                                "<<std::endl;
  std::cout<<"       \\         /           \\                               "<<std::endl;
  std::cout<<"        \\nand1__/____carry    \\_sum                          "<<std::endl;
  std::cout<<"        /       \\             /                              "<<std::endl;
  std::cout<<" in2___/_________\\nand3______/                               "<<std::endl;
  std::cout<<"                                                             "<<std::endl;
  PerceptronOP sum, carry, nand1, nand2, nand3;
  Perceptron  *in1, *in2;
  
  nand1.setValues(-2,-2,3);

  nand2.setValues(-2,-2,3);

  nand3.setValues(-2,-2,3);
  nand3.setInputs(&nand1, in2);

  sum.setValues(-2,-2,3);
  sum.setInputs(&nand2,&nand3);

  carry.setValues(-2,-2,3);
  carry.setInputs(&nand1,&nand1);

  nand1.setInputs(&cero,&cero);
  nand2.setInputs(&nand1, &cero);
  nand3.setInputs(&nand1, &cero);
  std::cout << "input: 0 0 | output: s:0 c:0 | result: s:" << sum.getOutput() <<" c:"<< carry.getOutput()<< std::endl;
  nand1.setInputs(&cero,&uno);
  nand2.setInputs(&nand1, &cero);
  nand3.setInputs(&nand1, &uno);
  std::cout << "input: 0 1 | output: s:1 c:0 | result: s:" << sum.getOutput() <<" c:"<< carry.getOutput()<< std::endl;
  nand1.setInputs(&uno,&cero);
  nand2.setInputs(&nand1, &uno);
  nand3.setInputs(&nand1, &cero);
  std::cout << "input: 1 0 | output: s:1 c:0 | result: s:" << sum.getOutput() <<" c:"<< carry.getOutput()<< std::endl;
  nand1.setInputs(&uno,&uno);
  nand2.setInputs(&nand1, &uno);
  nand3.setInputs(&nand1, &uno);
  std::cout << "input: 1 1 | output: s:0 c:1 | result: s:" << sum.getOutput() <<" c:"<< carry.getOutput()<< std::endl;
  
  return 0;
}
