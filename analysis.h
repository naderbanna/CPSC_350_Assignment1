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
    double getRelProb();
    double getBiProb();
    void writeFile();

    std::string iFile;
    int sum;
    double mean;
    double var;
    double sd;
  

    // string relProb();
    // string relprobBi();
};
