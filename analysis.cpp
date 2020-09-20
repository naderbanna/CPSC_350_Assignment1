#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "Analysis.h"

using namespace std;

//default constructor
Analysis::Analysis(){
  iFile = "testInput.txt";

  ifstream dnaStream;
  dnaStream.open(iFile);
  string line = "";
  int i;
  for(i = 0; getline(dnaStream, line); ++i){
    if(line.back() == '\r')
      line.erase(line.size() - 1);
    data += line + " ";
    //dataFull += line;
  }
  dnaStrands = i;
  dnaStream.close();
}

//overloaded constructor
Analysis::Analysis(string input){
  iFile = input;

  ifstream dnaStream;
  dnaStream.open(iFile);
  string line = "";
  int i;
  for(i = 0; getline(dnaStream, line); ++i){
    if(line.back() == '\r')
      line.erase(line.size() - 1);
    data += line + " ";
  }
  dnaStrands = i;
  dnaStream.close();
}

//destructor
Analysis::~Analysis(){
}

int Analysis::getSum(){
  sum = 0;
  for(char c : data)
    if(c != ' ')
      sum += 1;
  return sum;
}

double Analysis::getMean(){
  mean = 0;
  mean = getSum()/(double)dnaStrands;
  return mean;

}

double Analysis::getVar(){
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

double Analysis::getSd(){
  sd = sqrt(getVar());
  return sd;
}

double Analysis::getRelProb(){
  rprobA = 0;
  rprobC = 0;
  rprobG = 0;
  rprobT = 0;

  for(char c : data){
    if(c == 'A' || c == 'a')
      rprobA += 1;
    if(c == 'C' || c == 'c')
      rprobC += 1;
    if(c == 'T' || c == 't')
      rprobT += 1;
    if(c == 'G' || c == 'g')
      rprobG += 1;
  }

  rprobA = rprobA/getSum();
  rprobC = rprobC/getSum();
  rprobT = rprobT/getSum();
  rprobG = rprobG/getSum();
}

double Analysis::getBiProb(){
  bprobAA,bprobAC,bprobAT,bprobAG,bprobCA,bprobCC,bprobCT,bprobCG,bprobTA,
  bprobTC,bprobTT,bprobTG,bprobGA,bprobGC,bprobGT,bprobGG = 0;

  for(int i = 0; i < data.size(); ++i){
    if(data[i] == 'A' && data[i+1] == 'A' || data[i] == 'a' && data[i+1] == 'a')
      bprobAA += 1;
    if(data[i] == 'A' && data[i+1] == 'C' || data[i] == 'a' && data[i+1] == 'c')
      bprobAC += 1;
    if(data[i] == 'A' && data[i+1] == 'T' || data[i] == 'a' && data[i+1] == 't')
      bprobAT += 1;
    if(data[i] == 'A' && data[i+1] == 'G' || data[i] == 'a' && data[i+1] == 'g')
      bprobAG += 1;
    if(data[i] == 'C' && data[i+1] == 'A' || data[i] == 'c' && data[i+1] == 'a')
      bprobCA += 1;
    if(data[i] == 'C' && data[i+1] == 'C' || data[i] == 'c' && data[i+1] == 'c')
      bprobCC += 1;
    if(data[i] == 'C' && data[i+1] == 'T' || data[i] == 'c' && data[i+1] == 't')
      bprobCT += 1;
    if(data[i] == 'C' && data[i+1] == 'G' || data[i] == 'c' && data[i+1] == 'g')
      bprobCG += 1;
    if(data[i] == 'T' && data[i+1] == 'A' || data[i] == 't' && data[i+1] == 'a')
      bprobTA += 1;
    if(data[i] == 'T' && data[i+1] == 'C' || data[i] == 't' && data[i+1] == 'c')
      bprobTC += 1;
    if(data[i] == 'T' && data[i+1] == 'T' || data[i] == 't' && data[i+1] == 't')
      bprobTT += 1;
    if(data[i] == 'T' && data[i+1] == 'G' || data[i] == 't' && data[i+1] == 'g')
      bprobTG += 1;
    if(data[i] == 'G' && data[i+1] == 'A' || data[i] == 'g' && data[i+1] == 'a')
      bprobGA += 1;
    if(data[i] == 'G' && data[i+1] == 'C' || data[i] == 'g' && data[i+1] == 'c')
      bprobGC += 1;
    if(data[i] == 'G' && data[i+1] == 'T' || data[i] == 'g' && data[i+1] == 't')
      bprobGT += 1;
    if(data[i] == 'G' && data[i+1] == 'G' || data[i] == 'g' && data[i+1] == 'g')
      bprobGG += 1;
  }

  bprobAA = bprobAA/getSum();
  bprobAC = bprobAC/getSum();
  bprobAT = bprobAT/getSum();
  bprobAG = bprobAG/getSum();
  bprobCA = bprobCA/getSum();
  bprobCC = bprobCC/getSum();
  bprobCT = bprobCT/getSum();
  bprobCG = bprobCG/getSum();
  bprobTA = bprobTA/getSum();
  bprobTC = bprobTC/getSum();
  bprobTT = bprobTT/getSum();
  bprobTG = bprobTG/getSum();
  bprobGA = bprobGA/getSum();
  bprobGC = bprobGC/getSum();
  bprobGT = bprobGT/getSum();
  bprobGG = bprobGG/getSum();
}

void Analysis::writeFile(){
  ofstream result;
  result.open("output.txt");
  result << "The Sum of the length of the DNA strings is: " << getSum() << endl;
  result << "The Mean of the length of the DNA strings is: " << getMean() << endl;
  result << "The Variance of the length of the DNA strings is: " << getVar() << endl;
  result << "The Standard Deviation of the length of the DNA strings is: " << getSd() << endl;
  result << "Here is the Relative Probability of each nucleotide:" <<  endl;
  getRelProb();
  getBiProb();
  result <<"A: " << rprobA << endl;
  result <<"C: " << rprobC << endl;
  result <<"T: " << rprobT << endl;
  result <<"G: " << rprobG << endl;
  result << endl;
  result << "Here is the Relative Probability of each nucleotide bigram: " << endl;
  result << "AA: " << bprobAA << endl;
  result << "AC: " << bprobAC << endl;
  result << "AT: " << bprobAT << endl;
  result << "AG: " << bprobAG << endl;
  result << "CA: " << bprobCA << endl;
  result << "CC: " << bprobCC << endl;
  result << "CT: " << bprobCT << endl;
  result << "CG: " << bprobCG << endl;
  result << "TA: " << bprobCA << endl;
  result << "TC: " << bprobCC << endl;
  result << "TT: " << bprobCT << endl;
  result << "TG: " << bprobCG << endl;
  result << "GA: " << bprobCA << endl;
  result << "GC: " << bprobCC << endl;
  result << "GT: " << bprobCT << endl;
  result << "GG: " << bprobCG << endl;

  //result << data << endl;
  result.close();

}
