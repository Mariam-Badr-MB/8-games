#ifndef _Word_H
#define _Word_H

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
class word_Random_Player : public RandomPlayer<T> , word_Board<T>{
public:
    word_Random_Player(T symbol);
    void getmove(int& x, int& y);
};

// Word game player class
template <typename T>
class word_Player : public Player<T> {
public:
     word_Player(string name, T symbol);
    void getmove(int& x, int& y);
};


//--------------------------------------- IMPLEMENTATION

#include <bits/stdc++.h>
using namespace std;

template<typename T>
char word_Board<T>::get_char() {
    char c;
    cout << "\nPlease, enter your character: ";
    cin >> c;
    return c ;
}


template <typename T>
word_Board<T>::word_Board() {
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 'x';
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool word_Board<T>::update_board(int x, int y, T symbol ) {

    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns || this->board[x][y] != 'x' )) {
            this->n_moves++ ;
            this->board[x][y] = (symbol == 'x' ? toupper(get_char()) : 'A' + rand() % 26);
            return true;
        }
    return false;
}
// Display the board and the pieces on it
template <typename T>
void word_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] != 'x')  cout << setw(2) << this->board[i][j] << " |";
            else           cout << "(" << i << "," << j << ")" << " |";


        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
// Returns true if there is any winner
template <typename T>
bool word_Board<T>::is_win() {
    ifstream words("dic.txt");
    map<string, string> validwords;
    string word;

    // Check if file is open
    if (!words.is_open()) {
        cerr << "Error opening dictionary file." << endl;
        return false;
    }

    // Read words into validwords map
    while (getline(words, word)) {
        if (!word.empty()) {
            validwords[word] = word;
        }
    }
    words.close(); // Close the file after reading

    // Horizontally
    for(int i = 0; i < this->rows; i++) {
        word = "";
        for (int j = 0; j < this->columns; j++) {
            word += this->board[i][j];
        }
        if (validwords.find(word) != validwords.end()) {
            return true;
        }
    }

    // Vertically
    for(int i = 0; i < this->rows; i++) {
        word = "";
        for (int j = 0; j < this->columns; j++) {
            word += this->board[j][i];
        }
        if (validwords.find(word) != validwords.end()) {
            return true;
        }
    }

    // Diagonally (top-left to bottom-right)
    word = "";
    for (int i = 0; i < min(this->rows, this->columns); ++i) {
        word += this->board[i][i];
    }
    if (validwords.find(word) != validwords.end()) return true;

    // Diagonally (top-right to bottom-left)
    word = "";
    for (int i = 0; i < min(this->rows, this->columns); ++i) {
        word += this->board[i][this->columns - 1 - i];
    }
    if (validwords.find(word) != validwords.end()) return true;

    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool word_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool word_Board<T>::game_is_over() {
    return is_win() || is_draw();
}


// Constructor for X_O_Player
template <typename T>
word_Player<T>::word_Player(string name, T symbol) : Player<T>(name, symbol) {}


template <typename T>
void word_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}


// Constructor for X_O_Random_Player
template <typename T>
word_Random_Player<T>::word_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}
// Function to generate a random move
template <typename T>
void word_Random_Player<T>::getmove(int& x, int& y) {

        x = rand() % 3;  // Random row between 0 and 2
        y = rand() % 3;  // Random column between 0 and 2

}

#endif //_Word_H
