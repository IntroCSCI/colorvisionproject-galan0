//Adonay Galan

#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>

using namespace std;

void createSVG(int neededColors, string title, 
     vector<string>);

//Pass by Refernce
void colorCode(vector<int>&, int neededColors);
//Pass by Value and Refernce
void sequence(vector<int>, vector<string>&);

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

  //Locating .svg in the name of file entered
  position = fileN.find(".svg");

  //No instance will result in .svg being added
  if(position == -1){
    paletteFile = fileN + ".svg";
  }
  else{
    paletteFile = fileN;
  }

  cout << "\"" << paletteFile << "\"" << " was created successfully." << endl;

  vector<int> rgbCodeValues;
  vector<string> svgColorCode;

  //Call to Functions
  colorCode(rgbCodeValues, numOfColors);
  sequence(rgbCodeValues, svgColorCode);

  createSVG(numOfColors, paletteFile, svgColorCode);

    
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
void colorCode(vector<int>& storeValues, int neededColors){
  int randomNumber;

  /*Creates 3 random numbers from 0-255 for each color 
  needed*/
  srand(time(0));
  for(int i = 0; i < 3 * neededColors; i++){
    randomNumber = rand()%256;
    storeValues.push_back(randomNumber);
  }
}


//FUNCTION #3
/*Combines the RGB values from the random generator into a 
single string*/
void sequence(vector<int> storeValues, vector<string>& 
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