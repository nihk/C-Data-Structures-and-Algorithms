#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "GridTraversing.h"

void printMazeGrid(char maze[NUM_MAZE_ROWS][NUM_MAZE_COLS]) {
	for (int i = 0; i < NUM_MAZE_ROWS; i++) {
		for (int j = 0; j < NUM_MAZE_COLS; j++) {
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}

void printFloodGrid(int image[NUM_FLOOD_ROWS_AND_COLS][NUM_FLOOD_ROWS_AND_COLS]) {
	for (int i = 0; i < NUM_FLOOD_ROWS_AND_COLS; i++) {
		for (int j = 0; j < NUM_FLOOD_ROWS_AND_COLS; j++) {
			printf("%d", image[i][j]);
		}
		printf("\n");
	}
}

int traverseMaze(char maze[NUM_MAZE_ROWS][NUM_MAZE_COLS], int currRow, int currCol) {
	// Array bounds checking
	if (currRow < 0 || currCol < 0 || currRow >= NUM_MAZE_ROWS || currCol >= NUM_MAZE_COLS) return 0;

	char cell = maze[currRow][currCol];
	// Wall or already traversed cell checking
	if (cell == '#' || cell == 'x') return 0 ;

	// Else: cell was untraversed, so mark it so
	maze[currRow][currCol] = 'x';

	// End of maze reached
	if (cell == 'E') return 1;

	// If end of maze reached, don't continue (keep returning 1)
	if (traverseMaze(maze, currRow + 1, currCol)) return 1;
	if (traverseMaze(maze, currRow - 1, currCol)) return 1;
	if (traverseMaze(maze, currRow, currCol + 1)) return 1;
	if (traverseMaze(maze, currRow, currCol - 1)) return 1;

	// Didn't find the right way or the end, so clear the x
	maze[currRow][currCol] = ' '; 

	return 0;
}

int countContiguousCells(int grid[NUM_ORG_ROWS][NUM_ORG_COLS]) {
	int orgCount = 0;

	for (int i = 0; i < NUM_ORG_ROWS; i++) {
		for (int j = 0; j < NUM_ORG_COLS; j++) {
			if (grid[i][j] == 1) {
				orgCount++;
				findContiguousCell(grid, i, j);
			}
		}
	}
	return orgCount;
}

void findContiguousCell(int grid[NUM_ORG_ROWS][NUM_ORG_COLS], int currRow, int currCol) {
	// Array bounds checking
	if (currRow < 0 || currCol < 0 || currRow >= NUM_ORG_ROWS || currCol >= NUM_ORG_COLS) return;

	int cell = grid[currRow][currCol];
	if (cell != 1) return;
	
	// Marking a '1' cell as '2' means it is both a part of a contiguous group and has been visited
	grid[currRow][currCol] = 2; 
	findContiguousCell(grid, currRow - 1, currCol);
	findContiguousCell(grid, currRow + 1, currCol);
	findContiguousCell(grid, currRow , currCol + 1);
	findContiguousCell(grid, currRow, currCol - 1);
}

void floodFill(int image[NUM_FLOOD_ROWS_AND_COLS][NUM_FLOOD_ROWS_AND_COLS], int currRow, int currCol) {
	int cell = image[currRow][currCol];

	// 1 is a "wall" and 2 is an already "painted" cell
	if (cell == 1 || cell == 2) return;

	// "Paint" the cell with the "color" 2
	image[currRow][currCol] = 2;

	// Traverse all possible neighbouring non-walls (1s)
	floodFill(image, currRow + 1, currCol);
	floodFill(image, currRow - 1, currCol);
	floodFill(image, currRow, currCol + 1);
	floodFill(image, currRow, currCol - 1);
}
