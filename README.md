# sudoku_solver
A sudoku solver program written in c++. It solves the sudoku using a recursive bruteforce.

## Installation
To install it on your local machine you will need to have cmake installed.
Use the following commands to install the sudoku_solver on your machine:
```bash
git clone https://github.com/sprmn/sudoku_solver.git
cd sudoku_solver
mkdir build
cd build
cmake ..
make
```

## Usage
You will have to provide the sudoku as a first argument to the program. Any character that is not equal to a number in the range 1-9 will be treated as an empty tile.

Example:
```bash
./sudoku_solver xxx491x764xxxx6x5xx7x2x34915xxxxx768x197x8x2xx6xxxx3xx932145xxxx4xx879x26x793x145
```
