#ifndef WORD_GAME_H
#define WORD_GAME_H

#include "BoardGame_Classes.h"

// Word game board class
template <typename T>
class word_Board : public Board<T> {
public:
    word_Board();                      // Constructor
    bool update_board(int x, int y, T symbol); // Update board
    void display_board();                 // Display board
    bool is_win();                        // Check win condition
    bool is_draw();                       // Check draw condition
    bool game_is_over();                  // Check if the game is over
    char get_char();
};

// Random player for Word Game
template <typename T>
class word_Random_Player : public RandomPlayer<T> , word_Board<T> {
public:
    word_Random_Player(T symbol);
    void getmove(int& x, int& y);
};

// Word game player class
template <typename T>
class word_Player : public Player<T> {
public:
     word_Player(std::string name, T symbol);
    void getmove(int& x, int& y);
};

#endif // WORD_GAME_H
