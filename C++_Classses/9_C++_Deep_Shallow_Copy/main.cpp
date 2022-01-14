#include <iostream>
using namespace std;

class Deep {
    private:
        int *data;
    public:
        void set_data_value(int d) {*data = d;}
        int get_data_value() { return *data;}
        // Deep constructor
        Deep(int d);
        // Copy constructor
        Deep(const Deep &source);
        // Destructor
        ~Deep();
};

// Regular constructor 
Deep::Deep(int d) {
    data = new int;
    *data = d;
}

// Copy constructor - delegating to line 18 
Deep::Deep(const Deep &source)
    : Deep(*source.data) {
        cout << "Copy constructor - shallow copy" << endl; 
}

// Destructor - deletes the memory address
Deep::~Deep() {
    delete data; 
    cout << "Destructor freeing data" << endl; 
}

// Displays what the value(s) are
void display_deep(Deep s) {
    cout << "Data: " << s.get_data_value() << endl; 
}


// class Shallow {
//     private:
//         int *data;
//     public:
//         void set_data_value(int d) {*data = d}
//         int get_data_value() { return *data;}
        
//         Shallow constructor
//         Shallow(int d);
//         Copy constructor
//         Shallow(const Shallow &source);
//         Destructor
//         ~Shallow();
// };

// Shallow::Shallow(int d) {
//     data = new int;
//     *data = d;
// }

// Shallow::Shallow(const Shallow &source)
//     : data(source.data) {
//         cout << "Copy constructor - shallow copy" << endl; 
// }

// Shallow::~Shallow() {
//     delete data; 
//     cout << "Destructor freeing data" << endl; 
// }

// void display_shallow(Shallow s) {
//     cout << s.get_data_value() << endl; 
// }

int main () {

// Shallow obj1 {100}; 
// display_shallow(obj1); 

// Shallow obj2 {obj1}; 
// obj.set_data_value(1000); 


Deep obj1{6547280};
display_deep(obj1);

Deep obj2{obj1};
obj2.set_data_value(1000); 

    return 0; 
}; 