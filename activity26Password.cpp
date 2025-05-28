//
//Activity 26: Password: C-Strings and Char Functions//  C++Projects

#include <stdio.h>
//  Created by Aqila Nasiry on 4/18/25.

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


const int SIZE = 25;

string checkPassword(const char password[]) {

    //int length = strlen(password);  // Get the length of the password using strlen()
    int length = strlen(password);

    // with these booleans we make sure the password is based on requirements
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;
    bool hasSpace = false;

    // this loop is to check every character of the entered password
    for (int i = 0; i < length; i++) {
        if (isspace(password[i])) hasSpace = true;
        if (isupper(password[i])) hasUpper = true;
        if (islower(password[i])) hasLower = true;
        if (isdigit(password[i])) hasDigit = true;
        if (password[i] == '$' || password[i] == '#' || password[i] == '!' || password[i] == '@') hasSpecialChar = true;
    }

    if (length < 10)
        return "Your entry is too short, password must be at least 10 characters long.";
    if (hasSpace)
        return  "Your password should not contain any spaces.";
    if (!hasUpper || !hasLower)
        return "Password needs at least one uppercase/lowercase letter.";

    if (!hasDigit)
        return "Password needs at least one number.";
    if (!hasSpecialChar)
        return "Password needs at least one special character: !, #, $, @.";

    return "Strong password.";

}

int main() {
    char password[SIZE];
   // string message;

    cout << "Enter a password: ";
    cin.getline(password, SIZE);

    string output = checkPassword(password);
    cout << output << endl;

    return 0;

}
