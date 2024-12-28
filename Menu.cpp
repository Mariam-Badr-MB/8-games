#include<bits/stdc++.h>
#include "BoardGame_Classes.h"

#include "main_Pyramid.h"
#include "main_Four_In_A_Row.h"
#include "main_5x5.h"
#include "main_word.h"
#include "main Numerical.h"
#include "main misere.h"
#include "main_4x4.h"
#include "main Ultimate.h"
#include "main sus.h"

using namespace std;

void clear_Input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();
}

int main() {

    cout << "******************************************* Welcome to the 8 Games *******************************************" << endl << endl;
   
    while (true) {

        int choice1 ;

        cout << "\n1) Pyramid Tic-Tac-Toe  " << endl ;
        cout << "2) Four-in-a-row  " << endl ;
        cout << "3) 5 x 5 Tic Tac Toe  " << endl ;
        cout << "4) Word Tic-Tac-Toe  " << endl ;
        cout << "5) Numerical Tic-Tac-Toe  " << endl ;
        cout << "6) Misere Tic Tac Toe  " << endl ;
        cout << "7) 4 x 4 Tic-Tac-Toe  " << endl ;
        cout << "8) Ultimate Tic Tac Toe  " << endl ;
        cout << "9) SUS  " << endl ;
        cout << "10) Exit   " << endl ;

        cout << "\n Please, enter what you want:  "  ;
        cin >> choice1;

        cout << endl ;
        while (true) {
            if ((choice1 >= 1 && choice1 <= 10) || cin.fail()) {
                break ;
            } else {
                clear_Input();
                cout << "Invalid input, Try again: " ;
                cin >> choice1;
                cout << endl ;
            }
        }

        switch (choice1) {
            case 1: main_Pyramid();
                break ;
            case 2: main_Four_In_A_Row();
                break ;
            case 3: main_5x5() ;
                break ;
            case 4: main_word();
                break ;
            case 5: main_numerical();
                break ;
            case 6: main_Misere();
                break ;
            case 7: main_4x4() ;
                break ;
            case 8: main_Ultimate() ;
                break ;
            case 9 :
                main_SUS();
                break ;
            case 10:
                cout << "***** Thanks For Using These games *****" << endl ;
                exit(0) ;
                break ;
            default: break ;
        }
        clear_Input() ;
    }
    return 0;
}
