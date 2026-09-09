#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <vector>
#include <string>

struct Move {
    int fromX, fromY;
    int toX, toY;
};

class ChessBoard {
public:
    char board[8][8];
    bool whiteTurn;

    ChessBoard();
    void setupBoard();
    void printBoard();
    bool makeMove(Move m);
    Move parseMove(const std::string &input);
};

#endif
