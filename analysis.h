//header file analysis.h
#include <string>

//capitalize analysis
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
  private:
    std::string iFile;
    std::string data;
    int dnaStrands;
    int sum;
    double mean;
    double var;
    double sd;



    // string relProb();
    // string relprobBi();
};
