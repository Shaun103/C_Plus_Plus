#include <iostream>
#include <iomanip>
#include <string>
using namespace std;



/////////////////////////////////////////////////////////////////////
// Functions prototypes 
/////////////////////////////////////////////////////////////////////

double calc_cost(double base_cost, double tax_rate = 0.06, double shipping  = 3.50);
void greeting(string name, string prefix = "Mr. ", string suffix = " "); 

/////////////////////////////////////////////////////////////////////
// function definitions 
/////////////////////////////////////////////////////////////////////

double calc_cost(double base_cost, double tax_rate, double shipping) {
    return base_cost += (base_cost * tax_rate) + shipping; 
}

/////////////////////////////////////////////////////////////////////
// greeting function 
// prefix - default argument Mr.
// suffix - default argument " " (space is nothing is passed into it)
//////////////////////////////////////////////////////////////////////

void greeting(string name, string prefix, string suffix){
        cout << "Hello " << prefix + " " + name +  " "  + suffix << endl; 
}

int main() {

// calculates cost 
double cost {0}; 

//////////////////////////////////
// arguments passed in... 
// (base_cost, tax_rate, shipping)
cost = calc_cost(100.0, 0.08, 4.25); 
cout << "Cost is: " << cost << endl;

cost = calc_cost(100.0, 0.08);
cout << "Cost is: " << cost << endl;

cost = calc_cost(200.0);
cout << "Cost is: " << cost << endl;


// Argument: name 
greeting("Glen Jones");
// Argument: name, suffix 
greeting("William", "Smith");
// Argument: name, prefix
greeting("Frank MIllier", "Dr.");
// Argument: name, prefix, prefix 
greeting("James Rogers", "Professor.", "MD");


cout << endl;
return 0; 
}