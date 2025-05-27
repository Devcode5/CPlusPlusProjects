
//  activity19TwoDimensionalArray.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 4/1/25.

#include "activity19TwoDimensionalArray.hpp"
#include <iostream>
using namespace std;
const int MAX_ROWS = 6;
const int MAX_COLUMNS = 10;

void arraya(int twod[][MAX_COLUMNS], int rows, int columns);
void arrayb(int twod[][MAX_COLUMNS], int rows, int columns);
void arrayc(int twod[][MAX_COLUMNS], int rows, int columns);
void arrayd(int twod[][MAX_COLUMNS], int rows, int columns);
void arraye(int twod[][MAX_COLUMNS], int rows, int columns);

int main()
{
    int box[MAX_ROWS][MAX_COLUMNS] = {
        {8, 0, 3, 6, 3, 1, 3, 1, 0, 7},
        {2, 7, 9, 4, 5, 9, 1, 2, 3, 9},
        {8, 1, 2, 0, 3, 7, 3, 1, 9, 6},
        {5, 4, 9, 7, 2, 1, 8, 7, 3, 0},
        {9, 1, 3, 4, 0, 6, 5, 7, 3, 5},
        {4, 0, 6, 5, 4, 9, 7, 2, 7, 0}
    };

    arraya(box, MAX_ROWS, MAX_COLUMNS);
    arrayb(box, MAX_ROWS, MAX_COLUMNS);
    arrayc(box, MAX_ROWS, MAX_COLUMNS);
    arrayd(box, MAX_ROWS, MAX_COLUMNS);
    arraye(box, MAX_ROWS, MAX_COLUMNS);

    return 0;
}

void arraya(int twod[][MAX_COLUMNS], int rows, int columns)
{
    int row, col;
    for (col = 0; col < columns; col++) {
        for (row = 0; row < rows; row++) {
            cout << " " << twod[row][col];
        }
        cout << endl;
    }
}

// Function to display the array in row-major order
void arrayb(int twod[][MAX_COLUMNS], int rows, int columns)
{
    int row, col;
    for (row = 0; row < rows; row++) {
        for (col = 0; col < columns; col++) {
            cout << " " << twod[row][col];
        }
        cout << endl;
    }
}

void arrayc(int twod[][MAX_COLUMNS], int rows, int columns)
{
    int row, col;
    for (col = columns - 1; col >= 0; col--) {
        for (row = 0; row < rows; row++) {
            cout << " " << twod[row][col];
        }
        cout << endl;
    }
}

void arrayd(int twod[][MAX_COLUMNS], int rows, int columns)
{
    int row, col;
    for (row = rows - 1; row >= 0; row--) {
        for (col = 0; col < columns; col++) {
            cout << " " << twod[row][col];
        }
        cout << endl;
    }
}

void arraye(int twod[][MAX_COLUMNS], int rows, int columns)
{
    int row, col;
    for (row = 0; row < rows; row++) {
        for (col = (row % 2 == 0) ? 0 : columns - 1;
             (row % 2 == 0) ? col < columns : col >= 0;
             (row % 2 == 0) ? col++ : col--)
        {
            cout << " " << twod[row][col];
        }
        cout << endl;
    }
}
















