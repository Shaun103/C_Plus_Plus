#include <iostream>
#include <algorithm>

int largest(int arry[], int size){

    int max = arry[0];  // what we are looking for

    for (int i = 0; i < size; i++) // looping through array 
        if (arry[i] > max)
            max = arry[i];
    return max;
}

int largest1(int arry[], int size){
    return *std::max_element(arry, arry+size);
}


int main(){ 

    int arry[] = {1, 5, 2, 6, 100, 8, 9, 3, 7, 3};
    int arr[] = {10, 324, 45, 90, 98}; 
    int myints[] = {3,7,2,5,6,4,9};
    int size = sizeof(arry) / sizeof(arry[0]);
    
    std::cout << "Largest number_1: " << largest(arry, size) << std::endl;
    std::cout << "Largest number_2: " << largest(arr, size) << std::endl;

    std::cout << "Largest number_1: " << largest1(arry, size) << std::endl;
    std::cout << "Largest number_2: " << largest1(arr, size) << std::endl;

    std::cout << "Largest number_1: " << largest1(myints, size) << std::endl;
    std::cout << "Largest number_2: " << largest1(myints, size) << std::endl;

    return 0;
}  