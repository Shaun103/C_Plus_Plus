#include <iostream>
#include <iomanip>
using namespace std; 


//////////////////
// function prototype 
void print_array(int arr[], size_t size);
void set_array(int arr[], size_t, int value);

//////////////////
// function definition print_array
void print_array(int arr[], size_t size){
        for (size_t i{0}; i < size; ++i)
                    cout << arr[i] << " ";
                cout << endl;
}

//////////////////
// function definition set_array
void set_array(int arr[], size_t size, int value){
            for (size_t i{0}; i < size; ++i)
                arr[i] = value; 
}

int main() {
    // initializing array 
    int my_scores[] {100, 98, 90, 86, 84}; 

        // function call to print initialized array
        // arr, size 
        print_array(my_scores, 5);  

        // function call to set
        // arr, size, value 
        set_array(my_scores, 5, 100); 

        // function call print array 
        // arr, size
        print_array(my_scores, 5);

    return 0; 
}