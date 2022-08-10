//
// Created by cyx on 20-5-29.
//

#ifndef INTLIST_IMPL_H
#define INTLIST_IMPL_H

#include <iostream>
#include "mylist.h"

template <class T>
void List<T>::print(){
    Node_t<T>* itr = first;
    while(itr){
        std::cout << itr->val;
        itr = itr->next;
    }
    std::cout << "\n";
}

template <class T>
void List<T>::removeAll(){
    while(!isEmpty()){
        removeFront();
    }
}

template <class T>
void List<T>::copyFrom(const List &l){
    for(Node_t<T> *p=l.first;p!=0;p=p->next){
        insertBack(p->val);
    }
}

template <class T>
bool List<T>::isEmpty() const{
    return !first;
}

template <class T>
void List<T>::insertBack(T val){
    Node_t<T> *newP = new Node_t<T>;
    newP->val = val;
    newP->next = nullptr;
    if(!last){
        last = newP;
        first = newP;
    }
    else{
        last->next = newP;
        last = newP;
    }
}

template <class T>
T List<T>::removeFront(){
    if(!first) throw EmptyList();
    Node_t<T> *victim = first;
    T value = victim->val;
    first = first->next;
    if(!first) last=0;
    delete victim;
    return value;
       
}

template <class T>
const Node_t<T>* List<T>::returnFront() const{
    return first;
}

template <class T>
List<T>::List():first(nullptr), last(nullptr) {}

template <class T>
List<T>::List(const List &l):first(nullptr), last(nullptr){
    copyFrom(l);
}

template <class T>
List<T> &List<T>::operator=(const List<T> &l){
    if(this!=&l){
        removeAll();
        copyFrom(l);
    }
    return *this;
}

template <class T>
List<T>::~List(){
    removeAll();
}


bool isLarger(const List<int> &a, const List<int> &b){
    const Node_t<int> *pa = a.returnFront();
    const Node_t<int> *pb = b.returnFront();
    bool larger = false;
    while(pa&&pb){
        if(pa->val>pb->val) larger = true;
        else if(pa->val<pb->val) larger = false;
        pa=pa->next;
        pb=pb->next;
    }
    if(!pa&&!pb) return larger;
    else if(!pa) return false;
    else return true;
}

List<int> add(const List<int> &a, const List<int> &b){
    const Node_t<int> *pa = a.returnFront();
    const Node_t<int> *pb = b.returnFront();
    List<int> sum ;
    int carry = 0;
    while(pa&&pb){
        int left=0, right=0;
        if(pa){
            left = pa->val;
            pa = pa->next;
        }
        if(pb){
            right = pb->val;
            pb = pb->next;
        }
        if(carry+left+right>=10){
            sum.insertBack(carry+left+right-10);
            carry=1;
        }
        else{
            sum.insertBack(carry+left+right);
            carry=0;
        }
    }
    
    if(carry==1) sum.insertBack(1);
    return sum;
}
#endif //INTLIST_IMPL_H

