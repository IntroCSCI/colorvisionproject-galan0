#include "palette.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

void palette::setFileSvg(string x){
  NewFileSvg = x;
}

string palette::getFileSvg(){
  string validFile = NewFileSvg;
  string paletteFile;
  size_t position;

  //Locating .svg in the name of file entered
  position = validFile.find(".svg");

  //No instance will result in .svg being added
  if(position == -1){
    paletteFile = validFile + ".svg";
  }
  else{
    paletteFile = validFile;
  } 

  NewFileSvg = paletteFile;

  return NewFileSvg;
}