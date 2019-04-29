// Sean Brookins, Last updated: 04/26/2019
// Final project - Sudoku solver
// FinalProject.cpp executes the main() code and tests both the default constructor + provided test puzzle

#include <iostream>
#include "PuzzleSolver.h"

using namespace std;
int main()
{
	cout << "------------------------------\nSodoku Solver\n------------------------------" << endl << endl;
	int grid[gridLength][gridLength] = // Taken from https://www.puzzles.ca/sudoku_puzzles/sudoku_easy_503.html
	{
	{ 6, 0, 0, 5, 0, 0, 7, 9, 0 },
	{ 0, 0, 0, 4, 0, 0, 0, 5, 0 },
	{ 4, 0, 0, 1, 0, 0, 0, 0, 0 },
	{ 7, 9, 0, 0, 0, 3, 0, 0, 0 },
	{ 0, 0, 2, 0, 8, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 9, 1, 8, 0, 0 },
	{ 0, 6, 0, 8, 0, 5, 0, 3, 0 },
	{ 8, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 3, 0, 2, 0, 1, 4, 0 }
	};

	int grid_unsolvable[gridLength][gridLength] = // Taken from https://www.puzzles.ca/sudoku_puzzles/sudoku_easy_503.html
	{
	{ 6, 0, 0, 5, 0, 0, 7, 9, 0 },
	{ 0, 0, 0, 4, 0, 0, 0, 5, 0 },
	{ 4, 0, 0, 1, 0, 0, 0, 0, 0 },
	{ 7, 9, 0, 1, 0, 3, 0, 0, 0 },
	{ 0, 0, 2, 0, 8, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 9, 1, 8, 0, 0 },
	{ 0, 6, 0, 8, 0, 5, 0, 3, 0 },
	{ 8, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 3, 0, 2, 0, 1, 4, 0 }
	};

	PuzzleSolver sudoku = PuzzleSolver();
	PuzzleSolver sudoku2 = PuzzleSolver(grid);
	PuzzleSolver sudoku3 = PuzzleSolver(grid_unsolvable);

	sudoku.solution();
	sudoku2.solution();
	sudoku3.solution();

	return 0;
}