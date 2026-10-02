#include "ChessBoard.h"
#include <iostream>
#include <cctype>
#include <cmath>

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

    // Rooks (Elephants)
    board[0][0] = board[0][7] = 'R';
    board[7][0] = board[7][7] = 'r';

    // Knights (Horses)
    board[0][1] = board[0][6] = 'N';
    board[7][1] = board[7][6] = 'n';

    // Bishops
    board[0][2] = board[0][5] = 'B';
    board[7][2] = board[7][5] = 'b';

    // Queens
    board[0][3] = 'Q';
    board[7][3] = 'q';

    // Kings
    board[0][4] = 'K';
    board[7][4] = 'k';

    // Empty squares
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = '.';
        }
    }
}

void ChessBoard::printBoard() {

    std::cout << "\n";
    std::cout << (whiteTurn ? "WHITE TO MOVE\n\n"
                            : "BLACK TO MOVE\n\n");

    for (int i = 7; i >= 0; i--) {

        std::cout << i + 1 << " ";

        for (int j = 0; j < 8; j++) {

            if ((i + j) % 2 == 0)
                std::cout << "[" << board[i][j] << "]";
            else
                std::cout << "{" << board[i][j] << "}";

        }

        std::cout << "\n";
    }

    std::cout << "   a  b  c  d  e  f  g  h\n\n";
}

Move ChessBoard::parseMove(const std::string &input) {

    Move m;

    m.fromX = input[0] - 'a';
    m.fromY = input[1] - '1';

    m.toX = input[3] - 'a';
    m.toY = input[4] - '1';

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

bool ChessBoard::isPathClear(int fromX, int fromY,
                             int toX, int toY) {

    int dx = (toX - fromX) == 0 ? 0 :
            ((toX - fromX) > 0 ? 1 : -1);

    int dy = (toY - fromY) == 0 ? 0 :
            ((toY - fromY) > 0 ? 1 : -1);

    int x = fromX + dx;
    int y = fromY + dy;

    while (x != toX || y != toY) {

        if (board[y][x] != '.')
            return false;

        x += dx;
        y += dy;
    }

    return true;
}

bool ChessBoard::isLegalMove(Move m) {

    char piece = board[m.fromY][m.fromX];
    char target = board[m.toY][m.toX];

    if (piece == '.')
        return false;

    if (m.fromX == m.toX &&
        m.fromY == m.toY)
        return false;

    // Turn-based validation
    if (whiteTurn && std::islower(piece))
        return false;

    if (!whiteTurn && std::isupper(piece))
        return false;

    // Prevent friendly captures
    if (target != '.') {

        if (whiteTurn && std::isupper(target))
            return false;

        if (!whiteTurn && std::islower(target))
            return false;
    }

    int dx = m.toX - m.fromX;
    int dy = m.toY - m.fromY;

    switch (std::tolower(piece)) {

        case 'p': // Pawn

            if (whiteTurn) {

                if (dy == 1 &&
                    dx == 0 &&
                    target == '.')
                    return true;

                if (dy == 1 &&
                    std::abs(dx) == 1 &&
                    std::islower(target))
                    return true;
            }
            else {

                if (dy == -1 &&
                    dx == 0 &&
                    target == '.')
                    return true;

                if (dy == -1 &&
                    std::abs(dx) == 1 &&
                    std::isupper(target))
                    return true;
            }

            break;

        case 'r': // Rook / Elephant

            if (dx == 0 || dy == 0) {

                if (isPathClear(
                        m.fromX,
                        m.fromY,
                        m.toX,
                        m.toY))
                    return true;
            }

            break;

        case 'n': // Horse

            if ((std::abs(dx) == 2 &&
                 std::abs(dy) == 1) ||

                (std::abs(dx) == 1 &&
                 std::abs(dy) == 2))

                return true;

            break;

        case 'b': // Bishop

            if (std::abs(dx) ==
                std::abs(dy)) {

                if (isPathClear(
                        m.fromX,
                        m.fromY,
                        m.toX,
                        m.toY))
                    return true;
            }

            break;

        case 'q': // Queen

            if (std::abs(dx) ==
                    std::abs(dy) ||

                dx == 0 ||
                dy == 0) {

                if (isPathClear(
                        m.fromX,
                        m.fromY,
                        m.toX,
                        m.toY))
                    return true;
            }

            break;

        case 'k': // King

            if (std::abs(dx) <= 1 &&
                std::abs(dy) <= 1)
                return true;

            break;
    }

    return false;
}