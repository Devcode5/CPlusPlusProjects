//
//  magicSquare.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 3/25/25.
//

//#include "magicSquare.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

const int SIZE = 3;

bool isLoShuMagicSquare(const int square[SIZE][SIZE]) {
    vector<int> numbers;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (square[i][j] < 1 || square[i][j] > 9) {
                return false;
            }
            numbers.push_back(square[i][j]);
        }
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < 9; i++) {
        if (numbers[i] != i + 1) {
            return false;
        }
    }

    int magicConstant = square[0][0] + square[0][1] + square[0][2];

    for (int i = 1; i < SIZE; i++) {
        int rowSum = square[i][0] + square[i][1] + square[i][2];
        if (rowSum != magicConstant) {
            return false;
        }
    }

    for (int j = 0; j < SIZE; j++) {
        int colSum = square[0][j] + square[1][j] + square[2][j];
        if (colSum != magicConstant) {
            return false;
        }
    }

    int diag1 = square[0][0] + square[1][1] + square[2][2];
    int diag2 = square[0][2] + square[1][1] + square[2][0];
    if (diag1 != magicConstant || diag2 != magicConstant) {
        return false;
    }

    return true;
}

void generateRandomSquare(int square[SIZE][SIZE]) {
    vector<int> numbers;
    for (int i = 1; i <= 9; i++) {
        numbers.push_back(i);
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(numbers.begin(), numbers.end(), g);

    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            square[i][j] = numbers[index++];
        }
    }
}

void printSquare(const int square[SIZE][SIZE]) {
    cout << "Current Square:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));
    int square[SIZE][SIZE];
    int attempts = 0;
    const int MAX_ATTEMPTS = 100000; // Prevent infinite loops


    do {
        generateRandomSquare(square);
        attempts++;
        
        if (attempts % 10000 == 0) {
            cout << "Attempt " << attempts << "...\n";
        }
    } while (!isLoShuMagicSquare(square) && attempts < MAX_ATTEMPTS);

    if (attempts >= MAX_ATTEMPTS) {
        cout << "Did not find a magic square after " << MAX_ATTEMPTS << " attempts.\n";
        cout << "Here's the last square generated:\n";
        printSquare(square);
    } else {
        cout << "\nFound a Lo Shu Magic Square after " << attempts << " attempts!\n";
        printSquare(square);
        
        cout << "Rows sum: ";
        for (int i = 0; i < SIZE; i++) {
            cout << (square[i][0] + square[i][1] + square[i][2]) << " ";
        }
        
        cout << "\nColumn sum: ";
        for (int j = 0; j < SIZE; j++) {
            cout << (square[0][j] + square[1][j] + square[2][j]) << " ";
        }
        
        cout << "\nDiagonal sum: ";
        cout << (square[0][0] + square[1][1] + square[2][2]) << " ";
        cout << (square[0][2] + square[1][1] + square[2][0]) << endl;
    }

    return 0;
}
