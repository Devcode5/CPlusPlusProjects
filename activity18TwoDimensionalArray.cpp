//
 // twoDimensionalArray.cpp
 // C++Projects

 // Created by Aqila Nasiry on 3/28/25.


//foucs is on functions, can use initialization list or another function.

//#include "twoDimensionalArray.hpp"
#include <iostream>
#include <climits>
using namespace std;
const int COLUMNS = 4;
int getTotal(const int array[][COLUMNS], int rows);
double getAverage(const int array[][COLUMNS], int rows);
int getRowTotal(const int array[][COLUMNS], int row);
int getColumnTotal(const int array[][COLUMNS], int column, int rows);
int getHighestInRow(const int array[][COLUMNS], int row);
int getLowestInRow(const int array[][COLUMNS], int row);
int main() {
    const int ROWS = 3;
    int testArray[ROWS][COLUMNS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    cout << "Here is the total of array elements: " << getTotal(testArray, ROWS) << endl;
    cout << "Here is the average of all elements: " << getAverage(testArray, ROWS) << endl;
    cout << "\nRow totals:" << endl;
    for (int row = 0; row < ROWS; row++) {
        cout << "Row " << row << " total: " << getRowTotal(testArray, row) << endl;
    }
    cout << "\nColumn totals:" << endl;
    for (int col = 0; col < COLUMNS; col++) {
        cout << "Column " << col << " total: " << getColumnTotal(testArray, col, ROWS) << endl;
    }
    cout << "\nHighest in each row:" << endl;
    for (int row = 0; row < ROWS; row++) {
        cout << "Row " << row << " highest: " << getHighestInRow(testArray, row) << endl;
    }
    cout << "\nLowest in each row:" << endl;
    for (int row = 0; row < ROWS; row++) {
        cout << "Row " << row << " lowest: " << getLowestInRow(testArray, row) << endl;
    }
    return 0;
}
int getTotal(const int array[][COLUMNS], int rows) {
    int total = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            total += array[i][j];
        }
    }
    return total;
}
double getAverage(const int array[][COLUMNS], int rows) {
    int total = getTotal(array, rows);
    return static_cast<double>(total) / (rows * COLUMNS);
}
int getRowTotal(const int array[][COLUMNS], int row) {
    int total = 0;
    for (int j = 0; j < COLUMNS; j++) {
        total += array[row][j];
    }
    return total;
}
int getColumnTotal(const int array[][COLUMNS], int column, int rows) {
    int total = 0;
    
    for (int i = 0; i < rows; i++) {
        total += array[i][column];
    }
    return total;
}
int getHighestInRow(const int array[][COLUMNS], int row) {
    int highest = INT_MIN;
    
    for (int j = 0; j < COLUMNS; j++) {
        if (array[row][j] > highest) {
            highest = array[row][j];
        }
    }
    return highest;
}
int getLowestInRow(const int array[][COLUMNS], int row) {
    int lowest = INT_MAX;
    
    for (int j = 0; j < COLUMNS; j++) {
        if (array[row][j] < lowest) {
            lowest = array[row][j];
        }
    }
    
    return lowest;
}
