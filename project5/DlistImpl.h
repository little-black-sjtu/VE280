#ifndef DLIST_IMPL_H
#define DLIST_IMPL_H

template <class T>
bool Dlist<T>::isEmpty() const{
    return !first;
}

template <class T>
void Dlist<T>::insertFront(T *op){
    node *p = new node;
    p->op = op;
    p->next = nullptr;
    p->prev = nullptr;
    if(isEmpty()){
        first = p;
        last = p;
    }
    else{
        first->prev = p;
        p->next = first;
        first = p;
    }
}

template <class T>
void Dlist<T>::insertBack(T *op){
    node * p= new node;
    p->op = op;
    p->next = nullptr;
    p->prev = nullptr;
    if(isEmpty()){
        first = p;
        last = p;
    }
    else{
        last->next = p;
        p->prev = last;
        last = p;
    }
}

template <class T>
T *Dlist<T>::removeFront(){
    if(isEmpty()) throw EmptyList();
    node *victim = first;
    T *t = victim->op;
    if(victim->next!=0){
        first = victim->next;
        first->prev = nullptr;
    }
    else{
        first = nullptr;
        last = nullptr;
    }
    delete victim;
      
    return t;
}

template <class T>
T *Dlist<T>::removeBack(){
    if(isEmpty()) throw EmptyList();
    node *victim = last;
    T *t = victim->op;
    if(victim->prev!=nullptr){
        last = victim->prev;
        last->next = nullptr;
    }
    else{
        first = nullptr;
        last = nullptr;
    }
    delete victim;
    return t;
}

template <class T>
Dlist<T>::Dlist():first(nullptr), last(nullptr){}

template <class T>
Dlist<T>::Dlist(const Dlist<T> &l):Dlist(){
    if(this!=&l)
        copyAll(l);
}

template <class T>
Dlist<T> &Dlist<T>::operator=(const Dlist<T> &l){
    if(this!=&l)
        copyAll(l);
    return *this;
}

template <class T>
Dlist<T>::~Dlist(){
    removeAll();
}

template <class T>
void Dlist<T>::removeAll(){
    while(!isEmpty()){
        T *t = removeFront();
        delete t; 
        //using delete to remove the pointer to T
    }
}

template <class T>
void Dlist<T>::copyAll(const Dlist<T> &l){
    removeAll();
    node *p = l.first;
    while(p){
        T *t = new T(*(p->op));
        //using new to deep copy a pointer to p
        insertBack(t);
        p = p->next;
    }
}

#endif