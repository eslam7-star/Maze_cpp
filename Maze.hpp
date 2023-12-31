#ifndef MAZE
#define MAZE

#include <iostream>
#include "Cell.cpp"
#include "hash_map.hpp"
#include "stack"

using namespace std;

const float cellSize = 30.f;


class Maze {

public:

cell*** maze;                     // 2d array of cell pointers
int rows,cols;
int size;
int curr_x,curr_y;
char arr_dir[4]{0};               // current available directions
Stack stack;
Hash_map h_map;
bool display_path=0;


int start_x,start_y,end_x,end_y;

//Maze( cell* startp, cell *endp, int rows = 15, int cols = 15, cell* obstacles );
Maze(int rows, int cols );
void display(sf::RenderWindow& window , sf::CircleShape& playerCircle);
void toggleWall(int x, int y);
cell* found_cell(int x,int Y);
bool isWall(int x, int y);
~Maze();
void setStartPoint(int x, int y);
void setEndPoint(int x, int y);
void solve(sf::CircleShape& playerCircle);
void set_direc(int x, int y);
bool move(char dir);

};



#endif 
