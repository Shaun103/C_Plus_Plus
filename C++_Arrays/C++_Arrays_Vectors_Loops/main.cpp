#include <iostream>
#include <vector>
#include <string>
#include <cstring> // strcpy, strlen,strcmp
// #include <cctype>
using namespace std; 

// ________________Table_Contents_____________________

// Arrays
// Vectors
// Cents challenge
// Bar graph
// Searching string (find method)
// Checks name for uppcase  
    //// strcpy, strlen, strcmp
    //// gin.getline
// encrypted message
// Do while
// Range based for loop

// ________________Table_Contents_____________________
 

int main() { 


    // // initialize array 
    // char vowels[] {'a', 'e', 'i', 'o', 'u', 'y'}; 
    
    // cout << "\n" << "Your vowel is: " << vowels[0] << "\n";

    // // array at position 0 initialized to 'T'
    // vowels[0] = 'T'; 
    // cout << "\n" << vowels[0] << "\n";

    // // initialize second array to hold 6 points, 
    //     // and initialize non specified points to 100
    // int test_scores [6];
    
    // // printing out each point in array 
    // cout << "Test score position 1: " <<test_scores[0] << endl;
    // cout << "Test score position 2: " <<test_scores[1] << endl;
    // cout << "Test score position 3: " <<test_scores[2] << endl;
    // cout << "Test score position 4: " <<test_scores[3] << endl;
    // cout << "Test score position 5: " <<test_scores[4] << endl;
    // cout << "Test score position 6: " <<test_scores[5] << endl; 

    // // typeing the positions manually 
    // cin >> test_scores[0];
    // cin >> test_scores[1];
    // cin >> test_scores[2];
    // cin >> test_scores[3];
    // cin >> test_scores[4];  
    // cin >> test_scores[5];

    ///////////////////
    // Arrays

    // // int test_scores [6];

    // cout << "Please input a number (1 - 6): " << endl;
    // for (int i = 0; i < 6; i++){
    //     cout << "Please input number " << 1 + i << ": " << endl; 
    //     cin >> test_scores[i];
    // }

    // for (int i = 0; i < 6; i++) {
    //     cout << "\nYour array at position: " << i + 1 << " is " << test_scores[i] << endl;
    // }

    ////////////////////
    // Vectors  

    // vector <int> vector1;
    // vector <int> vector2;
    
    // double input; 

    // cout << "Please input a number (1 - 6): " << endl;
    // for (int i = 1; i <= 3; i++){
    //     cout << "Please input number " << i << ": " << endl; 
    //     cin >> input;
    //     vector1.push_back(input);
    // }

    // for (int i = 0; i < vector1.size(); i++) {
    //     cout << "\nYour array at position: " << i + 1 
    //     << " is " << vector1[i] << endl;
    // }

    // cout << "\n";
    // cout << "Display vector at: " << endl;
    // cout << "At position 1: " << vector1.at(0) << endl;  // 1
    // cout << "At position 2: " <<vector1.at(1) << endl;   // 2
    // cout << "At position 3: " <<vector1.at(2) << endl;   // 3

    ////////////////////
    // Cents challenge 

    //     const int dollar_value {100}, 
    //     quarter_value {25},
    //     dime_value {10},
    //     nickle_value {5},
    //     penny_value {1}; 
    //     int  change_amount {};
        
    // cout << "Please enter the number of cents into the program: ";
    // cin >> change_amount; 
    
    //  int ballance {};
    //  double dollar {}, quarter {}, dime {}, nickle {}, penny {};
    
    // dollar = change_amount / dollar_value; 
    // ballance = change_amount % dollar_value;
    
    // quarter = ballance / quarter_value;
    // ballance %= quarter_value;
    
    // dime = ballance / dime_value;
    // ballance %= dime_value; 
    
    // nickle = ballance / nickle_value;
    // ballance %= nickle_value;
    
    // penny = ballance; 
   
    // cout <<  " \nDollar: " << dollar << " \nQuarter: " << quarter  <<" \nDime: "  
    //         <<  dime<< " \nNickle: " << nickle << " \nPenny: " << penny << endl;

    ////////////////////
    // bar graph

    // int num_items {0}; // number of input items
    // cout << "How many data items do you have?"; 
    // cin >> num_items;
    
    // vector<int> data {}; // vector to hold each num_items 
    
    // for (int i {1}; i <= num_items; ++i){
    //     int data_item {0}; // number of 
    //     cout << "Ener data item " << i << ": "; 
    //     cin >> data_item;
    //     data.push_back(data_item); 
    // }
    
    // cout << "\nDisplaying Histogram" << endl;
    // for (auto val : data){ // outside loop (slow)
    //     for (int i {1}; i <= val; ++i){  // inside loop (fast)
    //         if (i % 5 == 0) // as long as it is divisible by 5 (equal zero) prints "*"
    //             cout << "*";
    //         else
    //             cout << "-"; // everything else will print "-"
    //     }
    //     cout << endl;
    // } 


    //////////////////////////////////
    // Searching string (find method)

    // string s1 = "The secret word is Boo!"; 
    // string word {};
    
    // cout << "Enter the word to find: " << endl;
    // cin >> word;

    // // size_t position {}; // measures the length of word

    // size_t position = s1.find(word); // find method search s1 string
    // if(position != string::npos)
    //     cout << "\nFound " << word << " at position:" << position << endl;
    // else
    //     cout << "\nSorry, " << word << " not found, or string not found in sentence" << endl;

    /////////////////////////////
    // Checks name for uppcase 

    //     char full_name[50] {};
    //     char temp[50] {};

    //     cout << "Enter your full name: "; 
    //     cin.getline(full_name, 30);
    //     cout << "Your full name is " << full_name << endl;

    //     cout << "---------------------------------" << endl;
    //     strcpy(temp, full_name); 
    //     if (strcmp(temp, full_name) == 0 ) // compares first time
    //         cout << temp << " and " << full_name << " are the same" << endl; // temp is a copy of full_name
    //     else
    //         cout << temp << " and " << full_name << " are different" << endl;
    //     cout << "----------------------------------" << endl;

    //     for(size_t i{0}; i < strlen(full_name); ++i){
    //         // isalpha checks if the characters is alphabetic 
    //         if (isalpha(full_name[i])) 
    //             full_name[i] = toupper(full_name[i]); // uppercase full_name
    //     }
    //     cout << "Your full name is " << full_name << endl; // full_name is now uppercase 

    // cout << "----------------------------------" << endl;
    // if(strcmp(temp, full_name) == 0) // compares for the last time
    //     cout << temp << " and " <<  full_name << " are the same" << endl;
    //     else 
    //         cout << temp <<  " and " << full_name << " are different" << endl;

    //     cout << "----------------------------------" << endl;
    //     cout << "Result of comparing " << temp << " and " << full_name << ": " << strcmp(temp, full_name) << endl;
    //     cout << "Result of comparing " << full_name << " and " << temp << ": " << strcmp(full_name, temp) << endl;


    //////////////////////
    // encrypted message

    // string encrypted {};
    // string decrypted {};
    
    // cout << "Please enter a secret message: " << endl; 
    // getline(cin, encrypted);

    // cout << "\nEncrypting message...";

    // for (int i  = 0; (i  < 100 && encrypted[i] != '\0'); i++)
    //     // encodes string input
    //     // This is adding +2 to each character to modify in the ACHII chart
    //     encrypted[i] = encrypted[i] + 2;         
    //     cout << "\nThe encrypted message is now: " << encrypted;
        
        
    // for (int i  = 0; (i  < 100 && encrypted[i] != '\0'); i++)
    //     // decodes the encrypted string 
    //     // Subtracting -2 to reverse the character modified from the ACHII chart 
    //     encrypted[i] = encrypted[i] - 2;  
    //     decrypted = encrypted; 
    //     cout << "\nThe decrypted message is now: " << decrypted;

    ////////////////////
    // while loop

    // bool done {false};  // gets into the loop the first time
    // int number {0};
    
    // while (!done){  // while this is false...do the rest

    //         cout << "Enter an integer between 1 and 5: "; 
    //         cin >> number;

    //         if (number <= 0 || number >= 6)
    //             cout << "Out of range, try again" << endl;
    //         else {
    //                 cout << "Thanks!" << endl;
    //                 cout << "You number was: " << number << endl;
    //                 done = true;  // set to true when condition is met 
    //         }
    //     cout << "You are now out of the loop" << endl;
    // }

    ////////////////////
    // do while loop

    // selection holds 'q' or 'Q'
    // char selection {};
    
    // do {
    //     cout << "\n-------------------" << endl;
    //     cout << "Choose a number from the choice selection: " << endl;
    //     cout << "1. Do This" << endl;
    //     cout << "2. Do That" << endl;
    //     cout << "3. Do Something else" << endl;
    //     cout << "Q. Quit" << endl;
    //     cout << "Enter you selection: ";
    //     cin >> selection; 
        
    //     if (selection == '1' )
    //         cout << "\nYou chose 1 - Doing this!" << endl;
    //     else if (selection == '2')
    //         cout << "\nYou chose 2 - Doing that!" << endl;
    //     else if (selection == '3')
    //         cout << "\nYou chose 3 - Doing something else!" << endl;
    //     else if (selection == 'Q' || selection == 'q')
    //         cout << "\nGoodbye, program terminating..." << endl;
    //     else 
    //         cout << "\nYou did not make a valid choice - please try again " << endl; 

    // // loop breaks once true
    // } while (selection != 'q' && selection != 'Q'); 


    ////////////////////
    // Range based for loop
    // use these when you need to loop through an array 

    // vector<int> vec1 {1, 3, 5, 15, 16, 17, 18, 19, 20, 21, 25, 26, 27, 30, 50, 55, 56, 58, 100, 200, 300, 400, 500, 600, 700};

    // int count {0};
    
    // for (auto i: vec1) {
    //         if (i % 3 == 0 || i % 5 == 0 ){
    //             cout << i << endl;
    //             ++count;
    //         }
    // }

    return 0; 
}