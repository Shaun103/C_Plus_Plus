// Section 12
// Passing Pointers 3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// When displaying use const
// You cannot manipulate what you are displaying


void display(const vector<string>  *const v) {
    // (*v).at(0) = "Funny";  // changes the first instance in vector
    for (auto str: *v)
        cout << str << " ";
    cout << endl;
  
//    v = nullptr; // null out the v-vector
}

void display(int *array, int sentinel) {
    while (*array != sentinel)
        cout << *array++ << " ";
    cout << endl;
}

int main() {

   cout << "-----------------------------" << endl;
   vector<string> stooges {"Larry", "Moe", "Curly"};
   display(&stooges);
   
    cout << "\n-----------------------------" << endl;
    int scores[] {100,98,97,79,85,-1};
    display(scores, scores[5]);
    

    return 0;
}

