#include "hash_map.hpp"

Hash_map::Hash_map(int n)
:size(n) 
{
    if(n<0){
        cerr<<"***Error! Negative Size***";
        exit(1);
    }
    hash_array_ptr = new (nothrow) cell[n];
    if(hash_array_ptr==0){
        cerr<<"***Error! Inadequate memory to allocate hash***";
        exit(1);
    } 
}

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

    bool Hash_map::isfound( cell& c) {
  if(hash_array_ptr[ hash_function(c) ]==c){
    return true;
  } 
    return false;
}



