# C++hess

A C++ chess project.

## Project layout

- `src/` - application and implementation source files
- `include/` - public header files
- `tests/` - unit tests
- `assets/` - sprites, fonts, and other UI assets
- `docs/` - architecture notes and sprint documentation

## ASCII UI
```
8 r n b q k b n r 
7 p p p p p p p p 
6 . . . . . . . . 
5 . . . . . . . . 
4 . . . . . . . . 
3 . . . . . . . . 
2 P P P P P P P P 
1 R N B Q K B N R 
  a b c d e f g h
White move: a2 a3
8 r n b q k b n r 
7 p p p p p p p p 
6 . . . . . . . . 
5 . . . . . . . . 
4 . . . . . . . . 
3 P . . . . . . . 
2 . P P P P P P P 
1 R N B Q K B N R 
  a b c d e f g h
```

## Build

```sh
cmake -S . -B build -DBUILD_TESTING=OFF
cmake --build build --config Debug
build/scripts/cpphess.exe
```

## Working features

- ChessBoard.h - Currently! we have a struct named Move and a class called ChessBoard(Main Class):
1. The ChessBoard Class contains var for the 8x8 board and an bool value named WhiteTurn (for Turn based mode).
2. 'ChessBoard Constructor' -> calls setupBoard and turns the bool flag WhiteTurn to true.
3. 'setupBoard()' -> Handels the initial placements of the pieces and setting ASCII board, Capital letters being White and empty seq = '.'
4. 'PrintBoard()' -> a simple loop to print the current Board and using simple Indexing trick to get a.....h and numbers on the left along. 
5. 'parseMove()' -> In our int main() we are currently using a string to get the user input, Its formate ig -> current_pos pos_to_be eg- (a2 a3) the is passed to parseMove(input). The method is of type move means it has 4 val, 2 from and 2 to(where). when the string is passed, Inside the function we have a var of move type named m, This holds the compiler readable pos for performing the move. we index the 0,1,3,4 element of string and then subtract it with 'a' for char and '1' for int and return the final move m
6. 'makeMove()' -> It's a simple finctiopn which picks up the cahr from board (piece) and moves it to newpos and upadtes the old with, Its is also Dependent on a isLegalMove fx which tells its wheather the move is legal or not.
7. 
