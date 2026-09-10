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
    if (!isLegalMove(m)) {
        std::cout << "Illegal move!\n";
        return false;
    }
    char piece = board[m.fromY][m.fromX];
    board[m.toY][m.toX] = piece;
    board[m.fromY][m.fromX] = '.';
    whiteTurn = !whiteTurn;
    return true;
}

bool ChessBoard::isPathClear(int fromX, int fromY, int toX, int toY) {
    int dx = (toX - fromX) == 0 ? 0 : (toX - fromX > 0 ? 1 : -1);
    int dy = (toY - fromY) == 0 ? 0 : (toY - fromY > 0 ? 1 : -1);

    int x = fromX + dx;
    int y = fromY + dy;

    while (x != toX || y != toY) {
        if (board[y][x] != '.') return false;
        x += dx;
        y += dy;
    }
    return true;
}

bool ChessBoard::isLegalMove(Move m) {
    char piece = board[m.fromY][m.fromX];
    if (piece == '.') return false;

    // Turn-based
    if (whiteTurn && islower(piece)) return false;
    if (!whiteTurn && isupper(piece)) return false;

    int dx = m.toX - m.fromX;
    int dy = m.toY - m.fromY;

    switch (tolower(piece)) {
        case 'p': // pawn
            if (whiteTurn) {
                if (dy == 1 && dx == 0 && board[m.toY][m.toX] == '.') return true;
                if (dy == 1 && abs(dx) == 1 && islower(board[m.toY][m.toX])) return true;
            } else {
                if (dy == -1 && dx == 0 && board[m.toY][m.toX] == '.') return true;
                if (dy == -1 && abs(dx) == 1 && isupper(board[m.toY][m.toX])) return true;
            }
            break;

        case 'r': // Elephant
            if (dx == 0 || dy == 0) {
                if (isPathClear(m.fromX, m.fromY, m.toX, m.toY)) return true;
            }
            break;

        case 'n': // Horse
            if ((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2)) return true;
            break;

        case 'b': // bishop
            if (abs(dx) == abs(dy)) {
                if (isPathClear(m.fromX, m.fromY, m.toX, m.toY)) return true;
            }
            break;

        case 'q': // queen
            if (abs(dx) == abs(dy) || dx == 0 || dy == 0) {
                if (isPathClear(m.fromX, m.fromY, m.toX, m.toY)) return true;
            }
            break;

        case 'k': // king
            if (abs(dx) <= 1 && abs(dy) <= 1) return true;
            break;
    }
    return false;
}


