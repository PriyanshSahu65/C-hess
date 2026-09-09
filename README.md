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

The executable is written to `build/scripts/cpphess.exe`. Tests are currently
disabled while the game code is being developed.
