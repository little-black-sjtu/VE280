#include "node.h"
#include <iostream>

void Node::addChild(Node* child){
    if(n!=child->n) return;
    if(child_num==n) throw tooManyChildren();
    children[child_num] = child;
    children[child_num]->parent = this;
    child_num++;
}

bool Node::equal(Node *other){
    if(n!=other->n) return false;
    if(other->child_num!=child_num) return false;
    if(other->child_num==0){
        if(value==other->value) return true;
        else return false;
    }   
    bool all = true;
    for(int i=0;i<child_num;i++){
        all = (all&&children[i]->equal(other->children[i]));
        if(all==false) break;
    }
    return (all&&(value==other->value));
}

bool Node::containHelper(Node *here, Node *sub){
    if(here->equal(sub)) return true;
    if(here->getHeight()<=sub->getHeight()) return false;
    bool one=false;
    for(int i=0;i<here->child_num;i++){
        one = (one||containHelper(here->children[i],sub));
        if(one==true) break;
    }
    return one;
}

Node::Node(int _value, int _n):value(_value), child_num(0), n(_n), parent(nullptr),children(new Node *[_n]), height(0){}


Node::~Node(){
    for(int i=0;i<child_num;i++) delete children[i];
    delete[] children;
}

void Node::addChild(int _value){
    if(child_num==n) throw tooManyChildren();
    children[child_num] = new Node(_value,n);
    children[child_num]->parent = this;
    child_num++;
}

void Node::traverse(){
    std::cout<<value<<" ";
    if(child_num==0) return;
    for(int i=0;i<child_num;i++){
        children[i]->traverse();
    }
}

bool Node::contain(Node *sub){
    return containHelper(this, sub);
}

int Node::getHeight(){
    if(child_num==0) return 0;
    int max = 0;
    for(int i=0;i<child_num;i++){
        int len = 1+children[i]->getHeight();
        if(len>max) max = len;
    }
    return max;
}

Node &Node::operator[](int i){
    if(i>=child_num) throw invalidIndex();
    return *(children[i]);
}
