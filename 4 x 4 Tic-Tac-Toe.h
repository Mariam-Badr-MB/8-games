#ifndef _4x4_O_H
#define _4x4_O_H

#include "BoardGame_Classes.h"
int n_x, n_y;
template <typename T>
class _4x4_Board:public Board<T> {
    int choice=0;

public:
    _4x4_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

    bool flag=false;
    int end=0;
};

template <typename T>
class _4x4_Player : public Player<T> {

public:
    _4x4_Player (string name, T symbol);
    void getmove(int& x, int& y) ;


};

template <typename T>
class _4x4_Random_Player : public RandomPlayer<T>{
public:

    _4x4_Random_Player(string name, T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include<bits/stdc++.h>
using namespace std;

// Constructor for _4x4_Board
template <typename T>
_4x4_Board<T>::_4x4_Board() {
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

bool _4x4_Board<T>::update_board(int x, int y, T mark) {


    // Validate the position
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns || this->board[x][y] != toupper(mark)) {
       if (mark != 'x' &&  mark != 'o') cout << "Invalid !! Try again." << endl;
        return false;
    }
    // Validate the new position
    if (n_x < 0 || n_x >= this->rows || n_y < 0 || n_y >= this->columns || this->board[n_x][n_y] != 0) {
        if (mark != 'x' && mark != 'o')  cout << "It is Invalid!! Try again." << endl;
        return false;
    }
    // Move the mark
    this->board[x][y] = 0;  // Clear
    this->board[n_x][n_y] = toupper(mark);  // update
    this->n_moves++;

    return true;
}

// Display the board and the pieces on it
template <typename T>
void _4x4_Board<T>::display_board() {
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
bool _4x4_Board<T>::is_win() {
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
bool _4x4_Board<T>::is_draw() {
return  false;
}

template <typename T>
bool _4x4_Board<T>::game_is_over() {
    return is_win();
}

//--------------------------------------

// Constructor for _4x4_Player
template <typename T>
_4x4_Player<T>::_4x4_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void _4x4_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
    n_x = x;n_y = y;
    cout << "\nPlease choose which direction:\n1) Right\n2) Left\n3) Up\n4) Down\n";
    int choice;

    cin >> choice;
    switch (choice) {
        case 1: n_y+=1; break; // Move Right
        case 2: n_y-=1; break; // Move Left
        case 3: n_x-=1;break; // Move Up
        case 4: n_x+=1; break; // Move Down


    }



}


template <typename T>
_4x4_Random_Player<T>::_4x4_Random_Player(string name,T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = name;
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}
template <typename T>
void _4x4_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
    n_x= rand() % this->dimension;
    n_y=rand() % this->dimension;
}







#endif //_4x4_O_H