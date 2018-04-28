#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int size;
    string charachter;
    string charachters;
    string result;
    bool isOpen = false;
    
    cin>>size;
    
    for (int i = 0; i < size; i++) {
        cin>>charachter;
        charachters += charachter;
    }
    
    for (int i = 0; i < size; i++) {
        if (charachters[i] == '-' && !isOpen) {
            result += "-";
        }
        else if (charachters[i] == '-' && isOpen) {
            result += ")-";
            isOpen = false;
        }
        else if (charachters[i] == '+' && !isOpen) {
            result += "(-";
            isOpen = true;
        }
        else if (charachters[i] == '+' && isOpen) {
            result += "-";
        }
    }
    
    if (isOpen) {
        result += ")";
    }
    
    cout << result;
    return 0;
}



