// Name: Willem Battey
// Student ID: 3046356
// Date Due: Oct 22, 2022
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static const int MAX_SIZE = 100;

bool readMatrix(int matrix[][100], ifstream& fin, int size)
{
    for (int i=0; i< size; i++){ // Loop through matrix size
        for (int j=0; j< size; j++){
            if (!(fin >> matrix[i][j])) { return false;} // If not able to read from file, return false
        }
    }
    return true;
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << '\t'; // Loops through size of matrix printing and formating each element
        }
        cout << '\n';
    }
}

void matrix_addition(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int size)
{
    int c[MAX_SIZE][MAX_SIZE]; // initalize new matrix to hold addition
    for (int i = 0; i < size; i++) { // Loop through matrix size
        for (int j = 0; j < size; j++) {
            c[i][j] = a[i][j] + b[i][j]; // Add together the values of a and b then place them in the corresponding spot of c
        }
    }
    printMatrix(c, size);
}

void muliply_matrix(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int size)
{
    int product;
    int c[MAX_SIZE][MAX_SIZE]; // initalize new matrix to hold addition
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c[i][j] = 0;
            for (int k = 0; k < size; k++) { // Uses third loop to help jump between the rows and columns for dot product
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printMatrix(c, size);
}

void matrix_difference (int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int size)
{
    int c[MAX_SIZE][MAX_SIZE]; // initalize new matrix to hold addition
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c[i][j] = a[i][j] - b[i][j]; // Subtract the values of a and b then place them in the corresponding spot of c
        }
    }
    printMatrix(c, size);
}

int main()
{

    // Initlalize the variables data to hold the matrix information
    int matrix_size;
    string dummy;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    ifstream fin("matrix_input.txt");

    fin >> matrix_size;
    getline(fin, dummy); // Use this to get rid of the extra text that accompanies the size

    // Error catching, incase the size given in the file is larger than the given max size of 100
    if (matrix_size > MAX_SIZE) {
        cout << "Matrix size is too large" << '\n';
        cout << "Will not read rest of file" << '\n';
        return 0;
    }

    bool A = readMatrix(matrixA, fin, matrix_size);
    bool B = readMatrix(matrixB, fin, matrix_size);
    // Error catching checking if either of the read functions return false indicating an error while reading in the matrices
    if (!A || !B) {
        cout << "Error reading file" << '\n';
        return 0;
    }
    fin.close();

    cout << "Willm Battey, Lab 6: Matrix Manipulation" << '\n';
    cout << '\n';

    // Printing out all the functions for the matrix manipulation
    cout << "Matrix A" << '\n';
    printMatrix(matrixA, matrix_size);
    cout <<'\n';
    cout << "Matrix B" << '\n';
    printMatrix(matrixB, matrix_size);
    cout << '\n';
    // Matrix addition
    cout << "Matrix addition A + B" << '\n';
    matrix_addition(matrixA, matrixB, matrix_size);

    cout << '\n';

    //matrix multiplication
    cout << "Matrix multiplication A * B" << '\n';
    muliply_matrix(matrixA, matrixB, matrix_size);
    cout << '\n';  
    // matrix difference
    cout << "Matrix Difference A - B" << '\n';
    matrix_difference(matrixA, matrixB, matrix_size);

    return 0;
}
