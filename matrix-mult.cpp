#include <iostream>
#include <fstream>

using std::cout; using std::endl;

// change values according to matrices in input file
// columns_one must equal rows_two
const int NUMBER_OF_ROWS_ONE = 5;
const int NUMBER_OF_COLUMNS_ONE = 5;
const int NUMBER_OF_ROWS_TWO = 5;
const int NUMBER_OF_COLUMNS_TWO = 5;

int main(){
    std::ifstream matrixInput("matrix-input.txt");
    if(!matrixInput.is_open()){
        cout << "Error opening input file\n";
        return 1;
    }
    // create and fill matrix one
    // memory allocation done by programmer unlike javascript*
    int** matrixOne = new int*[NUMBER_OF_ROWS_ONE];
    for(int i = 0; i < NUMBER_OF_ROWS_ONE; ++i){
        matrixOne[i] = new int[NUMBER_OF_COLUMNS_ONE];
    }
    int num;
    for(int i = 0; i < NUMBER_OF_ROWS_ONE; ++i){
        for(int j = 0; j < NUMBER_OF_COLUMNS_ONE && matrixInput >> num; ++j){
            matrixOne[i][j] = num;
        }
    }
    // create matrix two
    int** matrixTwo = new int*[NUMBER_OF_ROWS_TWO];
    for(int i = 0; i < NUMBER_OF_ROWS_TWO; ++i){
        matrixTwo[i] = new int[NUMBER_OF_COLUMNS_TWO];
    }
    for(int i = 0; i < NUMBER_OF_ROWS_TWO; ++i){
        for(int j = 0; j < NUMBER_OF_COLUMNS_TWO && matrixInput >> num; ++j){
            matrixTwo[i][j] = num;
        }
    }
    // create matrix that gets product of one and two
    int** matrixProduct = new int*[NUMBER_OF_ROWS_ONE];
    for(int i = 0; i < NUMBER_OF_ROWS_ONE; ++i){
        matrixProduct[i] = new int[NUMBER_OF_COLUMNS_TWO];
    }
    // calculate product matrix
    
    int productElement = 0;
    for(int oneRow = 0; oneRow < NUMBER_OF_COLUMNS_ONE; ++oneRow){
        for(int twoColumn = 0; twoColumn < NUMBER_OF_COLUMNS_TWO; ++twoColumn){
            for(int oneColumn = 0, twoRow = 0; oneColumn < NUMBER_OF_COLUMNS_ONE
                && twoRow < NUMBER_OF_COLUMNS_TWO; ++oneColumn, ++twoRow){
                productElement += (matrixOne[oneRow][oneColumn] 
                    * matrixTwo[twoRow][twoColumn]);
            }
            matrixProduct[oneRow][twoColumn] = productElement;
            productElement = 0; 
        }
    }

    // output for debug purposes
    cout << "Matrix one:\n";
    for(int i = 0; i < NUMBER_OF_ROWS_ONE; ++i){
        for(int j = 0; j < NUMBER_OF_COLUMNS_ONE; ++j){
            cout << matrixOne[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "Matrix two:\n";
    for(int i = 0; i < NUMBER_OF_ROWS_TWO; ++i){
        for(int j = 0; j < NUMBER_OF_COLUMNS_TWO; ++j){
            cout << matrixTwo[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "Product matrix:\n";
    for(int i = 0; i < NUMBER_OF_ROWS_ONE; ++i){
        for(int j = 0; j < NUMBER_OF_COLUMNS_TWO; ++j){
            cout << matrixProduct[i][j] << "     ";
        }
        cout << endl;
    }

    
    
    matrixInput.close();
}