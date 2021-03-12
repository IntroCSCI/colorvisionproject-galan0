//Adonay Galan

#include <iostream>
#include <fstream>
#include <stdio.h>
#include "libraries/bitmap.h"

using namespace std;

int main()
{
 //Variables
 int numOfColors;
 string paletteFile, fileN;
 size_t position;

//Ask for amount of Colors
 cout << "Enter the amount of colors needed (2+): " << endl;

//DO-While loop until the requirement is met
 do{
  cin >> numOfColors;
  if(numOfColors <2){
    cout << "Minimum amount of 2 was not met. Please try again."
          << endl;
  }

 }while(numOfColors <2);

//Verify the number of Colors is 2+ (precaution)
 if(numOfColors >= 2){

   //Ask user for file name
   cout << "Enter a name for the palette file: " << endl;
   cin.ignore();
   getline(cin, fileN);

  //Locating .txt in the name of file entered
  position = fileN.find(".txt");

  //No instance will result in .txt being added
  if(position == -1){
    paletteFile = fileN + ".txt";
  }
  else{
    paletteFile = fileN;
  }

  cout << "\"" << paletteFile << "\"" << " was created successfully." << endl;

  //Attempting to open the file with the given name
  ofstream dataFile;
  dataFile.open(paletteFile, ios:: out);   

  //Entering information into the file
  dataFile << "Number of distint color values: "
  << numOfColors << endl;

  dataFile.close();
}

else{
  cout << "Minimum of 2 was not met. Please try again" << endl;
}
 
return 0;
}
