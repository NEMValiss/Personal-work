#include "SolverManager.h"
#include <iostream>
using namespace std;


SolverManager::SolverManager(std::vector<std::vector<int>> newMap) {
	mapSize = 9;
	solverIterations = 0;
	sudokuMap = newMap;
	currentSolvingMethods = new SudokuSolverMethods(sudokuMap);
	currentSolvingMethods->sudokuMap = this->sudokuMap;
}

SolverManager::SolverManager()
{
}
SolverManager::~SolverManager() {
	delete(currentSolvingMethods);
}



std::vector<std::vector<int>> SolverManager::SolveSudokuMap()
{


	int foundValue = 0;
	do {
		foundValue = mapIterator();
	} while (foundValue == valueFound);

	if (foundValue == allValuesFound) {
		cout << "A value was found" << endl;
	}
	else if(foundValue == noValueFound){
		cout << "The SudokuMap could not be solved" << endl;
	}
	else {
		cout << "Solution found was invalid" << endl;
	}
	return sudokuMap;
}

//returns allValuesFound if it could not find a missing number. returns noValueFound if found a missing number but could not find a value for it. returns valueFound if a value was found.
int SolverManager::mapIterator()
{
	int result;
	bool missingValue = false;
	for (unsigned int row = 0; row < sudokuMap.size(); row++) {
		for (unsigned int colm = 0; colm < sudokuMap[row].size(); colm++) {

			cout << sudokuMap[row][colm];
			for (SolvingMethods solvingMethod : solvingMethods) {

				if (sudokuMap[row][colm] == 0) {
					missingValue = true;
					result = (currentSolvingMethods->*solvingMethod)(row, colm);
					sudokuMap[row][colm] = result;
					currentSolvingMethods->sudokuMap[row][colm] = result;
					if (result != 0) return valueFound;
				}

			}
		}
	}

	if (missingValue == true) return noValueFound;
	else {
		if (checkIfValidSolution()) return allValuesFound;
		else return invalidSolution;
	}
}

bool SolverManager::checkIfValidSolution()
{
	//check if the sum off all the cells is 48*9
	int totalCellSum = 0;
	for (vector<int> col : sudokuMap) {
		for (int cell : col) {
			totalCellSum++;
		}
	}

	if (totalCellSum == 48 * 9) return true;
	else return false;
	
}
