#include"stack.hpp"


Stack::Stack(){
    myTop = 0;
}

StackElement Stack::top() const{
    if(!empty())
        return myTop->direction;
    
    else{
        cerr<<"***Error! Stack is empty***";
        return;
    }
}