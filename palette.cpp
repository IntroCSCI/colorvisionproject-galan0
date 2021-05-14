#include "palette.h"
#include <string>
#include <vector>

using std::string;
using std::vector;


void palette::setFileSvg(string userFileName){
  newFileSvg = userFileName;
}

string palette::getFileSvg(){
  string validFile = newFileSvg;
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

  newFileSvg = paletteFile;

  return newFileSvg;
}