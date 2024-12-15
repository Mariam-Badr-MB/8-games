#include<bits/stdc++.h>
#include "BoardGame_Classes.h"
#include "Misere Tic Tac Toe.h"

void main_Misere() {

    char choice ;
    Player<char>* players[2];
    Misere_Board<char>* B = new Misere_Board<char>();
    string player1Name, player2Name;

    cout << "====== Welcome to Misere Tic-Tac-Toe Game ======\n\n";


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
            players[0] = new Misere_Player<char>(player1Name, 'X');
            break;
        case 'B':
            players[0] = new Misere_Random_Player<char>(player1Name,'X');
            break;

        default:  break ;
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
            cin >> choice ;
        }
    }


    switch(choice) {
        case 'A':
            players[1] = new Misere_Player<char>(player2Name, 'O');
            break;
        case 'B':
            players[1] = new Misere_Random_Player<char>(player2Name,'O');
            break;

        default:
           break ;
        return ;
    }


    // Create the game manager and run the game
    GameManager<char> Misere_game(B, players);
    Misere_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }



}