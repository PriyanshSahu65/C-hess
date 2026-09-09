#include "ChessBoard.h"
#include <iostream>

ChessBoard::ChessBoard() {
    setupBoard();
    whiteTurn = true;
}

void ChessBoard::setupBoard() {
    // Pawns
    for (int i = 0; i < 8; i++) {
        board[1][i] = 'P';
        board[6][i] = 'p';
    }
    // Elephants
    board[0][0] = board[0][7] = 'R';
    board[7][0] = board[7][7] = 'r';
    // Horses
    board[0][1] = board[0][6] = 'N';
    board[7][1] = board[7][6] = 'n';
    // Bishops
    board[0][2] = board[0][5] = 'B';
    board[7][2] = board[7][5] = 'b';
    // Queens
    board[0][3] = 'Q'; board[7][3] = 'q';
    // Kings
    board[0][4] = 'K'; board[7][4] = 'k';

    // Empty squares
    for (int i = 2; i < 6; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = '.';
}

void ChessBoard::printBoard() {
    for (int i = 7; i >= 0; i--) {
        std::cout << i+1 << " ";
        for (int j = 0; j < 8; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "  a b c d e f g h\n";
}

Move ChessBoard::parseMove(const std::string &input) {
    Move m;
    m.fromX = input[0] - 'a';
    m.fromY = input[1] - '1';
    m.toX   = input[3] - 'a';
    m.toY   = input[4] - '1';
    return m;
}

bool ChessBoard::makeMove(Move m) {
    char piece = board[m.fromY][m.fromX];
    board[m.toY][m.toX] = piece;
    board[m.fromY][m.fromX] = '.';
    whiteTurn = !whiteTurn;
    return true;
}
