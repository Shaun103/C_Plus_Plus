#include <iostream>
using namespace std; 

class Calculate {
    private:
        //     void func2(int &x, int y, int z){
        // // (result)30 = 30 + 10 + 20
        // x += y + z; 
        // }
    
    public: 
        int plusFunc(int x, int y) {
        return x + y;
        }

        double plusFunc(double x, double y) {
        return x + y;
        } 


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
};

int main() {

Calculate myObj;

        int x {10}, y {20}, z {};
        z = myObj.func1(x, y);
        cout << "Here is the data: " << endl;
        cout << z << endl; 

// #################################################### //

        int myNum1 = myObj.plusFunc(8, 5);  
        double myNum2 = myObj.plusFunc(4.3, 6.26);

        cout << "Int: " << myNum1 << "\n";
        cout << "Double: " << myNum2;

    return 0; 
}