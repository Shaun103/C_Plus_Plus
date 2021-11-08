#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_ROWS = 6;
const int NUM_COL = 5;

const int numRows = 13; 
const int numCols = 6;

// Print the array elements CHAR
void printMatrix(char matrix[][numCols], int rows){
    for (int i = 0; i < rows; i++){
        for (int ii = 0; ii < numCols; ii++)
            cout << setw(5) << matrix[i][ii] << " "; 
        cout << endl; 
    }
}

// Print the array elements INT
void printMatrix(int matrix[][NUM_COL], int rows){
    for (int i = 0; i < rows; i++){
        for (int ii = 0; ii < NUM_COL; ii++)
            cout << setw(5) << matrix[i][ii] << " "; 
        cout << endl; 
    }
}

void sumRows(int matrix[][NUM_COL], int NUM_ROWS){
    int sum; 
    for (int i = 0; i < NUM_ROWS; i++){
        sum = 0;
        for (int ii = 0; ii < NUM_COL; ii++){
            sum = sum + matrix[i][ii];
            cout << "The sum of row " << (sum + 1) << " is: " << sum << endl;
        }
    }
}

void largestInRows(int matrix[][NUM_COL], int NUM_ROWS){
    int largest; 
    for (int i = 0; i < NUM_ROWS; i++){
        largest = matrix[i][0];
        for (int ii = 0; ii < NUM_COL; ii++)
        if (matrix[i][ii] > largest)
            largest = matrix[i][ii];
    cout << "The largest element of row " 
    << i + 1 << " is: " << largest << endl; 
    }
}

void initializeSeats(char matrix[][numCols], int numRows){
    for (int i = 0; i < numRows; i++)
        for (int ii = 0; ii < numCols; ii++){
            matrix[i][ii] = '*'; 
        }
}

int main(){

    // // 2d Arrays     
        
    int board[NUM_ROWS][NUM_COL]
     = {{17, 8, 24, 10, 28},
    {9, 20, 16, 55, 90},
    {25, 45, 35, 8, 78},
    {5, 0, 96, 45, 38},
    {76, 30, 8, 14, 28},
    {9, 60, 55, 62, 10}};

    // Print the array 
    printMatrix(board, NUM_ROWS);

    // Summation of the rows 
    sumRows(board, NUM_ROWS);
    
    // Largest number in row
    largestInRows(board, NUM_ROWS); 

    // _______________________________________
    // Project tips 

    char seats[numRows][numCols];

    initializeSeats(seats, numRows);  
    
    printMatrix(seats, numRows); 

    return 0;
}
