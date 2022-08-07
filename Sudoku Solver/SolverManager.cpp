#include "SolverManager.h"
#include <iostream>
using namespace std;


//Constructors
SolverManager::SolverManager() {
	this->mapSize = 9;
	solverIterations = 0;
	
}


std::vector<std::vector<int>> SolverManager::SolveSudokuMap(std::vector<std::vector<int>> newMap)
{
	sudokuMap = newMap;
	currentSolvingMethods.loadMap(sudokuMap);

	sudokuMap[0][0] = 9;

	int foundValue;
	do {
		foundValue = mapIterator();
	} while (foundValue == valueFound);

	if (foundValue == allValuesFound) {
		cout << "A value was found" << endl;
	}
	else {
		cout << "The SudokuMap could not be solved" << endl;
	}
	return sudokuMap;
}

//returns allValuesFound if it could not find a missing number. returns noValueFound if found a missing number but could not find a value for it. returns valueFound if a value was found.
int SolverManager::mapIterator()
{
	int result;
	bool missingValue = false;
	for (int col = 0; col < sudokuMap.size(); col++) {
		for (int row = 0; row < sudokuMap[col].size(); row++) {
			for (SolvingMethods solvingMethod : solvingMethods) {

				if (sudokuMap[col][row] == 0) {
					missingValue = true;
					result = (currentSolvingMethods.*solvingMethod)(col, row);
					sudokuMap[col][row] = result;
					//I think this a little weird but I dont want the solver methods to have to assign the cell and I cant get c++ to get the classes to share. 
					currentSolvingMethods.sudokuMap[col][row] = result;
					if (result != 0) return valueFound;
				}

			}
		}
	}

	if (missingValue == true) return noValueFound;
	else return allValuesFound;
}
