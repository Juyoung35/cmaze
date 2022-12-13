#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "maze.c"

int main(void) {
	squared_maze *dst = (squared_maze*)malloc(sizeof(squared_maze));
	generate_squared_maze(dst, 30, 30);
	free(dst);
	return 0;
}
