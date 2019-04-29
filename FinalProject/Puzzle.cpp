// Sean Brookins, Last updated: 04/26/2019
// Final project - Sudoku solver
// Puzzle.cpp defines the class/structure for a sudoku puzzle

#include "Puzzle.h"
#include <iostream>


using namespace std;

static const int puzzleGridDefault[gridLength][gridLength] = // Taken from https://www.puzzles.ca/sudoku_puzzles/sudoku_easy_505.html
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

Puzzle::Puzzle() : Puzzle::Puzzle(puzzleGridDefault) {}
Puzzle::~Puzzle(){	//std::cout << "Puzzle destroyed " << this << endl; // Troubleshooting 
}
Puzzle::Puzzle(const int grid[gridLength][gridLength])
{
	for (int row = 0; row < gridLength; row++)
	{
		for (int col = 0; col < gridLength; col++)
			this->grid[row][col] = grid[row][col];
	}
}

void Puzzle::Print_Puzzle() // Prints the current puzzle
{
	for (int row = 0; row < gridLength; row++)
	{
		for (int col = 0; col < gridLength; col++)
		{
			printf("%2d ", this->grid[row][col]);
		}
		printf("\n");
	}
	printf("\n------------------------------\n\n");
}