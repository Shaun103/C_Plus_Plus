#include <iostream>
#include <cmath>
#include <tuple>
// #include "gsl\gsl.h" //- pointer 
using namespace std;

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



int main() {

    // COMMENT OUT FULL CODE, EITHER STRUCT OR TUPLE BEFORE RUNNING PROGRAM

    //////////////////////
    //// STRUCT 

    int number1, number2, number3, number4;

    twoNumbers result = fooStruct(100);

     // answers
    number1 = result.value1;
    number2 = result.value2;
    number3 = result.value3; 
    number4 = result.value4;

    cout << number1 << "\n" << number2 << "\n" << number3 << "\n" << number4 << endl;

    ////////////////////
    // TUPLE
    // tie() - ties number1, number2, number3 to each other and turns them into a tuple 

    // int number1, number2, number3; 

    tie(number1, number2, number3) = fooTwo(12);

    cout << "Number1: " << number1 << " " << "Number2: " << number2 << " " << "Number3: " << number3 << endl; 

    ///////////////////////////////////////////////////////
    //// Tuple - cpp 17 (QUESTION, cant get this to work)
    // auto[answer, number] = fooTwo(9); 
    // cout << answer << " " << number << endl;
    //
    ///////////////////////////////////////////////////////
    // Tuple - END 

    return 0;
}