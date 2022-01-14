#include <iostream>
#include <cstring>

using namespace std;


/*

    STRUCTS by default use public variables
    CLASSES by default use private variables 

*/



/*          Book struct                       */
struct Books {
    string title;
    string author;
    string subject;
    int id;
};

// function - Book Struct
void displayBookInfo(struct Books myBook) {
cout << "Book title: " << myBook.title << endl; 
cout << "Book author: " << myBook.author << endl;
cout << "Book subject: " << myBook.subject << endl;
cout << "Book ID: " << myBook.id << endl; 
} 


/*          Person struct                       */
struct Person {
    string name;
    int age;
    float salary;
};


/*          myMovies struct                       */
struct myMovies{
    string title;
    int year;
} mine, yours;


int main () {
    
// struct 1
    myMovies mine, years;
    // mine.title = "Avatar";                      // initializing manually 

    cout << "Enter info: " << endl;          // user setting variable
    cin >> mine.title;

    mine.year = 2008;
    cout << "My favorite movie is: " << mine.title << endl;
    cout << "The year is: " << mine.year << endl;

    cout << "Enter a movie title: " << endl;
    cin >> yours.title;

    cout << "Enter the movie year: " << endl;
    cin >> yours.year;
    cout << "Your favorite movie is: " << yours.title << " Year:  " << yours.year << endl; 


// /*****************************************************/
// // struct lesson 2

//     Person p1, p2;
//     cout << "Enter the full name: " << endl;
//     cin >> p1.name;
//     cout << "Enter the age: " << endl;
//     cin >> p1.age;
//     cout << "Enter the salary: " << endl;
//     cin >> p1.salary;

//     cout << "\nDisplay the information" << endl; 
//     cout << "Name: " << p1.name << endl;
//     cout << "Age: " << p1.age << endl;  
//     cout << "Salary: " << p1.salary << endl;


//     p2.name = "Jane"; 
//     p2.age = 23;
//     p2.salary = 5000;   
//     cout << "p2 Name: " << p2.name << " p2 age: " << p2.age << " p2 salary " << p2.salary << endl;


/*****************************************************/
// struct lesson 3 

    // struct Books book1;
    // struct Books book2;
    // struct Books book3;


    // // Attribute for the first book 
    // book1.title = "Frankenstein";
    // book1.author = "Thomas Henry"; 
    // book1.subject = "Scifi"; 
    // book1.id = 2343;

    // // Attribute for the second book 
    // // strcpy(book2.title, "Teach yourself Computer Networking");  // trouble with this line
    // book2.title = "Teach yourself Computer Networking"; 
    // book2.author = "Allison Hamilton";
    // book2.subject = "Networking";
    // book2.id = 5425;

    // // Attribute for the third book 
    // book3.title = "BookBook3"; 
    // book3.author = "John Doe";
    // book3.subject = "Boo";
    // book3.id = 435;

    // // Print the book1 information 
    // cout << "Book1 title: " << book1.title << endl;
    // cout << "Book1 author: " << book1.author << endl; 
    // cout << "Book1 subject: " << book1.subject << endl;
    // cout << "Book1 ID: " << book1.id << endl;
    
    // cout << "\n" << endl; 
    // // Print the book2 information  
    // cout << "Book2 title: " << book2.title << endl;
    // cout << "Book2 author: " << book2.author << endl; 
    // cout << "Book2 subject: " << book2.subject << endl;
    // cout << "Book2 ID: " << book2.id << endl;

    // cout << "\n" << endl; 
    // // Print the book3 information 
    // cout << "Book3 title: " << book3.title << endl;
    // cout << "Book3 author: " << book3.author << endl; 
    // cout << "Book3 subject: " << book3.subject << endl;
    // cout << "Book3 ID: " << book3.id << endl;



// /*****************************************************/
// /*   More efficient way of printing information   */
// // struct functions
//     // printing book information for struct 


//     displayBookInfo(book1);
//     cout << "\n" << endl; 

//     displayBookInfo(book2);
//     cout << "\n" << endl; 

//     displayBookInfo(book3);
//     cout << "\n" << endl; 

    return 0; 
} 