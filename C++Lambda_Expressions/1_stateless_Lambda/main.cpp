#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>  // for std::function

class Person{
    friend std::ostream &operator << (std::ostream &os, const Person &rhs);
    private:
        std::string name;
        int age;
    public:
        Person (std::string name, int age): name{name}, age{age} {};
        Person (const Person &p): name{p.name}, age{p.age} {};
        ~Person() = default;
        std::string get_name() const {return name;};
        void set_name(std::string name){this -> name = name;};
        int get_age() const{return age;}
        void set_age(int age){this -> age = age;}
};

std::ostream &operator <<(std::ostream &os, const Person &rhs){
    os << "[Person: " << rhs.name << ":" << rhs.age << "]";
    return os; 
}

// 
void Test1(){
    std::cout << "\n---Test1 ---------------------------" << std::endl;

    [] () {std::cout << "Hi" << std::endl;}();

    [] (int x) {std::cout << x << std::endl;}(100);

    [] (int x, int y) {std::cout << x + y << std::endl;}(100, 200);
}

void Test2(){
    std::cout << "\n---Test2 ---------------------------" << std::endl;

    auto l1 = [] () {std::cout << "Hi" << std::endl;};
    l1();

    int num1 {100};
    int num2 {200};
    
    auto l2 = [](int x, int y) {std::cout << x + y << std::endl;};
    l2(10,20);
    l2(num1, num2);

    auto l3 = [](int &x, int y){
        std::cout << "x:" << x << " " << "y:" << y << std::endl;
        x = 10000; // reference change
        y = 2000;  // local copy change 
        std::cout << "x:" << x << " " << "y:" << y << std::endl;
    };

    l3(num1, num2); // 1000, 100
    std::cout << "num1: " << num1 << " " << "num2: " << num2 << std::endl;
}

void Test3(){
    std::cout << "\n---Test3 ---------------------------" << std::endl;
    Person stooge {"Larry", 18};
    std::cout << stooge << std::endl;

    // ________________________________________________
    // copy constructor, by value
    auto l4 = [] (Person p){
        std::cout << p << std::endl;
    };
    l4(stooge);
    // ________________________________________________
    
    
    // ________________________________________________
    // reference, 
    auto l5 = [] (const Person &p){
        std::cout << p << std::endl;
    };
    l5(stooge);
    // ________________________________________________


    // ________________________________________________
    auto l6 = [] (Person &p){
        p.set_name("Frank");
        p.set_age(25);
        std::cout << p << std::endl;
    };
    l6(stooge);
    // ________________________________________________
    
    std::cout << stooge << std::endl;
}


// predicate lambda - expects one or more 
// perameters and returns a bool  
void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func){
// void filter_vector (const std::vector<int> &vec, auto func) {    // c++14
    std::cout << "[";
    for (int i:vec){
        if(func(i))
            std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

// passing a lambda into a function
void Test4(){
    std::cout << "\n---Test2 ---------------------------" << std::endl;
    std::vector<int> nums {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    filter_vector(nums, [](int x) {return x>50;});

    filter_vector(nums, [](int x) {return x<=30;});

    filter_vector(nums, [](int x) {return x>=30 && x <= 60;});
}


auto make_lambda() {
    return [](){std::cout << "This lambda was made using the make_lambda function!";};
}

void Test5(){
    std::cout << "\n---Test5------------------------" << std::endl;

    auto l5 = make_lambda();
    l5();
}

// must overload the operator overload
void Test6(){
    std::cout << "\n---Test6------------------------" << std::endl;

    auto l6 = [](auto x, auto y) {
        std::cout << "x: " << x << " " << "y:" << y << std::endl;
    };
    
    l6(10, 20);
    l6(100.3, 200);
    l6(12.5, 15.54);

    l6(Person("Larry", 18), Person("Curly", 22));
}

void Test7(){
    std::cout << "\n---Test7------------------------" << std::endl;

    std::vector<Person> stooges{
        {"Larry", 18},
        {"Moe", 30},
        {"Curly", 25}
    };

    // alternate syntax: stooges.begin(), stooges.end()
    std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2){
        return p1.get_name() < p2.get_name();
    });

    std::for_each(begin(stooges), end(stooges), [](const Person &p){
        std::cout << p << std::endl;
    });

    std::cout << std::endl;

    // sort by age
    std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2){
        return p1.get_age() < p2.get_age();
    });

    std::for_each(begin(stooges), end(stooges), [](const Person &p){
        std::cout << p << std::endl;
    });
}



int main(){ 
    
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

return 0;
}  