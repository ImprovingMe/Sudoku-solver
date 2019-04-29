// Sean Brookins, Last updated: 04/21/2019
// Final project - Sudoku solver
// Puzzle.h defines the prototypes for Puzzle.cpp

#pragma once
#ifndef PuzzleConstraints
#define SIDELEN 3 // Number of cells in a square lenth
#define UNUSED 0 // Describes value for cells that haven't been utilized in the puzzle yet
#endif //!PuzzleConstraints

constexpr int gridLength{ SIDELEN * SIDELEN }; // Total length of grid

class Puzzle
{
public:
	Puzzle();
	Puzzle(const int grid[gridLength][gridLength]);
	~Puzzle();
	void Print_Puzzle(); // Displays puzzle in console

protected:
	int grid[gridLength][gridLength]; // Our board
private:


};
