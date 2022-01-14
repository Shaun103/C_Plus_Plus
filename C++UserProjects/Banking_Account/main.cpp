#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

class bankAccount{
    // operator overloaded so i can print account information
    friend std::ostream &operator<<(std::ostream &os, const bankAccount &b);  
    private:
        std::string accountName, accountType;
        int accountNumber;
        double accountBalance, accountInterestRate;
        static int  nextID; // variable to increment each new instance object is created
    public:
        // set functions
        void setAccountName(std::string myAccountName);
        void setAccountType(std::string myAccountType);
        void setAccountNumber(int myAccountNumber);
        void setAccountBalance(double myAccountBalance);
        void setAccountInterestRate(double myAccountInterestRate);

        // manipulates balance
        void withdraw(double withDrawAmount); 
        void deposit(double withDrawAmount);

        // get functions
        std::string getAccountName() const;
        std::string getAccountType() const;
        int getAccountNumber() const;
        double getAccountBalance() const;
        double getAccountInterestRate() const;

        // displays all account information
        void print();

        bankAccount(); // Default constructor
};
// operator overloaded to display account information
std::ostream &operator<<(std::ostream &os, const bankAccount &b) {
    std::cout << std::fixed << setprecision(2) << std::endl;
    os << "\nAccount Holder Name: " << b.accountName << "\n" 
       << "Account Type: " << b.accountType << "\n"
       << "Account Number: " << b.accountNumber << "\n"
       << "Balance: $" << b.accountBalance << "\n"
       << "Interest Rate: " << b.accountInterestRate << "%"<< endl;
    return os;
}

int bankAccount::nextID = 1000;  // Creates account numbers

