#ifndef DS
#define DS


#include<iostream>
#include "Cell.cpp"


using namespace std;

class Hash_map{

cell* hash_array_ptr;

public:

Hash_map(int size);
int hash_function(const cell& c);
void insert(const cell& c , int index); 
void delete_cell(int index);
bool isfound(const cell& c);
~Hash_map();

};

#endif