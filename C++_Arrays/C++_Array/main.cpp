#include <iostream>
#include <iomanip>
using namespace std;

template <typename T, typename T1>
void displayArry(T arr[], T1 x){
    cout << "The elements in the array are: " << endl;
    for (int i = 0; i < x; i++){
        cout << arr[i] << endl; 
    }    
}

double getAverage(int arr[], int size){
    int i, sum = 0; 
    double average; 

    for (i = 0; i < size; i++){
        sum+= arr[i]; 
    }

    average = double(sum) / size;

    return average; 
}

int main(){

    int size = 5;
    int balance[size] = {5, 3, 2, 20, 9};
   
    cout << "The average is: " << getAverage(balance, size) << endl; 
    displayArry(balance, 5); 

    return 0;
}





