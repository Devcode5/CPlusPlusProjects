//
//  activity10DiceGame.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 2/28/25.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Named constants

const int TOTAL = 11;
const int DICE_SIDES = 8;   // based on the requirements sides of the dice is set to 8.
int main() {

    // random number generator
    srand(time(0));
    int player1Score, player2Score;
     player1Score = 0;
     player2Score = 0;
//we have to use for loop because of eleven turns.
    for (int turn = 1; turn <= TOTAL; ++turn) {
        int turn1 = rand() % DICE_SIDES + 1;
        int turn2 = rand() % DICE_SIDES + 1;
        int totalRoll = turn1 + turn2;

        cout << "Turn " << turn << ": Dice 1 = " << turn1 << ", Dice 2 = " << turn2
             << ", Total = " << totalRoll << endl;

        // If the total is even, player1 gets a point; if odd, player2 gets a point
        if (totalRoll % 2 == 0) {
            player1Score++;
        } else {
            player2Score++;

        }

    }
    // displaying final scores

    cout << "\nFinal Scores: " << endl;
    cout << "Player 1: " << player1Score << " points" << endl;
    cout << "Player 2: " << player2Score << " points" << endl;
    //if condition for winner

    if (player1Score > player2Score) {
        cout << "First player congratulations." << endl;
    } else if(player2Score > player1Score) {
        cout << "Second player congratulations." << endl;
    }
    return 0; // execution
}
