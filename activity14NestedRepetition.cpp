//
//  activity14NestedRepetition.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 3/8/25.
//

#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;

const int MAX_WIDTH = 40;
const int MAX_HEIGHT = MAX_WIDTH / 2;
void getWidth(int &width) {
    do {
        cout << "Enter width in range: 1-" << MAX_WIDTH << " ";
        cin >> width;
        if (cin.fail() || width < 1 || width > MAX_WIDTH) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Your input is not valid. Please enter an integer between 1 and " << MAX_WIDTH << "." << endl;
        } else {
            break;
        }
    } while (true);
}

void checkerboard(int width) {
    for (int row = 0; row < MAX_HEIGHT; row++) {
        for (int column = 0; column < MAX_WIDTH; column++) {
            if (((row / width) + (column / width)) % 2 == 0) {
                cout << '.';
            } else {
                cout << '*';
            }
        }
        cout << endl;
    }
}

int main() {
    int width;
    getWidth(width);
    checkerboard(width);
    return 0;
}
