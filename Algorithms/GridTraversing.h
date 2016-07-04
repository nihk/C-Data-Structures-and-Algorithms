#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define NUM_MAZE_ROWS 9
#define NUM_MAZE_COLS 11
#define NUM_ORG_ROWS 5
#define NUM_ORG_COLS 7
#define NUM_FLOOD_ROWS_AND_COLS 6

void printMazeGrid(char grid[NUM_MAZE_ROWS][NUM_MAZE_COLS]);
void printFloodGrid(int image[NUM_FLOOD_ROWS_AND_COLS][NUM_FLOOD_ROWS_AND_COLS]);
int traverseMaze(char maze[NUM_MAZE_ROWS][NUM_MAZE_COLS], int currRow, int currCol);
int countContiguousCells(int grid[NUM_ORG_ROWS][NUM_ORG_COLS]);
void findContiguousCell(int grid[NUM_ORG_ROWS][NUM_ORG_COLS], int currRow, int currCol);
void floodFill(int image[NUM_FLOOD_ROWS_AND_COLS][NUM_FLOOD_ROWS_AND_COLS], int currRow, int currCol);
