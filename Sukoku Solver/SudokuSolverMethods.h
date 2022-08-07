#pragma once
#include <vector>
#include <iostream>

class SudokuSolverMethods
{
private:
public:

	std::vector<std::vector<int>> sudokuMap;
	int loadMap(std::vector<std::vector<int>> &sudokuMap) {
		this->sudokuMap = sudokuMap;
		return 0;
	}

	//Enter Sudoku Solving Methods in this area
	int lastPossibleValue(int col, int row) {

		return -1;
	}
	int eliminateLikeValues(int col, int row) {
		return -2;
	}








};


