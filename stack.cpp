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

bool Stack:: empty() const{
    return myTop==NULL;
 }

  void Stack:: push(const StackElement& value){
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