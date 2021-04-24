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

  //RGB colorcodes
  int numColor = numOfColors;
  int generatedNum;
  int count = 0;
  vector <int> generatedNumHolder;
  vector <string> colorCode;

  cout << "num of color (2+)" << endl;
  cin >> numColor;

  srand(time(0));
  for(int i = 0; i < 3 * numColor; i++){
    generatedNum = (rand()%256) + 1;
    generatedNumHolder.push_back(generatedNum);
  }

  for(int i = 0; i < numColor; i++){
    int value1 = generatedNumHolder[0 + (3 * count)];
    int value2 = generatedNumHolder[1+ (3 * count)];
    int value3 = generatedNumHolder[2+ (3 * count)];

    stringstream rgb1, rgb2, rgb3;
    string all, a, b, c;

    rgb1 << value3;
    rgb1 >> a;
    rgb2 << value2;
    rgb2 >> b;
    rgb3 << value1;
    rgb3 >> c;

    all = "rgb(" + a + "," + b + "," + c + ")";
    colorCode.push_back(all);
    count ++;
  }

  /*//Attempting to open the file with the given name
  ofstream dataFile;
  dataFile.open(paletteFile, ios:: out);   

  //Entering information into the file
  dataFile << "Number of distint color values: "
  << numOfColors << endl;

  dataFile.close();*/


}

else{
  cout << "Minimum of 2 was not met. Please try again" << endl;
}
 
return 0;
}
