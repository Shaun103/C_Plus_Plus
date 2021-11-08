// C++ implementation to concatenate
// two matrices of size N x M
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define M 2
#define N 2
 
// Function to concatenate two
// matrices A[][] and B[][]
void mergeMatrix(int A[M][N], int B[M][N]) {

    // Matrix to store
    // the result
    int C[M][2 * N];
   
    // Merge the two matrices
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
 
            // To store elements
            // of matrix A
            C[i][j] = A[i][j];
 
            // To store elements
            // of matrix B
            C[i][j + N] = B[i][j];
        }
    }
 
    // Print the result
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 2 * N;j++)
            cout << C[i][j] << " ";
        cout << endl; 
    }
}


void printMatrix(int matrix[][2]){
    for (int i = 0; i < 2; i++)
        for (int ii = 0; ii < 2; ii++)
            cout << matrix[i][ii] << endl; 
}

 
// Driven Code
int main()
{
    int A[M][N] = {{ 1, 2 },
                    { 3, 4 }};
 
    int B[M][N] = {{ 5, 6 },
                    { 7, 8 }};
 
    // Find the merge of
    // the 2 matrices
    cout << "Matrix A: " << endl;
    printMatrix(A);
    cout << "Matrix B: " << endl; 
    printMatrix(B);
    cout << "Merged matrix: " << endl;
    mergeMatrix(A, B);
 
    return 0;
}