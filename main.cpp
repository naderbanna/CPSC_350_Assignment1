#include <iostream>
#include <fstream>
#include "Analysis.h"

using namespace std;

int main(int argc, char** argv){
  string inputFile = argv[1];
  Analysis *test = new Analysis(inputFile);
  test->writeFile();
  return 0;
};
