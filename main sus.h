#include <bits/stdc++.h>
#include "BoardGame_Classes.h"
#include "SUS.h"

using namespace std;

void main_SUS() {

    char choice;
    Player<char>* players[2];
    string player1Name, player2Name;

    cout << "====== Welcome to SUS Tic Tac Toe Game ======\n\n";

    // Lambda function for input validation
    auto validate_choice = []() {
        char c;
        while (true) {
            cin >> c;
            c = toupper(c);
            if (c == 'A' || c == 'B') return c;
            cout << "Invalid input. Try again (A or B): ";
        }
    };

    // Set up player 1
    cout << "Please, enter Player 1 name: ";
    cin >> player1Name;

    cout << "Choose Player 1 type:\n";
    cout << "A) Human\n";
    cout << "B) Random Computer\n";
    cout << "Enter your choice (A or B): ";
    choice = validate_choice();

    if (choice == 'A')
        players[0] = new SUS_Player<char>(player1Name, 'S');
    else
        players[0] = new SUS_Random_Player<char>('S');

    // Set up player 2
    cout << "\nPlease, enter Player 2 name: ";
    cin >> player2Name;

    cout << "Choose Player 2 type:\n";
    cout << "A) Human\n";
    cout << "B) Random Computer\n";
    cout << "Enter your choice (A or B): ";
    choice = validate_choice();

    if (choice == 'A')
        players[1] = new SUS_Player<char>(player2Name, 'U');
    else
        players[1] = new SUS_Random_Player<char>('U');

    // Create the game manager and run the game
    SUS_Board<char>* board = nullptr;
    try {
        board = new SUS_Board<char>(players);
        GameManager<char> SUS_game(board, players);
        SUS_game.run();
    }
    catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }

    // Clean up dynamically allocated memory
    delete board;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
