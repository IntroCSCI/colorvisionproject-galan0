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

void createSVG(int color, string file, vector<string> g);

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
  position = fileN.find(".svg");

  //No instance will result in .txt being added
  if(position == -1){
    paletteFile = fileN + ".svg";
  }
  else{
    paletteFile = fileN;
  }

  cout << "\"" << paletteFile << "\"" << " was created successfully." << endl;

  //RGB colorcodes
  int numColor = numOfColors;
  int generatedNum;
  int countforgen = 0;
  vector <int> generatedNumHolder;
  vector <string> colorCode;

  srand(time(0));
  for(int i = 0; i < 3 * numColor; i++){
    generatedNum = (rand()%256) + 1;
    generatedNumHolder.push_back(generatedNum);
  }

  for(int i = 0; i < numColor; i++){
    int value1 = generatedNumHolder[0 + (3 * countforgen)];
    int value2 = generatedNumHolder[1+ (3 * countforgen)];
    int value3 = generatedNumHolder[2+ (3 * countforgen)];

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
    countforgen ++;
  }

  createSVG(numOfColors, paletteFile, colorCode);

    
 }

else{
  cout << "Minimum of 2 was not met. Please try again" << endl;
}
 
return 0;
}

//Function Definitons:

//Specified instructions for the layout for the pallete
void createSVG(int color, string file, vector<string> g){
  int x = 50;
    int y = 50;
    int width = 100;
    int height = 100;
    int num = color;
    int count = 0;
    int ycolumn = 0;

    ofstream newFile(file);
    if(newFile.is_open()){
    newFile << "<?xml version=\"1.0\" encoding=\"utf-8\"?>"<< endl;
    newFile << "<svg xmlns=\"http://www.w3.org/2000/svg\" height=\"1000\" width=\"1000\">" << endl;

    newFile << "<text x =\"390\" y= \"25\">";
    newFile << "Number of distint color values: ";
    newFile << num;
    newFile << "</text>";

    for(int i =0; i < num; i++){
    newFile <<"<rect ";

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
    newFile << g[i];
    newFile <<"\" />" << endl;
    count++;
    }
    newFile << "</svg>";

}
}