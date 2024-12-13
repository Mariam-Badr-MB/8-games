#ifndef _MINMAXPLAYER_H
#define _MINMAXPLAYER_H

#include "BoardGame.h"

template <typename T>
class X_O_MinMax_Player : public Player<T> {
public:
    X_O_MinMax_Player(string name, T symbol);

    void getmove(int& x, int& y) override;

private:
    int calculateMinMax(T s, bool isMaximizing);
    std::pair<int, int> getBestMove();
};

//--------------------------------------- IMPLEMENTATION

#include <limits>
#include <algorithm> // For std::max and std::min
using namespace std;

template <typename T>
X_O_MinMax_Player<T>::X_O_MinMax_Player(string name, T symbol) : Player<T>(symbol) {
    this->name = name;
}

template <typename T>
void X_O_MinMax_Player<T>::getmove(int& x, int& y) {
    std::pair<int, int> bestMove = getBestMove();
    x = bestMove.first;
    y = bestMove.second;
}

template <typename T>
int X_O_MinMax_Player<T>::calculateMinMax(T s, bool isMaximizing) {
    if (this->boardPtr->is_win()) {
        return isMaximizing ? -10 : 10; // Penalize AI wins, reward opponent wins
    } else if (this->boardPtr->is_draw()) {
        return 0; // Draw is neutral
    }

    int bestValue = isMaximizing ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
    T opponentSymbol = (s == 'X') ? 'O' : 'X';

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (this->boardPtr->update_board(i, j, s)) {
                int value = calculateMinMax(opponentSymbol, !isMaximizing);
                this->boardPtr->update_board(i, j, 0); // Undo move

                if (isMaximizing) {
                    bestValue = std::min(bestValue, value); // Minimize for AI
                } else {
                    bestValue = std::max(bestValue, value); // Maximize for opponent
                }
            }
        }
    }

    return bestValue;
}

template <typename T>
std::pair<int, int> X_O_MinMax_Player<T>::getBestMove() {
    int bestValue = std::numeric_limits<int>::max(); // Minimize for AI
    std::pair<int, int> bestMove = {-1, -1};
    T opponentSymbol = (this->symbol == 'X') ? 'O' : 'X';

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (this->boardPtr->update_board(i, j, this->symbol)) {
                if (this->boardPtr->is_win()) {
                    this->boardPtr->update_board(i, j, 0); // Undo move
                    continue; // Skip this move, as it makes the AI "win"
                }

                int moveValue = calculateMinMax(opponentSymbol, false);
                this->boardPtr->update_board(i, j, 0); // Undo move

                if (moveValue < bestValue) { // Minimize for AI
                    bestMove = {i, j};
                    bestValue = moveValue;
                }
            }
        }
    }

    return bestMove;
}

#endif //_MINMAXPLAYER_H