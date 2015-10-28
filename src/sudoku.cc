#include "sudoku.h"

#include <cstring>

static const int kMaxRows = 9;
static const int kMaxColumns = 9;
static const int kSudokuLength = 81;

Sudoku::Sudoku(char * sudoku) {
  memcpy(sudoku_, sudoku, 81);
  sudoku_[kSudokuLength] = '\0';
}

int Sudoku::GetEmptyTileIndex() {
  for (int i = 0; i < kSudokuLength; ++i) {
    if (sudoku_[i] < '1' || sudoku_[i] > '9') {
      return i;
    }
  }
  return -1;
}

void Sudoku::GetSharedTilesInRow(int tile, char *destination) {
  int row = tile/kMaxRows;
  for (int column = 0; column < kMaxColumns; ++column) {
    destination[column] = sudoku_[column + row*kMaxColumns];
  }
}

void Sudoku::GetSharedTilesInColumn(int tile, char *destination) {
  int column = tile%kMaxColumns;
  for (int row = 0; row < kMaxRows; ++row) {
    destination[row] = sudoku_[column + (row*kMaxColumns)];
  }
}

void Sudoku::GetSharedTilesInSquare(int tile, char *destination) {
  int index = 0;
  for (int row = ((tile/kMaxRows)/3)*3; row < ((tile/kMaxRows)/3+1)*3; ++row) {
    for (int column = ((tile%kMaxColumns)/3)*3; column < ((tile%kMaxColumns)/3+1)*3; ++column) {
      destination[index++] = sudoku_[column + row*kMaxColumns];
    }
  }
}

void Sudoku::FindValidEntries(int tile, bool *destination) {
  // find all tiles in same row, column and square
  char shared_tiles[27];
  GetSharedTilesInRow(tile, &(shared_tiles[0]));
  GetSharedTilesInColumn(tile, &(shared_tiles[9]));
  GetSharedTilesInSquare(tile, &(shared_tiles[18]));
  // initialize valid entries array
  for (int i = 0; i < 9; ++i) {
    destination[i] = true;
  }
  // mark all numbers found in shared entries false
  int number = 0;
  for (int i = 0; i < 27; ++i) {
    number = shared_tiles[i] - '0';
    if (number>=1 && number<=9) {
      destination[number-1] = false;
    }
  }
}

char *Sudoku::Solve() {
  int empty_tile_index = GetEmptyTileIndex();
  if (empty_tile_index < 0) {
    return sudoku_;
  } else {
    bool valid_entries[9];
    FindValidEntries(empty_tile_index, valid_entries);
    // bruteforce all possible entries in a new sudoku until solved
    for (int i = 0; i < 9; ++i) {
      if (valid_entries[i]) {
        // try valid entry
        sudoku_[empty_tile_index] = i+'1';
        Sudoku *child = new Sudoku(sudoku_);
        char *solution = child->Solve();
        if (solution) {
          // return solution
          memcpy(sudoku_, solution, 81);
          delete[] child;
          return sudoku_;
        } else {
          delete[] child;
        }
      }    }
    return NULL;
  }
}
