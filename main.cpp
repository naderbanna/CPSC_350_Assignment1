#include <iostream>
#include <fstream>
#include "Analysis.h"
//#include "Analysis.cpp"
//#include "Analysis.h";
using namespace std;

int main(int argc, char** argv){

  //Analysis *test = new Analysis();
  Analysis *test = new Analysis("assign1-sampleInput.txt");

  test->writeFile();


  return 0;
};
