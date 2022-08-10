#include "binaryTree.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
/* ===================== Helper Function for Recursion ====================== */
static bool findPathHelperbool(Node* p, const string& s)
{ // Find the string in this node, or this node's subnodes.
    // Return true if s can be find through p tree.
    if (p == nullptr)
        return false;
    if (p->getstr() == s)
        return true;
    return findPathHelperbool(p->leftSubtree(), s) || findPathHelperbool(p->rightSubtree(), s);
}

static string findPathHelperstr(Node* p, const string& s)
{
    if (p->getstr() == s)
        return "";
    // If s can be find in the left subtree, append 0 to the return str;
    // If s can be find in the right subtree, append 1 to the return str;
    if (findPathHelperbool(p->leftSubtree(), s))
        return "0" + findPathHelperstr(p->leftSubtree(), s);
    if (findPathHelperbool(p->rightSubtree(), s))
        return "1" + findPathHelperstr(p->rightSubtree(), s);
    return "-1";
}

static int sumHelper(Node* p)
{
    if (p == nullptr)
        return 0;
    // Add the value of this node and all of his subtree nodes.
    return p->getnum() + sumHelper(p->leftSubtree()) + sumHelper(p->rightSubtree());
}

static int depthHelper(Node* p)
{
    if (p == nullptr)
        return 0;
    // Caculate the depth of all paths and return the maximum one.
    int leftDepth = 1 + depthHelper(p->leftSubtree());
    int rightDepth = 1 + depthHelper(p->rightSubtree());
    return (leftDepth > rightDepth) ? leftDepth : rightDepth;
}

static void preorder_numHelper(Node* p)
{
    if (p == nullptr)
        return;
    // Print the num of this first and print its lefttree and righttree.
    cout << p->getnum() << " ";
    preorder_numHelper(p->leftSubtree());
    preorder_numHelper(p->rightSubtree());
}

static void inorder_strHelper(Node* p)
{
    if (p == nullptr)
        return;
    // Print the string of the leftstree, this node and the righttree.
    inorder_strHelper(p->leftSubtree());
    cout << p->getstr() << " ";
    inorder_strHelper(p->rightSubtree());
}

static void postorder_numHelper(Node* p)
{
    if (p == nullptr)
        return;
    // Print its lefttree and righttree first and print the num of this.
    postorder_numHelper(p->leftSubtree());
    postorder_numHelper(p->rightSubtree());
    cout << p->getnum() << " ";
}

static bool allPathSumGreaterHelper(Node* p, int sum)
{
    // If all path sum greater than sum, then the subtree's all path sum
    // should be greater than the sum-this->num. If p is a leaf and the
    // num is greater than 0, the function return true.
    if (p == nullptr)
        return true;
    if (p->leftSubtree() == nullptr && p->rightSubtree() == nullptr) {
        if (p->getnum() > sum)
            return true;
        else
            return false;
    }
    return (allPathSumGreaterHelper(p->leftSubtree(), sum - p->getnum()) && allPathSumGreaterHelper(p->rightSubtree(), sum - p->getnum()));
}

static bool covered_byHelper(Node* self, Node* other)
{
    // Covered by if the num of this node is equal and the subtree
    // of other is also covered by this's subtree.
    if (self == nullptr)
        return true;
    if (other == nullptr)
        return false;
    return (self->getnum() == other->getnum() && covered_byHelper(self->leftSubtree(), other->leftSubtree())
        && covered_byHelper(self->rightSubtree(), other->rightSubtree()));
}

static bool contained_byHelper(Node* self, Node* other)
{
    if (other == nullptr)
        return false;
    // Contained by if the other is covered by this or the subtree of other is contained by this.
    return (covered_byHelper(self, other) || contained_byHelper(self, other->leftSubtree()) || contained_byHelper(self, other->rightSubtree()));
}

static Node* copyHelper(Node* p)
{
    if (p == nullptr)
        return nullptr;
    // Copy the str and num to a new Node and also copy the subtree.
    Node* copy = new Node(p->getstr(), p->getnum(), copyHelper(p->leftSubtree()), copyHelper(p->rightSubtree()));
    return copy;
}
/* ================================== Node =================================== */
Node::Node(const std::string& str, int num, Node* left, Node* right)
    : str(str)
    , num(num)
    , left(left)
    , right(right)
{
}

Node* Node::leftSubtree() const
{
    return left;
}

void Node::setleft(Node* n)
{
    left = n;
}

Node* Node::rightSubtree() const
{
    return right;
}

void Node::setright(Node* n)
{
    right = n;
}

string Node::getstr() const
{
    return str;
}

int Node::getnum() const
{
    return num;
}

void Node::incnum()
{
    num++;
}

Node* Node::mergeNodes(Node* leftNode, Node* rightNode)
{
    return new Node(leftNode->getstr() + rightNode->getstr(), leftNode->getnum() + rightNode->getnum(),
        leftNode, rightNode);
}
/* =============================== Binary Tree =============================== */

BinaryTree::BinaryTree(Node* rootNode)
    : root(rootNode)
{
}

BinaryTree::~BinaryTree()
{
    if (root->leftSubtree() != nullptr) {
        BinaryTree* left = new BinaryTree(root->leftSubtree());
        delete left;
    }
    if (root->rightSubtree() != nullptr) {
        BinaryTree* right = new BinaryTree(root->rightSubtree());
        delete right;
    }
    delete root;
}

string BinaryTree::findPath(const string& s) const
{
    return findPathHelperstr(root, s);
}

int BinaryTree::sum() const
{
    return sumHelper(root);
}

int BinaryTree::depth() const
{
    return depthHelper(root);
}

void BinaryTree::preorder_num() const
{
    preorder_numHelper(root);
    cout << endl;
}

void BinaryTree::inorder_str() const
{
    inorder_strHelper(root);
    cout << endl;
}

void BinaryTree::postorder_num() const
{
    postorder_numHelper(root);
    cout << endl;
}

bool BinaryTree::allPathSumGreater(int sum) const
{
    return allPathSumGreaterHelper(root, sum);
}

bool BinaryTree::covered_by(const BinaryTree& tree) const
{
    return covered_byHelper(root, tree.root);
}

bool BinaryTree::contained_by(const BinaryTree& tree) const
{
    return contained_byHelper(root, tree.root);
}

BinaryTree BinaryTree::copy() const
{
    BinaryTree copy = BinaryTree(copyHelper(root));
    return copy;
}
