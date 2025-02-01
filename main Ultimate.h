#include<bits/stdc++.h>
#include "BoardGame_Classes.h"
#include "Ultimate Tic Tac Toe.h"


void main_Ultimate(){

    char choice;
    Player<char>* players[2];
    Ultimate_tic_tac_Board<char>* B = new Ultimate_tic_tac_Board<char>();
    string player1Name, player2Name;

    cout << "====== Welcome to Ultimate Tic-Tac-Toe Game ======\n\n";

     // Set up player 1

    cout << "Please, enter Player1 name: ";
    cin >> player1Name;

    cout << "Choose Player1 type:\n";
    cout << "A) Human\n";
    cout << "B) Random Computer\n";
    cin >> choice; choice = toupper(choice) ;

    while(true){
        if (toupper (choice) == 'A' || toupper(choice) == 'B'){
            break ;
        }else{
            cin.ignore();
            cout << "Invalid input, Try again: "  ;
            cin >> choice ;choice = toupper(choice) ;
        }
    }
    cout << endl ;

    switch(choice) {
        case 'A' :
            players[0] = new Ultimate_tic_tac_player<char>(player1Name, 'X');
            break;
        case 'B' :
            players[0] = new Ultimate_tic_tac_Random_Player<char>('X');
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
        if (toupper (choice) == 'A' || toupper (choice) == 'B'){
            break ;
        }else{
            cin.ignore();
            cout << "Invalid input, Try again: " << endl ;
            cin >> choice ; choice = toupper(choice) ;
        }
    }

    switch(choice) {
        case 'A':
            players[1] = new Ultimate_tic_tac_player<char>(player2Name, 'O');
            break;
        case 'B' :
            players[1] = new Ultimate_tic_tac_Random_Player<char>('O');
            break;
        default:
              break ;
    }

    // Create the game manager and run the game
    GameManager<char> Ultimate_tic_tac_game(B, players);
    Ultimate_tic_tac_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}