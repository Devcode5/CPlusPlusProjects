//
//  randomNumbers.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 4/4/25.

#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); //Generate random numbers
    while (true) { //outer loop
        int number1 = rand() % 12 + 1;
        int number2 = rand() % 12 + 1;
        while (true) { //inner loop
            // Ask the question
            cout << "How much is " << number1 << " times " << number2 << "?";
            // Get the answer
            int answer;
            cin >> answer;
            if (cin.fail()) { //validation with cin.fail
                cin.clear(); // Clear the error flag
                cin.ignore(1000, '\n'); // Discard invalid input
                cout << "Invalid entry. Please enter a number.\n";
                continue;
            }

            if (answer == -1) {             // if user wants to exit
                cout << "Exit!" << endl;
                return 0; // Exit the program
            }
            // if the answer is correct
            if (answer == number1 * number2) {
                cout << "Very good!" << endl;
                break; // Exit inner loop
            } else {
                cout << "Incorrect Answer. Please try again." << endl;
            }
        }
    }
    return 0;
}
    
    
    
    
