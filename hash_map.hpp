#ifndef DS
#define DS


#include<iostream>
#include "Cell.cpp"


using namespace std;

class Hash_map{

cell** hash_array_ptr;
int size;

public:

Hash_map(int n);
int hash_function( cell* c );
bool insert( cell* c ); 
bool isfound( cell* c);
~Hash_map();
void display(ostream& out)const;


};

#endif