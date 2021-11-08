#include <iostream>
#include <iomanip>
using namespace std;

class ptrMemberVarType{
    private:
        int maxSize;    // variable to store max size p 
        int length;     // vairable to store the number of elements in p 
        double *p;      // dynamically allocated array 

    public:
        // output the data stored in the array p
        void print() const;

        // inserting into dynamic arry
        void insertAt(int index, double i);

        // constructor 
        ptrMemberVarType(double size = 50);

        // Destructor: dealocated the memory space occupied by the array p
        ~ptrMemberVarType(); 
};

// Constructor 
ptrMemberVarType::ptrMemberVarType(double size){
    if (size <= 0){
        cout << "The array size must be postive" << endl; 
        cout << "Creating an array of the size 50" << endl;
        maxSize = size;  
    } else
        maxSize = size;

    length = 0;
    p = new double[maxSize];
}

// Destructor 
ptrMemberVarType::~ptrMemberVarType(){
    // cout << "Destructor call!" << endl; 
    delete [] p;
}

void ptrMemberVarType::insertAt(int index, double i){
    if (i < 25){
        p[index] = i*i;
    } else{
        p[length] = i*3;    
    }
    length++;
}

// Function calls _________________________________
void ptrMemberVarType::print() const{
    int counter = 0;
    for (int j = 1; j <= 5; j++) {
        for (int i = 1; i <= 10; i++) {
            if (counter < 50)
                cout << setw(5) << p[counter];
            else
                break;
            counter++;
    }
        cout << endl;
    }
}

int main(){

    ptrMemberVarType listOne;

    for (double i = 0; i <= 50; i++)
        listOne.insertAt(i, i);

    listOne.print();
    cout << endl;

    return 0; 
} 