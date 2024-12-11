#include <iostream>
#include "BoardGame_Classes.h"
#include "task5.h"

using namespace std;

int main() {
    int choice;
    Player<int>* players[2];
    NumericalTic_Tac_Toe_board<int>* B = new NumericalTic_Tac_Toe_board<int>();
    string playerXName, player2Name;
   

    cout << "Welcome to FCAI NumericalTic_Tac_Toe_board :)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new NumericalTic_Tac_Toe_player<int>(playerXName, 1);
            break;
        case 2:
            players[0] = new NumericalTic_Tac_Toe_random_player<int>(1);
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
    cin >> choice;

    switch(choice) {
        case 1:
            players[1] = new NumericalTic_Tac_Toe_player<int>(player2Name, 2);
            break;
        case 2:
            players[1] = new NumericalTic_Tac_Toe_random_player<int>(2);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return 1;
    }

    // Create the game manager and run the game
    GameManager<int> NumericalTic_Tac_Toe_game(B, players);
     NumericalTic_Tac_Toe_game .run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

    return 0;
}



