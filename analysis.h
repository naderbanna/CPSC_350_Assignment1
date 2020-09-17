#include <iostream>

using namepspace std;

class fileProcessor{
  public:
    fileProcessor();
    string openFile(string input);
    ~fileProcessor();

    //void open();
    void close();
    void writeOutput();

}
