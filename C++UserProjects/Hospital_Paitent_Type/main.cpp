#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class patientType {
    // allows output of class elements
    friend std::ostream &operator<<(std::ostream &os, const patientType &b);
    private:
        double id, age;
        std::string name, illnessDescription;
    public:
        // constructors
        patientType();  // default constructor - zero arguments
        // user generated output
        patientType(double myId, double myAge, std::string myName, std::string myIllnessDescription);

        // setter functions
        void setId(double myId);
        void setAge(double myAge);
        void setName(std::string myName);
        void setIllnessDescription(std::string myIllnessDescription);
        
        // getter functions
        double getId() const;
        double getAge() const;
        std::string getName() const;
        std::string getIllnessDescription() const;
};

std::ostream &operator<<(std::ostream &os, const patientType &p) {
        os << "\nPatient Name: " << p.name << "\n" 
        << "Patient age: " << p.age << "\n"
        << "Patient ID: " << p.id << "\n"
        << "Patient illness description: " << p.illnessDescription << endl;
    return os;
}

// Constructors - default constructor
patientType::patientType(){
    id = 0;
    age = 0;
    name = "xxxxxxx";
    illnessDescription = "No description";
}

// Constructor - values passed in by user
patientType::patientType(double myId, double myAge, std::string myName, std::string myIllnessDescription){
    id = myId;
    age = myAge;
    name = myName;
    illnessDescription = myIllnessDescription;
}

// setter functions
void patientType::setId(double myId){
    id = myId;
}
void patientType::setAge(double myAge){
    age = myAge;
}
void patientType::setName(std::string myName){
    name = myName;
}
void patientType::setIllnessDescription(std::string myIllnessDescription){
    illnessDescription = myIllnessDescription;
}

// getter methods
double patientType::getId() const{
    return id;
}
double patientType::getAge() const{
    return age;
}
std::string patientType::getName() const{
    return name;
}
std::string patientType::getIllnessDescription() const{
    return illnessDescription;
}

// user selection menu 
int mainMenu(){
    int menuChoice = 0;
    std::cout << "\nPlease select a number from the menu: " << std::endl;
    std::cout << "1: Adding a new Patient" << std::endl;
    std::cout << "2: Searching for a patient" << std::endl;
    std::cout << "3: Listing patients" << std::endl;
    std::cout << "4: Delete Patient Records" << std::endl;
    std::cout << "5: Updating patient records" << std::endl;
    std::cout << "6: Print All Records" << std::endl;    
    std::cout << "7: Exit Program" << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "Select Your Choice :=>" << std::endl;
    std::cin >> menuChoice;
    return menuChoice;
}

void addPatient(std::vector<patientType> &vec){
    std::string name, illnessDescription;
    double age, id;

    std::cout << "\nEnter patient's name: " << endl;
    std::getline(std::cin, name);
    std::getline(std::cin, name);
    std::cout << "Enter patients illness description: " << std::endl;
    std::getline(std::cin, illnessDescription);
    std::cout << "Enter patients age: " << std::endl;
    std::cin >> age;
    std::cout << "Enter patient ID: " << std::endl;
    std::cin >> id;

    patientType temp; // temp object to be placed into vector

    temp.setId(id);
    temp.setAge(age);
    temp.setName(name);
    temp.setIllnessDescription(illnessDescription);

    vec.push_back(temp);
}

void searchPatient(std::vector<patientType> &vec){
    int myNum = 0;  // patient ID number we are searching for
    std::cout << "\nEnter patient ID number to display: " << std::endl;
    std::cin >> myNum;

    auto iter = std::find_if(vec.begin(), vec.end(), [&](patientType &s){ return s.getId() == myNum; }); 

    if (iter != vec.end()){
        std::cout << *iter << std::endl;
    } else {
        std::cout << "...invalid ID number" << std::endl;
    }
}

void removePatient(std::vector<patientType> &vec){
    int myNum = 0;  // patient ID number we are searching for
    std::cout << "\nEnter patient ID number: " << std::endl;
    std::cin >> myNum;

    auto iter = std::remove_if(vec.begin(), vec.end(), [&](patientType &s) { return s.getId() == myNum; }); 
        vec.erase(iter, vec.end()); 
}

