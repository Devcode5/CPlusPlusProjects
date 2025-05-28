//
//  activity28Structures.cpp
//  C++Projects
//
//

#include <stdio.h>
//Aqila Nasiry
/* passing a structure and structure pointers to functions,
 accessing structure contents via pointers
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int MIN_LIST = 3;

struct Numlist {
    float *list;   /* list of values - must be dynamically allocated */
    int   len;     /* count of values in list   */
    float min,     /* the minimal value in list */
          max,     /* the maximal value in list */
          avg;     /* the mean of the numbers   */
};

void getInput(Numlist& numList) {
    cout << "Enter the number of elements (minimum " << MIN_LIST << "): ";
    cin >> numList.len;

    while (numList.len < MIN_LIST) {

        cout << "Length must be at least " << MIN_LIST << ". Please enter again: ";

        cin >> numList.len;

    }

    numList.list = new float[numList.len];

    cout << "Enter " << numList.len << " numbers:\n";
    for (int i = 0; i < numList.len; i++) {
        cout << "Value " << (i + 1) << ": ";
        cin >> numList.list[i];
    }
}


void compute(Numlist& numList) {
    numList.min = numList.list[0];
    numList.max = numList.list[0];
    float total = 0.0f;
    for (int i = 0; i < numList.len; i++) {
        if (numList.list[i] < numList.min) {
            numList.min = numList.list[i];

        }
        if (numList.list[i] > numList.max) {
            numList.max = numList.list[i];

        }

        total += numList.list[i];
    }

    numList.avg = total / numList.len;
}

void display(const Numlist& numList) {

    cout << fixed << setprecision(2);
    cout << "List of numbers: ";
    for (int i = 0; i < numList.len; i++) {
        cout << numList.list[i] << " ";

    }

    cout << endl;
    cout << "Minimum: " << numList.min << endl;
    cout << "Maximum: " << numList.max << endl;
    cout << "Average: " << numList.avg << endl;

}

int computeStats(Numlist* listPtr) {
    if (listPtr == nullptr) {
        return -1;

    }

    if (listPtr->list == nullptr) {
        return -2;
    }
    if (listPtr->len <= 0) {
        return -3;

    }

    compute(*listPtr);
    return 0;

}

int main() {
    Numlist numbers;
    getInput(numbers);
    int result = computeStats(&numbers);

    if (result == 0) {
        display(numbers);
    } else {
        cout << "Error: ";

        if (result == -1) {

            cout << "Null value received." << endl;

        } else if (result == -2) {

            cout << "Number list pointer is null." << endl;

        } else if (result == -3) {

            cout << "Invalid length." << endl;

        }
    }

    delete[] numbers.list;

    return 0;

}
