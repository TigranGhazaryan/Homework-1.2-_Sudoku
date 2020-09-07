#include "Sudoku.h"
#include <iostream>

//Constructor
Sudoku::Sudoku(int Row, int Column) : row(Row), column(Column), matrix(new int*[Row])
{
    for (int i = 0; i < Row; ++i)
        matrix[i] = new int[Column];
}

//Destructor
Sudoku::~Sudoku()
{
    for (int i = 0; i < row; i++)
        delete[] matrix[i];
    delete[] matrix;
};

//1.Check for Valid Sudoku Pattern
bool Sudoku::ValidSudoku()
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            if (!ValidInput(j, i, matrix[j][i]))
                return false;
    return true;
}

//2.Enter Digits
void Sudoku::enterDigits()
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            std::cin >> matrix[i][j];

    if (!ValidSudoku())
    {
        std::cout << "Invalid Sudoku Pattern\n"
            << "Input another one!\n";
        enterDigits();
    }
}


//3. Row/Column is Empty 
bool Sudoku::IsEmpty(int& row, int& column)
{
    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->column; ++j)
        {
            if (matrix[j][i] == 0)
            {
                row = j;
                column = i;
                return true;
            }
        }
    }
    return false;
}

//4. Column Check
bool Sudoku::ColumnCheck(int row, int column, int e)
{
    for (int i = 0; i < this->column; ++i)
        if (e < 0 || e > 9 || (e > 0 && column != i && matrix[row][i] == e))
            return false;
    return true;
}

//5. Row Check
bool Sudoku::RowCheck(int row, int column, int e)
{
    for (int i = 0; i < this->row; ++i)
        if (e < 0 || e > 9 || (e > 0 && row != i && matrix[i][column] == e))
            return false;
    return true;
}

//6. BoxCheck
bool Sudoku::BoxCheck(int row, int column, int e)
{
    int row0 = (row / 3) * 3;
    int column0 = (column / 3) * 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (e < 0 || e > 9 || (e > 0 && row != (row0 + i) && column != (column0 + j) && matrix[row0 + i][column0 + j] == e))
                return false;
    return true;
}

//7.Check for ValidInput
bool Sudoku::ValidInput(int row, int column, int e)
{
    if (RowCheck(row, column, e) && ColumnCheck(row, column, e) && BoxCheck(row, column, e))
        return true;
    return false;
}

//8.Solve Sudoku
bool Sudoku::solve()
{
    int row{};
    int column{};

    //Base case
    if (!IsEmpty(row, column))
        return true;

    if (IsEmpty(row, column))
    {
        for (int e = 1; e <= 9; ++e)
        {
            if (ValidInput(row, column, e))
            {
                matrix[row][column] = e;
                if (solve())
                    return true;
                //Backtrack
                matrix[row][column] = 0;
            }
        }
        return false;
    }
}

//9.Print Solution
void Sudoku::print()
{
    std::cout << "\n";
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
            //Updated the printing order (matrix [i][j] is the correct output)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
}
