#include <cstdio>

#include "sudoku.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Please provide a sudoku string\n");
    return -1;
  }
  Sudoku *s = new Sudoku(argv[1]);
  char *solution = s->Solve();
  if (solution) {
    printf("Solution:\n%s\n", solution);
  } else {
    printf("No solution found!\n");
  }
  delete[] s;
  return 0;
}
