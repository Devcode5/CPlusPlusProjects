//
//  activity9ColorMixer.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 2/25/25.
//

#include <stdio.h>
#include <iostream>

#include <string>
using namespace std;
int main() {

   string color1, color2;
    // asking user for input

    cout << "Enter the first color (red, blue, yellow): ";
    cin >> color1;
    cout << "Enter the second color (red, blue, yellow): ";
    cin >> color2;

    if ((color1 != "red" && color1 != "blue" && color1 != "yellow") ||

        (color2 != "red" && color2 != "blue" && color2 != "yellow")) {

        cout << "Invalid color entered. Please enter only primary colors (red, blue, or yellow).\n";

    }

else {

        if ((color1 == "red" && color2 == "blue") || (color1 == "blue" && color2 == "red")) {
            cout << "Mixing red and blue gives purple.\n";
        } else if ((color1 == "red" && color2 == "yellow") || (color1 == "yellow" && color2 == "red")) {
            cout << "Mixing red and yellow gives orange.\n";
        } else if ((color1 == "blue" && color2 == "yellow") || (color1 == "yellow" && color2 == "blue")) {
            cout << "Mixing blue and yellow gives green.\n";

        }
    }
    return 0;
}
