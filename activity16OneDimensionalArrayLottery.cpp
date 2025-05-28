//
//  activity16OneDimensionalArrayLottery.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 3/16/25.
//

#include <stdio.h>
#include <iostream>

#include <cstdlib>

#include <ctime>

using namespace std;

const int NUM_DIGITS = 5;

int main() {

    int lottery[NUM_DIGITS], user[NUM_DIGITS];

    int matchingDigits = 0;

    srand(static_cast<unsigned int>(time(0)));

    // random numbers[range 0-9]

    for (int i = 0; i < NUM_DIGITS; i++) {

        lottery[i] = rand() % 10;  // Generates a random number between 0 and 9

    }

    // ask user to enter their lottery numbers

    cout << "Please enter five digits between (0-9): ";

    for (int i = 0; i < NUM_DIGITS; i++) {

        cin >> user[i];

    }

    for (int i = 0; i < NUM_DIGITS; i++) {

        if (lottery[i] == user[i]) {

            matchingDigits++;

        }

    }

    // Display the lottery numbers

    cout << "Lottery numbers: ";

    for (int i = 0; i < NUM_DIGITS; i++) {

        cout << lottery[i] << " ";

    }

    cout << endl;

    // Display the number of matching digits

    cout << "You have " << matchingDigits << " matching digit(s)." << endl;

    // Check if the user is the grand prize winner

    if (matchingDigits == NUM_DIGITS) {

        cout << "Congratulations! You are the grand prize winner!" << endl;

    }

    return 0;

}
