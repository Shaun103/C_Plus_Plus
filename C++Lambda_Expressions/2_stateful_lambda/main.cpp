#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// lambda - [](){}
// [this] - ALWAYS USE THIS ONE
// [=] - by value, deprecated in c++ 20
// [&] - by reference

int global_x {1000}; // global variable

// used for test8
class Person {
    friend std::ostream &operator << (std::ostream &os, const Person &rhs);
    private:
        std::string name;
        int age;
    public:
        Person() = default;
        Person(std::string name, int age):name{name}, age{age}{}
        Person(const Person &p) = default; // copy constructor
        ~Person() = default;
        std::string get_name() const { return name; };
        void set_name(std::string name) { this->name = name; };
        int get_age() const { return age; }
        void set_age(int age) { this->age=age; }

        auto change_person1() {return [this](std::string new_name, int new_age){name = new_name; age = new_age;};}
        auto change_person2() {return [=](std::string new_name, int new_age){name = new_name; age = new_age;};}  // deprecated c++ 20
        auto change_person3() {return [&](std::string new_name, int new_age){name = new_name; age = new_age;};}
};

std::ostream &operator << (std::ostream &os, const Person &rhs){
    os << "[Person: " << rhs.name << " : " << rhs.age << " ]";
    return os;
}

// User for test9
class Lambda {
    private:
        int y;
    public:
        Lambda(int y):y{y}{};

        void operator() (int x) const {
            std::cout << x + y << std::endl;
        };
};


// Capture by value
// The global variable global_x cannot be captured because it is not
// within the reaching scope of the lambda. It can however still be accessed
// from within the lambda using normal name lookup rules.
void test1(){
    std::cout << "\n---Test1----------------------------------------" << std::endl;

    int local_x {100};

    // making a copy
    auto l = [local_x] () {
        std::cout << local_x << std::endl;
        std::cout << global_x << std::endl;
    };
    l();
}

void test2(){
    std::cout << "\n---Test2----------------------------------------" << std::endl;

    int x {100};

    auto l = [x] () mutable {
        x += 100;
        std::cout << x << std::endl; 
    };

    l();// 200
    std::cout << x << std::endl; // 100 

    l(); // 300
    std::cout << x << std::endl; // 100
}

void test3(){
    std::cout << "\n---Test3----------------------------------------" << std::endl;

    int x {100};

    auto l = [&x] () mutable {
        x += 100;
        std::cout << x << std::endl; 
    };

    l();// 200
    std::cout << x << std::endl; // 100 
}


// Default capture by value - mutable
// Only variables used within the lambda body are captured by value
// The variable z is not captured by the lambda
void test4(){
    std::cout << "\n---Test4----------------------------------------" << std::endl;

    int x{100}, y{200}, z{300};

    auto l = [=] () mutable {
        x += 100;
        y += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;  
    };
    l(); // 200, 300 

    std::cout << "\n";
    std::cout << x << std::endl; // 100
    std::cout << y << std::endl; // 200
}

void test5(){
    std::cout << "\n---Test5----------------------------------------" << std::endl;

    int x{100}, y{200}, z{300};

    auto l = [&](){
        x += 100 + 1000;
        y += 100;
        z += 100;

        std::cout << "x: " << x << std::endl; // 200
        std::cout << "y: " << y << std::endl; // 300 
        std::cout << "z: " << z << std::endl; // 400
    };

    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

void test6(){
    std::cout << "\n---Test6----------------------------------------" << std::endl;

    int x{100}, y{2000}, z{300};

    auto l = [=,&y,&z] () mutable {
        x += 100;
        y += 100; // y: by reference
        z += 100;
        std::cout << "x: " << x << std::endl; // 200
        std::cout << "y: " << y << std::endl; // 300 
        std::cout << "z: " << z << std::endl; // 400
    };
    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

void test7(){
    std::cout << "\n---Test7----------------------------------------" << std::endl;

    int x{100}, y{2000}, z{300};

    // capture everything by reference except x, z
    auto l = [&, x, z] () mutable {
        x += 100;
        y += 100; // y: by reference
        z += 100;
        std::cout << "x: " << x << std::endl; // 200
        std::cout << "y: " << y << std::endl; // 2100 
        std::cout << "z: " << z << std::endl; // 400
    };
    l();

    std::cout << std::endl;
    std::cout << x << std::endl; // 100
    std::cout << y << std::endl; // 2100
    std::cout << z << std::endl; // 300
}

void test8(){
    std::cout << "\n---Test8----------------------------------------" << std::endl;
    std::cout << std::endl;

    Person person("Larry", 18);
    std::cout << person << std::endl;

    // Default capture [this]
    // This is the perferred way
    auto change_person1 = person.change_person1();
    change_person1("Moe", 30);
    std::cout << person << std::endl;

    // ____________________________________________________________
    // Default capture [=]
    // This has been deprecated in C++20
    auto change_person2 = person.change_person2();
    change_person2("Curly", 30);
    std::cout << person << std::endl;

    // Default capture [&]
    auto change_person3 = person.change_person3();
    change_person3("Frank", 34);
    std::cout << person << std::endl;
}

void test9(){
    std::cout << "\n---Test9----------------------------------------" << std::endl;

    int y {100};
    // int x is equal to 200

    Lambda lambda1(y); // class function
    auto lambda2 = [y] (int x) {std::cout << x + y << std::endl;}; // lambda function

    lambda1(200); // class function
    lambda2(200); // lambda function
}

// Class use in the test10 example
class People {
        std::vector<Person> people;
        int max_people;
    public:
        People(int max=10):max_people(max){}
        People(const People &p) = default;
        void add(std::string name, int age){
            people.emplace_back(name, age);
        }
        void set_max_people(int max){
            max_people = max;
        }
        int get_max_people() const {
            return max_people;
        }

// This method returns a vector of Person object in 
// people whose age > max_age AND it limits the number of 
// persons returned to be >= the member variable max_people
// Note that the lambda in this example captures this, by reference, and by value
std::vector<Person> get_people(int max_age) {
    std::vector<Person> result;
    int count{0};
    std::copy_if(people.begin(), people.end(), std::back_inserter(result), 
                [this, &count, max_age](const Person &p){return p.get_age() > max_age && ++count <= max_people;});
    return result;
    }
};

void test10(){
    std::cout << "\n---Test10----------------------------------------" << std::endl;

    // creating people classes 

    People friends;
    friends.add("Larry", 18);
    friends.add("Curly", 25);
    friends.add("Moe", 35);
    friends.add("Frank", 28);
    friends.add("James", 65);

    // __________________________________________________

    auto result = friends.get_people(17);

    std::cout << std::endl;
    for (const auto &p : result)
        std::cout << p << std::endl;
    
    //

    friends.set_max_people(3); 

    result = friends.get_people(17);
    std::cout << std::endl;

    for (const auto &p : result)
        std::cout << p << std::endl;

    //

    result = friends.get_people(50);

    std::cout << std::endl;
    for (const auto &p : result)
        std::cout << p << std::endl;
}
           
int main(){ 

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

return 0;
}  