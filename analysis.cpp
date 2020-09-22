#define _USE_MATH_DEFINES
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
  //open file, assigns each line + a space to variable data (handles nextline character)
  ifstream dnaStream;
  dnaStream.open(iFile);
  string line = "";
  int i;
  for(i = 0; getline(dnaStream, line); ++i){
    if(line.back() == '\r')
      line.erase(line.size() - 1);
    //to uppercase
    transform(line.begin(), line.end(), line.begin(), ::toupper);
    data += line + " ";
  }
  dnaStrands = i;
  dnaStream.close();
}

//overloaded constructor
Analysis::Analysis(string input){
  iFile = input;
  //open file, assigns each line + a space to variable data (handles nextline character)
  ifstream dnaStream;
  dnaStream.open(iFile);
  string line = "";
  int i;
  for(i = 0; getline(dnaStream, line); ++i){
    if(line.back() == '\r')
      line.erase(line.size() - 1);
    //to uppercase
    transform(line.begin(), line.end(), line.begin(), ::toupper);
    data += line + " ";
  }
  dnaStrands = i;
  dnaStream.close();
}

//destructor
Analysis::~Analysis(){
}
//get sum function
int Analysis::getSum(){
  sum = 0;
  //iterate through data and add non-space values to sum
  for(char c : data)
    if(c != ' ')
      sum += 1;
  return sum;
}
//get mean function
double Analysis::getMean(){
  mean = 0;
  //divide the sum by the number of dna strands
  return mean = getSum()/(double)dnaStrands;
}
//get variable function
double Analysis::getVar(){
  var = 0;
  double temp;
  //iterate through data
  for(char c : data){
    if(c == ' '){
      //at end of dna strand, calculate difference to mean and ^2
      var += pow(temp-getMean(),2);
      temp = 0;
    }if(c != ' ')
      temp += 1;
  }
  //divide by total number of dna strands for final variance
  return var/(double)dnaStrands;
}
//get standard deviation
double Analysis::getSd(){
  //square root of variance
  return sd = sqrt(getVar());
}
//get relative probability function
double Analysis::getRelProb(){
  rprobA = 0;
  rprobC = 0;
  rprobG = 0;
  rprobT = 0;
  //iterate through data and count each nucleotide
  for(char c : data){
    if(c == 'A')
      rprobA += 1;
    if(c == 'C')
      rprobC += 1;
    if(c == 'T')
      rprobT += 1;
    if(c == 'G')
      rprobG += 1;
  }
  //divide each count by the total sum for probability
  rprobA = rprobA/getSum();
  rprobC = rprobC/getSum();
  rprobT = rprobT/getSum();
  rprobG = rprobG/getSum();
}
//relative probability function
double Analysis::getBiProb(){
  bprobAA,bprobAC,bprobAT,bprobAG,bprobCA,bprobCC,bprobCT,bprobCG,bprobTA,
  bprobTC,bprobTT,bprobTG,bprobGA,bprobGC,bprobGT,bprobGG = 0;
  //iterate through data in pairs and assign to each bigram count
  for(int i = 0; i < data.size(); ++i){
    if(data[i] == 'A' && data[i+1] == 'A')
      bprobAA += 1;
    if(data[i] == 'A' && data[i+1] == 'C')
      bprobAC += 1;
    if(data[i] == 'A' && data[i+1] == 'T')
      bprobAT += 1;
    if(data[i] == 'A' && data[i+1] == 'G')
      bprobAG += 1;
    if(data[i] == 'C' && data[i+1] == 'A')
      bprobCA += 1;
    if(data[i] == 'C' && data[i+1] == 'C')
      bprobCC += 1;
    if(data[i] == 'C' && data[i+1] == 'T')
      bprobCT += 1;
    if(data[i] == 'C' && data[i+1] == 'G')
      bprobCG += 1;
    if(data[i] == 'T' && data[i+1] == 'A')
      bprobTA += 1;
    if(data[i] == 'T' && data[i+1] == 'C')
      bprobTC += 1;
    if(data[i] == 'T' && data[i+1] == 'T')
      bprobTT += 1;
    if(data[i] == 'T' && data[i+1] == 'G')
      bprobTG += 1;
    if(data[i] == 'G' && data[i+1] == 'A')
      bprobGA += 1;
    if(data[i] == 'G' && data[i+1] == 'C')
      bprobGC += 1;
    if(data[i] == 'G' && data[i+1] == 'T')
      bprobGT += 1;
    if(data[i] == 'G' && data[i+1] == 'G')
      bprobGG += 1;
  }
  //divide each bigram count by the total sum for bigram probability
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
//function to generate 1000 dna strands
void Analysis::generateDNA(){

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  srand((unsigned)time(NULL));
  a = (float) rand()/RAND_MAX;
  b = (float) rand()/RAND_MAX;

  c = sqrt(-2*log(a)) * cos(2*M_PI*b);

  d = getVar()*c + getMean();

  for (int j = 0; j < 1001; ++j){
    string genStrand = "";
    for(int i = 0; i < round(d); ++i){
      bool isLetter = false;
      //find letter based on probability
      while(!isLetter){
        double nt = (float) rand()/RAND_MAX;
        int rA = rprobA/nt;
        nt = (float) rand()/RAND_MAX;
        int rC = rprobC/nt;
        nt = (float) rand()/RAND_MAX;
        int rT = rprobT/nt;
        nt = (float) rand()/RAND_MAX;
        int rG = rprobG/nt;
        //dividing probability against random number
        int rSum = rA + rC + rT + rG;
        //assign nucleotide based on probability
        if(rSum == 1){
          isLetter = true;
          if(rA == 1){
            genStrand.append("A");
          }else if(rC == 1){
            genStrand.append("C");
          }else if(rT == 1){
            genStrand.append("T");
          }else{
            genStrand.append("G");
          }
        }
      }
  }
  //print each generated strand to file
  ofstream result;
  result.open("naderbanna.txt", std::ios_base::app);
  result << genStrand << endl;
  result.close();
}
}

void Analysis::writeFile(){
  ofstream result;
  result.open("naderbanna.txt");
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
  result << endl;
  generateDNA();
  result.close();
}
