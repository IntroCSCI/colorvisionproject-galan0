#ifndef PALETTE_H
#define PALETTE_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class palette
{
  private: 
    string newFileSvg;
  
  public: 
    void setFileSvg(string userFileName);
    string getFileSvg();

};
#endif