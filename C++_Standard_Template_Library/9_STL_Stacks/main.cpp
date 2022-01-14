// Section 20
// Stack

// Stacks - everything happens at the top - like stacking plates, 
// the newest is on top, oldest on bottom 
// last one in, first one out 

#include <iostream>
#include <stack>
#include <vector>
#include <list>


// This function displays a stack of 
// by repeatedly topping and popping the stack
// Note that the stack is passed in by value so we
// don't affect the passed in stack.

template <typename T>
void display(std::stack <T> s){
    std::cout << "[";
    while (!s.empty()){
        T elem = s.top();
        s.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}   


int main() {

    // stacks can be vectors, lists, or a deque
    std::stack<int> s;                          // default to deque
    std::stack <int, std::vector<int>> s1;      // vector
    std::stack <int, std::list<int>> s2;        // lists
    std::stack <int, std::deque<int>> s3;       // deque


    for (int i: {1,2,3,4,5})    // filling a stack
        s.push(i);

    display(s);

    s.push(100);    // placing 100 ontop of stack
    display(s);


    s.pop();        // removing top element
    s.pop();

    display(s);

    std::cout << "Size: " << s.size() << std::endl;

    while (!s.empty())      // how to clear a stack
        s.pop();
    display(s);

    std::cout << "Size: " << s.size() << std::endl;

    s.push(10);
    display(s);

    std::cout << "Size: " << s.size() << std::endl;

    
    display(s);
    s.top() = 100;  // manualing placing on top of stack 
    
    
    return 0;
}