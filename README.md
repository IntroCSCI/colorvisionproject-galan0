# SVG Palette Generator

## Description

The program will prompt the user for a number of colors needed for their palette and a name for the file that values will be stored in.

Depending on the the amount that was chosen a set of colors values will be added into the contents of the file as well.

### v0.2 Updates

This version of the program creates RGB color codes for each of the user's needed colors. These values were chosen with the help of a random number generator. This ensures that the palette consists of distinct colors.

The user will be able to see the amount of colors they chose. As well as, the color palette created in an svg file titled by the user.

### v1.0 Updates

In this update of the program previous features are present. However, this version makes a conscious effort to creates a color palette with the least amount of problematic color combinations.

It does so by modifying the R value in every RGB code so to avoid close or similar color value.


## Developer

Adonay Galan

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
Enter the amount of colors needed (2+): 
8
Enter a name for the palette file: 
myColors
"myColors.svg" was created successfully.
```

## C++ Guide

### Variables and Data Types

* `int numOfColors;` *stores the number the user enters*
* `size_t position;` *stores a position*
* `string fileN;` *stores the name of the file given by the user*
* `string paletteFile;` *stores the complete file name*
* `ofstream newFile(title);;` *used to create svg file and store colors*
* `int x = 50;` *determines the shape's position on x axis*
* `int y = 50;` *determines the shape's position on y axis*
* `int width = 100;` *width of square*
* `int height = 100;` *length of square*
* `int distinctColors;` *stores the amount of colors user needed*
* `int count = 0;` *keeps track of the amount of loops*
* `int ycolumn = 0;`*alters the y axis for the shape's position on y axis
* `int randomNumber;` *stores number from the random generator* 
* `stringstream convertion1, convertion2, convertion3;` *each used to hold a different integer that will be converted into a string*
* `string r, g, b;` *Each store strings that were made from the integers*
* `string code;` *stores the combination of r, g, and b string values and formatted for svg* 

### Console Input and Output
* `numOfColors` was assigned the number the user entered in `cin >> numOfCOlors`
* `fileN` was assigned the user's preferred file name from `getline(cin,fileN)`

### Decisions

* `if(numOfColors <2)` to display a message. If the the user enters a value 2 or more it should do nothing.
For example:
```
Enter the amount of colors needed (2+): 
1
Minimum amount of 2 was not met. Please try again.
3
Enter a name for the palette file:

```
*  There was another precaution set after the do while loop to verify and decide if the number met the requirments with `if(numOfColors >= 2)`
* `if(position == -1)` was used to verify if within the string `fileN` there
was not an instance of ".svg". If there was not then it would be added by the program and assign fileN to paletteFile. 
`else` it would simply assign fileN to paletteFile, because it found an instance of ".svg" within the string.
* `if(count == 9)` was used to restart (`count = 0;`) or add to (`ycolumn ++;`) an integer that dictates the position of the next palette color.

### Iteration

The `do-while` loop was include to trap the user from going any further into the program until the requirement of 2 or more colors were specified. Each time displaying a message to try again until  the condition :`while(numOfColors <2);`, was met.
For example:
```
Enter the amount of colors needed (2+): 
1
Minimum amount of 2 was not met. Please try again.
-1
Minimum amount of 2 was not met. Please try again.
0
Minimum amount of 2 was not met. Please try again.
-23
Minimum amount of 2 was not met. Please try again.
2
Enter a name for the palette file:

```


### File Input and Output

The file was opened with `dataFile.open(paletteFile,ios::out);` creating a new file with the name the user preferred even if it does not currently exist in the files folder. `ios::out` was included since the file was being open for writing in information

### Arrays/Vectors

* `vector<int> rgbCodeValues;` This vector is used to store integers that come from the random number generator. Since the number of integers created correlates to the amount of colors the user needs. A vector was used since it can shrink or expand the storage based on the needs at that very moment.
* `vector<string> svgColorCode;` This vector is used to store the RGB color code used in a svg file.A vector was used to ensure that there is enough space for the strings.

### Functions

* `void createSVG(int neededColors, string title, 
     vector<string>);` This function uses three parameters to open a svg file and create an image filled with one of the random colors created for the user's color palette. Here the values are not being changed and are an example of pass by value since it is a copy of the actual parameter's value being passed in.

* `void randomGeneratedValues(vector<int>&, int neededColors);` This function uses two parameters to determine the amount of values the randomizer needs to generate. Then storing that information into the vector with the use of `.push_back`. Here the value in the integer was a copy of the actual parameter(pass by value). While the `vector<int>&` when called modifies the value of the of the argument(pass by reference).

* `void rgbForSvg(vector<int>, vector<string>&);` This function uses two parameters to create a string. That string incorporates the generated numbers into a rgb color code in the proper svg format. Here the values for the `vector<int>` are a pass by value since nothing was altered and only copied so that the code can be made with the given information. `vector<string>&`  on the otherhand modifies the value with the string that resulted in the end of the function.

* `void setFileSvg(string userFileName);` This function uses one parameter to modify the value of class private `string newFileSvg`. Here the values for the `string userFileName` are a pass by value since the actual value was not modied.

* `string getFileSvg();` This function uses the data member `string userFileName` to search and for an instance of ".svg". If no instance is loacted within the string it is added and then reassigned to the class private. 

### Classes

* `class palette` It contains one data member: `string newFileName`; and two function members: `void setFileSvg(string userFileName)` and `string getFileSvg();`. The date member is unable to be accessed from outside the class and is only reused by the functions located within class. There is a single instance of the class in the main program where it is used to open and create a usable svg file.
