#include <iostream>
#include "Sudoku.h"

int main()
{
	Sudoku s(9, 9);
	s.enterDigits();
	s.solve();
	s.print();
}
