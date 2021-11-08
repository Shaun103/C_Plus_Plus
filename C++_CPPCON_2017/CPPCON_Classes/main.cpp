#include <iostream>
#include <cmath>
#include <tuple>
// #include "gsl\gsl.h" //- pointer 
using namespace std;


////////////////////////////
// Class
class Simple { 
    private:
        int a = -1;
        int b = -1;
        int c = -1;
        int d = -1; 
    public:
        Simple() = default; // "default" instead of {} - no user defined constructors (world)
        Simple(double x1, double x2, double y1, double y2) : a(x1), b(y1), c(x2), d(y2) {
            double answer {};
            cout << "\n" << endl;  
            cout << "Distance Formula: " << endl;

            answer = sqrt((pow(a - b, 2)) + (pow(c - d, 2)));
            cout << answer << endl;
            cout << "\n" << endl; 
        }
        
        Simple(int aa) : a(aa) {
            cout << "Second CHECK: " << endl; 
            cout << a << endl;
        }
        void distanceForm(int x1, int x2, int y1, int y2) {
            double d {};
            cout << "Distance Formula CHECK: " << endl;
            d = sqrt((pow(x1 - y1, 2)) + (pow(x2 - y2, 2)));
            cout << d << endl; 
        }
};

// Class - END 


int main() {
    Simple myObj; // defining Simple
    
    Simple(1,2,3,4);
    Simple(100);
    myObj.distanceForm(1, 2, 3, 4); 
    cout << "\n" << endl; 


    int area(Point p1, Point p2); 
    int a = area({1, 1}, {11, 21});
    cout << a << endl; 


return 0;
}