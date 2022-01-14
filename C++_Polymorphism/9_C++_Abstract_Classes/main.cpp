// Section 16
// Pure virtual functions and abstract base classes
#include <iostream>
#include <vector>


/*********************************************************************/
// Abstract BASE CLASS - Templete
// MAIN BOSS CLASS
class Shape {			// cant: Shape s;  or  Shape *p = new Shape();
private:
       // attributes common to all shapes
public:
      virtual void draw() = 0;	   // pure virtual function  -  '=0' pure virtual function 
      virtual void rotate() = 0;   // pure virtual function
      virtual ~Shape() { }
};

// MINI BOSS CLASSES - RELATED TO SHAPE 
class Open_Shape: public Shape {    // Abstract class   - Related to Line Class 
public:
    virtual ~Open_Shape() { }
};

// MINI BOSS CLASSES - RELATED TO SHAPE 
class Closed_Shape : public Shape {  // Abstract class  - Related to Square, Circle Class
public:
    virtual ~Closed_Shape() { };
};


/*********************************************************************/
// Concrete class - working classes 
class Line: public Open_Shape {     // Concrete class  
public:
    virtual void draw() override {  // overriding pure virtual functions
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {}
};

class Circle: public Closed_Shape {     // Concrete class
public:
    virtual void draw() override {  // overriding pure virtual functions
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle() {}
};

class Square: public Closed_Shape {     // Concrete class
public:
    virtual void draw() override {  // overriding pure virtual functions
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square() {}
};

/**********************************************************************/
//

void screen_refresh(const std::vector<Shape *> &shapes) {
    std::cout << "Refreshing: " << std::endl;
    for (const auto p: shapes) 
        p->draw();
}

int main() {

// Shape s;                        // COMPILER ERROR: Abstract class
// Shape *p = new Shape();     

// Circle c;                       // Using concrete class directly 
// c.draw();

// Shape *ptr = new Circle();      // Using the abstract class to create an instances of a concrete class 
// ptr->draw();
// ptr->rotate();


Shape *s1 = new Circle();           // Using Abstract Shape class to create pointers for Cirlce, Line, Square
Shape *s2 = new Line();
Shape *s3 = new Square();

std::vector<Shape *> shapes {s1, s2, s3};       // Vector to hold each other created obj
// for (const auto p: shapes)
//     p->draw();

    screen_refresh(shapes);  // Made into a function 
        
delete s1;
delete s2;
delete s3;

    return 0;
}