#include <iostream>

using namespace std;

/*
    When we allocate arrays dynamically on the heap, 
    we need to have a way of use (walk, display) them 
*/


int main() {
    
    int scores[] {100, 95, 89};
    
    cout << "Value of scores: " << scores << endl;                              // memory location
    
    int *score_ptr {scores};
    cout << "Value of score_ptr: " << score_ptr << endl;                        // memory location
    
    cout << "\nArray subscript notation -------------------------" << endl;     
    cout << scores[0] << endl;                                                  // displays first position
    cout << scores[1] << endl;
    cout << scores[2] << endl;
    
    cout << "\nPointer subscript notation -------------------------" << endl;
    cout << score_ptr[0] << endl;                                               // displays first position
    cout << score_ptr[1] << endl;
    cout << score_ptr[2] << endl;
    
    cout << "\nPointer offset notation-------------------------" << endl;       // using the pointer 
    cout << *score_ptr << endl;                                                 // displays first position
    cout << *(score_ptr + 1) << endl;
    cout << *(score_ptr + 2) << endl;
    
    cout << "\nArray offset notation-------------------------" << endl;         // using what is being pointed to
    cout << *scores << endl;                                                    // displays first position
    cout << *(scores + 1) << endl;
    cout << *(scores + 2) << endl;
    
    cout << endl;
    
    return 0;
}

