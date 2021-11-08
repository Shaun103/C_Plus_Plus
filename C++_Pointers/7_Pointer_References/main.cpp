// Section 12
// References
// Please see the section 11 examples for references as function paramters
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    
    int num {100};
    int &ref {num};             // reference to a pointer

    int *ref2 {nullptr};        // pointer to a reference
    ref2 = &ref;

    cout << num << endl;        
    cout << ref << endl;

    cout << "\n---------------------------------" << endl;
    cout << &ref << endl;       // memory location
    cout << ref2 << endl;       // memory location

    cout << ref2[0] << endl;    // subscrit notation
    cout << *(ref2) << endl;    // offset notation
    
    num  = 200;
    cout << "\n---------------------------------" << endl;
    cout << num << endl;
    cout << ref << endl;
    
    ref = 300;
    cout << "\n---------------------------------" << endl;
    cout << num << endl;
    cout << ref << endl;
    
    cout << "\n---------------------------------" << endl;


    // vector<string> stooges {"Larry", "Moe", "Curly"};


    // for (auto str: stooges)     
    //     str = "Funny";                      // str is a COPY of the each vector element - no changes
      
    // for (auto str:stooges)                  // No change
    //     cout << str << endl;
 

    // cout << "\n---------------------------------" << endl;


    // for (auto &str: stooges)                // str is a reference to each vector element
    //     str = "Funny";
     
    // for (auto const &str:stooges)           // notice we are using const
    //     cout << str << endl;                // now the vector elements have changed
    
    // cout << endl;
    return 0;
}

