#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
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

  return sum;
}

double analysis::getMean(){
  mean = 0;
  ifstream dnaStream;
  dnaStream.open(iFile);

  //get line count of file
  string line = "";
  double lineCount;
  for (lineCount = 0; getline(dnaStream, line); ++lineCount)
  ;
  mean = getSum()/lineCount;

  return mean;

}

double analysis::getVar(){
  var = 0;
  ifstream dnaStream;
  dnaStream.open(iFile);

  string line = "";
  double temp = 0;
  int lineCount;

  for (lineCount = 0; getline(dnaStream, line); ++lineCount)
    temp += pow((line.length()-1)-getMean(),2);

  var = temp/lineCount;
  return var;
}

double analysis::getSd(){
  sd = sqrt(getVar());
  return sd;
}

void analysis::writeFile(){
  ofstream result;
  result.open("output.txt");
  result << "The Sum of the length of the DNA strings is: " << getSum() << endl;
  result << "The Mean of the length of the DNA strings is: " << getMean() << endl;
  result << "The Variance of the length of the DNA strings is: " << getVar() << endl;
  result << "The Standard Deviation of the length of the DNA strings is: " << getSd() << endl;

  result.close();

}
