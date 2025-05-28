//
//  activity17OneDimensionalArray.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 3/15/25.
//

#include <stdio.h>
#include <iostream>

#include <sstream>
// size of the array
const int ARRAY_SIZE = 6;
using namespace std;
// Function to populate the array
void populateArray(int arr[], int size) {
    cout << "Please enter " << size << " integers separated by spaces:\n";
    string input;
    getline(cin, input);
    istringstream stream(input);
    for (int i = 0; i < size; i++) {
        stream >> arr[i];
    }

}
// Function to find the second smallest number in the array
int findSecondSmallest(int arr[], int size) {
    if (size < 6) {
        // If array has fewer than 2 elements, return an invalid value
        cout << "Array must have at least two elements to find the second smallest number." << endl;
        return -1;

    }

    int smallest = arr[0];
    int secondSmallest = arr[1];
    if (smallest > secondSmallest) {
        swap(smallest, secondSmallest);
    }
    // Here we have to loop through the rest of the array to find the second smallest number
    for (int i = 2; i < size; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    return secondSmallest;
}

int main() {
    // Array declaration
    int numbers[ARRAY_SIZE];

    // Here we populate the array with numbers entered by user
    populateArray(numbers, ARRAY_SIZE);
    // Output the entered array
    cout << "Entered numbers: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    // Here we find the second smallest number in the array and display it
    int secondSmallest = findSecondSmallest(numbers, ARRAY_SIZE);
    if (secondSmallest != -1) {
        cout << "The second smallest number is: " << secondSmallest << endl;
    }
    return 0;
}
