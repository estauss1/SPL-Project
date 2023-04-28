// Generates matrices with size of global constants and
// outputs them to file
// Eric Stauss
// 4/28/2023

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::string; using std::cout;

const int NUMBER_OF_ROWS_ONE = 250;
const int NUMBER_OF_COLUMNS_ONE = 250;
const int NUMBER_OF_ROWS_TWO = 250;
const int NUMBER_OF_COLUMNS_TWO = 250;
const string OUTPUT_FILE_NAME = "matrix-input.txt";

int main(){
    std::srand(std::time(nullptr));

    std::ofstream matrixTxt(OUTPUT_FILE_NAME, std::ofstream::trunc);
    if(!matrixTxt.is_open()){
        cout << "error opening file\n";
        return 1;
    }
    // output matrices to file
    for(int row = 0; row < NUMBER_OF_ROWS_ONE; ++row){
        for(int column = 0; column < NUMBER_OF_COLUMNS_ONE; ++column){
            matrixTxt << (std::rand() % 10) << " ";
        }
        matrixTxt << std::endl;
    }
    for(int row = 0; row < NUMBER_OF_ROWS_TWO; ++row){
        for(int column = 0; column < NUMBER_OF_COLUMNS_TWO; ++column){
            matrixTxt << (std::rand() % 10) << " ";
        }
        matrixTxt << std::endl;
    }

    cout << "Wrote " << NUMBER_OF_ROWS_ONE << 'x' << NUMBER_OF_COLUMNS_ONE
         << " matrix and " << NUMBER_OF_ROWS_TWO << 'x'
         << NUMBER_OF_COLUMNS_TWO << " matrix into \""
         << OUTPUT_FILE_NAME << "\"\n";
    
    matrixTxt.close();
}