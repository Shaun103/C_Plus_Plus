// C++ Program to Merge Two Arrays
// ---codescracker.com---

#include<iostream>
using namespace std;

int main()
{
    int arry1[50], arr2[50], arr3[100];
    int arrySize1, arrySize2, k, i;

    // Creating arry 1 
    cout << "\nEnter Size for arry1: " << endl;
    cin >> arrySize1;
    cout << "Enter " << arrySize1 << " Elements for First Array: " << endl;
    for (i = 0; i < arrySize1; i++){
        cin >> arry1[i];
        arr3[i] = arry1[i];
    }
        
    k = arrySize1; // get the length of the first arry
    
    // Creating arry 2
    cout << "\nEnter Size for arry2: " << endl;
    cin >> arrySize2;
    cout << "Enter " << arrySize2 << " Elements for Second Array: " << endl;
    for (i = 0; i < arrySize2; i++){
        cin >> arr2[i];
        arr3[k] = arr2[i];
        k++; // adds length of first arry with the second arry 
    }

    // merging arry 1 and arry 2
    cout<<"\nThe New Array (Merged Array):\n";
    for(i = 0; i < k; i++)
        cout << arr3[i] << " ";
    cout << endl;


    return 0;
}