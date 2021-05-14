#ifndef PALETTE_H
#define PALETTE_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class palette
{
  private: 
    string NewFileSvg;
  
  public: 
    void setFileSvg(string x);
    string getFileSvg();

};
#endif