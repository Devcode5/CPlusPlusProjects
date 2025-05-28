//
//  activity8MobileServiceProvider.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 2/22/25.
//
#include <iostream>
#include <iomanip>
using namespace std;
int main() {

    // Named constants for package prices and data limits

    const double PAC_A_Cost = 39.99;

    const double PACKAGE_A_LIMIT = 4.0;

    const double PACKAGE_A_EXTRA_COST = 10.0;
    const double PACKAGE_B_COST = 59.99;
    const double PACKAGE_B_LIMIT = 8.0;
    const double PACKAGE_B_EXTRA_COST = 5.0;
    const double PACKAGE_C_COST = 69.99; // Unlimited data
    // Variables
    char packageType;
    double gigabytesUsed;
    double totalCost = 0.0;
    // User input
    cout << "Enter the package type (A, B, or C): ";
    cin >> packageType;
    // Validate input
    if (packageType != 'A' && packageType != 'B' && packageType != 'C' &&

        packageType != 'a' && packageType != 'b' && packageType != 'c') {

        cout << "Invalid package type. Please enter A, B, or C." << endl;

        return 1;

    }

    

    cout << "Enter the number of gigabytes used: ";

    cin >> gigabytesUsed;

    

    // Calculate the total bill based on the package selected

    switch (toupper(packageType)) {

        case 'A':

            totalCost = PAC_A_Cost;

            if (gigabytesUsed > PACKAGE_A_LIMIT) {

                totalCost += (gigabytesUsed - PACKAGE_A_LIMIT) * PACKAGE_A_EXTRA_COST;

            }

            break;

        

        case 'B':

            totalCost = PACKAGE_B_COST;

            if (gigabytesUsed > PACKAGE_B_LIMIT) {

                totalCost += (gigabytesUsed - PACKAGE_B_LIMIT) * PACKAGE_B_EXTRA_COST;
            }

            break;
        case 'C':
            totalCost = PACKAGE_C_COST;
            break;
    }

    // Display the total cost
    cout << fixed << setprecision(2);
    cout << "Total amount due: $" << totalCost << endl;
    return 0;
}
