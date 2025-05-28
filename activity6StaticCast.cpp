
//  staticCast.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 4/7/25.



#include <iostream>
using namespace std;



//1 acre = 43,560 square feet

int main(){
    const int SQ_FEET_ACRE = 43500;
    int land;
    double total;
    
    cout<< "enter total square feet in a piece of land: \n";
     cin>> land;
    
    //user inputs an integer so we should convert it in double to have best resutls.

    total = static_cast<double>(land) / SQ_FEET_ACRE;
    cout << "Here is the total: " << total << endl;
    
    
    
    return 0;
    

    
}