int mainMenu2(){
    int menuChoice2;
    std::cout << "\nPlease select a number from the menu below: " << std::endl;
    std::cout << "1: Update patient name" << std::endl;
    std::cout << "2: Update patient age" << std::endl;
    std::cout << "3: Update patient id" << std::endl;
    std::cout << "4: Update patient illness description" << std::endl;
    std::cout << "9: Exit update menu" << std::endl;
    std::cin >> menuChoice2;
    return menuChoice2;
}

void updatePatients(std::vector<patientType> &vec){
    int myNum = 0;  // patient ID number we are searching for
    bool toContinue2 = true; // bool to break out of update menu 

    // variables to change patientType elements
    std::string newName, newIllnessDescription; 
    double newAge, newId; 

    // variable to find object in vector
    std::cout << "\nEnter patient ID number to update: " << std::endl;
    std::cin >> myNum;

    for (auto &patient: vec)
        if (patient.getId() == myNum){
            do {
                switch (mainMenu2()) {
                    case 1:
                        std::cout << "***MENU: update patient name: ";
                        std::cout << "\nUpdate patient name: " << std::endl;
                        std::getline(std::cin, newName);
                        std::getline(std::cin, newName);
                        patient.setName(newName);
                        break;
                    case 2:
                        std::cout << "***MENU: update patient age: ";
                        std::cout << "\nUpdate patient age: " << std::endl;
                        std::cin >> newAge; 
                        patient.setAge(newAge);
                        break;
                    case 3:
                        std::cout << "***MENU: update patient id: ";
                        std::cout << "\nUpdate patient id: " << std::endl;
                        std::cin >> newId; 
                        patient.setId(newId);
                        break;
                    case 4:
                        std::cout << "***MENU: update patient illness description: ";
                        std::cout << "\nUpdate patient illness description: " << std::endl;
                        std::getline(std::cin, newIllnessDescription);
                        std::getline(std::cin, newIllnessDescription);
                        patient.setIllnessDescription(newIllnessDescription);
                        break;
                    case 9:
                        cout << "\n..Now terminating program" << endl;
                        toContinue2 = false;  // breaks the do-while loop, end program
                        break;
                    default: 
                        std::cout << "\nYou did not select an option from the menu..." << std::endl;
                    }
        } while (toContinue2 != false);
    } else {
        std::cout << "..invalid ID number" << std::endl;
    }    
}

void displayPatients(std::vector<patientType> &vec){
    char star = '*';
    int num = 30;
    for (const auto &item: vec) {
        std::cout << std::string(num, star) << std::endl;
        std::cout << item;
    }
    std::cout << std::string(num, star) << std::endl; 
    std::cout << std::endl;
}

// method can take any type of vector
template <typename T>
void printAllRecords(const std::vector<T> &lem) {
    char star = '*';
    int num = 30;

    ofstream MyFile("PatientRecords.txt");

    MyFile << "=== Patient Records ===" << endl;

    for (const auto &item: lem) {
        MyFile << std::string(num, star) << std::endl;
        MyFile << item;
    }
    MyFile << std::string(num, star) << std::endl; 
    MyFile << std::endl;

    MyFile.close();  // Close the file
}

// Main programming
int main(){ 
    bool toContinue = true;       // bool to break terminate program       
    std::vector<patientType> vec; // main vector to add patients
    do {
        switch (mainMenu()) {
            case 1:
                std::cout << "***MENU: Add New Patient: ";
                addPatient(vec);   // adds patient
                break;
            case 2:
                std::cout << "***MENU: Search Patient:";
                searchPatient(vec); // finds an displays searched patient
                break;
            case 3:
                std::cout << "***MENU: Display All Patients:";
                displayPatients(vec);   // displays ALL patient information
                break;
            case 4:
                std::cout << "***MENU: Delete Patient Records:";
                removePatient(vec);     // deletes patient
                std::cout << "\n" << std::endl;
                std::cout << "..patient was removed.";
                std::cout << "\n" << std::endl;
                break;
            case 5: 
                std::cout << "***MENU: Updating patient Records:";
                updatePatients(vec);    // updates patient information
                break;
            case 6: 
                printAllRecords(vec);    // updates patient information
                std::cout << "\n" << std::endl;
                std::cout << "..file has been created" << std::endl;
                std::cout << "\n" << std::endl;
                break;
            case 7:
                cout << "..Now terminating program" << endl;
                toContinue = false;  // breaks the do-while loop, end program
                break;
            default: 
                std::cout << "You did not select an option from the menu..." << std::endl;
        }
    } while (toContinue != false); 
return 0;
}  