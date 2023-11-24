#ifndef MAZE
#define MAZE

#include <iostream>
#include "Cell.cpp"

using namespace std;

class Maze {

cell** maze; 
cell startp,endp;
cell* obstacles; 
int rows,cols;

public:

Maze( cell startp, cell endp, int rows = 15, int cols = 15, cell* obstacles );
Maze(int rows = 15, int cols = 15);
void display_maze();

};


#endif 
