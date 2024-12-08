#include <bits/stdc++.h>
#include "BoardGame_Classes.h"
using namespace std;

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
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) ) {
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

// Word game player class
template <typename T>
class word_Player : public Player<T> {
public:
     word_Player(string name, T symbol);
    void getmove(int& x, int& y);
};


// Constructor for X_O_Player
template <typename T>
word_Player<T>::word_Player(string name, T symbol) : Player<T>(name, symbol) {}


template <typename T>
void word_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}

// Random player for Word Game
template <typename T>
class word_Random_Player : public RandomPlayer<T> , word_Board<T>{
public:
    word_Random_Player(T symbol);
    void getmove(int& x, int& y);
};
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

// AI player for Word Game
template <typename T>
class word_AI_Player : public Player<T> {
public:
     word_AI_Player(T symbol);
    void getmove(int& x, int& y);
};

int main() {
    int choice;
    Player<char>* players[2];
    word_Board<char>* B = new word_Board<char>();
    string playerXName, player2Name;
    // Set up player 1
    cout << "\nEnter Player 1 name: ";
    cin >> playerXName;
    cout << "\n Choose Player 1 type: \n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new word_Player<char>(playerXName, 'x');
        break;
        case 2:
            players[0] = new word_Random_Player<char>('o');
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
            players[1] = new word_Player<char>(player2Name, 'x');
        break;
        case 2:
            players[1] = new word_Random_Player<char>('o');
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
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

    return 0;
}

