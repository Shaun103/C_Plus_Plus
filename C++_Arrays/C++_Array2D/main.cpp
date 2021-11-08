#include <iostream>
using namespace std;

void displayArrayInfo(int arry[][2], int row, int column){
    cout << "The element at location [1][1] is: " << arry[1][1] << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++)
        cout << arry[i][j] << endl; 
    }
} 

int main(){
 
    int row = 3, column = 2;
    int arr[3][2];
    
    arr[0][0] = 0;
    arr[0][1] = 1;
    arr[1][0] = 2;
    arr[1][1] = 3;

    displayArrayInfo(arr, row, column);

    return 0;
}