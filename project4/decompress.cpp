#include "binaryTree.h"
#include "huffmanTree.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void binary_decode(ifstream &ifile, HuffmanTree &tree){
    string temp;
    while(ifile>>temp){
        Node *p = tree.root;
        for(int i=0;i<temp.length();i++){
            //Through the binary code to get the demanding char.
            //0 represents left, 1 represents right.
            if(temp[i]=='0') p = p->leftSubtree();
            if(temp[i]=='1') p = p->rightSubtree();
        }
        cout<<p->getstr();
    }
}
//EFFECT: Output the decoding information through
//the tree file and teh binary file.

int main(int argc, char *argv[]) {
    if(argc!=3) exit(EXIT_FAILURE);//The argument inputs num should be 3;
    //The seconde argument should be name of the tree file.
    string filename(argv[1]); 
    HuffmanTree tree(filename); //Construct the Huffmantree through tree file.
    //The third argument should be the name of binary file.
    ifstream ifile;
    ifile.open(argv[2]);
    if(!ifile) exit(EXIT_FAILURE);

    binary_decode(ifile, tree);
    return 0;
}