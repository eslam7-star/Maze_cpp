#include "Maze.hpp"
#include <ctime>
#include <cstdlib>



Maze::Maze(int rows , int cols ): rows(rows), cols(cols) , h_map(10 * rows + cols) {
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

void Maze::display(sf::RenderWindow& window , sf::CircleShape& playerCircle ) {

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
            if ( display_path ){
                if( maze[i][j]->get_in_path() )
                    cellShape.setFillColor(sf::Color::Yellow);
            } 
            
            window.draw(cellShape);
        }
    }
    playerCircle.setPosition(cellSize*curr_x,cellSize*curr_y);   
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
    if( found_cell(x,y) == 0 || ( x == start_x &&  y == end_y )|| ( x == end_x && y == end_y )) return;
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
        curr_x = start_x;
        curr_y = start_y;
    }
    cell *c = found_cell(x,y); 
    if( c->issolid() ) c->toggle_wall();
    h_map.insert(maze[start_y][start_x]);
}

void Maze::setEndPoint(int x, int y) {
    if (x >= 0 && x < cols && y >= 0 && y < rows) {
        end_x = x;
        end_y = y;
    }
    cell *c = found_cell(x,y); 
    if( c->issolid() ) c->toggle_wall();
}


void Maze::solve(sf::CircleShape& playerCircle){
    int ran,i=0;
    cell* c;
    char pre;
    bool z=0;

    set_direc(curr_x,curr_y);
    srand(static_cast<unsigned>(std::time(nullptr)));
    ran = rand() % 4;
    i=-1;
    cout<<"randdom :"<<ran<<endl;
    cout<<"arr_dir : "<<arr_dir[0]<<" "<<arr_dir[1]<<" "<<arr_dir[2]<<" "<<arr_dir[3]<<endl;
    while( arr_dir[ran] == 'f' && i < 3 ){ 
        i++;
        ran = i;
        cout<<"in loop : "<<ran<<endl;
    }
    if( arr_dir[ran] == 'f' )
    {
        cerr<<"Maze unsolvable :) , make some changes "<<endl;
        return;
    }else{
        c = ( arr_dir[ran] == 'r' )? &r : ( arr_dir[ran] == 'l')? &l : (arr_dir[ran] == 'n')? &s : (arr_dir[ran] == 's')? &n : nullptr;
        if( c == 0)
            cerr<<"null c"<<endl;
        c->display();
        maze[curr_y+c->get_Y()][curr_x+c->get_x()]->display();
        cout<<"found ?? :"<<h_map.isfound(maze[curr_y+c->get_Y()][curr_x+c->get_x()])<<endl;
        if( h_map.isfound(maze[curr_y+c->get_Y()][curr_x+c->get_x()]) ){
            for (size_t i = 0; i < 4 ; i++){
                ran = i;
                c = ( arr_dir[i] == 'r' )? &r : ( arr_dir[i] == 'l')? &l : (arr_dir[i] == 'n')? &s : (arr_dir[i] == 's')? &n : nullptr;
                if ( c != 0 ){
                    c->display();
                    if( !h_map.isfound(maze[curr_y+c->get_Y()][curr_x+c->get_x()]) ){
                        h_map.insert(maze[curr_y+c->get_Y()][curr_x+c->get_x()]);
                        move(arr_dir[i]);
                        cout<<"inserted case 1"<<endl;
                        stack.push(arr_dir[i]);
                        //maze[curr_y+c->get_Y()][curr_x+c->get_x()]->set_in_path();
                        goto l;
                    }
                }
            }
            if(ran == 3){
                p:                  // all avaialbe directions stored in hash_table
                pre = stack.top();
                if ( !stack.empty() ){     
                    stack.pop();
                    // int b = (pre == 'r')? 1: (pre == 'l')? -1 : 0; //x
                    // int p = (pre == 's')? 1: (pre == 'n')? -1 : 0; //y
                    // maze[curr_y+p][curr_x+b]->unset_inpath();
                }else{
                    cerr<<"unsolvable maze"<<endl;
                    exit(1);
                }    
                cout<<"return case "<<endl;
                bool check_return = ( pre == 'r' )? move('l'): ( pre == 'l')? move('r') : (pre == 's')? move('n') : ( pre == 'n')? move('s'): 0;
                if( check_return == 0 ){
                    cerr<<"return error "<<endl;
                    goto p;
                }
            }
        }else{
            cout<<h_map.insert(maze[curr_y+c->get_Y()][curr_x+c->get_x()])<<endl;
            cout<<"inserted case 2"<<endl;
            stack.push(arr_dir[ran]);
            //maze[curr_y+c->get_Y()][curr_x+c->get_x()]->set_in_path();
            z = move(arr_dir[ran]);
        }
    }
    l:
    cout<<"current x :"<<curr_x<<"curr_y"<<curr_y<<endl;
    cout<<z<<endl;
    h_map.display(cout);
    stack.display(cout);
    cout<<"=============="<<endl;

    if( curr_x == end_x && curr_y == end_y ){
        cout<<"maze solved, reached the end point "<<endl;
        Stack s;
        int x=start_x,y=start_y;
        int tmp;
        char c;
        cout<<"start at : "<<start_x<<"start_y :"<<start_y<<endl;
        while ( !stack.empty() )
        {
            s.push(stack.top());
            stack.pop();
        }
        
        while ( !s.empty() )
        {
            c = s.top();
            tmp = (c == 'r')? 1: (c == 'l')? -1 : 0;      //x
            x+=tmp;
            tmp = (c == 's')? 1: (c == 'n')? -1 : 0;      //y
            y+=tmp;
            cout<<"x : "<<x<<" : "<<"y: "<<y<<endl;
            if( maze[y][x] != NULL ){
                maze[y][x]->set_in_path();
            }else{  
                cerr<<"null pointer exception"<<endl;
                cerr<<"x : "<<x<<" : "<<"y: "<<y<<endl;
            }
            s.pop();
        }

        display_path = 1;
        //exit(1);
    }    
    //sf::sleep(sf::seconds(1));
    
}
    

bool Maze::move( char e ) {
    cout<<e<<endl;
    //cout<<curr_x<<endl;
    bool moved = 0;
    if (e == 'r' && curr_x + 1 < cols && !maze[curr_y][curr_x+1]->issolid()) {
        curr_x++;
        moved =1;
    } else if ( e == 'l' && curr_x - 1 > 0 && !maze[curr_y][curr_x-1]->issolid()) {
        curr_x--;
        moved =1;
    } else if ( e == 's' && curr_y + 1 < rows && !maze[curr_y+1][curr_x]->issolid()) {
        curr_y++;
        moved =1;
    } else if ( e == 'n' && curr_y - 1 > 0 && !maze[curr_y-1][curr_x]->issolid()) {
        curr_y--;
        moved =1;
    }else{
        cout<<"error can't move"<<endl;
        return 0;
    }

    return moved;
}


void Maze::set_direc(int x, int y ){
    ( x+1 < cols && !maze[y][x+1]->issolid() )? arr_dir[1] = 'r' : arr_dir[1] = 'f';
    ( y+1 < rows && !maze[y+1][x]->issolid())? arr_dir[0] = 's' : arr_dir[0] = 'f';
    ( x-1 > 0 && !maze[y][x-1]->issolid())? arr_dir[2] = 'l' : arr_dir[2] = 'f';
    ( y-1 > 0 && !maze[y-1][x]->issolid())? arr_dir[3] = 'n' : arr_dir[3] = 'f'; 
}


