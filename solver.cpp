#include<iostream>
#include "cell.cpp"

using namespace std;

class solver{

int x,y;
bool has_many_dire;
int possible_ways;
bool has_right,has_left,has_north,has_south;

public:

solver(cell& s){
    x = s.get_x();
    y = s.get_Y();
    set_possible_ways();
}

void move(){
    
}

void set_possible_ways(){
     
}

bool manyways(){
    
}


};
