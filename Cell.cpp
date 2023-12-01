#pragma once

class cell{
    int x,y;
    bool iswall = 0;    
    
    public:
    cell() :x(0) , y(0) { };
    cell(int x,int y,bool b=0): x(x) , y(y) , iswall(b){};


    int get_x() const{
        return x;
    }
    int get_Y() const{
        return y;
    }
    
    bool issolid(){
        return iswall;
    }
    
    bool operator==(cell c){
        if(x==c.get_x()&&y==c.get_Y()&&iswall==c.issolid()) {
          return true;
        }
        return false;
    }

    void display(){
        (iswall)? std::cout<<"#":std::cout<<"=";
    }

    void toggle_wall(){
        ( iswall )? iswall=0:iswall=1;
    }

}r(1,0),l(-1,0),n(0,1),s(0,-1);     // directions



bool issolid(cell& c){
    return c.issolid();
}
