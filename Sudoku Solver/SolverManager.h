#pragma once

#include <vector>
#include "SudokuSolverMethods.h"

class SolverManager
{
public:
	SolverManager(std::vector<std::vector<int>> newMap);
	SolverManager();
	~SolverManager();
	std::vector<std::vector<int>> SolveSudokuMap();
	int mapIterator();
	bool checkIfValidSolution();

private:
	std::vector<std::vector<int>> sudokuMap;
	int solverIterations;
	int mapSize;
	SudokuSolverMethods *currentSolvingMethods;
	enum IterationReturns
	{
		valueFound,
		noValueFound,
		allValuesFound,
		invalidSolution
	};


	typedef int(SudokuSolverMethods::*SolvingMethods)(int, int);
	std::vector<SolvingMethods>  solvingMethods = {

		//Enter the SudokuSolverMethod here in the format of &SudokuSolverMethods::METHODNAME add comas where needed.
		&SudokuSolverMethods::lastPossibleValue,
		&SudokuSolverMethods::eliminateLikeValues
		
	};
	
};

