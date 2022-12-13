#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <stdbool.h>

#define MAX_MAZE_WIDTH 63
#define MAX_MAZE_HEIGHT 63

typedef enum Direction {
	East, West, South, North
} Direction;

int DX[4] = {1, -1, 0, 0};
int DY[4] = {0, 0, 1, -1};
Direction OPPOSITE[4] = {West, East, North, South};

void swap(int *array, int l, int r) {
	int tmp = array[l];
	array[l] = array[r];
	array[r] = tmp;
}

void shuffle_directions(int directions[4]) {
	int i, j;
	for (i = 0; i < 4; i++) {
		j = rand() % 4;
		swap(directions, i, j);
	}
}

void carve_passages_from(int cx, int cy, bool maze[MAX_MAZE_HEIGHT][MAX_MAZE_WIDTH], int width, int height) {
	int nx, ny, direction;

	Direction directions[4] = {East, West, South, North};
	shuffle_directions((int*)directions);

	for (int i = 0; i < 4; i++) {
		direction = directions[i];
		nx = cx + DX[direction];
		ny = cy + DY[direction];

		if (0 <= nx && nx < width && 0 <= ny && ny < height && !maze[ny * 2 + 1][nx * 2 + 1]) {
			// cell is valid
			maze[cy * 2 + 1 + DY[direction]][cx * 2 + 1 + DX[direction]] = true;
			maze[ny * 2 + 1][nx * 2 + 1] = true;
			carve_passages_from(nx, ny, maze, width, height);
		}
	}
}

void generate_maze(bool maze[MAX_MAZE_HEIGHT][MAX_MAZE_WIDTH], int width, int height) {
	srand(time(NULL));
	carve_passages_from(0, 0, maze, width, height);
}

void print_maze(bool maze[MAX_MAZE_HEIGHT][MAX_MAZE_WIDTH], int width, int height) {
	int i, j;
	for (i = 0; i < height * 2 + 1; i++) {
		for (j = 0; j < width * 2 + 1; j++) {
			if (maze[i][j]) printf("□");
			else printf("■");
		}
		printf("\n");
	}

	FILE *fp = NULL;
	fp = fopen("maze.mcfunction", "w");
	fprintf(fp, "fill 0 0 0 %d 4 %d air\n", width * 2 + 1, height * 2 + 1);
	for (i = 0; i < height * 2 + 1; i++) {
		for (j = 0; j < width * 2 + 1; j++)
			if (!maze[i][j]) fprintf(fp, "fill %d 0 %d %d 4 %d stone\n", j, i, j, i);
	}
	fclose(fp);
}

int main(void) {
	int width, height;
	bool maze[MAX_MAZE_HEIGHT][MAX_MAZE_WIDTH];
	memset(maze, 0, MAX_MAZE_HEIGHT * MAX_MAZE_WIDTH);

	printf("insert a width of the maze: ");
	scanf("%d", &width);
	printf("insert a height of the maze: ");
	scanf("%d", &height);

	generate_maze(maze, width, height);
	print_maze(maze, width, height);

	return 0;
}
