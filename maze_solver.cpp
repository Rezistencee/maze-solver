// Author: Rezistence © 2021
// Maze solver with right hand rule (wall follower)

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;

const int MazeHeight = 9;
const int MazeWidth = 9;

struct coordinates {
	int x = 1;
	int	y = 4;
	int direction = 1;
} c;


char maze[MazeHeight][MazeWidth + 1] =
{
	"#########",
	"#   #   x",
	"# ### # #",
	"# #   ###",
	"#    #  #",
	"# ##### #",
	"# # #   #",
	"#   #   #",
	"#########",
};

const char wall = '#';
const char road = ' ';
char dude = ' ';
const char exit_maze = 'x';

bool solve = false;
coordinates Direction_List[4] = { {0,-1}, {1,0}, {0,1}, {-1,0} };
int steps = 0;

bool Move_Abbility()
{
	if (maze[c.y + Direction_List[c.direction].y][c.x + Direction_List[c.direction].x] != wall) {
		return true;
	}
	else {
		return false;
	}
}

void Move()
{
	if (c.direction == 0 && (maze[c.y - 1][c.x] == road || maze[c.y - 1][c.x] == exit_maze)) {
		c.y -= 1;
	}
	if (c.direction == 1 && (maze[c.y][c.x + 1] == road || maze[c.y][c.x + 1] == exit_maze)) {
		c.x += 1;
	}
	if (c.direction == 2 && (maze[c.y + 1][c.x] == road || maze[c.y + 1][c.x] == exit_maze)) {
		c.y += 1;
	}
	if (c.direction == 3 && (maze[c.y][c.x - 1] == road || maze[c.y][c.x - 1] == exit_maze)) {
		c.x -= 1;
	}
}

void PrintMaze()
{
	system("CLS");
	cout << "\t\t\t\t\t\t Maze solver!\n\n";
	for (int i = 0; i < MazeHeight; i++)
	{
		for (int j = 0; j < MazeWidth; j++) {
			if ((i == c.y) && (j == c.x)) {
				switch (c.direction) {
				case 0:
					dude = 'N';
					break;
				case 1:
					dude = 'E';
					break;
				case 2:
					dude = 'S';
					break;
				case 3:
					dude = 'W';
					break;
				}
				printf("\x1B[33m%c\033[0m", dude);
			}
			else cout << maze[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Steps: " << steps;
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "RUS");

	// A cycle that runs until the maze is completed (solve != true)
	while (!solve) {
		PrintMaze();
		if (maze[c.y][c.x] == exit_maze) {
			solve = true;
		}
		c.direction = (c.direction + 1) % 4;
		for (int i = 0; i < 4; i++) {
			if (!Move_Abbility()) {
				c.direction = (c.direction + 3) % 4;
			}
			else break;
		}
		if (Move_Abbility()) {
			Move();
			steps++;
		}
		if (steps % 50 == 0) {
			c.direction = (c.direction + 2) % 4;
		}
		Sleep(250);
	}

	cout << endl;
	if (solve) {
		cout << "Exit was found!" << endl;
	}
	else
	{
		cout << "I can't find exit!" << endl;
	}
}

/*
const int MazeHeight = 9;
const int MazeWidth = 9;

char maze[MazeHeight][MazeWidth + 1] =
{
	"#########",
	"#   #   x",
	"# ### # #",
	"# #   ###",
	"#    #  #",
	"# ##### #",
	"# # #   #",
	"#   #   #",
	"#########",
};


const int MazeHeight = 9;
const int MazeWidth = 14;

char maze[MazeHeight][MazeWidth + 1] =
{
	"##############",
	"#       #    #",
	"# ### #      #",
	"###   ## ##  #",
	"#    #    ## #",
	"# ##   # ##  #",
	"# # #  ##    x",
	"#   #   #    #",
	"##############",
};


const int MazeHeight = 11;
const int MazeWidth = 14;

char maze[MazeHeight][MazeWidth + 1] =
{
	"##############",
	"#       #    #",
	"# ### ##     #",
	"###   ## ##  #",
	"#    #    ## #",
	"# ##   # ##  #",
	"# # #  ####  x",
	"#   #     #  #",
	"#   ##### ####",
	"#       #    #",
	"##############",
};

*/