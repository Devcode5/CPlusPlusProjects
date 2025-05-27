

//  Created by Aqila Nasiry on 4/4/25.

#include <iostream>
using namespace std;

// Function using pointers
int doMultipleThings(int* numx, int* numy) {
    int temp = *numx;
    *numx = (*numy) * 10;
    *numy = temp * 10;

    return *numx + *numy;
}

int main() {
    // Declare two integers
    int x = 5;
    int y = 7;

    // Declare two pointers and point them to x and y
    int* xPtr = &x;
    int* yPtr = &y;

    // Call the function with pointers
    int result = doMultipleThings(xPtr, yPtr);

    // Display the return value
    cout << "Return value: " << result << endl;

    // Display the contents of the memory locations xPtr and yPtr points to
    cout << "Value pointed by xPtr: " << *xPtr << endl;
    cout << "Value pointed by yPtr: " << *yPtr << endl;

    return 0;
}



