//
// Created by owencramer on 5/1/2023.
//

#ifndef TICTACTOE_TICLOGIC_H
#define TICTACTOE_TICLOGIC_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "TicLogic.h"

using namespace std;

class TicLogic {
public:

    TicLogic(); //constructor
    ~TicLogic(); //destructor

    void initialize_board();
    void print_board();
    bool check_win(char marker);
    bool check_draw();
    void player_turn();
    void computer_turn();
    void play_game();

};


#endif //TICTACTOE_TICLOGIC_H
