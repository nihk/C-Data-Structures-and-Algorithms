#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "GridTraversing.h"

int main(void) {
	// Maze traversal
	int startRow = 5;
	int startCol = 5;

	// 'S' is the start, 'E' is the exit
	char maze[NUM_MAZE_ROWS][NUM_MAZE_COLS] = {
		{ "##########" },
		{ "# #   #  #" },
		{ "# # # ## #" },
		{ "#   #    #" },
		{ "# ###### #" },
		{ "# # #S # E" },
		{ "#      # #" },
		{ "##########" }
	};

	traverseMaze(maze, startRow, startCol);
	printMazeGrid(maze);

	/* Maze traversal output:

		##########
		# #xxx#  #
		# #x#x## #
		#xxx#xxxx#
		#x######x#
		#x# #x #xx
		#xxxxx # #
		##########

	*/

	// Flood fill (like MS Paint bucket fill)
    int image[NUM_FLOOD_ROWS_AND_COLS][NUM_FLOOD_ROWS_AND_COLS] = {
        { 1,1,1,1,1,1 },
        { 1,0,1,0,0,1 },
        { 1,1,0,0,0,1 },
        { 1,0,0,0,1,1 },
        { 1,0,0,1,0,1 },
        { 1,1,1,1,1,1 },
    };

	startRow = 2;
	startCol = 3;

	floodFill(image, startRow, startCol);

	printFloodGrid(image);

	/* Flood fill output:

		111111
		101221
		112221
		122211
		122101
		111111

	*/

	// Contiguous number (1s) counting (Up, down, left, right; not diagonals)
	int grid[][NUM_ORG_COLS] = {
		{ 0,1,0,1,1,1,0 },
		{ 0,0,1,1,0,0,0 },
		{ 1,1,0,1,0,0,1 },
		{ 1,0,1,0,0,1,1 },
		{ 1,1,0,0,0,1,0 },
	};

	printf("\n%d contiguous cells of 1s found.\n\n", countContiguousCells(grid));

	return 0;
}
