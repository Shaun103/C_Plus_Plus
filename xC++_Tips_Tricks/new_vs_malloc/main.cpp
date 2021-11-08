#include <iostream>
#include <new>
// https://www.youtube.com/watch?v=p-sprvJX07E

void *operator new(std::size_t sz){

    // avoid std::malloc(0) which
    // may return nullptr on success
    if (sz == 0)
        ++sz;
    
    if (void *ptr = std::malloc(sz))
        return ptr;
    
    throw std::bad_alloc{};
    // return nullptr;
    // normally, throw std::bad_alloc{};
}

void operator delete(void *ptr) noexcept{
    std::free(ptr);
}

int main(){ 

    int *p1 = new int;
    if (nullptr == p1)
        std::cout << "Whoops!";
    else 
        delete p1;
    
    // ______________________________________

    try {
        while (true){

            // Throwing version of new
            new int[100000000ul];
        }
    } catch (const std::bad_alloc &e){
        std::cout << e.what() << '\n';
    }

    ///// vs /////

    while (true){

        // Non-throwing version of new
        int *p = new(std::nothrow) int[100000000ul];
        if (p == nullptr) {
            std::cout << "Allocation returned nullptr\n";
            break;
        }
    }

    // ______________________________________

    unsigned char buf[sizeof(int)*3] ;

    //Placement new in buffer
    int *pInt = new (buf) int(3);

    pInt[0] = 0;
    pInt[1] = 1;
    pInt[2] = 2;

    return 0;
}  