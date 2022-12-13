#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <stdbool.h>

#define MAX_MAZE_WIDTH 63
#define MAX_MAZE_HEIGHT 63

void generate_maze(bool maze[MAX_MAZE_HEIGHT][MAX_MAZE_WIDTH], int width, int height) {

}

void print_maze(bool maze[MAX_MAZE_HEIGHT][MAX_MAZE_WIDTH], int width, int height) {
	int i, j;
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (maze[i][j]) printf("■");
			else printf("□");
		}
		printf("\n");
	}
}

int main(void) {
	int width, height;
	bool maze[MAX_MAZE_HEIGHT][MAX_MAZE_WIDTH];

	scanf("insert a width of the maze: ", &width);
	scanf("insert a height of the maze: ", &height);

	generate_maze(maze, width, height);

	return 0;
}
