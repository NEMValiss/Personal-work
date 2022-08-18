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
		//Look at all numbers that are in the same row, col, and subsquare (Group) and see if only one remains If so that is a soltion for col row
		int foundNumber[10] = { 0 };
		int subsquarRow = row/3;
		int subsquarColm = colm/3;
		for (int i = 0; i < 9; i++) {
			//check column numbers
			foundNumber[sudokuMap[i][colm]] = 1;
			//check row numbers
			foundNumber[sudokuMap[row][i]] = 1;
			//checksubsquare numbers
			foundNumber[sudokuMap[subsquarRow * 3 + i % 3][subsquarColm * 3 + i / 3]] = 1;
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
		int subsquarRow = row / 3;
		int subsquarColm = colm / 3;
		int foundNumber[10] = { 0 };
		
		//Check for missing values; Then check if the other rows and comlumsn in the subsquare all are missing the value, if so return value
		for (int i = 0; i < 9; i++) {
			//check column numbers
			foundNumber[sudokuMap[i][colm]] = 1;
			//check row numbers
			foundNumber[sudokuMap[row][i]] = 1;
			//checksubsquare numbers
			foundNumber[sudokuMap[subsquarRow * 3 + i % 3][subsquarColm * 3 + i / 3]] = 1;
		}

		//check location to see if there are no like values in its group (Group: a cell in the same column, row, subsquare
		for(int value = 1; value <= 9; value++){
			if (foundNumber[value] == 0) {
				int possibleValueLoactionElimination = 0; //if set to 1 it is not guarenteed to be the location.

				for (int i = 0; i < 9; i++)
				{
					//if value can not be eliminated from possible location  possibleValueLoactionElimination should be assigned to 1 to say that row,colm could not be narrowed down to value
					if (sudokuMap[i][colm] == 0) {
						//ignore values in subsquare and row,colm
						if (i / 3 != subsquarRow && i != row) {
							//check row and subsquare of possible loaction to see if it can be eliminated as a possible value loaction.
							for (int j = 0;j < 9;j++) {

							}
						
						}
					}
					if (sudokuMap[row][i] == 0) {
						//ignore values in subsquare and row,colm
						if (i / 3 != subsquarColm && i != colm) {
							//check colm and subsquare of possible loaction to see if it can be eliminated as a possible value loaction.

						}

					}
					if (sudokuMap[subsquarRow * 3 + i % 3][subsquarColm * 3 + i / 3] == 0) {
						//ignore row,colm
						if (!(subsquarRow * 3 + i % 3 == row && subsquarColm * 3 + i / 3 == colm)) {
							//check row and colm of possible locations to see if it can be eliminated

						}
					}
				}
				if (possibleValueLoactionElimination == 0) {
					return value;
				}

			}

		}


		return 0;
	}








};


