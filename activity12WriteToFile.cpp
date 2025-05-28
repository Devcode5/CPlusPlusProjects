//
//  activity12WriteToFile.cpp
//  C++Projects


#include <stdio.h>
//
/******************  Created by Aqila Nasiry on 3/4/25. *********************/
//

#include <iostream>
#include <fstream>  // For file operations
#include <limits>   // For numeric_limits

using namespace std;

// Named constants
const int MINIMUM_INPUT = 10;
const int MAXIMUM_INPUT = 30;

int main() {
    // Declare the necessary variables
    int userInput;
    char userSelections = 'y'; // Initialize with 'y' to enter the loop

    // Create an ofstream object (file stream)
    ofstream outFile;

    // Base on the requirement open the file "output.txt" using file.open()
    outFile.open("output.txt");

    if (!outFile) {
        cout << "Error opening the file." << endl;
        return 1;  // Exit
    }

    while (userSelections == 'y' || userSelections == 'Y') {
        bool validInput = false;  // Flag to track valid input

        while (!validInput) {                 // Input validation
            cout << "Enter an integer between " << MINIMUM_INPUT << " & " << MAXIMUM_INPUT << ": ";
            cin >> userInput;

            // Check for any invalid inputs
            if (cin.fail() || userInput < MINIMUM_INPUT || userInput > MAXIMUM_INPUT) {
                cout << "That is not valid. Can you please enter a valid integer between "
                     << MINIMUM_INPUT << " and " << MAXIMUM_INPUT << "." << endl;

                cin.clear();
                cin.ignore(100, '\n');
            } else {
                validInput = true;
            }
        }

        // Write the valid input to the file
        outFile << userInput << endl;

        // Ask the user if they want to continue
        cout << "Do you wish continue entering another number? (y/n): ";
        cin >> userSelections;
    }

    // Close file
    outFile.close();

    cout << "Finished,your file has been saved." << endl;

    return 0;
}
