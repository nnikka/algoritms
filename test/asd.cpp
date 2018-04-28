/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;




int main()
{
     ifstream input;
    ofstream output;
    int size = 0;
    string str = "";
    cout << "enter input filename";
    cin >> str;
    input.open(str);
    cout << "enter output filename";
    cin >> str;
    output.open(str);
    getline(input, str);
    size = stoi(str);
    vector<int> array;
    vector<long long int> result;
    getline(input, str);
    stringstream nums(str);
    for (int i = 0; i<size; i++) {
        int tmp = 0;
        nums >> tmp;
        array.push_back(tmp);
    }
    
    
    long long int  coeff = 0;  
    for(int i=0; i<size-1; i++){
        coeff += abs(array.at(i) - array.at(i+1));
    }
  


    for(int i=0; i<size; i++){
        long long int minimal = -1;
        for(int j=0; j<size; j++){
            int initFirstPrev = 0;
            int initFirstNext = 0;
            int initSecPrev = 0;
            int initSecNext = 0;
            
            int lastFirstPrev = 0;
            int lastFirstNext = 0;
            int lastSecPrev = 0;
            int lastSecNext = 0;
             
                if( i != size -1 ){
                    initFirstPrev = abs( array.at(i) - array.at(i+1) );
                    if( j - i != 1) lastFirstPrev = abs( array.at(j) - array.at(i+1) );
                    else lastFirstPrev = abs( array.at(j) - array.at(i) );
                }
                if( i != 0){
                    initFirstNext = abs( array.at(i-1) - array.at(i) );
                    if( i-j != 1) lastFirstNext = abs( array.at(i-1) - array.at(j) );
                    else lastFirstNext = abs( array.at(i) - array.at(j) );
                }
                if (j != size-1 ){
                    initSecPrev   = abs( array.at(j) - array.at(j+1) );
                    if( i - j != 1 )  lastSecPrev   = abs( array.at(i) - array.at(j+1) );
                    else lastSecPrev   = abs( array.at(i) - array.at(j) );
                } 
                if( j != 0){
                    initSecNext   = abs( array.at(j-1) - array.at(j) );
                    if( j- i !=1 ) lastSecNext   = abs( array.at(j-1) - array.at(i) );
                    else lastSecNext   = abs( array.at(j) - array.at(i) );
                } 
                
            int min = initFirstPrev + initFirstNext + initSecPrev + initSecNext;
            int plus = lastFirstPrev + lastFirstNext + lastSecPrev + lastSecNext;
            long long int tmp = coeff; 
            tmp = tmp - min + plus;
            
            if( minimal == -1){
                minimal = tmp;
            }else if(minimal > tmp){
                minimal = tmp;
            }
        }
        result.push_back(minimal);
    }
   
    for (int el : result) output << el << "\n";
    
    output.close();
    input.close();
    
    return 0;
}



