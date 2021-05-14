//Adonay Galan

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "palette.h"

using namespace std;

void createSVG(int neededColors, string title, 
     vector<string>);

//Pass by Refernce
void randomGeneratedValues(vector<int>&, int neededColors);
//Pass by Value and Refernce
void rgbForSvg(vector<int>, vector<string>&);

int main()
{
 //Variables
 int numOfColors;
 string fileN;
 palette colorFileName;

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

  colorFileName.setFileSvg(fileN);

  cout << "\"" << colorFileName.getFileSvg() << "\"" << " was created successfully." << endl;

  vector<int> rgbCodeValues;
  vector<string> svgColorCode;

  //Call to Functions
  randomGeneratedValues(rgbCodeValues, numOfColors);
  rgbForSvg(rgbCodeValues, svgColorCode);

  createSVG(numOfColors, colorFileName.getFileSvg(), svgColorCode);

    
 }

else{
  cout << "Minimum of 2 was not met. Please try again" << endl;
}
 
return 0;
}

//Function Definitons:

//FUNCTION #1
//Specified instructions for the layout for the pallete
void createSVG(int neededColors, string title, 
vector<string> svgCodeFormat){
    int x = 50;
    int y = 50;
    int width = 100;
    int height = 100;
    int distinctColors = neededColors;
    int count = 0;
    int ycolumn = 0;

  ofstream newFile(title);
  if(newFile.is_open()){
    newFile << "<?xml version=\"1.0\" encoding=\"utf-8\"?>"<< endl;
    newFile << "<svg xmlns=\"http://www.w3.org/2000/svg\" height=\"1000\" width=\"1000\">" << endl;

    newFile << "<text x =\"390\" y= \"25\">";
    newFile << "Number of distinct color values: ";
    newFile << distinctColors;
    newFile << "</text>";

  for(int i =0; i < distinctColors; i++){
    newFile <<"<rect ";

    /*Once count equals 9 it will begin printing the color palette on the next line*/
    if(count == 9){
      count = 0;
      ycolumn ++;
    }

    newFile <<"x=\"" << x + 100 * count << "\" ";
    newFile <<"y=\"" << y + 100 * ycolumn << "\" ";

    newFile <<"width=\"" << width << "\" ";
    newFile <<"height=\"" << height << "\" ";
    newFile <<"stroke=\"black\" stroke-width=\"4\" ";
    newFile <<"fill=\""; 
    newFile << svgCodeFormat[i];
    newFile <<"\" />" << endl;
    count++;
    }
    newFile << "</svg>";

  }
}


//FUNCTION #2
//Random Generator creates the three values for the RGB code
void randomGeneratedValues(vector<int>& storeValues, int neededColors){
  int randomNumber;
  int count = 0;

  /*Creates 3 random numbers from 0-255 for each color 
  needed*/
  srand(time(0));
  for(int i = 0; i < 3 * neededColors; i++){
    randomNumber = rand()%256;

    //An attempt to cause wider variety by altering R value to avoid similar tones and problematic combinations
    
    if(count == 3 && randomNumber > 66){
      randomNumber = randomNumber - 100;
    }

    if(count == 6){
      count = 0;
      randomNumber = randomNumber + 100;
    }

    storeValues.push_back(randomNumber);
    count++;
  }
}


//FUNCTION #3
/*Combines the RGB values from the random generator into a 
single string*/
void rgbForSvg(vector<int> storeValues, vector<string>& 
     rgbCodes){
  int count = 0;

  for(int i=0; i < storeValues.size(); i++){
    int value1 = storeValues[0 + (3 * count)];
    int value2 = storeValues[1 + (3 * count)];
    int value3 = storeValues[2 + (3 * count)];

    //converts the integers into string
    stringstream convertion1, convertion2, convertion3;
    string code, r, g, b;

    convertion1 << value3;
    convertion1 >> r;
    convertion2 << value2;
    convertion2 >> g;
    convertion3 << value1;
    convertion3 >> b;

    /*Template that is the correct way of using an RGB code 
    for an SVG file*/
    code = "rgb(" + r + "," + g + "," + b + ")";
    
    rgbCodes.push_back(code);
    count ++;
  }

}