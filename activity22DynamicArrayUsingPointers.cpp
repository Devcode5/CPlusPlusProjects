//
//  activity22DynamicArrayUsingPointers.cpp
//  C++Projects
// Created by Aqila Nasiry on 4/6/25.



#include <stdio.h>
#include <iostream>
using namespace std;
const int ARRAY_SIZE = 10;
double* reverseArray(double* firstArray, int size) {
    double* reversedArray = new double[size];
    for (int i = 0; i < size; i++) {
        reversedArray[i] = firstArray[size - 1 - i];
    }
    // Deallocation
    delete[] firstArray;
    return reversedArray;
}
int main() {
    // Dynamically allocation
    double* numbers = new double[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = (i + 1) * 1.0;
    }
    numbers = reverseArray(numbers, ARRAY_SIZE);
    cout << "Here is the reversed array:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    // Cleaning up memory
    delete[] numbers;
    return 0;
}









