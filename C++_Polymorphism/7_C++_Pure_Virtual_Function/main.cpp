// Section 16
// Pure virtual functions and abstract base classes
#include <iostream>
#include <vector>

/***************************************************************************/
// Shape - Base function

class Shape {			// Abstract Base class
private:
       // attributes common to all shapes
public:
      virtual void draw() = 0;	    // pure virtual function
      virtual void rotate() = 0;    // pure virtual function
      virtual ~Shape() { }
};

class Open_Shape: public Shape {    // Abstract class
public:
    virtual ~Open_Shape() { }
};

class Closed_Shape : public Shape {  // Abstract class
public:
    virtual ~Closed_Shape() { };
};

/***************************************************************************/
// Line - Open_Shape

class Line: public Open_Shape {     // Concrete class
public:
    virtual void draw() override {                      // overriding the pure virtual functions
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override {                    // overriding the pure virtual functions
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {}
};

/***************************************************************************/
// Circle - Closed_Shape

class Circle: public Closed_Shape {     // Concrete class
public:
    virtual void draw() override {                      // overriding the pure virtual functions
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override {                    // overriding the pure virtual functions
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle() {}
};


/***************************************************************************/
// Square - Closed_Shape

class Square: public Closed_Shape {                        // Concrete class
public:
    virtual void draw() override {                         // overriding the pure virtual functions
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override {                       // overriding the pure virtual functions
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square() {}
};

/***************************************************************************/
//
void screen_refresh(const std::vector<Shape *> &shapes) {
    std::cout << "Refreshing" << std::endl;
    for (const auto p: shapes) 
        p->draw();
}

int main() {

    
//    Shape s;                              // ERROR - abstract class should not work
//    Shape *p = new Shape();

/***************************************************************************/

//    Circle c;
//    c.draw();

/***************************************************************************/

//    Shape *ptr = new Circle();
//    ptr->draw();
//    ptr->rotate();

/***************************************************************************/

Shape *s1 = new Circle();
Shape *s2 = new Line();
Shape *s3 = new Square();

std::vector<Shape *> shapes {s1,s2,s3};

//    for (const auto p: shapes) 
//        p->draw();
    
screen_refresh(shapes);

delete s1;
delete s2;
delete s3;
    
    return 0;
}

