#include "SolverManager.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

int printMap(vector<vector<int>>sudokuMapGrid) {
	for(unsigned int column =0; column < sudokuMapGrid.size();column++)
	{ 
		for (unsigned int row = 0; row < sudokuMapGrid[column].size();row++) {
			
			cout << sudokuMapGrid[column][row] << " ";
			if (row == 2 || row == 5) cout << "|";
		}
		cout << endl;
		if (column == 2 || column == 5) cout << setfill('-') << setw(19) << "-" << endl;
	}
	return 1;
}

int main(int argc, char argv[]) {
	fstream sukokuFile("TestPuzzle.txt");
	if (sukokuFile.is_open()) {
		string sudokuRow;
		vector<vector<int>> sudokuGrid;


		cout << "Contents of file" << endl;
		while (getline(sukokuFile, sudokuRow)) {
			stringstream rows(sudokuRow);
			string cell;
			vector<int>row;

			while (getline(rows, cell, ',')) {
				row.push_back(stoi(cell));
			}
			sudokuGrid.push_back(row);

		}
		printMap(sudokuGrid);
		SolverManager sudokuSolver(sudokuGrid);
		vector<vector<int>> solvedSudokuGrid;
		solvedSudokuGrid = sudokuSolver.SolveSudokuMap();
		printMap(solvedSudokuGrid);

	}
	else {
		cout << "File was not opened sucsesfully" << endl;
	}

	sukokuFile.close();
	return 0;
}