// Constructors calls - Default constructor
bankAccount::bankAccount(){
    accountName = "xxxxxxxxx";
    accountType = "xxxxxxxxx";
    nextID = nextID + 100;  // adding 100 each time an object is creted
    accountNumber = nextID;
    accountBalance = 0;
    accountInterestRate = 0.0;
}
// _____________________________________________________________________
// bankAccount set functions
void bankAccount::setAccountName(string myAccountName){
    accountName = myAccountName;
}
void bankAccount::setAccountType(string myAccountType){
    accountType = myAccountType;
}
void bankAccount::setAccountNumber(int myAccountNumber){ 
    accountNumber = myAccountNumber;
}
void bankAccount::setAccountBalance(double myAccountBalance){
    accountBalance = myAccountBalance;
}
void bankAccount::setAccountInterestRate(double myAccountInterestRate){
    accountInterestRate = myAccountInterestRate;
}
// _____________________________________________________________________
// bankAccount get functions
std::string bankAccount::getAccountName() const{
    return accountName;
}
std::string bankAccount::getAccountType() const{
    return accountType;
}
int bankAccount::getAccountNumber() const{
    return accountNumber;
}
double bankAccount::getAccountBalance() const{
    return accountBalance;
}
double bankAccount::getAccountInterestRate() const{
    return accountInterestRate;
}
// _____________________________________________________________________
// bankAccount functions to print and manipulate balance
void bankAccount::print(){
    std::cout << "Account Holder Name: " << accountName << std::endl;
    std::cout << "Account Type: " << accountType << std::endl;
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Balance: $" << accountBalance << std::endl;
    std::cout << "Interest Rate: " << accountInterestRate << "%"<< std::endl;
}
void bankAccount::withdraw(double withDrawAmount){
    if (accountBalance >= withDrawAmount){
        accountBalance -= withDrawAmount;
    } else 
        std::cout << "Insufficient balance" << endl; 
}
void bankAccount::deposit(double withDrawAmount){
        accountBalance += withDrawAmount;
}
// end of bankAccount__________________________________________________________________________________
int mainMenu1(){
    int menuChoice;
    std::cout << "\nPlease select a number from the menu below: " << std::endl;
    std::cout << "Enter 1 to add a new customer" << std::endl;
    std::cout << "Enter 2 for an existing customer" << std::endl;
    std::cout << "Enter 3 to print customers data" << std::endl;
    std::cout << "Enter 9 to exit program" << std::endl;
    std::cin >> menuChoice;

    return menuChoice;
}
void addCustomer(std::vector<bankAccount> &vec){
    std::string name, accountType;
    double depositAmount, interestRate;
    std::cout << "Enter Customer's name: " << endl;
    std::getline(std::cin, name);
    std::getline(std::cin, name);
    std::cout << "Enter Customer's type (checking/savings): " << std::endl;
    std::getline(std::cin, accountType);
    std::cout << "Enter amount to be deposited to open an account: " << std::endl;
    std::cin >> depositAmount;
    std::cout << "Enter interest rate (as a percent): " << std::endl;
    std::cin >> interestRate;

    bankAccount temp; // temp object to be placed into vector
    temp.setAccountName(name);
    temp.setAccountType(accountType);
    temp.setAccountBalance(depositAmount);
    temp.setAccountInterestRate(interestRate);

    vec.push_back(temp);
}
void printVec(std::vector<bankAccount> &vec){
    char star = '*';
    int num = 30;
    for (const auto &item : vec) {
        std::cout << std::string(num, star) << std::endl; 
        std::cout << std::endl;
        cout << item;
    }
    
}
int mainMenu2(){
    int menuChoice2;
    std::cout << "\nPlease select a number from the menu below: " << std::endl;
    std::cout << "Enter 1 to make deposit" << std::endl;
    std::cout << "Enter 2 to make withdraw" << std::endl;
    std::cout << "Enter 3 to check balance" << std::endl;
    std::cout << "Enter 9 to exit menu" << std::endl;
    std::cin >> menuChoice2;

    return menuChoice2;
}
void checkBalance(std::vector<bankAccount> &vec, int myNum){
    std::cout << std::fixed << setprecision(2) << std::endl;
        for (auto &mov: vec)
            if (mov.getAccountNumber() == myNum){
                std::cout << "\nAccount Holder Name: " << mov.getAccountName();
                std::cout << "\nAccount Type: " << mov.getAccountType();
                std::cout << "\nAccount Number: " << mov.getAccountNumber();
                std::cout << "\nBalance: $" << mov.getAccountBalance();
                std::cout << "\nInterest Rate: " << mov.getAccountInterestRate() << "%";
                std::cout << "\n" << std::endl;
        }
}
void withDrawBalance(std::vector<bankAccount> &vec, int myNum){
    double myAmount;
    for (auto &mov: vec)
        if (mov.getAccountNumber() == myNum){
            std::cout << "\nEnter amount to withdraw: ";
            std::cin >> myAmount; 
            mov.withdraw(myAmount);
        }
}
void depositBalance(std::vector<bankAccount> &vec, int myNum){
    double myAmount;
    for (auto &mov: vec)
        if (mov.getAccountNumber() == myNum){
            std::cout << "\nEnter amount to deposit: ";
            std::cin >> myAmount; 
            mov.deposit(myAmount);
        }
}
void findRecord(std::vector<bankAccount> &vec){

    int myNum;  // account number we are searching for
    bool toContinue2 = true;

    std::cout << "\nEnter account number: " << std::endl;
    std::cin >> myNum;

    for (auto &mov: vec)
        if (mov.getAccountNumber() != myNum){
            std::cout << "Invalid customer id." << std::endl;
        }
        do {
            system("cls");
            switch (mainMenu2()) {
            case 1:
                system("cls");
                std::cout << "Make deposit menu: ";
                depositBalance(vec, myNum);
                system("pause");
                break;
            case 2:
                system("cls");
                std::cout << "Make withdraw menu: ";
                withDrawBalance(vec, myNum);
                system("pause");
                break;
            case 3:
                system("cls");
                std::cout << "Check balance menu: ";
                checkBalance(vec, myNum);
                system("pause");
                break;
            case 9:
                system("cls");
                cout << "..exiting existing customer menu" << endl;
                toContinue2 = false;  // breaks the do-while loop, end program
                break;
            default: 
                std::cout << "You did not select an option from the menu..." << std::endl;
            }
        } while (toContinue2 != false);
}
int main () {

    // checking if methods work on my objects 
    // ________________________________________________________________

    // bankAccount obj1;
    // obj1.setAccountName("John Doe");
    // obj1.setAccountType("Checking");
    // obj1.setAccountBalance(100);
    // obj1.withdraw(10);
    // obj1.print();

    // bankAccount obj2;
    // obj2.setAccountName("Jane Doe");
    // obj2.setAccountType("Savings");
    // obj2.setAccountBalance(200);
    // obj2.print();

    // ________________________________________________________________

    bool toContinue = true;         // to stay within while loop
    std::vector<bankAccount> vec;   // will hold bankAccount information 

    do {
        system("cls");
        switch (mainMenu1()) {
        case 1:
            system("cls");
            std::cout << "Add new customer menu: ";
            addCustomer(vec);   
            break;
        case 2:
            system("cls");
            std::cout << "Existing customer menu: ";
            findRecord(vec);
            system("pause");
            break;
        case 3:
            system("cls");
            std::cout << "Print customer data menu: ";
            printVec(vec);
            system("pause");
            break;
        case 9:
            system("cls");
            cout << "..Now terminating program" << endl;
            toContinue = false;
            break;
        default: 
            std::cout << "You did not select an option from the menu..." << std::endl;
        }
    } while (toContinue != false);

    system("pause");
    return 0; 
} 