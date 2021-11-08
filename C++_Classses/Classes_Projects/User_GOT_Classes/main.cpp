#include <iostream>
#include <cmath>
using namespace std;

/*

outline
  
  class <className> {
    private:
      // Private attribute
      <setVariable>;

    public:
      // Setter, function
      void <setter>() { 
        salary = s;
      }
      // Getter
      int <getter>() {
        return salary;
      }
  };

outline

  To access a private attribute, 
  use public "get" and "set" methods:

*/ 

class houseWords { 
  private:
    //  Encapsulation - Private "HouseWords" attribute
    string houseWords;
  public:
    // Set method
    // passing in a string variable s 
    
    void setHouseWords(string s) {
      houseWords = s;
    }

    // Get method
    string getHouseWords() {
      return houseWords;
    }

    // Public method
    // Distance formula - d=√(x₁ – x₂)² + (y₁ – y₂)²
    void distanceForm (int x1, int x2, int y1, int y2){
        double d{0}; 
        
        d = sqrt((pow(x1 - y1, 2)) + (pow(x2 - y2, 2)));
        cout << "Distance Formula: " << d << endl; 
    }
};

int main() {
    // creating the Targaryen object

    // "myObj.set.....()"
    // "myObj.get.....()"

    houseWords myObj;                                                                     // creating an instance of hourseWords 

    myObj.setHouseWords("Fire and Blood");                                                // setting Targaryen words

    // get - getHouseWords to display what was passed in
    cout << "The Targaryen words are: " << "\"" << myObj.getHouseWords() << "\"\n";

    myObj.setHouseWords("Winter is Coming");                                              // setting Stark words
    // get - getHouseWords to display what was passed in
    cout << "The Stark words are: " << "\"" << myObj.getHouseWords() << "\"";
    cout << "\n" << endl; 

    // Distance Formula 
    myObj.distanceForm(1, 2, 3, 4);

  return 0;
}