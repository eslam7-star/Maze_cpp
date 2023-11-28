#include "hash_map.hpp"

Hash_map::Hash_map(int n)
:size(n) 
{
    if(n<0){
        cerr<<"***Error! Negative Size***";
        exit(1);
    }
    hash_array_ptr = new (nothrow) cell*[n];
    if(hash_array_ptr==0){
        cerr<<"***Error! Inadequate memory to allocate hash***";
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        hash_array_ptr[i] = nullptr;
    }
}

Hash_map::~Hash_map(){
    for (int i=0;i<size,i++){
        delete hash_array_ptr[i];
    }
    delete[] hash_array_ptr;
}

int Hash_map::hash_function( cell& c ){
    int index = (10*(c.get_Y()) + c.get_x()) % size;
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



