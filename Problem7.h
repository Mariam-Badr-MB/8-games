
#ifndef _3X3X_O_H
#define _3X3X_O_H

#include "Board_Game.h"

template <typename T>
class X_O_Board:public Board<T> {
    int choice=0;
public:
    X_O_Board ();
    bool update_board (int x , int y , T symbol);

    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
bool flag=false;
    int end=0;
};

template <typename T>
class X_O_Player : public Player<T> {

public:
    X_O_Player (string name, T symbol);
    void getmove(int& x, int& y) ;


};

template <typename T>
class X_O_Random_Player : public RandomPlayer<T>{
public:

    X_O_Random_Player(string name, T symbol);


    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()

using namespace std;

// Constructor for X_O_Board
template <typename T>
X_O_Board<T>::X_O_Board() {
    this->rows = this->columns = 4;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            if(i==0||i==3 ) {
                if(j%2==0)
                this->board[i][j] = 'X';
                else
                    this->board[i][j] = 'O';
            }
            else
                this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>

bool X_O_Board<T>::update_board(int x, int y, T mark) {
    // Validate the position
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns || this->board[x][y] != toupper(mark)) {
        cout << "Invalid !! Try again." << endl;
        return false;
    }


    cout << "\nPlease choose which direction:\n1) Right\n2) Left\n3) Up\n4) Down\n";
    int choice;
    cin >> choice;

    // Store the previous position
    int prev_x = x, prev_y = y;

    // Update x and y based on the choice
    switch (choice) {
        case 1: y++; break; // Move Right
        case 2: y--; break; // Move Left
        case 3: x--; break; // Move Up
        case 4: x++; break; // Move Down
        default:
            cout << "Invalid !!Try again." << endl;
        return false;
    }

    // Validate the new position
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns || this->board[x][y] != 0) {
        cout << "it is Invalid!! Try again." << endl;
        return false;
    }

    // Move the mark
    this->board[prev_x][prev_y] = 0;  // Clear
    this->board[x][y] = toupper(mark);  // update
    this->n_moves++;

    return true;
}

// Display the board and the pieces on it
template <typename T>
void X_O_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool X_O_Board<T>::is_win() {
    // Check rows and columns

    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0) ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 0)) {

            return true;
        }
    }

    // Check diagonals
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0)) {

        return true;
    }

    return false;
}

template <typename T>
bool X_O_Board<T>::is_draw() {
return  false;
}

template <typename T>
bool X_O_Board<T>::game_is_over() {
    return is_win();
}

//--------------------------------------

// Constructor for X_O_Player
template <typename T>
X_O_Player<T>::X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void X_O_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";

    cin >> x >> y;


}


template <typename T>
X_O_Random_Player<T>::X_O_Random_Player(string name,T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = name;
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}
template <typename T>
void X_O_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
}







#endif //_3X3X_O_H



