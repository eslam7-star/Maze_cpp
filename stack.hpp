#ifndef STACK
#define STACK


#include <iostream>
#include "Cell.cpp"

using namespace std;

typedef cell StackElement;

class Stack {

public:
    Stack();
    ~Stack();
    bool empty() const;
    void push(const StackElement& value);
    void display(ostream& out) const;
    StackElement top() const;
    void pop();
    //new comitsss 
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
