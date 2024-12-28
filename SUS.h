#ifndef _SUS_H
#define _SUS_H

#include "BoardGame_Classes.h"
#include <bits/stdc++.h>
using namespace std;

// SUS game board class
template <typename T>
class SUS_Board : public Board<T> {
private:
    static int cnt1, cnt2; // Score counters for players
    int x1, y1;            // Last move coordinates
    char symbol;           // Last player's symbol
    Player<T>* players[2]; // Array to hold players

public:
    SUS_Board(Player<T>* playerArray[2]);  // Constructor
    bool update_board(int x, int y, T symbol); // Update board
    void display_board();                      // Display board
    bool is_win();                             // Check win condition
    bool is_draw();                            // Check draw condition
    bool game_is_over();                       // Check if game is over

    bool row[3]={false,false,false};
    bool column[3]={false,false,false};
    bool diagonal[3]={false,false,false};
    
};

// Static variables initialization
template <typename T>
int SUS_Board<T>::cnt1 = 0;

template <typename T>
int SUS_Board<T>::cnt2 = 0;

// Random player for SUS Game
template <typename T>
class SUS_Random_Player : public RandomPlayer<T> {
public:
    SUS_Random_Player(T symbol);
    void getmove(int& x, int& y);
};

// SUS game player class
template <typename T>
class SUS_Player : public Player<T> {
public:
    SUS_Player(string name, T symbol);
    void getmove(int& x, int& y);
};

//--------------------------------------- IMPLEMENTATION

// SUS_Board Constructor
template <typename T>
SUS_Board<T>::SUS_Board(Player<T>* playerArray[2]) {
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];

    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0; // Initialize as empty
        }
    }
    this->n_moves = 0;

    // Store players
    players[0] = playerArray[0];
    players[1] = playerArray[1];
}

// Update the board with a move
template <typename T>
bool SUS_Board<T>::update_board(int x, int y, T symbol) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns || this->board[x][y] != 0 )) {
        this->board[x][y] = symbol;
        this->n_moves++;
        this->x1 = x;
        this->y1 = y;
        this->symbol = symbol;
        return true;
    }
    return false;
}

// Display the board
template <typename T>
void SUS_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] != 0)
                cout << setw(2) << this->board[i][j] << " |";
            else
                cout << "   |";
        }
        cout << "\n------------------";
    }
    cout << endl;
}

// Check for a winning condition
template <typename T>
bool SUS_Board<T>::is_win() {

    for (int i = 0; i < 3; i++) {
        if (!this->row[i] && this->board[i][0] == 'S' && this->board[i][1] == 'U' && this->board[i][2] == 'S') {
            this->row[i] = true;
            if (this->symbol == 'S') {
                this->cnt1++;
            } else if (this->symbol == 'U') {
                this->cnt2++;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if (!this->column[i] && this->board[0][i] == 'S' && this->board[1][i] == 'U' && this->board[2][i] == 'S') {
            this->column[i] = true;
            if (this->symbol == 'S') {
                this->cnt1++;
            } else if (this->symbol == 'U') {
                this->cnt2++;
            }
        }
    }

   
    if (!this->diagonal[0] && this->board[0][0] == 'S' && this->board[1][1] == 'U' && this->board[2][2] == 'S') {
        this->diagonal[0] = true;
        if (this->symbol == 'S') {
            this->cnt1++;
        } else if (this->symbol == 'U') {
            this->cnt2++;
        }
    }

    if (!this->diagonal[1] && this->board[2][0] == 'S' && this->board[1][1] == 'U' && this->board[0][2] == 'S') {
        this->diagonal[1] = true;
        if (this->symbol == 'S') {
            this->cnt1++;
        } else if (this->symbol == 'U') {
            this->cnt2++;
        }
    }

    cout << "Score1 = " << this->cnt1 << " Score2 = " << this->cnt2 << endl;

    
    if (this->n_moves < 9) {
        return false;
    } else {
        if (this->cnt1 > this->cnt2) {
            return true;
        } else if (this->cnt2 > this->cnt1) {
            cout << this->players[1]->getname() << " wins\n";
            return false;
        }
    }
}

// Check for a draw
template <typename T>
bool SUS_Board<T>::is_draw() {
    return (this->cnt1 == this->cnt2 && this->n_moves == 9);
}

// Check if the game is over
template <typename T>
bool SUS_Board<T>::game_is_over() {
    return (this->n_moves == 9 && !is_draw() && !is_win());
}

// SUS_Player Constructor
template <typename T>
SUS_Player<T>::SUS_Player(string name, T symbol) : Player<T>(name, symbol) {}

// Get move from player
template <typename T>
void SUS_Player<T>::getmove(int& x, int& y) {
    cout << "\nEnter your move (row and column 0-2): ";
    cin >> x >> y;
}

// SUS_Random_Player Constructor
template <typename T>
SUS_Random_Player<T>::SUS_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

// Generate random move
template <typename T>
void SUS_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % 3;
    y = rand() % 3;
}

#endif //_SUS_H
