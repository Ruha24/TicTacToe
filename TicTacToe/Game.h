#pragma once

#include <iostream>

#include "Board.h"
#include "Computer.h"
#include "Player.h"

class Game
{
public:
    Game();

    // Method to start the game
    int start();

    // Method to execute a player's turn
    void player_turn(char playerSymbol, TicTacToe<char>& ttt);

    // Method to execute a computer's turn
    void computer_turn(char computerSymbol, TicTacToe<char>& ttt);

private:
    // Pointers to the player and computer
    Gamers* player;
    Gamers* computer;

    char turn;

    // Game board (Tic-Tac-Toe grid)
    TicTacToe<char> ttt;

    // Flag indicating the game outcome (win/lose)
    bool win = false;
};
