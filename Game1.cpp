#include <bits/stdc++.h>
#include "BoardGame_Classes.h"
using namespace std;

template <typename T>
class pyramid_Board : public Board<T> {
private:
    vector<vector<T>> board; // Pyramid representation

public:
    pyramid_Board();                      // Constructor
    bool update_board(int x, int y, T symbol); // Update board
    void display_board();                 // Display board
    bool is_win();                        // Check win condition
    bool is_draw();                       // Check draw condition
    bool game_is_over();                  // Check if the game is over
};

// Constructor implementation
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

// Update board implementation
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

// Display the pyramid-shaped board
template <typename T>
void pyramid_Board<T>::display_board() {
    cout << "Current Pyramid Board:" << endl;
    for (int i = 0; i < this->rows; ++i) {
        cout << string((this->rows - i - 1) * 4, ' '); // Add spaces for alignment
        for (int j = 0; j < board[i].size(); ++j) {
            if (!board[i][j])cout << "| (" << i << "," << j << ") " ;
            cout << (board[i][j] ? board[i][j] : ' ') << " ";
        }
        cout << "|" << endl;
        cout << string((this->rows - i - 1) * 4, ' '); // Add spacing for row separator
        cout << string((i * 8) + 6, '_') << endl;      // Create separator based on row length
    }
}

// Check win conditions
template <typename T>
bool pyramid_Board<T>::is_win() {
    // Check vertical
    if (board[0][2] == board[1][2] && board[2][2] == board[1][2] && board[0][2] != 0) {
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
    if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[0][2] != 0) {
        return true;
    }
    if (board[0][2] == board[1][3] && board[2][4] == board[1][3] && board[0][2] != 0) {
        return true;
    }

    return false;
}

// Check draw conditions
template <typename T>
bool pyramid_Board<T>::is_draw() {
    return this->n_moves == 9 && !is_win();
}

// Check if the game is over
template <typename T>
bool pyramid_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

// Pyramid player class
template <typename T>
class pyramid_player : public Player<T> {
public:
    pyramid_player(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
pyramid_player<T>::pyramid_player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void pyramid_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move (x y): ";
    cin >> x >> y;
}
template <typename T>
class pyramid_Random_Player : public RandomPlayer<T>{
public:
     pyramid_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};


// Constructor for Pyramid_Random_Player
template <typename T>
pyramid_Random_Player<T>::pyramid_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->name = "Random Pyramid Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

// Generate random valid moves for the pyramid board
template <typename T>
void pyramid_Random_Player<T>::getmove(int& x, int& y) {

    x = rand() % 3; // Random row between 0 and 2
    y = rand() % (x * 2 + 1); // Random column based on the row size

}

// AI

// Main function
int main() {
    int choice;
    Player<char>* players[2];
    pyramid_Board<char>* B = new pyramid_Board<char>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI X-O Game. :)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new pyramid_player<char>(playerXName, 'X');
        break;
        case 2:
            players[0] = new pyramid_Random_Player<char>('X');
        break;
        case 3:
            //players[0] = new X_O_MinMax_Player<char>('X');
                players[0]->setBoard(B);
        break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
        return 1;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[1] = new pyramid_player <char>(player2Name, 'O');
        break;
        case 2:
            players[1] = new pyramid_Random_Player<char>('O');
        break;
        case 3:
            //players[1] = new X_O_MinMax_Player<char>('O');
                players[1]->setBoard(B);
        break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
        return 1;
    }

    // Create the game manager and run the game
    GameManager<char> pyramid_game(B, players);
    pyramid_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
    return 0;
}