#include <iostream>
#include <cmath>
#include <tuple>
// #include "gsl\gsl.h" //- pointer 
using namespace std;

// Class
//// Writing a class properly 
//// Alternative to writing overloading functions
// Struct
//// RETURNING MULTIPLE VALUES
// Tuple  
//// RETURNING MULTIPLE VALUES


////////////////////////////
// Class
class Simple{ 
    private:
        int a = -1;
        int b = -1;
        int c = -1;
        int d = -1; 
    public:
        Simple() = default; // "default" instead of {} - no user defined constructors (world)
        Simple(double x1, double x2, double y1, double y2) : a(x1), b(y1), c(x2), d(y2){
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
            double d{};
            cout << "Distance Formula CHECK: " << endl;
            d = sqrt((pow(x1 - y1, 2)) + (pow(x2 - y2, 2)));
            cout << d << endl; 
        }
};
// Class - END 

//////////////////////////
// QUESTION
// Stuff 
class Stuff { 
    private:
        int number1;
        double number2;
        int LongComplicatedCalculation() const;
    // mutable, exempt from const
    mutable int cachedValue; 
    mutable bool cachedValid; 

  public:
    Stuff(int n1, double n2) : number1(n1), number2(n2), cachedValue(0), cachedValid(false) {}
        bool Service1(int x);
        bool Service2(int y);
        int getValue() const; 
};

// Stuff - END
//////////////////////////

/////////////////////////
// Struct 
// RETURNING MULTIPLE VALUES 
// (to return multiple "out" values, 
// prefer returning a tuple or struct)
struct twoNumbers{     
    int value1;
    int value2;
    int value3; 
    int value4;
};

twoNumbers fooStruct(int inValue){
    return twoNumbers{ inValue * 2, inValue * 3, inValue * 4, inValue * 100 }; 
};

// Struct - END 

//////////////////////
// Tuple
// RETURNING MULTIPLE VALUES
tuple<int, int, int> fooTwo(int inValue) {
    return make_tuple(inValue * 2, inValue * 3, inValue * 4);
};
// Tuple - END


int main(){
    Simple myObj; // defining Simple
    
    Simple(1,2,3,4);
    Simple(100);
    myObj.distanceForm(1, 2, 3, 4); 
    cout << "\n" << endl; 


    // int area(Point p1, Point p2); 
    // int a = area({1, 1}, {11, 21});
    // cout << a << endl; 

    //////////////////////
    //// struct 
    // int number1, number2, number3, number4;

    // twoNumbers result = fooStruct(100);

    //  // answers
    // number1 = result.value1;
    // number2 = result.value2;
    // number3 = result.value3; 
    // number4 = result.value4;

    // cout << number1 << "\n" << number2 << "\n" << number3 << "\n" << number4 << endl;

    ////////////////////
    // Tuple
    // tie() - ties number1, number2, number3 to each other and turns them into a tuple 
    // int number1, number2, number3; 

    // tie(number1, number2, number3) = fooTwo(12);

    // cout << "Number1: " << number1 << " " << "Number2: " << number2 << " " << "Number3: " << number3 << endl; 

    ///////////////////////////////////////////////////////
    //// Tuple - cpp 17 (QUESTION, cant get this to work)
    // auto[answer, number] = fooTwo(9); 
    // cout << answer << " " << number << endl;
    //
    ///////////////////////////////////////////////////////
    // Tuple - END 

    //////////////////////
    // RUN TIME ERROR WHEN YOU SET YOUR POINTEER TO NULL
    // if you ptr is not supposed to be null, mark that it
        // is not supposed to be null 
    //// #include "gsl\gsl.h"

    // Service* GetPointer(Service* p)
    // {
    //     return p;
    // }

    // gsl::not_null<Service*> ps = &s;

    // ps = GetPointer(nullptr); 

    // // ......thousands of lines later

    // i = ps ->DoSomething(); - when you try to run your code 



    return 0;
}