# SVG Palette Generator

## Description

The program will prompt the user for a number of colors needed for their palette and a name for the file that values will be stored in.

Depending on the the amount that was chosen a set of colors values will be added into the the contents of the file as well.

### v0.2 Updates

*Coming soon*

### v1.0 Updates

*Coming soon*


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
4
Enter a name for the palette file: 
testing
"testing.txt" was created successfully.
```

## C++ Guide

### Variables and Data Types

* `int numOfColors;` *stores the number the user enters*
* `size_t position;` 
* `string fileN;` *stores the name of the file given by the user*
* `string paletteFile;` *stores the complete file name*
* `ofstream dataFile;` *used to create files and write information*

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
was not an instance of ".txt". If there was not then it would be added by the program and assign fileN to paletteFile. 
`else` it would simply assign fileN to paletteFile, because it found an instance of ".txt" within the string.

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

*Coming in version 0.2*

### Functions

*Coming in version 0.2*

### Classes

*Coming in version 1.0*
