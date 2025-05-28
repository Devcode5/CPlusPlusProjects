//
//  activity13OverloadedFunction.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 3/7/25.
//

#include <stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;

const double MIN_CHARGES= 0.0;
double totalCharges(int days, double rate, double medCharges, double services);
double totalCharges(double medical, double services);
bool inputValidation(double value);

int main(){
    //variables declaration and initialization
    int days=0;
    char category;
    double rate=0.0, medCharges=0.0, services=0.0, total=0.0;
    cout << "This program is to calculate charges for a patient’s hospital stay\n------------------------------------------------------------------\n";
    cout << "Are you registered as inpatient or outpatient? For inpatient press 1, otherwise 2: ";
    cin >> category; // will take patient type
    category= toupper(category); //Toupper calss converts lowercase letter to uppercase
    // Input validation for patient type
    while (toupper(category) != '1' && toupper(category) != '2') {
        cout << "Your input is invalid. Enter 1 for inpatient or 2 for outpatient: ";
        cin >> category;
    }
    if (toupper(category) == '1'){
        cout << "Enter the number of days spent in the hospital: ";
        cin >> days;
        while(!inputValidation(days)) {
            cout << " Your input is invalid. You cannot enter negative numbers for days. Try again ";
            cin >> days;
        }
       cout << "Enter every day rate:$";
        cin >> rate;
        while (!inputValidation(rate)) {
            cout << "Your input is invalid. Rate cannot be negative. Try again: $";
            cin >> rate;
        }

        cout << "Enter medication charges: $";
        cin >> medCharges;
        while (!inputValidation(medCharges)) {
            cout << "Your input is invalid. You should not enter a negative number for medication charges. Try again: $";
            cin >> medCharges;
        }
       cout << "Enter hospital services charges: $";
        cin >> services;
        while (!inputValidation(services)) {
            cout << "Your input is invalid. You should not enter a negative number for services. Try again: $";
            cin >> services;
        }
       total = totalCharges(days, rate, medCharges, services);
    }

    

    else{ //here we take data for outpatients
        cout << "Enter medication charges: $";
        cin >> medCharges;
        while (!inputValidation(medCharges)) {
            cout << "Your input is invalid. You should not enter a negative number for medication charges. Try again: $";
            cin >> medCharges;
        }

        cout << "Enter hospital services charges: $";
        cin >> services;
        while (!inputValidation(services)) {
            cout << "Your input is invalid. You should not enter a negative number for services. Try again: $";
            cin >> services;
        }
        total = totalCharges(medCharges, services);
    }

        cout << fixed << setprecision(2); // how to display the output
        cout << "Here is the total charges for your stay at the hospital: $" << total << endl;
        return 0;
    }

double totalCharges(int days, double rate, double medCharges, double services) {  //this is an overloaded function to calculate total charges for inpatient
    return (days * rate) + medCharges + services;

}

double totalCharges(double medCharges, double services){   //this is an overloaded function to calculate total charges for outpatient
    return medCharges + services;
}
bool inputValidation(double value){ // validation of the input using that functiion
    return value >= MIN_CHARGES;
}
