#ifndef _Ultimate_H
#define _Ultimate_H

#include "BoardGame_Classes.h"

template <typename T>
class Ultimate_tic_tac_Board : public Board<T> {

public:
    char** arr ;
    Ultimate_tic_tac_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    void is_win2();
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
    void fill_grad(int start , int end, T marker);
     

};

template <typename T>
class Ultimate_tic_tac_player : public Player<T> {
public:
    Ultimate_tic_tac_player (string name, T symbol);
    void getmove(int& x, int& y) ;

};


template <typename T>
class Ultimate_tic_tac_Random_Player : public RandomPlayer<T>{
public:
    Ultimate_tic_tac_Random_Player(T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include<bits/stdc++.h>
using namespace std;

// Constructor for X_O_Board
template <typename T>
Ultimate_tic_tac_Board<T>::Ultimate_tic_tac_Board() {

    
    this->rows = this->columns = 9;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;


    arr = new char*[3];
    for (int i = 0; i < 3; i++) {
        arr[i] = new char[3];
        for (int j = 0; j < 3; j++) {
            arr[i][j] = 0;
        }
    }
   

}



template <typename T>
bool Ultimate_tic_tac_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            //this->n_moves++;
            this->board[x][y] = toupper(mark);
        }
        this->is_win2();

        return true;
       
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void Ultimate_tic_tac_Board<T>::display_board() {
     cout << "Main Board:\n";

    for (int i = 0; i < 9; i++) {
        cout << "  "; 
        for (int j = 0; j < 9; j++) {
        
            cout << " " << this->board[i][j] << " ";
            if ((j + 1) % 3 != 0) 
                cout << "|";
            else if (j < 8) 
                cout << "   ";
        }
        cout << "\n";

       
        if ((i + 1) % 3 == 0 && i < 8) {
            cout << "  "; 
            for (int j = 0; j < 9; j++) {
                cout << "---";
                if ((j + 1) % 3 != 0)
                    cout << "+";
                else if (j < 8)
                    cout << "   ";
            }
            cout << "\n";
        }
    }
    cout << endl;
    cout << endl;
    cout << "Mini-Board (arr):\n";
    for (int i = 0; i < 3; i++) {
        cout << "\n| ";
        for (int j = 0; j < 3; j++) {
            cout << setw(2) << this->arr[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    
}



template <typename T>
void Ultimate_tic_tac_Board<T>::fill_grad(int start, int end, T marker)
{
   for (int i = start; i < start+3; i++)
   {
    for (int j = end; j < end+3; j++)
    {
     if ( this->board[i][j]==0)
     {
        this->board[i][j]=marker;
     }
     
    }
    
   }
   
}


// Returns true if there is any winner
template <typename T>
void Ultimate_tic_tac_Board<T>::is_win2() {
    // Check rows
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j += 3) {
           
            if (this->board[i][j] == this->board[i][j + 1] && 
                this->board[i][j + 1] == this->board[i][j + 2] && 
                this->board[i][j] != 0) {

                if (i >= 0 && i <= 2 && j == 0) {
                    this->arr[0][0] = this->board[i][j];
                    this->fill_grad(0, 0, this->board[i][j]);
                    
                } else if (i >= 0 && i <= 2 && j == 3) {
                    this->arr[0][1] = this->board[i][j];
                    this->fill_grad(0, 3, this->board[i][j]);
                     
                } else if (i >= 0 && i <= 2 && j == 6) {
                    this->arr[0][2] = this->board[i][j];
                    this->fill_grad(0, 6, this->board[i][j]);
                     
                } else if (i >= 3 && i <= 5 && j == 0) {
                    this->arr[1][0] = this->board[i][j];
                    this->fill_grad(3, 0, this->board[i][j]);
                    
                } else if (i >= 3 && i <= 5 && j == 3) {
                    this->arr[1][1] = this->board[i][j];
                    this->fill_grad(3, 3, this->board[i][j]);
                     
                } else if (i >= 3 && i <= 5 && j == 6) {
                    this->arr[1][2] = this->board[i][j];
                    this->fill_grad(3, 6, this->board[i][j]);
                     
                } else if (i >= 6 && i <= 8 && j == 0) {
                    this->arr[2][0] = this->board[i][j];
                    this->fill_grad(6, 0, this->board[i][j]);
                     
                } else if (i >= 6 && i <= 8 && j == 3) {
                    this->arr[2][1] = this->board[i][j];
                    this->fill_grad(6, 3, this->board[i][j]);
                     
                } else if (i >= 6 && i <= 8 && j == 6) {
                    this->arr[2][2] = this->board[i][j];
                    this->fill_grad(6, 6, this->board[i][j]);
                     
                }
            }
        }
    }

    // Check columns
    for (int j = 0; j < this->columns; j++) {
        for (int i = 0; i < this->rows; i += 3) {
           
            if (this->board[i][j] == this->board[i + 1][j] && 
                this->board[i + 1][j] == this->board[i + 2][j] && 
                this->board[i][j] != 0) {

                if (i >= 0 && i <= 2 && j == 0) {
                    this->arr[0][0] = this->board[i][j];
                    this->fill_grad(0, 0, this->board[i][j]);

                    
                } else if (i >= 0 && i <= 2 && j == 3) {
                    this->arr[0][1] = this->board[i][j];
                    this->fill_grad(0, 3, this->board[i][j]);
                     
                } else if (i >= 0 && i <= 2 && j == 6) {
                    this->arr[0][2] = this->board[i][j];
                     this->fill_grad(0, 6, this->board[i][j]);
                    
                } else if (i >= 3 && i <= 5 && j == 0) {
                    this->arr[1][0] = this->board[i][j];
                     this->fill_grad(3, 0, this->board[i][j]);
                    
                } else if (i >= 3 && i <= 5 && j == 3) {
                    this->arr[1][1] = this->board[i][j];
                    this->fill_grad(3, 3, this->board[i][j]);
                     
                } else if (i >= 3 && i <= 5 && j == 6) {
                    this->arr[1][2] = this->board[i][j];
                     this->fill_grad(3, 6, this->board[i][j]);
                     
                } else if (i >= 6 && i <= 8 && j == 0) {
                    this->arr[2][0] = this->board[i][j];
                    this->fill_grad(6, 0, this->board[i][j]);

                     
                } else if (i >= 6 && i <= 8 && j == 3) {
                    this->arr[2][1] = this->board[i][j];
                    this->fill_grad(6, 3, this->board[i][j]);
                     
                } else if (i >= 6 && i <= 8 && j == 6) {
                    this->arr[2][2] = this->board[i][j];
                     this->fill_grad(6, 6, this->board[i][j]);
                    
                }
            }
        }
    }

    // Check diagonals
    for (int i = 0; i <= 6; i += 3) {
        // Check main diagonal
        if (this->board[i][i] == this->board[i + 1][i + 1] && 
            this->board[i + 1][i + 1] == this->board[i + 2][i + 2] && 
            this->board[i][i] != 0) {

            if (i == 0) {
                this->arr[0][0] = this->board[i][i];
                this->fill_grad(0, 0, this->board[i][i]);

                 
            } else if (i == 3) {
                this->arr[1][1] = this->board[i][i];
                 this->fill_grad(3, 3, this->board[i][i]);
                 
            } else if (i == 6) {
                this->arr[2][2] = this->board[i][i];
                this->fill_grad(6, 6, this->board[i][i]);
                 
            }
        }
    }

    if (this->board[0][3]==this->board[1][4] && this->board[1][4]==this->board[2][5] && this->board[0][3]!=0)
    {
        this->arr[0][1]=this->board[0][3];
          this->fill_grad(0, 3, this->board[0][3]);
       
    }
    

    if (this->board[0][6]==this->board[1][7] && this->board[1][7]==this->board[2][8] && this->board[0][6]!=0)
    {
        this->arr[0][2]=this->board[0][6];
         this->fill_grad(0, 6, this->board[0][6]);
       
    }
    

    if (this->board[3][0]==this->board[4][1] && this->board[4][1]==this->board[5][2] && this->board[3][0]!=0)
    {
        this->arr[1][0]=this->board[3][0];
            this->fill_grad(3, 0, this->board[3][0]);
       
    }
    

    if (this->board[3][6]==this->board[4][7] && this->board[4][7]==this->board[5][8] && this->board[3][6]!=0)
    {
        this->arr[1][2]=this->board[3][6];
          this->fill_grad(3, 6, this->board[3][6]);
       
    }

    if (this->board[6][0]==this->board[7][1] && this->board[7][1]==this->board[8][2] && this->board[6][0]!=0)
    {
        this->arr[2][0]=this->board[6][0];
        this->fill_grad(6, 0, this->board[6][0]);

       
    }

    if (this->board[6][3]==this->board[7][4] && this->board[7][4]==this->board[8][5] && this->board[6][3]!=0)
    {
        this->arr[2][1]=this->board[6][3];
        this->fill_grad(6, 3, this->board[6][3]);
       
    }

    // Check anti diagonal

    if (this->board[0][2]==this->board[1][1] && this->board[1][1]==this->board[2][0] && this->board[0][2]!=0)
    {
        this->arr[0][0]=this->board[0][2];
        this->fill_grad(0, 0, this->board[0][2]);

       
    }

    if (this->board[0][5]==this->board[1][4] && this->board[1][4]==this->board[2][3] && this->board[0][5]!=0)
    {
        this->arr[0][1]=this->board[6][3];
        this->fill_grad(0, 3, this->board[6][3]);
       
    }

    if (this->board[0][8]==this->board[1][7] && this->board[1][7]==this->board[2][6] && this->board[0][8]!=0)
    {
        this->arr[0][2]=this->board[0][8];
        this->fill_grad(0, 6, this->board[0][8]);
       
    }

    if (this->board[3][2]==this->board[4][1] && this->board[4][1]==this->board[5][0] && this->board[3][2]!=0)
    {
        this->arr[1][0]=this->board[3][2];
        this->fill_grad(3, 0, this->board[3][2]);
       
    }


    if (this->board[3][5]==this->board[4][4] && this->board[4][4]==this->board[5][3] && this->board[5][3]!=0)
    {
        this->arr[1][1]=this->board[3][5];
        this->fill_grad(3, 3, this->board[3][5]);
       
    }

    if (this->board[3][8]==this->board[4][7] && this->board[4][7]==this->board[5][6] && this->board[3][8]!=0)
    {
        this->arr[1][2]=this->board[3][8];
        this->fill_grad(3, 6, this->board[3][8]);
       
    }

    if (this->board[6][2]==this->board[7][1] && this->board[7][1]==this->board[8][0] && this->board[6][2]!=0)
    {
        this->arr[2][0]=this->board[6][2];
        this->fill_grad(6, 0, this->board[6][2]);

       
    }

     if (this->board[6][5]==this->board[7][4] && this->board[7][4]==this->board[8][3] && this->board[6][5]!=0)
    {
        this->arr[2][1]=this->board[6][5];
        this->fill_grad(6, 3, this->board[6][5]);
       
    }

    if (this->board[6][8]==this->board[7][5] && this->board[7][5]==this->board[8][6] && this->board[6][8]!=0)
    {
        this->arr[2][2]=this->board[6][8];
        this->fill_grad(6, 6, this->board[6][8]);
       



}
}


template <typename T>
bool Ultimate_tic_tac_Board<T>::is_win() {
    this->is_win2();
    for (int i = 0; i < 3; i++) {
        if ((this->arr[i][0] == this->arr[i][1] && this->arr[i][1] == this->arr[i][2] && this->arr[i][0] != 0) ||
            (this->arr[0][i] == this->arr[1][i] && this->arr[1][i] == this->arr[2][i] && this->arr[0][i] != 0)) {
            return true;
        }
    }

   
     if ((this->arr[0][0] ==this->arr[1][1] &&this->arr[1][1] == this->arr[2][2] && this->arr[0][0] != 0) ||
        (this->arr[0][2] == this->arr[1][1] && this->arr[1][1] ==this->arr[2][0] && this->arr[0][2] != 0)) {
        return true;
    }

    return false;
}
    
    


template <typename T>
bool Ultimate_tic_tac_Board<T>::is_draw() {
   
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
           
            if (this->board[i][j] == 0) {
                return false; 
            }
        }
    }
    
    return !is_win(); 
}



template <typename T>
bool Ultimate_tic_tac_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for Ultimate_Player
template <typename T>
Ultimate_tic_tac_player<T>::Ultimate_tic_tac_player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Ultimate_tic_tac_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 8) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for X_O_Random_Player
template <typename T>
Ultimate_tic_tac_Random_Player<T>::Ultimate_tic_tac_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 9;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void Ultimate_tic_tac_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
}



#endif //_Ultimate_O_H