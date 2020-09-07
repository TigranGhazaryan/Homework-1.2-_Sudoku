#include "Class.h"
#include <iostream>

//Constructor
Sudoku::Sudoku(int Row, int Column) : row(Row), column(Column)
{
    matrix = new int* [Row];
    for (int i = 0; i < Row; ++i)
        matrix[i] = new int[Column];
}

//Destructor
Sudoku::~Sudoku()
{
    for (int i = 0; i < column; i++)
        delete[] matrix[i];
    delete[] matrix;
};

//Enter Digits
void Sudoku::enterDigits()
{
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            std::cin >> matrix[i][j];
}



//1. Row/Column is Empty (== 0)
bool Sudoku::IsEmpty(int& row, int& column)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (matrix[j][i] == 0)
            {
                row = i;
                column = j;
                return true;
            }
        }
    }
    return false;
}

//2. Column Check
bool Sudoku::ColumnCheck(int row, int e)
{
    for (int i = 0; i < 9; ++i)
        if (matrix[row][i] == e)
            return false;
    return true;
}

//3. Row Check
bool Sudoku::RowCheck(int column, int e)
{
    for (int i = 0; i < 9; ++i)
        if (matrix[i][column] == e)
            return false;
    return true;
}

//4. BoxCheck
bool Sudoku::BoxCheck(int row, int column, int e)
{
    int row0 = (row / 3) * 3;
    int column0 = (column / 3) * 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (matrix[row0 + i][column0 + j] == e)
                return false;
    return true;
}

//Solve Sudoku
bool Sudoku::solve()
{
    int i{};
    int j{};
    
    //Base case
    if (!IsEmpty(i, j))
        return true;

    if (IsEmpty(i, j))
    {
        for (int e = 1; e <= 9; ++e)
        {
            if (RowCheck(i, e) && ColumnCheck(j, e) && BoxCheck(j, i, e))
            {
                matrix[j][i] = e;
                if (solve())
                   return true;  
                //Backtrack
                matrix[j][i] = 0;
            }
        }
        return false;
    }
}

//Print Solution
void Sudoku::print()
{
    std::cout << "\n";
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
            //Updated the printing order (matrix [i][j] is the correct output)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    };
}


