#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku {
  private:
    char sudoku_[82];
    int GetEmptyTileIndex();
    void GetSharedTilesInRow(int, char *);
    void GetSharedTilesInColumn(int, char *);
    void GetSharedTilesInSquare(int, char *);
    void FindValidEntries(int, bool*);
  public:
    Sudoku(char * sudoku);
    char *Solve();
};

#endif // SUDOKU_H
