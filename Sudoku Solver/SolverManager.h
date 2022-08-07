#pragma once

#include <vector>
#include "SudokuSolverMethods.h"

class SolverManager
{
public:
	SolverManager();
	std::vector<std::vector<int>> SolveSudokuMap(std::vector<std::vector<int>> newMap);
	int mapIterator();

private:
	std::vector<std::vector<int>> sudokuMap;
	int solverIterations;
	int mapSize;
	SudokuSolverMethods currentSolvingMethods;
	enum IterationReturns
	{
		valueFound,
		noValueFound,
		allValuesFound
	};


	typedef int(SudokuSolverMethods::*SolvingMethods)(int, int);
	std::vector<SolvingMethods>  solvingMethods = {
		&SudokuSolverMethods::eliminateLikeValues,
		&SudokuSolverMethods::lastPossibleValue
	};
	
};

