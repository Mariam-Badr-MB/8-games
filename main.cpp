#include <iostream>
# include "BoardGame.h"
#include "problem6.h"
#include "MinMaxPlayer6.h"

using namespace std;

void problem6() {
    int choice1, choice2;
    Player<char>* players[2];
    X_O_Board<char>* B = new X_O_Board<char>();
    string playerXName, player2Name;

    cout << "Welcome to  Misere Tic Tac Toe Game. :)\n";

    cout << "Enter Player X name: ";
    // Set up player 1
    cin >> playerXName;

    cout << "Enter Player 2 name: ";
    cin >> player2Name;

    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice1;


    switch(choice1) {
        case 1:
            players[0] = new X_O_Player<char>(player2Name, 'X');
        break;
        case 2:
            players[0] = new X_O_Random_Player<char>(player2Name,'X');

        break;
        case 3:
            players[0] = new X_O_MinMax_Player<char>(player2Name,'X');
        players[0]->setBoard(B);
        break;

        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
        return ;
    }

    // Set up player 2

    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice2;

    switch(choice2) {
        case 1:
            players[1] = new X_O_Player<char>(playerXName, 'O');
        break;
        case 2:
            players[1] = new X_O_Random_Player<char>(playerXName,'O');
        break;

        case 3:
            players[1] = new X_O_MinMax_Player<char>(playerXName,'O');
        players[1]->setBoard(B);
        break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
        return ;
    }

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);

    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }



}
int main() {
    problem6();
}


