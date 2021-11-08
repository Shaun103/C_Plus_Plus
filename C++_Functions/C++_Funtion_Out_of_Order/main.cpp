#include <iostream>
using namespace std; 

const double pi = {3.14149};

////////////////////////////////////////
// void if functions are not returning 
// anything, changing variables

///////////////////////
// Function prototypes
double calc_volume_cylinder(double radius, double height);
double calc_area_circle(double radius);
void area_circle();
void volume_cylinder();
 
////////////////
// main 
int main() {

area_circle();
volume_cylinder();  //pi r^2 * height

cout << endl;
return 0; 
}


///////////////////////
// function definitions 
// calc_area
double calc_area_circle(double radius){
return pi * radius * radius; 
}

///////////////////////
// function definition
// calc_volume
double calc_volume_cylinder(double radius, double height){
       // return pi * radius * radius * height; 
       return calc_area_circle(radius) * height;
}

////////////////////////
// function definition
// area_circle

void area_circle(){
double radius {};
cout << "Enter radius of the cirlce: " << endl;
cin >> radius;
cout << "The area of a circle wtih radius " << radius << 
               " is: " << calc_area_circle(radius) << endl;
}

///////////////////////
// function definition
// volume_cylinder

void volume_cylinder(){

double radius {};
double height {};

cout << "\nEnter radius of the cylinder: " << endl;
cin >>  radius;
cout << "\nEnter height of the cylinder: " << endl; 
cin >> height; 
cout << "The volume of the cylinder with radius " << radius << " and height " << height <<
                " is " << calc_volume_cylinder(radius, height) << endl;
}