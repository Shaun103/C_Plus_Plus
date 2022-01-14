#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  ////////////////////////////////
  // Create and open a text file

  // const char *path = "Files.txt";

  ofstream MyFile("histogramFiles.txt");

  int num_items {0}; // number of input items

  cout << "How many data items do you have?"; 
  cin >> num_items;

  //////////////////////////////////
  // vector to hold each num_items
  vector<int> data {0}; 

  for (int i {1}; i <= num_items; ++i){
      int data_item {0};  // number of data elements
      cout << "Enter data item " << i << ": "; 
      cin >> data_item;
      data.push_back(data_item); 
  }

  // // MyFile - assigns where and what to print to a text file  

  MyFile << "\nDisplaying Histogram" << endl;
      for (auto val : data){                          // outside loop (slow)
          for (int i {1}; i <= val; ++i){             // inside loop (fast)
              if (i % 5 == 0)                         // as long as it is divisible by 5 (equal zero) prints "*"
                  MyFile << "*" << i; 
              else
                  MyFile << "-";                      // everything else will print "-"
          }
          MyFile << endl;
      } 

    // Close the file
    MyFile.close();

  return 0;
}