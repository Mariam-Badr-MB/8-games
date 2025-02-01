#include "BoardGame_Classes.h"

#ifndef _5X5_H
#define _5X5_H

template <typename T>

class _5x5_Board:public Board<T> {
   static int scoreX ;
   static  int scoreO ;
    Player<T>* players[2];
    bool player1win=0;

public:
    _5x5_Board(Player<T>* playerArray[2]);
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
    bool little_win();
    bool little_draw();

};

template <typename T>
class _5x5_Player : public Player<T> {

public:
_5x5_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class _5x5_Random_Player : public RandomPlayer<T>{
public:
_5x5_Random_Player (string name,T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include<bits/stdc++.h>
using namespace std;

// Constructor for _5x5_Board
template <typename T>
_5x5_Board<T>::_5x5_Board(Player<T>* playerArray[2]) {
    this->rows = this->columns = 5;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
    // Store the players array
    players[0] = playerArray[0];
    players[1] = playerArray[1];
}
template<typename T>
bool _5x5_Board<T>::little_draw() {
    return (!little_win());
}


template <typename T>
bool _5x5_Board<T>::update_board(int x, int y, T mark) {

    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void _5x5_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------------------";
    }
    cout << endl;
}

template <typename T>
int _5x5_Board<T>::scoreX=0;
template <typename T>
int _5x5_Board<T>::scoreO=0;

template <typename T>
bool _5x5_Board<T>::little_win() {
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
bool _5x5_Board<T>::is_win() {
    if(this->n_moves < 24) return false;
    int dx[] = {0, 1, 1, 1}; // Right, Down-Right, Down, Up-Right
    int dy[] = {1, 1, 0, -1};


    // Evaluate board for all possible patterns
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] == 0) continue; // Skip empty cells


            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                int fi = ni + dx[d], fj = nj + dy[d];


                if (ni >= 0 && ni < this->rows && nj >= 0 && nj < this->columns &&
                    fi >= 0 && fi < this->rows && fj >= 0 && fj < this->columns) {


                    if (this->board[i][j] == this->board[ni][nj] &&
                        this->board[ni][nj] == this->board[fi][fj]) {

                        if (this->board[i][j] == 'X') scoreX++;
                        if (this->board[i][j] == 'O') scoreO++;
                        }
                    }
            }
        }
    }
    cout << "scoreX : "<< scoreX << ' ' << "scoreO : "<< scoreO << endl;
    if(scoreX < scoreO) return true;
    if(scoreX>scoreO) {
        cout<<"\n"<<this->players[0]->getname() << " wins\n";;
    }
    return false;
}



// Return true if 24 moves are done and no winner
template <typename T>
bool _5x5_Board<T>::is_draw() {
    return false;
}

template <typename T>
bool _5x5_Board<T>::game_is_over() {

    return(24 == this->n_moves);
}

//--------------------------------------

// Constructor for _5x5_Player
template <typename T>
_5x5_Player<T>::_5x5_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void _5x5_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for _5x5_Random_Player
template <typename T>
_5x5_Random_Player<T>::_5x5_Random_Player(string name,T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 5;
    this->name = name;
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void _5x5_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 4
    y = rand() % this->dimension;
}




#endif //_5X5_O_H