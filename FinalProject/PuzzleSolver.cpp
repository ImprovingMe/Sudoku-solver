// Sean Brookins, Last updated: 04/26/2019
// Final project - Sudoku solver
// PuzzleSolver.cpp provides mechanisms to solve a sodoku puzzle

#include "PuzzleSolver.h"
#include <iostream>

static const int puzzleSolverGridDefault[gridLength][gridLength] = // Taken from https://www.puzzles.ca/sudoku_puzzles/sudoku_easy_505.html
{
{ 0, 7, 0, 0, 0, 2, 0, 0, 0 },
{ 0, 9, 0, 3, 7, 0, 0, 0, 0 },
{ 0, 0, 5, 0, 8, 0, 0, 0, 1 },
{ 0, 0, 4, 7, 0, 0, 0, 0, 9 },
{ 0, 0, 0, 0, 9, 6, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 8, 6, 5, 4 },
{ 0, 2, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 1, 0, 4, 3 },
{ 4, 0, 7, 9, 5, 0, 2, 6, 0 }
};

PuzzleSolver::PuzzleSolver() : PuzzleSolver::PuzzleSolver(puzzleSolverGridDefault) {}
PuzzleSolver::~PuzzleSolver() {}
PuzzleSolver::PuzzleSolver(const int grid[gridLength][gridLength])
{
	for (int row = 0; row < gridLength; row++)
	{
		for (int col = 0; col < gridLength; col++)
			PuzzleSolver::grid[row][col] = grid[row][col];
	}
}


void PuzzleSolver::solution()
{
	if (PuzzleSolver::isSolved())
	{
		std::cout << "\tSolved " << std::endl << std::endl;
		this->Print_Puzzle();
	}
	else
	{
		std::cout << "The provided puzzle is unable to be solved." << std::endl;
		printf("\n------------------------------\n\n");
		this->Print_Puzzle();
	}
}


bool PuzzleSolver::isValid(int row, int col, int value)
{
	return	(
		!(
			doesBoxContain(row - row % 3, col - col % 3, value) ||
			doesRowContain(row, value) || doesColContain(col, value)
			) && this->grid[row][col] == UNUSED
		); // If the row, col, or box returns true then we will return false. Requires cell to be UNUSED.
}


bool PuzzleSolver::isSolved()
{
	int row = 0;
	int col = 0;

	if (!findNextEmptyCell(row, col))
		return true; // No more empty cells. Puzzle is solved.

	for (int cellCounter = 1; cellCounter <= gridLength; cellCounter++)
		// Allowed 1-gridLength based on gridLength by gridLength box.
	{
		if (isValid(row, col, cellCounter))
		{
			this->grid[row][col] = cellCounter; // Tentative assignment
			if (isSolved())
				return true; // We solved it!
			this->grid[row][col] = UNUSED; // If we didn't solve the puzzle, try again.
		}
	}
	return false; // If we fail to solve the puzzle, backtrack to the beginning and try again
}



bool PuzzleSolver::doesRowContain(int row, int value) const
{
	for (int col = 0; col < gridLength; col++)
	{
		if (this->grid[row][col] == value)
			return true;
	}
	return false;
}


bool PuzzleSolver::doesColContain(int col, int value) const
{
	for (int row = 0; row < gridLength; row++)
	{
		if (this->grid[row][col] == value)
			return true;
	}
	return false;
}


bool PuzzleSolver::doesBoxContain(int boxRow, int boxCol, int value) const
{
	for (int row = 0; row < SIDELEN; row++)
	{
		for (int col = 0; col < SIDELEN; col++)
		{
			if (this->grid[row + boxRow][col + boxCol] == value)
				return true;
		}
	}
	return false;
}


bool PuzzleSolver::findNextEmptyCell(int & row, int & col) const
{
	for (row = 0; row < gridLength; row++)
	{
		for (col = 0; col < gridLength; col++)
		{
			if (this->grid[row][col] == UNUSED)
				return true;
		}
	}
	return false;
}