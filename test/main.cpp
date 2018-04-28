#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

bool testMyResult(int * realResults, int * myResults, int n) 
{
    for (int i = 0; i < n; i++) {
        if (realResults[i] != myResults[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream input;
    int n = 0;
    string str = "";
    string outputFileName = "";
    cout << "Enter input dir (fileName): ";
    cin >> outputFileName;
    input.open(outputFileName);
    ifstream outPut;
    string outPutFileName = "";
    cout << "Enter output dir (fileName): ";
    cin >> outPutFileName;
    getline(input, str);
    n = stoi(str);
    vector<long long int> myResult;
    vector<int> heights;
    getline(input, str);
    stringstream nums(str);
    if (input.is_open()) {
        for (int i = 0; i < n; i++) {
        int tmp = 0;
        nums >> tmp;
        heights.push_back(tmp);
    }
    }else {
        cout << "Can't open input file !!!";
    }
    long long int  coefficient = 0;  
    for(int i = 0; i < n-1; i++){
        coefficient += abs(heights.at(i) - heights.at(i+1));
    }
    cout << "\n";
    for(int i = 0; i < n; i++){
        long long int currentCoeficient = -1;
        for(int j = 0; j < n; j++){
            int leftFprev = 0; int leftFnext = 0; int leftSprev = 0; int leftSnext = 0;
            int rightFprev = 0; int rightFnext = 0; int rightSprev = 0; int drightSnext = 0;
            if ( i != n -1 ) {
                leftFprev = abs( heights.at(i) - heights.at(i+1) );
                if ( j - i != 1) {
                    rightFprev = abs( heights.at(j) - heights.at(i+1) );
                } else {
                    rightFprev = abs( heights.at(j) - heights.at(i) );
                }
            }
            if ( i != 0) {
                leftFnext = abs( heights.at(i-1) - heights.at(i) );
                if ( i-j != 1) {
                    rightFnext = abs( heights.at(i-1) - heights.at(j) );
                } else {
                    rightFnext = abs( heights.at(i) - heights.at(j) );
                }
            }
            if (j != n-1 ) {
                leftSprev   = abs( heights.at(j) - heights.at(j+1) );
                if ( i - j != 1 )  {
                    rightSprev   = abs( heights.at(i) - heights.at(j+1) );
                 } else {
                    rightSprev   = abs( heights.at(i) - heights.at(j) );
                 }
            }
            if ( j != 0) {
                leftSnext   = abs( heights.at(j-1) - heights.at(j) );
                if ( j- i !=1 ) {
                    drightSnext   = abs( heights.at(j-1) - heights.at(i) );
                } else {
                    drightSnext   = abs( heights.at(j) - heights.at(i) );
                }
            } 
            long long int newCoefficient = coefficient; 
            int addition = rightFprev + rightFnext + rightSprev + drightSnext;
            int offset = leftFprev + leftFnext + leftSprev + leftSnext;
            newCoefficient = newCoefficient - offset + addition;
            if ( currentCoeficient == -1) {
                currentCoeficient = newCoefficient;
            } else if (currentCoeficient > newCoefficient) {
                currentCoeficient = newCoefficient;
            }
        }
        myResult.push_back(currentCoeficient);
    }
    input.close();
    int myResultArr[n];
    cout << "----------------My results----------------------\n";
    int i = 0;
    for (int el : myResult) {
        cout << el;
        cout << " ";
        myResultArr[i] = el;
        i++;
    }
    cout << "\n";
    outPut.open(outPutFileName);
    int realResults[n];
    if (outPut.is_open()) {
        cout << "----------------Real results----------------------\n";
        for (int i = 0; i < n; i++) {
            string line;
            getline(outPut, line);
            int currentInteget = stoi(line);
            realResults[i] = currentInteget;
            cout << realResults[i] << " ";
        }
    } else {
        cout << "Can't open output file !!!";
    }
    cout << "\n";
    if (testMyResult(realResults, myResultArr, n)) {
        cout << "---------------Test Passed !!!----------------------";
    } else {
        cout << "---------------Test Failed !!!----------------------";
    }
    return 0;
}



