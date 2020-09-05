#pragma once

class Sudoku
{
private:
    int row{};
    int column{};
    int** matrix{};
public:
    Sudoku(int Row, int Column);
    ~Sudoku();
    void enterDigits();
    bool IsEmpty(int& row, int& column);
    bool ColumnCheck(int row, int e);
    bool RowCheck(int column, int e);
    bool BoxCheck(int row, int column, int e);
    bool solve();
    void print();

};



