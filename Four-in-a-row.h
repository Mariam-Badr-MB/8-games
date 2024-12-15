#ifndef _Four_H
#define _Four_H

#include"BoardGame_Classes.h"

template <typename T>
class Four_in_row_Board:public Board<T> {
public:
    Four_in_row_Board ();
    bool update_board (int x=0 , int y=0 , T symbol=0);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class Four_in_row_player : public Player<T> {
public:
    Four_in_row_player (string name, T symbol);
    void getmove(int& x=0, int& y=0) ;

};

template <typename T>
class Four_in_row_Random_Player : public RandomPlayer<T>{
public:

    Four_in_row_Random_Player(T symbol);
    void getmove(int &x=0, int &y=0) ;
};




//--------------------------------------- IMPLEMENTATION

#include<bits/stdc++.h>
using namespace std;

template <typename T>
Four_in_row_Board<T>::Four_in_row_Board()
{
    this->rows=6;this->columns=7;
    this->board=new char *[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->board[i]=new char[this->columns];
        for (int j = 0; j<this->columns ; j++)
        {
           this->board[i][j] = 0;
        }
        
    }

}


template <typename T>
bool Four_in_row_Board<T>::update_board(int x, int y, T mark)
{
    if (y < 0 || y >= this->columns) {
        cout << "Invalid column!" << endl;
        return false;
    }

    
    for (int i = this->rows - 1; i >= 0; i--) {
        if (this->board[i][y] == 0) {  
            x = i;  
            this->board[x][y] = toupper(mark);  
            this->n_moves++; 
            return true;
        }
    }

    cout << "Column is full!" << endl; 
    return false;
}


template <typename T>
void  Four_in_row_Board<T>::display_board()
{
   for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
           
            if (this->board[i][j] == 0) {
                cout << "   | "; 
            } else {
                cout << setw(2) << this->board[i][j] << " | ";  // عرض الرمز
            }
        }
        cout << "\n---------------------------------";
    }
    cout << endl;
}

template <typename T>
bool Four_in_row_Board<T>::is_win()
{
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2]&& this->board[i][2] == this->board[i][3] && this->board[i][0] != 0) ||
            (this->board[i][1] == this->board[i][2] && this->board[i][2] == this->board[i][3]&& this->board[i][3] == this->board[i][4] && this->board[i][1] != 0) ||
            (this->board[i][2] == this->board[i][3] && this->board[i][3] == this->board[i][4]&& this->board[i][4] == this->board[i][5] && this->board[i][2] != 0) ||
            (this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5]&& this->board[i][5] == this->board[i][6] && this->board[i][3] != 0) ||

            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i]&& this->board[2][i] == this->board[3][i] && this->board[0][i] != 0) ||
            (this->board[1][i] == this->board[2][i] && this->board[2][i] == this->board[3][i]&& this->board[3][i] == this->board[4][i] && this->board[1][i] != 0) ||
            (this->board[2][i] == this->board[3][i] && this->board[3][i] == this->board[4][i]&& this->board[4][i] == this->board[5][i] && this->board[2][i] != 0) )
        {
            return true;
        }

    }



    for (int i = 0; i < this->rows-3; i++)
    {
        for (int j= 0; j< this->columns-3; j++)
        {
          if (this->board[i][j] == this->board[i+1][j+1] && this->board[i+1][j+1] == this->board[i+2][j+2]&& this->board[i+2][j+2] == this->board[i+3][j+3] && this->board[i][j] != 0)
          {
           return true;
          }
          
        }
        
    }
    

     for (int i = 0; i < this->rows-3; i++)
    {
        for (int j= this->columns-1; j>=3; j--)
        {
          if (this->board[i][j] == this->board[i+1][j-1] && this->board[i+1][j-1] == this->board[i+2][j-2]&& this->board[i+2][j-2] == this->board[i+3][j-3] && this->board[i][j] != 0)
          {
           return true;
          }
          
        }
        
    }



    return false;
}

template <typename T>
bool Four_in_row_Board<T>::is_draw() {
    return (this->n_moves == 42 && !is_win());
}



template <typename T>
bool Four_in_row_Board<T>::game_is_over() {
    return is_win() || is_draw();
}



template <typename T>
Four_in_row_player<T>::Four_in_row_player(string name, T symbol) : Player<T>(name, symbol) {
    this->name = name;
    this->symbol = symbol;
}



template <typename T>
void Four_in_row_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your colunm y (0 to 6) separated by spaces: ";
    cin >> y;
    x=-1;
    
}
 
template <typename T>
Four_in_row_Random_Player<T>::Four_in_row_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension=7;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  
}



template <typename T>
void Four_in_row_Random_Player<T>::getmove(int& x, int& y) {
    x = -1;
    y = rand() % this->dimension;
}


#endif //_Four_O_H
