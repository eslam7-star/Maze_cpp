#include "hash_map.hpp"

int Hash_map::hash_function( cell& c ){
    int index = (10*(c.get_Y()) + c.get_x());
    if ( index < 0 || index > size){
        exit(-1);
    }
}

void Hash_map::insert( cell& c ){
    if( !isfound(c) ){
        hash_array_ptr[ hash_function(c) ] = c;
    }else{
        cerr<<"a collision detected"<<endl;   // to avoid add the same cell twice
    }
}

