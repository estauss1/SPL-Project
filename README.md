# Structure of Programming Languages Project
The purpose of this project is to highlight some differences between
C++ and JavaScript

The main differences I focused on were:
- C++ is statically typed while JavaScript is dynamically typed
- Memory management in C++ is done explicitly by the programmer 
    and JavaScript uses automatic garbage collection
- Javascript is an intepretted language while C++ is a compiled
    language which results in different execution speeds

The main purpose of the programs is to compare the execution speeds 
of JavaScript as an intepretted language vs a compiled language like 
C++. To compare this, the javascript and c++ programs measure how 
long it takes to calculate the product of two large matrices.

## How to run
Firstly, get all the files onto a local directory.

The c++ program is straightforward to run. Just compile the matrix-mult.cpp
file using your favorite compiler(I used g++) and then run the executable.

For the javascript program, I opened the files in vscode and used the 
live server extension. In the bottom right it says "go live" which hosts 
a local server. Then hit the start test button element to get the time it 
takes to calculate the product matrix.

If you want to test different sized matrices, there is also an optional
matrix-generator.cpp file which you can change the values of the global 
constant values, compile and then execute which will delete the contents
of matrix-input.txt and write the new size matrices to the file.

warning: You need to change the values of the global constants in matrix-mult.js
and matrix-mult.cpp to match the values used in matrix-generator.cpp. Also, the
number of columns for matrix one must match the number of rows of matrix two.