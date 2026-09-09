#include "ChessBoard.h"
#include <iostream>

int main() {
    ChessBoard cb;
    cb.printBoard();

    std::string input;
    while (true) {
        std::cout << (cb.whiteTurn ? "White" : "Black") << " move: ";
        std::getline(std::cin, input);

        if (input == "exit") break;

        Move m = cb.parseMove(input);
        cb.makeMove(m);
        cb.printBoard();
    }
    return 0;
}
