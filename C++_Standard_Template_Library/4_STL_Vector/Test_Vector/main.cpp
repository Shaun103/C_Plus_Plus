#include <iostream>
#include <vector>
#include <string>

class Movie {
    friend std::ostream &operator<<(std::ostream &os, const Movie &p);  // displaying class objects
private:
    std::string name;
    std::string rating;
    int watched;
public:
    Movie() = default;
    Movie(std::string name, std::string rating, int watched) 
        : name{name}, rating{rating}, watched{watched} {};

    void add_movie(std::vector<Movie> &vec, std::string,  std::string name);
    void increment_watched(std::vector<Movie> vec, std::string name);

    bool operator<(const Movie &rhs) const {                       // always overload
        return this->watched < rhs.watched;
    }
    bool operator==(const Movie &rhs) const {  // how the program compares two elements
        return (this->name == rhs.name && this->watched == rhs.watched);    // always overload
    }

    void set_name(std::string name) {
        this->name = name; 
    }

    std::string getName() { 
        return name; 
    }

    void set_rating(std::string rating) {
        this->rating = rating; 
    }

    std::string getrating() { 
        return rating; 
    }

    void set_watched(int watched) {
        this->watched = watched; 
    }

    int get_watched() { 
        return watched; 
    }
};

std::ostream &operator<<(std::ostream &os, const Movie &p) {
    os << p.name << ", " << p.rating << ", " << p.watched;
    return os;
}

// template function to display any vector
template <typename T>
void display(const std::vector<T> &lem) {
    std::cout << "\n===================================" << std::endl;
    for (const auto &elem: lem)
        std::cout << elem << " " << std::endl;
    std::cout << "\n===================================" << std::endl;
}

void add_movie(std::vector<Movie> &vec, std::string name, std::string rating, int watched) {
    Movie temp {name, rating, watched};
    vec.push_back(temp);
}


// I want to modify this function to increment the "watched" variable by one
void increment_watched(std::vector<Movie> &vec, std::string name){
    int watched;
    for (auto &mov: vec)
        if (mov.getName() == name){
            watched = mov.get_watched();
            watched++;
            mov.set_watched(watched);
            std::cout << " -> " << mov.getName() << " Watch has been incremented " << std::endl;
        }  
}

int main() {

    std::vector<Movie> vec;

    add_movie(vec, "Star Wars", "PG", 2);
    add_movie(vec, "Indiana Jones", "PG", 1);
    add_movie(vec, "Matrix", "PG-13", 5);
    add_movie(vec,"Cinderella", "PG", 7);
    add_movie(vec, "Ice Age", "PG", 3);
    add_movie(vec, "Big", "PG-13", 2);

    display(vec);

    increment_watched(vec, "No Movie");
    increment_watched(vec, "Star Wars");
    increment_watched(vec, "Matrix");
    
    display(vec);

    return 0;
}