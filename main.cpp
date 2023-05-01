/* Owen Cramer
 * FRCC2034
 * 1 May 2023
 * Main program to run the TicTacToe Game
 * This came offers a way to play with friend (work-progress) and
 * playing against the computer. How the computer works is by selecting
 * a random location on the board if there is space available. Basically
 * the game runs on easy mode for the player against the computer.
 *
 */

#include <iostream>
#include "TicLogic.h"

using namespace std;

int main() {
    cout << "Welcome to TicTacToe!\n";
    TicLogic playgame;
    playgame.play_game();
    return 0;
}
