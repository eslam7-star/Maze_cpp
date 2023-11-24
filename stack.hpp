#ifndef STACK
#define STACK


#include <iostream>
#include "Cell.cpp"

using namespace std;

typedef cell StackElement;
const int DEFAULT_CAPACITY = 128;

class Stack {

public:
    Stack(int numElements = DEFAULT_CAPACITY);
    ~Stack();
    const Stack& operator= (const Stack& rhs);
    bool empty() const;
    void push(const StackElement& value);
    void display(ostream& out) const;
    StackElement top() const;
    void pop();

private:

    class Node {
    public:
        cell direction;
        Node* next;
        Node(){};
        Node(Node* link = 0) : next(link) {};
    };
    typedef Node* NodePointer;
    NodePointer myTop; 
    
};


#endif 
