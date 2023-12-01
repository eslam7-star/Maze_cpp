#include<iostream>
#include "cell.cpp"


using namespace std;

class solver{

int x,y;
bool has_many_dire;
int possible_ways;
bool has_right,has_left,has_north,has_south;


public:

solver( float radius , int x , int y){
    
}

void move(int dx ,int dy){
    x = x + dx;
    y = y + dy;
}

void move_to(int x , int y){
    x = x;
    y=y;
}

void set_possible_ways(){
     
}



};
