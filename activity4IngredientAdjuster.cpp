//
//  activity4IngredientAdjuster.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 1/30/25.
//

#include <iostream>
using namespace std;

int main() {
    // named constants for the original recipe
    const double SUGAR_PER_COOKIE = 1.5;
    const double BUTTER_PER_COOKIE = 1.0;
    const double FLOUR_PER_COOKIE = 2.75;

   // The recipe produces 48 cookies
    const int NUM_ORIGINAL_COOKIES = 48;

    // we need a variable for the number of cookies
    int numCookies;

    cout << "Enter the number of cookies you want: ";
    cin >> numCookies;

    // we are calculating the ingredients after the user input
    double sugar = (SUGAR_PER_COOKIE / NUM_ORIGINAL_COOKIES) * numCookies;
    double butter = (BUTTER_PER_COOKIE / NUM_ORIGINAL_COOKIES) * numCookies;
    double flour = (FLOUR_PER_COOKIE / NUM_ORIGINAL_COOKIES) * numCookies;

    // Display the results
    cout << "To make " << numCookies << " cookies, you will need:" << endl;
    cout << "Sugar: " << sugar << " cups" << endl;
    cout << "Butter: " << butter << " cups" << endl;
    cout << "Flour: " << flour<< " cups" << endl;

    return 0;
}
