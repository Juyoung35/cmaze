#include <stdio.h>
#include "maze.h"

void generate_squared_maze(squared_maze *dst, int width, int height) {
	dst = squared_maze;
}

void generate_maze(maze *dst, int n, int radius);

int solve_squared_maze(squared_maze maze_);

int solve_maze(maze maze_);

int print_squared_maze(squared_maze maze_) {
	int i, j;
	for (i = 0; i < maze_.height; i++) {
		for (j = 0; j < maze_.width; j++) {
			if (maze_.data[i][j]) printf("■");
			else printf("□");
		}
		printf("\n");
	}
	return 0;
}

int print_maze(maze maze_) {
	int diameter, i, j;
	diameter = maze_.radius * 2 + 1;
	for (i = 0; i < diameter; i++) {
		for (j = 0; j < diameter; j++) {
			switch (maze_.data[i][j]) {
				case Empty:
					break;
				case Path:
					printf("□");
					break;
				case Wall:
					printf("■");
					break;
				default:
					printf("Wrong MazeStatus value occured");
					return -1;
			}
		}
		printf("\n");
	}
	return 0;
}
