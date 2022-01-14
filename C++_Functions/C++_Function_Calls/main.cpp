#include <iostream>
using namespace std; 


    // use void when you do not need to return a value
    // else
    // declare a type such as: int, double, ect..


void func2(int &x, int y, int z){
        // (result)30 = 30 + 10 + 20
        x += y + z; 
}

double func1(int a = 0, int b = 0){
    // defining the result within the function 
    int result {};

    result = a + b;     // 10 + 20 = 30 

    // local function call to func2
    // pass three arugments - result(30), a(10), b(20)
        func2(result, a, b);    // 30 + 10 + 20 = 60  
    return result; 
}


int plusFunc(int x, int y) {
  return x + y;
}

double plusFunc(double x, double y) {
  return x + y;
}

int main() {
    
        int x {10}, y {20}, z {};
        z = func1(x, y);
        cout << "Here is the data: " << endl;
        cout << z << endl; 

// #################################################### //

        int myNum1 = plusFunc(8, 5);  // assign different variable 
        double myNum2 = plusFunc(4.3, 6.26);

        cout << "Int: " << myNum1 << "\n";
        cout << "Double: " << myNum2;

    return 0; 
}