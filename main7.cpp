#include <iostream>
# include "Board_Game.h"
#include "problem7.h"


using namespace std;

int main() {
    int choice1, choice2;
    Player<char>* players[2];
    X_O_Board<char>* B = new X_O_Board<char>();
    string playerXName, player2Name;

    cout << "Welcome to  4 x 4 Tic-Tac-Toe Game. :)\n";

    cout << "Enter Player X name: ";
    // Set up player 1
    cin >> playerXName;

    cout << "Enter Player 2 name: ";
    cin >> player2Name;

    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";

    cin >> choice1;


    switch(choice1) {
        case 1:
            players[0] = new X_O_Player<char>(playerXName, 'X');
        break;
        case 2:
            players[0] = new X_O_Random_Player<char>(playerXName,'X');
        break;


        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
        return 1;
    }

    // Set up player 2

    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice2;

    switch(choice2) {
        case 1:
            players[1] = new X_O_Player<char>(player2Name, 'O');
        break;
        case 2:
            players[1] = new X_O_Random_Player<char>(player2Name,'O');
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



