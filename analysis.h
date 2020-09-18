//header file analysis.h
#include <string>

class analysis{
  public:
    analysis(); //default
    analysis(std::string inputFile); //overloaded
    ~analysis();  //deconstructer

    int getSum();
    double getMean();
    double getVar();
    double getSd();

    std::string iFile;
    int sum;
    double mean;

    // string relProb();
    // string relprobBi();
};
