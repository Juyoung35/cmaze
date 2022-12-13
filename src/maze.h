#define MAX_WIDTH 128
#define MAX_HEIGHT 128
#define MAX_RADIUS 64

typedef struct point {
	int x;
	int y;
} point;

typedef struct squared_maze {
	int width;
	int height;
	int **data;
	point start;
	point end;
} squared_maze;

typedef enum MazeStatus {
	Empty,
	Path,
	Wall
} MazeStatus;

typedef struct maze {
	int n;
	int radius;
	int **data;
	point start;
	point end;
} maze;

void generate_squared_maze(squared_maze *dst, int width, int height);

void generate_maze(maze *dst, int n, int radius);

int solve_squared_maze(squared_maze maze_);

int solve_maze(maze maze_);

int print_squared_maze(squared_maze maze_);

int print_maze(maze maze_);
