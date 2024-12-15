#ifndef _Numeric_H
#define _Numeric_H

#include"BoardGame_Classes.h"

template <typename T>
class Numerical_Tic_Tac_Toe_board : public Board<T> {
public:
    Numerical_Tic_Tac_Toe_board();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class  Numerical_Tic_Tac_Toe_player: public Player<T> {
public:
    Numerical_Tic_Tac_Toe_player (string name, T symbol);
    void getmove(int& x=0, int& y=0) ;
   

};

template <typename T>
class Numerical_Tic_Tac_Toe_random_player : public RandomPlayer<T>{
public:
    Numerical_Tic_Tac_Toe_random_player(T symbol);
    void getmove(int &x=0, int &y=0) ;
};





//--------------------------------------- IMPLEMENTATION

#include<bits/stdc++.h>
using namespace std;

template <typename T>

Numerical_Tic_Tac_Toe_board <T>::Numerical_Tic_Tac_Toe_board ()
{
    this->rows=3;this->columns=3;
    this->n_moves=0;
    this->board=new int *[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->board[i]=new int[this->columns];
        for (int j = 0; j<this->columns ; j++)
        {
           this->board[i][j] = 0;
        }
        
    }

}


template <typename T>
bool Numerical_Tic_Tac_Toe_board <T>::update_board(int x, int y, T mark) {
   
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns) {
        cout << "Invalid coordinates! Please enter x and y between 0 and 2." << endl;
        return false;
    }

   
    if (mark <= 0 || mark > 9) {
        cout << "Invalid number! Please enter a number between 1 and 9." << endl;
        return false;
    }

    
    if (this->n_moves % 2 == 0) {
        if (mark % 2 == 0) {
            cout << "Player 1 should enter an odd number!" << endl;
            return false;
        }
    } else { 
        if (mark % 2 != 0) {
            cout << "Player 2 should enter an even number!" << endl;
            return false;
        }
    }

   
    if (this->board[x][y] != 0) {
        cout << "This spot is already taken!" << endl;
        return false;
    }

    if ( this->board[0][0]== mark || this->board[0][1]== mark ||this->board[0][2]== mark ||this->board[1][0]== mark ||this->board[1][1]== mark ||this->board[1][2]== mark || this->board[2][0]== mark ||this->board[2][1]== mark || this->board[2][2]== mark )
    {
        cout << "This number is already taken!" << endl;
        return false;
    }
    this->board[x][y] = mark;
    this->n_moves++; 
    return true;
}



template <typename T>
void  Numerical_Tic_Tac_Toe_board <T>::display_board()
{
   for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
           
            if (this->board[i][j] == 0) {
                cout << "   | "; 
            } else {
                cout << setw(2) << this->board[i][j] << " | ";  
            }
        }
        cout << "\n---------------------------------";
    }
    cout << endl;
}

template <typename T>
bool Numerical_Tic_Tac_Toe_board <T>::is_win()
{
     for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] + this->board[i][1]+this->board[i][2]==15 && this->board[i][0] != 0 && this->board[i][1] != 0 && this->board[i][2] != 0 ) ||
            (this->board[0][i] + this->board[1][i]+this->board[2][i]==15   && this->board[0][i] != 0 && this->board[1][i] != 0 && this->board[2][i] != 0 )) {
            return true;
        }
    }

    
    if ((this->board[0][0] + this->board[1][1] + this->board[2][2] ==15  && this->board[0][0] != 0  && this->board[1][1] != 0 && this->board[2][2] != 0 ) ||
        (this->board[0][2] + this->board[1][1] + this->board[2][0] ==15  && this->board[0][2] != 0  && this->board[1][1] != 0  && this->board[2][0] != 0)) {
        return true;
    }

    return false;
}

template <typename T>
bool Numerical_Tic_Tac_Toe_board <T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}



template <typename T>
bool Numerical_Tic_Tac_Toe_board <T>::game_is_over() {
    return is_win() || is_draw();
}



template <typename T>
Numerical_Tic_Tac_Toe_player<T>::Numerical_Tic_Tac_Toe_player(string name, T symbol) : Player<T>(name, symbol) {
    this->name = name;
    this->symbol = symbol;
}



template <typename T>
void Numerical_Tic_Tac_Toe_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
    int mark=0;
    cout << "\nPlease enter a valid move (1 to 9), with odd numbers for Player 1 (X) and even for Player 2 (O): ";
    cin >> mark;
    this->symbol=mark;
   
    
}



 
template <typename T>
Numerical_Tic_Tac_Toe_random_player<T>::Numerical_Tic_Tac_Toe_random_player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}



template <typename T>
void Numerical_Tic_Tac_Toe_random_player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
    int num;
    num=(rand() %9)+1;
    this->symbol=num;
    cout<<num;


}

#endif //_Numerical_H