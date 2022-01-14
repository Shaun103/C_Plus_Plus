#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

void input_vector(vector<double> &v);
void display_vector(const vector<double> &v);
void check_vector(const vector<double> &v);
void vector_largest(const vector<double> &v);
void vector_smallest(const vector<double> &v);

void input_vector(vector<double> &vec){
    while(true){
        double input{}, SENTINEL {-1}; 
        cout << "Input your data: " << endl;
        cin >> input;
            if (input == SENTINEL)
                break;
            else 
                vec.push_back(input);
        }
            check_vector(vec);
}

void display_vector(const vector<double> &vec){
    cout << "Your input numbers: " << endl; 
    cout << "[ "; 

    for (auto num: vec)
        cout << num << " ";
    cout << " ]" << endl; 
        
    vector_largest(vec);
    cout << "This is also the largest number: " << *max_element(vec.begin(), vec.end()) << endl;
    vector_smallest(vec);
    cout << "This is also the smallest number: " << *min_element(vec.begin(), vec.end()) << endl;
}

void check_vector(const vector<double> &vec){
    if (vec.size() == 0)
        cout << "[] - the list is empty" << endl;
    else 
        display_vector(vec);
}

void vector_largest(const vector<double> &vec){
    int max {};
        for (int i {}; i < vec.size(); i++)
            if (vec[i] > max)
                max = vec[i];
                cout << "Max number is: " << max << endl;
}

void vector_smallest(const vector<double> &vec){
    double min {vec[0]};        
        for (int i{0}; i < vec.size(); i++) 
            if (vec[i] <= min) 
                min = vec[i]; 
        cout << "Min number is: " << min << endl;
}

int main(){
    vector<double> num;
    input_vector(num);
    
    cout << endl;
    return 0; 
}

