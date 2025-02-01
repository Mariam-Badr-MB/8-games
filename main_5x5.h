#include<bits/stdc++.h>
#include "BoardGame_Classes.h"
#include "5 x 5 Tic Tac Toe.h"
#include "MinMax_player3.h"

void main_5x5() {

    char choice ;
    Player<char>* players[2];
    string player1Name, player2Name;

    cout << "====== Welcome to _5x5 Tic-Tac-Toe Game ======\n\n";


    // Set up player 1
    cout << "Please, enter Player1 name: ";
    cin >> player1Name;

    cout << "Choose Player1 type:\n";
    cout << "A) Human\n";
    cout << "B) Random Computer\n";
    cout << "C) Smart Computer (AI)\n";
    cin >> choice; choice = toupper(choice) ;

    while(true){
        if (toupper(choice) == 'A' || toupper(choice) == 'B'|| toupper(choice) == 'C'){
            break ;
        }else{
            cin.ignore();
            cout << "Invalid input, Try again: " << endl ;
            cin >> choice ; choice = toupper(choice) ;
        }
    }

    switch(choice) {
        case 'A':
            players[0] = new _5x5_Player<char>(player1Name, 'X');
            break;
        case 'B':
            players[0] = new _5x5_Random_Player<char>(player1Name,'X');
            break;
        case 'C':
            players[0] = new X_O_MinMax_Player3<char>( 'X');
        default:  break ;
    }

        // Set up player 2
    cout << "Please, enter Player2 name: ";
    cin >> player2Name;

    cout << "Choose Player2 type:\n";
    cout << "A) Human\n";
    cout << "B) Random Computer\n";
    cout << "C) Smart Computer (AI)\n";
    cin >> choice; choice = toupper(choice) ;

    while(true){
        if (toupper(choice) == 'A' || toupper(choice) == 'B'|| toupper(choice) == 'C'){
            break ;
        }else{
            cin.ignore();
            cout << "Invalid input, Try again: " << endl ;
            cin >> choice ; choice = toupper(choice) ;
        }
    }


     switch(choice) {
        case 'A':
            players[1] = new _5x5_Player<char>(player2Name, 'O');
            break;
        case 'B':
            players[1] = new _5x5_Random_Player<char>(player2Name,'O');
            break;
         case 'C':
             players[1] = new X_O_MinMax_Player3<char>( 'O');
        default:
            break ;
    }

    // Create the game manager and run the game
    _5x5_Board<char>* B = new _5x5_Board<char>(players);
    GameManager<char> _5x5_game(B, players);
    _5x5_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }


}
