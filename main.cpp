#include <iostream>
#include <fstream>
//#include "analysis.h";
using namespace std;

int main(int argc, char** argv){

  // string inputFile = argv[0];
  //
  // cout << inputFile << endl;

  ifstream inputFile("assign1-sampleInput.txt");
  int sum;
  char data;
  while(!inputFile.eof()){
      for(int i = 0; i < data.length(); ++i){
        
      }
        inputFile>>data;
    cout<<data;
  }
  cout<<endl;


  inputFile.close();


};
