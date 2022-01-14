/******************************************************************
 * Section 13 Challenge Solution
 * main.cpp
 * 
 * Test the Movies project
 * 
 * ***************************************************************/
#include <iostream>
#include <vector>
#include <string>

/*
    creating Movie class object - (name, rating, watched)
*/ 

class Movie {
private:
    std::string name;       // the name of the movie
    std::string rating;     // the movie rating G,PG, PG-13, R
    int watched;            // the number of times you've watched the movie
public:
    // Constructor - expects all 3 movie attributes
    Movie(std::string name, std::string rating, int watched);
    // Copy constructor 
    Movie(const Movie &source); 
    // Destructor
    ~Movie();
    
    // Basic getters and setters for private attributes
    // implement these inline and watch your const-correctness
    void set_name(std::string name) {
        this->name = name; 
    }

    std::string get_name() const { 
        return name; 
    }
    
    void set_rating(std::string rating) {
        this->rating = rating; 
    }

    std::string get_rating() const { 
        return rating; 
    }
    
    void set_watched(int watched) {
        this->watched = watched; 
    }

    int get_watched() const { 
        return watched; 
    }
    
    // Simply increment the watched attribute by 1
    void increment_watched() { 
        ++watched; 
    }
    
    // simply displays the movie information ex.) Big, PG-13, 2
    void display() const;
};

// Implemention of the construcor
Movie::Movie(std::string name, std::string rating, int watched) 
    : name(name), rating(rating), watched(watched)  {
}

//Implemention of the copy constructor
Movie::Movie(const Movie &source) 
    : Movie{source.name, source.rating, source.watched} {
}

// Implementation of the destructor
Movie::~Movie() {
}

// Implementation of the display method
// should just insert the movie attributes to cout
void Movie::display() const {
    std::cout << name << ", " << rating <<  ", " << watched  <<  std::endl;
}

class Movies {
private:
    std::vector<Movie> movies;
public:
    Movies();             // Constructor
    ~Movies();            // Destructor

    // Function prototypes
    bool add_movie(std::string name, std::string rating, int watched);
    bool increment_watched(std::string name);
    void display() const;
};

Movies::Movies() {
}

Movies::~Movies() {
}

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    for (const Movie &movie: movies) {
        if (movie.get_name() == name)
            return false;
    }
    // temporary Movie object value
    Movie temp {name, rating, watched}; 
    movies.push_back(temp);
    return true;
}

bool Movies::increment_watched(std::string name) {
    for (auto &movie: movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const {
    if (movies.size() == 0) {
        std::cout << "Sorry, no movies to display\n" << std::endl;
    } else {
        std::cout << "\n===================================" << std::endl;
        for (const auto &movie: movies)
            movie.display();
        std::cout << "\n===================================" << std::endl;
    }
}

// // Function prototypes
// void increment_watched(Movies &movies, std::string name);
// void add_movie(Movies &movies, std::string name, std::string rating, int watched);
void increment_watched(Movies &movies, std::string name) {
    if (movies.increment_watched(name)) {
        std::cout << name << " watch incremented" <<  std::endl;
    } else {
        std::cout << name << " not found" <<  std::endl;
    }
}

void add_movie(Movies &movies, std::string name, std::string rating, int watched) {
    if (movies.add_movie(name,rating,watched)) {
        std::cout << name << " added" << std::endl;
    } else {
        std::cout << name << " already exists" <<  std::endl;
    }
}

int main() {
    
    Movies my_movies;         // creating movie list (vector) to hold movies 

    // my_movies.display();   // creating vector object my_movies from  Move

    add_movie(my_movies, "Big", "PG-13", 2);             // OK
    add_movie(my_movies,"Star Wars", "PG", 5);           // OK
    add_movie(my_movies,"Cinderella", "PG", 7);          // OK
    my_movies.display();                                 // Big, Star Wars, Cinderella

    add_movie(my_movies,"Cinderella", "PG", 7);          // Already exists
    add_movie(my_movies,"Ice Age", "PG", 12);            // OK

    my_movies.display();                                 // Big, Star Wars, Cinderella, Ice Age

    increment_watched(my_movies, "Big");                 // OK
    increment_watched(my_movies, "Ice Age");             // OK

    my_movies.display();                                 // Big and Ice Age watched count incremented by 1

    // increment_watched(my_movies,"XXX");               // XXX not found

	return 0;
}