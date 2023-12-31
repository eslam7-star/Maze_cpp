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


/* 
Hash_map::Hash_map()
    : size(0), hash_array_ptr(nullptr) {
}


Hash_map& Hash_map::operator=(const Hash_map& other) {
    if (this != &other) { // Check for self-assignment
        // Deallocate existing memory
        delete[] hash_array_ptr;

        // Copy size
        size = other.size;

        // Allocate new memory
        hash_array_ptr = new (nothrow) cell*[size];
        if (hash_array_ptr == nullptr) {
            cerr << "***Error! Inadequate memory to allocate hash***";
            exit(1);
        }

        // Copy contents
        for (size_t i = 0; i < size; ++i) {
            if (other.hash_array_ptr[i] != nullptr) {
                hash_array_ptr[i] = new cell(*(other.hash_array_ptr[i]));
            } else {
                hash_array_ptr[i] = nullptr;
            }
        }
    }
    return *this;
} */


Hash_map::~Hash_map(){
    for (int i=0;i<size;i++){
        delete hash_array_ptr[i];
    }
    delete[] hash_array_ptr;
}

int Hash_map::hash_function( cell* c ){
    if ( c == 0 ){
        cerr<<"null cell pointer "<<endl;
        exit(1);
    }
    int index = (10*(c->get_Y()) + c->get_x());
    if ( index < 0 || index > size){
        cerr<<"index not valid"<<endl;
        exit(1);
    }
    return index;
}

bool Hash_map::insert( cell* c ){
    if( !isfound(c) ){
        hash_array_ptr[ hash_function(c) ] = c;
    }else{
        cerr<<"a collision detected"<<endl;   // to avoid add the same cell twice
        cout<<"x:"<<c->get_x()<<" : y"<<c->get_Y()<<endl;
        return 0;
    }
    return 1;
}

bool Hash_map::isfound(cell* c){
    if ( c != nullptr && hash_array_ptr[hash_function(c)] == c )
    {
        return 1;
    }
    return 0;
}




void Hash_map::display(ostream& out)const{

    if( hash_array_ptr == 0  ) return;
    for (size_t i = 0; i < size; i++)
    {
        if ( hash_array_ptr[i] != 0 )
            out<<"cell X : "<<hash_array_ptr[i]->get_x()<<", cell Y : "<<hash_array_ptr[i]->get_Y()<<", issolid : "<<hash_array_ptr[i]->issolid()<<endl;
    }
}

ostream& operator<< (ostream& out, const Hash_map& a) {
    a.display(out);
    return out;
}


