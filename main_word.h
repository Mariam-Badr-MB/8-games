#include <bits/stdc++.h>
#include "BoardGame_Classes.h"
#include "Word Tic-Tac-Toe.h"

using namespace std;

void main_word() {

    char choice;
    Player<char>* players[2];
    word_Board<char>* B = new word_Board<char>();
    string player1Name, player2Name;

   cout << "====== Welcome to Pyramid Tic Tac Toe Game ======\n\n";

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
            cin >> choice ; choice = toupper(choice) ;
        }
    }
    switch(choice) {
        case 'A':
            players[0] = new word_Player<char>(player1Name, 'x');
            break;
        case 'B':
            players[0] = new word_Random_Player<char>('o');
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
            players[1] = new word_Player<char>(player2Name, 'x');
           break;
        case 'B':
            players[1] = new word_Random_Player<char>('o');
            break;

        default:
          break ;
    }

    // Create the game manager and run the game
    GameManager<char> word_game(B, players);
    word_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}