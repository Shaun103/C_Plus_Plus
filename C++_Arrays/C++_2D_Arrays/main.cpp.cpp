#include <iostream>
using namespace std;

    // Two dimentional array

    // Highest and lowest temperatures for each month of the year 

    // High temperatures - 38, 40, 45, 52, 65, 80, 75, 90, 85, 82, 70, 44
    // low temperatures - -10, 5, 2, 25, 30, 40, 45, 60, 0, 46, 15, 5

void getData(int twoDim[][2], int rows);
int averageHigh(int twoDim[][2], int rows); 
int averageLow(int twoDim[][2], int rows); 
int indexHighTemp(int twoDim[][2], int rows); 
int indexLowTemp(int twoDim[][2], int rows);
const int numMonths = 5;

int main() {
    
    int hiLowArray[numMonths][2]; 
    int indexHigh, indexLow; 

    // get temperature from users
    getData(hiLowArray, numMonths);
     
    // Calculate averages 
    cout << "Averag high temperatures " << averageHigh(hiLowArray, numMonths) << endl;
    cout << "Averag low temperatures " << averageLow(hiLowArray, numMonths) << endl;

    indexHigh = indexHighTemp(hiLowArray, numMonths);
    cout << "Highest temperature: " << hiLowArray[indexHigh][0] << endl;
    
    indexLow = indexLowTemp(hiLowArray, numMonths);
    cout << "Lowest temperature: " << hiLowArray[indexLow][1] << endl;

  return 0;
}

void getData(int twoDim[][2], int rows){
    cout << "Enter high temperatures for each month" << endl; 
    for (int i = 0; i < rows; i++)
        cin >> twoDim[i][0];    // Column 1
    
    cout << "Enter low temperatures for each month" << endl; 
        for (int i = 0; i < rows; i++)
        cin >> twoDim[i][1];    // Column 2
}

int averageHigh(int twoDim[][2], int rows){
    int sum = 0; 

    for (int i = 0; i < rows; i++)
        sum = sum + twoDim[i][0]; 
    
    if (rows > 0 )
        return sum / rows;
    else 
        return 0; 
}

int averageLow(int twoDim[][2], int rows){
    int sum = 0; 

    for (int i = 0; i < rows; i++)
        sum = sum + twoDim[i][1]; 
    
    if (rows > 0 )
        return sum / rows;
    else 
        return 0; 
} 

int indexHighTemp(int twoDim[][2], int rows){
    int highIndex = 0; 

    for (int i = 1; i < rows; i++)
        if (twoDim[highIndex][0] < twoDim[i][0])
            highIndex = i; 
    
    return highIndex; 
}

int indexLowTemp(int twoDim[][2], int rows){
        int lowIndex = 0; 

    for (int i = 1; i < rows; i++)
        if (twoDim[lowIndex][0] < twoDim[i][1])
            lowIndex = i; 
    
    return lowIndex; 
}