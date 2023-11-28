#include"stack.hpp"


Stack::Stack(){
    myTop = 0;
}

StackElement Stack::top() const{
    if(!empty())
        return myTop->direction;
    
    else{
        cerr<<"***Error! Stack is empty***"<< endl;
        return;
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
    if (empty())
    {
      myTop =new Stack::Node(NULL); 
      myTop->direction=value;
    }
    else{ 
        myTop->next=new Stack::Node(NULL);
        myTop = myTop->next;
        myTop->direction=value;
    }
}