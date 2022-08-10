#include "binaryTree.h"
#include "huffmanTree.h"
#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool compare(Node *left, Node *right){
    if(left->getnum()!=right->getnum()) return (left->getnum()>right->getnum());
    else return (left->getstr()>right->getstr());
}
//EFFECT: Give the rule of comparing two nodes. The node has a smaller num
//should be put on the right. If the num is equal, the node whose string 
//has a smaller ascii num should be put ong the right.

vector<Node *> read_char(string filename){
    ifstream ifile;
    ifile.open(filename);
    if(!ifile) exit(EXIT_FAILURE);
    char temp;
    //Construct a nodes vector.
    vector<Node *> nodes;
    while(ifile.get(temp)){
        //Count the num of each char appeared in the text file.
        string tempstr = "a";
        tempstr[0] = temp;
        int i;
        for(i=0;i<nodes.size();i++){
            if(nodes[i]->getstr()==tempstr){
                nodes[i]->incnum();
                break;
            }
        }
        if(i==nodes.size()) nodes.push_back(new Node(tempstr, 1));
    }

    ifile.close();
    return nodes;
}
//REQUIRE: Filename exists.
//EFFECT: Read the characters appeared in the file and return a vector
//contains the counts of all appeared characters.


void build_tree(vector<Node *> &nodes){
    //Sort the nodes vector through the compare function.
    while(nodes.size()>1){
            //
            sort(nodes.begin(),nodes.end(),compare);
            Node *right = nodes.back();
            nodes.pop_back();
            Node *left = nodes.back();
            nodes.pop_back();
            Node *merged = Node::mergeNodes(left, right);
            nodes.push_back(merged);
    }
}
//EFFECT: Depend on the rule to construct the HuffmanTree
//recursively until the nodes has one node.

void output(HuffmanTree &tree, char* argv[], string filename){
    //If "-tree", output the tree file, else, output the binary file.
    if(string(argv[1]) == "-tree") tree.printTree();
    else{
        ifstream ifile;
        ifile.open(filename);
        char temp;
        while(ifile.get(temp)){
            string tempstr = "a";
            tempstr[0] = temp;
            cout<<tree.findPath(tempstr)<<" ";
        }
        ifile.close();
    }
}
//EFFECT: Output information.


int main(int argc, char *argv[]) {
    if(argc<=1) exit(EXIT_FAILURE);
    string filename = argv[argc-1];
    vector<Node *> nodes = read_char(filename);  //The text should always be the last argument.
    build_tree(nodes);
    HuffmanTree tree(nodes.front());
    output(tree, argv, filename);
    return 0;
}