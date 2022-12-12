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

void generate_squared_maze(int width, int height);

void generate_maze(int n, int radius);

int solve_squared_maze(squared_maze maze_);

int solve_maze(maze maze_);

void print_squared_maze(squared_maze maze_);

void print_maze(maze maze_);
