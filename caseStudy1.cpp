
//  caseStudy1.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 4/8/25.


#include <stdio.h>
#include<iostream>
using namespace std;

int main(){
    
    double volume, cost, customerCharge, profit,length, width, height;
    
    const double COST_PER_CUBIC_FOOT = 0.23;
    const double CHARGE_PER_CUBIC_FOOT = 0.5;
    
    
    
    cout << "Please enter the dimensions of the crate\n--------------------------------\n";
    cout << "Enter the length: ";
    cin>>length;
    cout << "Enter the width: ";
    cin >> width;
    cout << "Enter the height: ";
    cin >> height;
    
    volume = length * width * height;
    cost = volume * COST_PER_CUBIC_FOOT;
    customerCharge = volume * CHARGE_PER_CUBIC_FOOT;
    profit = customerCharge - cost;
    
    cout << "The volume is: " << volume<< " cubic foot"<< endl;
    cout << "Cost to build is: $" << cost<< endl;
    cout << "The customer charge is: $" << customerCharge<< endl;
    cout << "The profit is: $" << profit<< endl;
    
    
    return 0;
}
