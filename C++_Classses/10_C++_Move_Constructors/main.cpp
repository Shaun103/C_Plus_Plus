#include <iostream>
#include <vector>
using namespace std;

/*
    By default, if there exists a 
    copy and move constructor, the 
    program will choose the move constructor
*/



/*
        L-VALUES 
 - l-values are values that have names and
    are addressable 
- modifiable if they are not constants 
- y = 100           - L-VALUE = y 
- x  = x + y        - LVALUE = x, R-VALUE = (x + y) 

******************************************

        R-VALUE
- anything that is not an L-VALUE is an R-VALUE
- R-VALUES can be assigned to L-VALUES explicitly 

Examples:
- name = "Frank"
- int y = x + 200
- int x = {100}

*/

class Move {
private:
    int *data;
public:
    void set_data_value(int d) { 
        *data = d;
    }
    
    int get_data_value() {
        return *data;
    }
    // PROTOTYPES

    // Constructor
    Move(int d);
    // Copy Constructor
    Move(const Move &source);
    // Move Constructor
    Move(Move &&source) noexcept; //  // UNCOMMENT PROTOTYPE
    // Destructor
    ~Move();
    
};

// Deep copy
Move::Move(int d) {
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

// Copy constructor - inefficient version
Move::Move(const Move &source)      
    : Move {*source.data} {
        cout << "Copy constructor - deep copy for: " << *data << endl; 
}

/***************************************************/
// UNCOMMENT BELOW - UNCOMMENT PROTOTYPE
// Move constructor - &&
// No copy constructor being called
// Is called because it is an R value temporary
/***************************************************/

Move::Move(Move &&source) noexcept: data(source.data) {
    source.data = nullptr;
    cout << "Move constructor - moving resource: " << *data << endl; // dereference
}

// Move destructor
Move::~Move() {

    if (data != nullptr) {
        cout << "Destructor freeing data for: " << *data << endl;
    } else {
        cout << "Destructor freeing data for nullptr" << endl; 
    }

    delete data; 
}

int main () {
    
    // makes copies behind the scenes, the vector is continuing to grow
    vector<Move> vec;           

    // Creates a temporary value
    // Move{10} - 10 = 'R' value
    vec.push_back(Move{10});
    // vec.push_back(Move{20});
    // vec.push_back(Move{30});
    // vec.push_back(Move{40}); 
    // vec.push_back(Move{50});
    // vec.push_back(Move{60});
    // vec.push_back(Move{70});
    // vec.push_back(Move{80});
    // vec.push_back(Move{90});
    // vec.push_back(Move{100});
        
    return 0; 
} 