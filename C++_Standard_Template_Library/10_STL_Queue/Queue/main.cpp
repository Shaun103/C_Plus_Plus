// Section 20
// Queue
// first in, first out
// scheduling, job, task, operating systems
// calculate expressions, balancing 

#include <iostream>
#include <queue>

// This function displays a queue of 
// by repeatedly removing elements from the front
// Note theat the queue is passed in by value so we
// don't affect the passed in queue.

template <typename T>
void display(std::queue<T> q) {
    std::cout << "[ ";
    while (!q.empty()) {
        T elem = q.front();
        q.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {

    std::queue <int> q;       // default deque 

    for (int i: {1,2,3,4,5})
        q.push(i);
    display(q);

    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;

    display(q);
    std::cout << "Size: " << q.size() << std::endl;
    std::cout << "\n------------------------------------------------------------" << std::endl; 


    q.push(100);
    display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;
    std::cout << "Size: " << q.size() << std::endl;
    std::cout << "\n------------------------------------------------------------" << std::endl; 


    q.pop();
    q.pop();
    display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;
    std::cout << "Size: " << q.size() << std::endl;
    std::cout << "\n------------------------------------------------------------" << std::endl; 

    while (!q.empty())
        q.pop();
    display(q);

    std::cout << "Size: " << q.size() << std::endl;
    std::cout << "\n------------------------------------------------------------" << std::endl; 

    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;
    std::cout << "Size: " << q.size() << std::endl;
    std::cout << "\n------------------------------------------------------------" << std::endl; 

    q.front() = 5;
    q.back() = 5000;
    display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl; 

    return 0;
}