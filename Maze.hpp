#ifndef MAZE
#define MAZE

#include <iostream>
#include "Cell.cpp"
#include "solver.cpp"

using namespace std;

const float cellSize = 30.f;


class Maze {

public:

cell*** maze;                     // 2d array of cell pointers :)
int rows,cols;
int size;
int curr_x,curr_y;
bool has_many_dire;
int possible_ways;
bool has_right,has_left,has_north,has_south;


int start_x,start_y,end_x,end_y;

//Maze( cell* startp, cell *endp, int rows = 15, int cols = 15, cell* obstacles );
Maze(int rows, int cols );
void display(sf::RenderWindow& window);
void toggleWall(int x, int y);
cell* found_cell(int x,int Y);
bool isWall(int x, int y);
~Maze();
void setStartPoint(int x, int y);
void setEndPoint(int x, int y);
void solve(sf::CircleShape& playerCircle);


};

#endif 
