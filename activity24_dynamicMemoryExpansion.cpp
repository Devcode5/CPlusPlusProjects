#include <iostream>
#include <string>

using namespace std;

// Constant for initializing values
const string EMPTY_STRING = "";

// Function to expand the array to twice its original size
string* expandArray(string* originalArray, int originalSize) {
    int newSize = originalSize * 2;
    
    // Dynamically allocate new array
    string* expandedArray = new string[newSize];

    // Copy original contents
    for (int i = 0; i < originalSize; i++) {
        expandedArray[i] = originalArray[i];
    }

    // Initialize remaining elements to empty string
    for (int i = originalSize; i < newSize; i++) {
        expandedArray[i] = EMPTY_STRING;
    }

    return expandedArray;
}

int main() {
    const int ORIGINAL_SIZE = 5;

    // Dynamically allocate and initialize original array
    string* originalArray = new string[ORIGINAL_SIZE];
    originalArray[0] = "apple";
    originalArray[1] = "banana";
    originalArray[2] = "cherry";
    originalArray[3] = "date";
    originalArray[4] = "elderberry";

    // Call expandArray function
    string* newArray = expandArray(originalArray, ORIGINAL_SIZE);

    // Calculate new size for printing
    int newSize = ORIGINAL_SIZE * 2;

    // Display contents of new array
    cout << "Expanded array contents:" << endl;
    for (int i = 0; i < newSize; i++) {
        cout << "Index " << i << ": " << newArray[i] << endl;
    }

    // Free allocated memory
    delete[] originalArray;
    delete[] newArray;

    return 0;
}

