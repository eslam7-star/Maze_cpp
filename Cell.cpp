class cell{
    int x,y;
    bool iswall = 0;    

    public:
    cell() x(0) , y(0) {};
    cell(int x,int y,bool b): x(x) , y(y) , issolid(b){};

    int get_x(){
        return x;
    }
    int get_Y(){
        return y;
    }

    void add_cell(cell d){
        x = x + d.x;
        y = y + d.y;
    }

    void sub_cell(cell d){
        x = x - d.x;
        y = y - d.y;
    }

    bool issolid(){
        return issolid;
    }



};

