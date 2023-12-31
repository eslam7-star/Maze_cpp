#include "stack.hpp"


Stack::Stack(){
    myTop = 0;
}

StackElement Stack::top() const{
    if(!empty())
        return myTop->direction;
    
    else{
        cerr<<"***Error! Stack is empty***"<< endl;
        exit(1);
    }
}

Stack::~Stack() {
    Stack::NodePointer currPtr = myTop, nextPtr = NULL;
    while (currPtr != NULL) {
        nextPtr = currPtr->next;
        delete currPtr;
        currPtr = nextPtr;
    }

}

void Stack::display (ostream& out) const {
    if (empty()) {
        cerr << "Stack-empty!" << endl;
        return;
    }
    Stack::NodePointer myPtr = myTop;
    while (myPtr != NULL) {
        out << myPtr-> direction  << ' ';
        myPtr = myPtr->next;
    }
    out << endl;
}

void Stack::pop(){
     if (!empty()) {
        Stack::NodePointer ptr = myTop;
        myTop = myTop->next;
        delete ptr;
    } 
    else {
        cerr << "***Error!Stack is Empty***" << endl;
    }
}

bool Stack::empty() const{
    return myTop==NULL;
}

void Stack::push(const StackElement& value){
    Stack::NodePointer ptr = new Stack::Node(NULL);
    ptr->direction = value;
    if (empty())
    { 
       myTop = ptr;
    }
    else{ 
        ptr->next = myTop;
        myTop = ptr;
    }
}
ostream& operator<< (ostream& out, const Stack& aStack) {
    aStack.display(out);
    return out;
}