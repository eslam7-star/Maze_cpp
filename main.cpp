//#include "cell.cpp"
#include "hash_map.cpp"
#include "stack.cpp"

// cell** generate_cells( ){
//     for (size_t i = 0; i < ; i++)
//     {
//         ;
//     }
    
// }




int main(int argc, char const *argv[])
{
    int x;
    cin>>x;
    Hash_map h(x);
    h.insert(&n);
    h.insert(&r);
    cout<<h;
    Stack s;
    s.push('r');
    s.push('l');
    s.push('r');
    s.push('n');
    s.push('s');
    s.display(cout);
    s.pop();
    s.display(cout);
    cout<<h.isfound(&n)<<endl;
    cell c(3,4,1),c2(1,2);
    h.insert(&c);
    //h.insert(&c2);
    h.insert(&c);
    cout<<h.isfound(&c)<<"   "<<h.isfound(&c2)<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}
