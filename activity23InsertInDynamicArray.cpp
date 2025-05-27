

//Keep the array compact
//helpfull for assignment 9
////  Created by Aqila Nasiry on 4/7/25.
//
#include <iostream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 8;

// This function is to insert an item into the array
bool insertAt(string *p, string item, int index, int count) {
    // first we will check if index is valid and if there is room in the array
    if (count >= ARRAY_SIZE || index < 0 || index > count) {
        return false;
    }

    // Here we are moving elements one position to the right, starting from the end
    for (int i = count; i > index; i--) {
        p[i] = p[i - 1];
    }
    p[index] = item;

    return true;
}

int main() {
    // Dynamically create array of size 8
    string *myArray = new string[ARRAY_SIZE];
    int elementCount = 0;

    // Insert at index 0 (insertAtZero)
    if (insertAt(myArray, "Books", 0, elementCount)) {
        elementCount++;
    }

    // Insert at the end (insertAtEnd)
    if (insertAt(myArray, "Pens", elementCount, elementCount)) {
        elementCount++;
    }

    // Insert in the middle (insertAtIndex)
    if (insertAt(myArray, "Notebooks", 1, elementCount)) {
        elementCount++;
    }

    // Print the array contents up to elementCount
    cout << "Here we can see the final array contents after insertion: ";
    for (int i = 0; i < elementCount; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // we should free dynamically allocated memory
    delete[] myArray;

    return 0;
}




