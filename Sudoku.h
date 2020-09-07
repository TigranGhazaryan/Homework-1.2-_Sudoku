#pragma once

class Sudoku
{
private:
    int row{};
    int column{};
    int** matrix{};
    bool ValidSudoku();
    bool IsEmpty(int& row, int& column);
    bool ColumnCheck(int row, int column, int e);
    bool RowCheck(int row, int column, int e);
    bool BoxCheck(int row, int column, int e);
    bool ValidInput(int row, int column, int e);
   
public:
    Sudoku(int Row, int Column);
    ~Sudoku();
    void enterDigits();
    bool solve();
    void print();

};

