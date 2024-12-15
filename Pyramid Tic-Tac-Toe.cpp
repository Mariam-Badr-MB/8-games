#include "Pyramid Tic-Tac-Toe.h"
#include <bits/stdc++.h>
using namespace std;

using namespace std;

// Constructor implementation
template <typename T>
pyramid_Board<T>::pyramid_Board() {
    rows = 3; 
    board.resize(rows);
    for (int i = 0; i < rows; ++i) {
        int cols = i * 2 + 1; 
        board[i].resize(cols, 0); 
    }
    n_moves = 0;
}

// Update board implementation
template <typename T>
bool pyramid_Board<T>::update_board(int x, int y, T symbol) {
    symbol = toupper(symbol);
    if (x >= 0 && x < board.size() && y >= 0 && y < board[x].size() && board[x][y] == 0) {
        n_moves++;
        board[x][y] = symbol;
        return true;
    }
    return false;
}

// Display the pyramid-shaped board
template <typename T>
void pyramid_Board<T>::display_board() {
    cout << "Current Pyramid Board:" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << string((rows - i - 1) * 4, ' ');
        for (int j = 0; j < board[i].size(); ++j) {
            if (!board[i][j]) cout << "| (" << i << "," << j << ") ";
            else cout << "| ";
            cout << (board[i][j] ? board[i][j] : ' ') << " ";
        }
        cout << "|" << endl;
        cout << string((rows - i - 1) * 4, ' ');
        cout << string((i * 8) + 6, '_') << endl;
    }
}

// Check win conditions
template <typename T>
bool pyramid_Board<T>::is_win() {
    // Implement win logic
    return false;
}

// Check draw conditions
template <typename T>
bool pyramid_Board<T>::is_draw() {
    return n_moves == 9 && !is_win();
}

// Check if the game is over
template <typename T>
bool pyramid_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

// Player constructor implementation
template <typename T>
pyramid_player<T>::pyramid_player(string name, T symbol) : name(name), symbol(symbol) {}

template <typename T>
void pyramid_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move (x y): ";
    cin >> x >> y;
}

// Random Player constructor
template <typename T>
pyramid_Random_Player<T>::pyramid_Random_Player(T symbol) : symbol(symbol) {
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void pyramid_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % 3;
    y = rand() % (x * 2 + 1);
}
