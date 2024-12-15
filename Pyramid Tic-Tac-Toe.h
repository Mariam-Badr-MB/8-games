#ifndef _PYRAMID_GAME_H
#define _PYRAMID_GAME_H

#include "BoardGame_Classes.h"

template <typename T>
class pyramid_Board : public Board<T> {
    private:
    vector<vector<T>> board; // Pyramid representation
public:
    pyramid_Board();                      // Constructor
    bool update_board(int x = 0, int y = 0, T symbol = 0);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class pyramid_player : public Player<T> {
public:
    pyramid_player(std::string name, T symbol);
    void getmove(int& x = 0, int& y = 0);
};

template <typename T>
class pyramid_Random_Player : public RandomPlayer<T> {
public:
    pyramid_Random_Player(T symbol);
    void getmove(int& x = 0, int& y = 0);
};

//--------------------------------------- IMPLEMENTATION

#include <bits/stdc++.h>
using namespace std; 

template <typename T>
pyramid_Board<T>::pyramid_Board() {
    this->rows = 3; // Number of levels in the pyramid
    this->board.resize(this->rows);
    for (int i = 0; i < this->rows; ++i) {
        int cols = i * 2 + 1; // Number of columns per row
        this->board[i].resize(cols, 0); // Initialize cells as empty
    }
    this->n_moves = 0;
}

template <typename T>
bool pyramid_Board<T>::update_board(int x, int y, T symbol) {
    symbol = toupper(symbol);
    if (x >= 0 && x < board.size() && y >= 0 && y < board[x].size() && board[x][y] == 0) {
        this->n_moves++;
        this->board[x][y] = symbol;
        return true;
    }
    return false;
}

template <typename T>
void pyramid_Board<T>::display_board() {
    cout << "Current Pyramid Board:" << endl;
    for (int i = 0; i < this->rows; ++i) {
        cout << string((this->rows - i - 1) * 4, ' '); // Add spaces for alignment
        for (int j = 0; j < board[i].size(); ++j) {
            if (!board[i][j]) cout << "| (" << i << "," << j << ") ";
            else cout << "| ";
            cout << (board[i][j] ? board[i][j] : ' ') << " ";
        }
        cout << "|" << endl;
        cout << string((this->rows - i - 1) * 4, ' '); // Add spacing for row separator
        cout << string((i * 8) + 6, '_') << endl;      // Create separator based on row length
    }
}

template <typename T>
bool pyramid_Board<T>::is_win() {
    // Check vertical
    if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[0][0] != 0) {
        return true;
    }

    // Check horizontal
    if (board[1][0] == board[1][1] && board[1][2] == board[1][1] && board[1][0] != 0) {
        return true;
    }
    if (board[2][0] == board[2][1] && board[2][2] == board[2][1] && board[2][0] != 0) {
        return true;
    }
    if (board[2][3] == board[2][2] && board[2][4] == board[2][3] && board[2][3] != 0) {
        return true;
    }

    // Check diagonals
    if (board[0][0] == board[1][0] && board[2][0] == board[1][0] && board[0][0] != 0) {
        return true;
    }
    if (board[0][0] == board[1][2] && board[2][4] == board[1][3] && board[0][0] != 0) {
        return true;
    }

    return false;
}

template <typename T>
bool pyramid_Board<T>::is_draw() {
    return this->n_moves == 9 && !is_win();
}

template <typename T>
bool pyramid_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
pyramid_player<T>::pyramid_player(std::string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void pyramid_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move (x y): ";
    cin >> x >> y;
}

template <typename T>
pyramid_Random_Player<T>::pyramid_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->name = "Random Pyramid Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void pyramid_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % 3; // Random row between 0 and 2
    y = rand() % (x * 2 + 1); // Random column based on the row size
}

#endif //_PYRAMID_GAME_H
