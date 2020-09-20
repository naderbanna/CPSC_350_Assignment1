//header file Analysis.h
#include <string>

//capitalize Analysis
class Analysis{
  public:
    Analysis(); //default
    Analysis(std::string inputFile); //overloaded
    ~Analysis();  //deconstructer

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
    std::string dataFull;
    int dnaStrands;
    int sum;
    double mean;
    double var;
    double sd;
    double rprobA;
    double rprobC;
    double rprobT;
    double rprobG;
    double bprobAA;
    double bprobAC;
    double bprobAT;
    double bprobAG;
    double bprobCA;
    double bprobCC;
    double bprobCT;
    double bprobCG;
    double bprobTA;
    double bprobTC;
    double bprobTT;
    double bprobTG;
    double bprobGA;
    double bprobGC;
    double bprobGT;
    double bprobGG;





    // string relProb();
    // string relprobBi();
};
