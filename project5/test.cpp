#include <iostream>
#include "Dlist.h"
#include "DlistImpl.h"

using namespace std;

int main(){
    try{
    Dlist<int> intlist;
    intlist.insertBack(new int(5));
    intlist.insertFront(new int(3));
    intlist.insertBack(new int(1));
    intlist.insertFront(new int(2));
    std::cout<<intlist<<std::endl;
    int *t = intlist.removeFront();
    cout<<*t<<endl;
    std::cout<<intlist<<std::endl;
    intlist.removeBack();
    intlist.removeBack();
    cout<<intlist.isEmpty()<<endl;
    std::cout<<intlist<<std::endl;
    intlist.removeBack();
    std::cout<<intlist<<std::endl;
    cout<<intlist.isEmpty()<<endl;    }
    catch(EmptyList){
        std::cout<<"the list is empty!"<<std::endl;
    }
}