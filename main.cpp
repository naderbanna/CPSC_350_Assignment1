#include <iostream>
#include <fstream>
#include "analysis.h"
//#include "analysis.cpp"
//#include "analysis.h";
using namespace std;

int main(int argc, char** argv){

  analysis *test = new analysis("testInput.txt");
  test->writeFile();


  return 0;
};
