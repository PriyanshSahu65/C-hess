# C++hess

A C++ chess project.

## Project layout

- `src/` - application and implementation source files
- `include/` - public header files
- `tests/` - unit tests
- `assets/` - sprites, fonts, and other UI assets
- `docs/` - architecture notes and sprint documentation

## Build

```sh
cmake -S . -B build -DBUILD_TESTING=OFF
cmake --build build --config Debug
build/scripts/cpphess.exe
```

## Working features

- ChessBoard.h - Currently! we have a struct named Move and a class called ChessBoard(Main Class)
1. The ChessBoard Class contains var for the 8x8 board and an bool value named WhiteTurn (for Turn based mode)
2. 'ChessBoard Constructor' -> calls setupBoard and turns the bool flag WhiteTurn to true.
3. 'setupBoard()' -> Handels the initial placements of the pieces and setting ASCII board, Capital letters being White and empty seq = '.'
