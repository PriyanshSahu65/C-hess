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
cmake -S . -B build
cmake --build build
ctest --test-dir build
```
