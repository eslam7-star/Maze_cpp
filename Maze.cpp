#include "Maze.hpp"

Maze::Maze(int rows , int cols ): rows(rows), cols(cols){
    size = cols*rows;
    maze = new (nothrow) cell**[rows];
    if ( maze == 0 ) {
        cerr<<"maze is null "<<endl;
        exit(1);
    }

    for (size_t i = 0; i < rows; i++)
    {
        maze[i] = new cell*[cols];  
        for (size_t j = 0; j < cols ; j++)
        {
            if( i==0 || j == 0 || i == rows -1 || j == cols - 1) {       // borders of maze should be walls
                maze[i][j] = new cell(j,i,1);
            }else{
                maze[i][j] = new cell(j,i);
            }
        }
    }
}

void Maze::display(sf::RenderWindow& window) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sf::RectangleShape cellShape(sf::Vector2f(cellSize, cellSize));
            cellShape.setPosition(j * cellSize, i * cellSize);
            if (i == start_y && j == start_x) {
                cellShape.setFillColor(sf::Color::Green);
            } else if (i == end_y && j == end_x) {
                cellShape.setFillColor(sf::Color::Red);
            } else {
                cellShape.setFillColor(maze[i][j]->issolid() ? sf::Color::Black : sf::Color::White);
            }
            window.draw(cellShape);
        }
    }   
}

cell* Maze::found_cell(int x,int y){
    if( x > cols || y > rows){
        cerr<<"cell not found invalid index"<<endl;
        return 0;
    }
    return maze[y][x];
}

bool Maze::isWall(int x, int y) {
    if( found_cell(x,y) == 0) return 0;
    return found_cell(x,y)->issolid();
}


void Maze::toggleWall(int x, int y){
    if( found_cell(x,y) == 0 || x == start_x || x == end_x ) return;
    found_cell(x,y)->toggle_wall(); 
}


Maze::~Maze() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            delete maze[i][j];
        }
        delete[] maze[i];
    }
    delete[] maze;
}

void Maze::setStartPoint(int x, int y) {
    if (x >= 0 && x < cols && y >= 0 && y < rows) {
        start_x = x;
        start_y = y;
    }
    cell *c = found_cell(x,y); 
    if( c->issolid() ) c->toggle_wall();
}

void Maze::setEndPoint(int x, int y) {
    if (x >= 0 && x < cols && y >= 0 && y < rows) {
        end_x = x;
        end_y = y;
    }
    cell *c = found_cell(x,y); 
    if( c->issolid() ) c->toggle_wall();
}