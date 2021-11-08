// Section 20
// Algorithms
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype> 

class Person {
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age)
        : name{name}, age{age} {}
    bool operator <(const Person &rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

// Find Test
// Find an element in a container
void find_test() {
    std::cout << "\n=======================================" << std::endl;

    std::vector<int> vec {1,2,3,4,5};

    auto loc = std::find(std::begin(vec), std::end(vec), 1);    // 1 is what i want to find
                            // vec.begin()
                            // vec.end()

    if (loc != std::end(vec))   // if doesnt find '1'
        std::cout << "Found the number: " << *loc << std::endl; // found
    else 
        std::cout << "Couldn't find the number" << std::endl;   // reaches the end

    std::cout << "\n=======================================" << std::endl;

    std::list<Person> players {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21}
    };

    auto loc1 = std::find(players.begin(), players.end(), Person{"Moe", 20});  // find Person {"Moe"}

    if (loc1 != players.end())   // if doesnt find '1'
        std::cout << "Found person! " << std::endl; // found
    else 
        std::cout << "Person not found.. " << std::endl;   // did not find
}

// Find element in a container
// count test
void count_test(){

    std::cout << "\n=======================================" << std::endl;

    std::vector<int> vec {1,2,3,4,5,1,2,1};

    int num = std::count(vec.begin(), vec.end(), 1);

    std::cout << num << " occurrences found" << std::endl;
}

// count the number of occurences of an element in a container
// based on a predicate using a lambda expression
// count if expression
void cout_if_test(){

    std::cout << "\n=======================================" << std::endl;

    // count only if the element is even
    std::vector<int> vec {1,2,3,4,5,1,2,1,100};

    int num = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 == 0;}); // lambda functions 
    std::cout << num << " even numbers found" << std::endl;

    num = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 != 0;}); 
    std::cout << num << " odd numbers found" << std::endl;

    // how can we determin how many elements in vec are >= 5?
    num = std::count_if(vec.begin(), vec.end(), [](int x) { return x >= 5;}); 
    std::cout << num << " numbers greater than or equal to 5" << std::endl;
}


// replace test 
void replace_test(){

    std::cout << "\n=======================================" << std::endl;

    std::vector<int> vec {1,2,3,4,5,1,2,1};
    
    for (auto i: vec){
        std::cout << i << " ";
    }

    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 100);
    for (auto i: vec){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void all_of_test() {
    
    std::vector<int> vec1 {1,3,5,7,9,1,3,13,19,5};

    // are all numbers > 10
    if (std::all_of(vec1.begin(), vec1.end(), [](int x) { return x > 10; }))
        std::cout << "All the elements are > 10" << std::endl;
    else    
        std::cout << "Not all the elements are > 10" << std::endl;
    
    // are all numbers < 20
    if (std::all_of(vec1.begin(), vec1.end(), [](int x) { return x < 20; }))
        std::cout << "All the elements are < 20" << std::endl;
    else    
        std::cout << "Not all the elements are < 20" << std::endl;        
}

// Transform elements in a container - string in this example
void string_transform_test() {
    std::cout << "\n========================" << std::endl;

    std::string str1 {"This is a test"};
    std::cout << "Before transform: " << str1 << std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper); // ":: " global scope 
    std::cout << "After transform: " << str1 << std::endl;
}


int main() {

    find_test();
    count_test();
    cout_if_test();
    replace_test();
    all_of_test();
    string_transform_test();

    return 0;
}