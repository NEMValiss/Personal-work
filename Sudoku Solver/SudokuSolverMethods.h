#pragma once
#include <vector>
#include <iostream>

class SudokuSolverMethods
{
private:
public:

	SudokuSolverMethods();
	SudokuSolverMethods(std::vector<std::vector<int>> &newMap) {
		//this->sudokuMap = newMap;
	} 

	std::vector<std::vector<int>> sudokuMap;
	

	//Enter Sudoku Solving Methods in this area
	int lastPossibleValue(int row, int colm) {
		//Look at all numbers that are in the same row, col, and subsquare and see if only one remains If so that is a soltion for col row
		int foundNumber[10] = { 0 };
		int subsquarCol = row/3;
		int subsquarRow = colm/3;
		for (int i = 0; i < 9; i++) {
			//check column numbers
			foundNumber[sudokuMap[i][colm]] = 1;
			//check row numbers
			foundNumber[sudokuMap[row][i]] = 1;
			//checksubsquar numbers
			foundNumber[sudokuMap[subsquarCol * 3 + i % 3][subsquarRow * 3 + i / 3]] = 1;
		}
		int sum = 0;
		int missing = 0;
		for (int i = 0; i < 10; i++) {
			if (foundNumber[i] == 1) sum++;
			else missing = i + 1;
		}
		//if sum is 9 then all numbers pluss 0(a empty spot) was found 
		if (sum == 9)  return missing;
		else return 0;

	}
	int eliminateLikeValues(int row, int colm) {
		int subsquarCol = row / 3;
		int subsquarRow = colm / 3;
		int foundNumber[10] = { 0 };
		
		//Check for missing values; Then check if the other rows and comlumsn in the subsquare all are missing the value, if so return value
		for (int i = 0; i < 9; i++) {
			//check column numbers
			foundNumber[sudokuMap[i][colm]] = 1;
			//check row numbers
			foundNumber[sudokuMap[row][i]] = 1;
			//checksubsquar numbers
			foundNumber[sudokuMap[subsquarCol * 3 + i % 3][subsquarRow * 3 + i / 3]] = 1;
		}

		for(int value = 0; value < 9; value++){


		}
	}








};


