#include <iostream>
#include <fstream>
#include "analysis.h"
//#include "analysis.cpp"
//#include "analysis.h";
using namespace std;

int main(int argc, char** argv){
  // string sampleInput = "assign1-sampleInput.txt";
  //analysis test ("assign1-sampleInput.txt");
  //test("assign1-sampleInput");
  //analysis *test = new analysis("assign1-sampleInput.txt");

  analysis *test = new analysis("assign1-sampleInput.txt");
  test->getSum();
  test->getMean();
  // string inputFile = argv[0];
  //
  // cout << inputFile << endl;

  // ifstream inputFile("assign1-sampleInput.txt");
  // int sum;
  // char data;
  // while(!inputFile.eof()){
  //     for(int i = 0; i < data.length(); ++i){
  //
  //     }
  //       inputFile>>data;
  //   cout<<data;
  // }
  // cout<<endl;
  //
  //
  // inputFile.close();

  return 0;
};
