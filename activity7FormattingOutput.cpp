//
//  activity7FormattingOutput.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 2/21/25.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
using namespace std;

int main() {

    // Constants

    const double STATE_TAX_RATE = 0.04;
    const double COUNTY_TAX_RATE = 0.02;
    const double TOTAL_TAX_RATE = 1.06;
    // Variables

    string month;
    int year;
    double totalCollected, sales, stateSalesTax, countySalesTax, totalSalesTax;
    // Input

    cout << "Enter the month: ";
    cin >> month;
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter total amount collected: $";
    cin >> totalCollected;
    // Calculations

    sales = totalCollected / TOTAL_TAX_RATE;
    stateSalesTax = sales * STATE_TAX_RATE;
    countySalesTax = sales * COUNTY_TAX_RATE;
    totalSalesTax = stateSalesTax + countySalesTax;
    // Output
    cout << fixed << setprecision(2);
    cout << "\nReporting period:      " << month << " " << year << endl;
    cout << "------------------------------------" << endl;
    cout << left << setw(25) << "Total Collected:" << "$" << right << setw(10) << totalCollected << endl;
    cout << left << setw(25) << "Sales:" << "$" << right << setw(10) << sales << endl;
    cout << left << setw(25) << "County Sales Tax:" << "$" << right << setw(10) << countySalesTax << endl;
    cout << left << setw(25) << "State Sales Tax:" << "$" << right << setw(10) << stateSalesTax << endl;
    cout << left << setw(25) << "Total Sales Tax:" << "$" << right << setw(10) << totalSalesTax << endl;
    return 0;

}
