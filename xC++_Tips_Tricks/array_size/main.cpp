// size of an array but in elements and not in bytes
// https://www.youtube.com/watch?v=p-sprvJX07E

#include <iostream>

#define ARRAYSIZEM(b) (sizeof(b)/sizeof(b)[0])

// OR for the nerds in the front row

template<typename T, size_t N>
    size_t ARRAYSIZET(T (&a)[N]){
        return N;
}

int main(int argc, char * argv[])
{ 
    int a[]={1,2,3,4,5,6};

    std::cout << ARRAYSIZEM(a) << std::endl;
    std::cout << ARRAYSIZET(a) << std::endl;
}  