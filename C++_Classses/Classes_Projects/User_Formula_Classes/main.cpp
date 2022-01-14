#include <iostream>
#include <cmath>
using namespace std;

// class Formula
  // Greeting
  // Distance Method Formula
  // Pythagorean Theorem
  // Area of Triangle
  // Quadratic Method Formula

// class Repeating 
    // repeats special character
// class endMessage
    // message when shutting down program  

//  Main

class Formula {
  private:
    // Private attribute
    string intro;
    string spChar;

  public:
    // Setter
    void setIntro(string s) {
      intro = s; 
    }
    // Getter
    // no void, returns the intro
    string getIntro() {
      return intro;
    }

    // public method - automatically called when calling function
    void greeting(string x){
    cout << "Welcome to my program!" << endl;
    cout << "Todays date is: " << x << endl;   
    cout << "This program should hold many\n" <<  
            "different formulas/equations\n" << endl;
    cout << "\n" << endl;  
  }

    /*******************************************************
    // Distance Method Formula - d=√(x₁ – x₂)² + (y₁ – y₂)²
    // 4 double
    ********************************************************/
    void distanceForm (double x1, double x2, double y1, double y2){
        
        double d {}, top, bottom; // variables 

        cout << "Distance Formula:" << endl;

        // Easier way on one line (I found on the internet) 
        // d = sqrt((pow(x1 - y1, 2)) + (pow(x2 - y2, 2))); 

      top = (pow(x1 - y1, 2));
      bottom = (pow(x2 - y2, 2));
      d = sqrt((top + bottom));
      cout << d << endl;
      cout << "\n" << endl; 
    }

  /********************************
  // Pythagorean Theorem: a²+b²=c²
  *********************************/
  void Pythagorean(int a, int b) {
    double side1 {0}, side2 {0}, hypotenuse {0};

    side1 = pow(a, 2);
    side2 = pow(b, 2);
    hypotenuse = sqrt(side1 + side2);
    cout << "Pythagorean Formula:" << endl; 
    cout << hypotenuse << endl;
    cout << "\n" << endl;
  }

  /************************************************
  // Area of Triangle: area = (1/2) (base) (height)
  *************************************************/
  void AreaTriangle(double base, double height) {
    double half {0.5}, area;

    area = half * (base * height);

    cout << "Area of a Triangle:" << endl; 
    cout << area << endl;
    cout << "\n" << endl;
  }

    /************************************************
    // Quadratic Method Formula: x = −b ± √b²-4ac/2a
    *************************************************/
    void quadraticForm(float a, float b, float c) {
      // variables 
      float x1, x2, discriminant, realPart, imaginaryPart;

      cout << "Quadratic Formula:" << endl;
      // cout << "Enter coefficients a, b and c: ";
      // ENTER: 4 5 1  (ANSWERS: -0.25, -1)
      // cin >> a >> b >> c;

      discriminant = b*b - 4*a*c;
      cout << "Discriminant: " << endl; 
      cout << discriminant << endl;
      if (discriminant > 0) {
          x1 = (-b + sqrt(discriminant)) / (2*a);
          x2 = (-b - sqrt(discriminant)) / (2*a);
          cout << "Roots are real and different." << endl;
          cout << "x1 = " << x1 << endl;
          cout << "x2 = " << x2 << endl;
      }
      else if (discriminant == 0) {
          cout << "Roots are real and same." << endl;
          x1 = -b/(2*a);
          cout << "x1 = x2 =" << x1 << endl;
      }
      else {
          realPart = -b/(2*a);
          imaginaryPart =sqrt(-discriminant)/(2*a);
          cout << "Roots are complex and different."  << endl;
          cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
          cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
          cout << "\n" << endl;
    }
  }
}; // Formula class end

class Repeating {
  private:
    // Private attribute
    string intro;
    string spChar;

  public:
  /****************************
   * repeats special character
   * string, int
   ****************************/ 
    void repeat(string a, int num) {/////////////////////////////////////////////////////////////////////
      spChar = a;
      for (int i = 0; i < num; i++) {
        // if (i % 5 == 0)
        //   cout << "=>";
        // else
        cout << spChar;
      }
    }
    
    // string repeat() {
    //   return spChar;
    // }
    
}; // Repeating class end

/****************************
 * repeats special character
 * string, int
 ****************************/
class endMessage {
  private:
  public:
    void closingProgram() {
    cout << "\nProgram now shutting down.." << endl;
    cout << "\n" << endl;
  }
}; //  endMessage End


/*****************************
//Main
******************************/
int main() {
  char selection; // Checks when to quit while loop

  Formula myObj; // Defining object
  Repeating myObj2; // Class 2 - Define Repeating
  endMessage myObj3; // // Class 3 - Closing program statement 

  // begin do-while loop
do { 

  /*****************************
  // old 
  // manualy setting asteriks 
  // myObj.setIntro("********");
  ******************************/

  /*****************************
  // repeating special character
  // specialChar, int
  // myObj.repeat("*", 20);
  ******************************/

  /*****************************
  // asteriks 
  ******************************/
  myObj2.repeat("*", 20);
  cout << "\n";

  /*****************************
  // Greeting - opening message 
      when opening the program
  ******************************/
  myObj.greeting("02/09/2021");
  myObj2.repeat("*", 20);
  cout << "\n";

  /*****************************
  // Math Formulas 
  ******************************/
  myObj.distanceForm(1, 2, 3, 4);
  myObj.quadraticForm(4, 5, 1);
  myObj.Pythagorean(2, 13);
  myObj.AreaTriangle(5, 8);


  /*****************************
  // Would you like to quit?
  ******************************/
  myObj2.repeat("*", 20);
  cout << "\n";
  cout << "Would you like to quit? ('Q' or 'q') " << endl;
  cin >> selection;


// begin do-while loop
} while (selection != 'q' && selection != 'Q');  

myObj3.closingProgram();  // closing program 
myObj2.repeat("@", 50);

return 0;
}