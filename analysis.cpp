#include <string>
#include <iostream>
#include <fstream>
#include "analysis.h"

using namespace std;

//default constructor
analysis::analysis(){
  iFile = "testInput.txt";
  sum = 0;
}

//overloaded constructor
analysis::analysis(string input){
  iFile = input;
  sum = 0;
}

//destructor
analysis::~analysis(){
}

int analysis::getSum(){
  sum = 0;
  //open input file
  ifstream dnaStream;
  dnaStream.open(iFile);

  //calculate the sum on nucleotides
  string line = "";
  while(getline (dnaStream, line)){
    sum += line.length() -1;
  }
  dnaStream.close();

  //write to output file
  ofstream result;
  result.open("output.txt");
  result << "The Sum of the length of the DNA strings is: " << sum << endl;
  result.close();
  return sum;
}

double analysis::getMean(){
  ifstream dnaStream;
  dnaStream.open(iFile);

  //get line count of file
  string line = "";
  double lineCount;
  for (lineCount = 0; getline(dnaStream, line); ++lineCount)
  ;
  mean = getSum()/lineCount;

  ofstream result;
  result.open("output.txt", std::ios_base::app);
  result << "The Mean of the length of the DNA strings is: " << mean << endl;
  result.close();
  return mean;

}
