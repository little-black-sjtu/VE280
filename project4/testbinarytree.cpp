#include <cassert>
#include <iostream>
#include "binaryTree.h"

using namespace std;

int main(){
    Node *p3 = new Node("a",3);
    Node *p4 = new Node("a",2,nullptr,p3);
    Node *p2 = new Node("a",5);
    Node *p1 = new Node("a",4,p4,p2);
    BinaryTree tree1(p1);
    BinaryTree tree2(p2);
    Node *p11 = new Node("a", 2,nullptr,new Node("a",3));
    BinaryTree tree3(p11);
    assert(!tree2.covered_by(tree1));
    assert(!tree3.covered_by(tree1));
    assert(tree1.allPathSumGreater(8)&&!tree1.allPathSumGreater(9));
    assert(tree3.contained_by(tree1));
}