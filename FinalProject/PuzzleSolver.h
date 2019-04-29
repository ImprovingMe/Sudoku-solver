// Sean Brookins, Last updated: 04/26/2019
// Final project - Sudoku solver
// PuzzleSolver.h defines the prototypes for PuzzleSolver.cpp

#pragma once
#include "Puzzle.h"


class PuzzleSolver : public Puzzle
{
public:
	PuzzleSolver();
	//PuzzleSolver(int grid[gridLength][gridLength]); // No longer need this as you can pass a regular int to a const int ctor. 
	PuzzleSolver(const int grid[gridLength][gridLength]);
	~PuzzleSolver();
	void solution(); // Calculate and display the outcome

private:
	bool isValid(int row,
		int col, int value); // Determines if the desired move is legal
	bool doesRowContain(int row, int value) const; // Determines if the value is contained within the row
	bool doesColContain(int col, int value) const; // Determines if the value is contained within the column
	bool doesBoxContain(int boxRow, int boxCol, int value) const; // Determiens if the value is contained within the SIDELEN by SIDELEN area
	bool findNextEmptyCell(int &row, int &col) const; // Locates next unused cell determined by #define UNUSED
	bool isSolved(); // Recursive algorithm to identify if a puzzle is solved
};