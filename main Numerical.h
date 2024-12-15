#include <bits/stdc++.h>
#include "BoardGame_Classes.h"
#include "Numerical Tic-Tac-Toe.h"

using namespace std;

void main_numerical() {
    
    char choice;
    Player<int>* players[2];
    Numerical_Tic_Tac_Toe_board<int>* B = new Numerical_Tic_Tac_Toe_board<int>();
    string player1Name, player2Name;
   

    cout << "===== Welcome to NumericalTic Tac Toe Game =====\n\n";

    // Set up player 1
    cout << "Please, enter Player1 name: ";
    cin >> player1Name;
    cout << "Choose Player1 type:\n";
    cout << "A) Human\n";
    cout << "B) Random Computer\n";
    cin >> choice; choice = toupper(choice) ;

    while(true){
        if (toupper(choice) == 'A' || toupper(choice) == 'B'){
            break ;
        }else{
            cin.ignore();
            cout << "Invalid input, Try again: " << endl ;
            cin >> choice ;
        }
    }

    switch(choice) {
        case 'A':
            players[0] = new Numerical_Tic_Tac_Toe_player<int>(player1Name, 1);
            break;
        case 'B':
            players[0] = new Numerical_Tic_Tac_Toe_random_player<int>(1);
            break;
        default:
            break ;
    }

    // Set up player 2
    cout << "Please, enter Player2 name: ";
    cin >> player2Name;
    cout << "Choose Player2 type:\n";
    cout << "A) Human\n";
    cout << "B) Random Computer\n";
    cin >> choice; choice = toupper(choice) ;

    while(true){
        if (toupper(choice) == 'A' && toupper(choice) == 'B'){
            break ;
        }else{
            cin.ignore();
            cout << "Invalid input, Try again: " << endl ;
            cin >> choice ;
        }
    }
    
    switch(choice) {
        case 'A':
            players[1] = new Numerical_Tic_Tac_Toe_player<int>(player2Name, 2);
            break;
        case 'B':
            players[1] = new Numerical_Tic_Tac_Toe_random_player<int>(2);
            break;
        default:
            break ;
    }

    // Create the game manager and run the game
    GameManager<int> Numerical_Tic_Tac_Toe_game(B, players);
     Numerical_Tic_Tac_Toe_game .run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}
