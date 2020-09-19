#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "analysis.h"

using namespace std;

//default constructor
analysis::analysis(){
  iFile = "assign1-sampleInput.txt";

  ifstream dnaStream;
  dnaStream.open(iFile);
  string line = "";
  int i;
  for(i = 0; getline(dnaStream, line); ++i){
    line.erase(line.size() - 1);
    data += line + " ";
  }
  dnaStrands = i;
  dnaStream.close();
}

//overloaded constructor
analysis::analysis(string input){
  iFile = input;

  ifstream dnaStream;
  dnaStream.open(iFile);
  string line = "";
  int i;
  for(i = 0; getline(dnaStream, line); ++i){
    line.erase(line.size() - 1);
    data += line + " ";
  }
  dnaStrands = i;
  dnaStream.close();
}

//destructor
analysis::~analysis(){
}

int analysis::getSum(){
  sum = 0;
  for(char c : data)
    if(c != ' ')
      sum += 1;
  return sum;
}

double analysis::getMean(){
  mean = 0;
  mean = getSum()/(double)dnaStrands;
  return mean;

}

double analysis::getVar(){
  var = 0;
  double temp;

  for(char c : data){
    if(c == ' '){
      var += pow(temp-getMean(),2);
      temp = 0;
    }if(c != ' ')
      temp += 1;
  }
  return var/(double)dnaStrands;
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
  result << data << endl;
  result.close();

}
