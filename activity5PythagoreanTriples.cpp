//
//  pythagoreanTriples.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 4/7/25.


#include <iostream>
using namespace std;

int main() {
    
    int m , n;
    cout << "Pythagorean Triple\n----------------------------\n";
    cout << "Enter first number: ";
    cin >> m;
    
    cout << "Enter second number: ";
    cin >> n;
    
    int side1 = pow(m, 2.0) - pow(n, 2.0);
    int side2 = 2*m*n;
    int hypotenuse = sqrt(pow(side1, 2.0) + pow(side2, 2.0));
    
    cout << "Here is the triples: " << endl;
    cout << "Side 1 is: " << side1<< endl;
    cout << "Side 2 is: " << side2 << endl;
    cout << "Side 3(Hypotenuse) is: "<< hypotenuse << endl;
    

    return 0;
}
