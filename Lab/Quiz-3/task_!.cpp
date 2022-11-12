#include <iostream>
#include <climits>
using namespace std;
class BSTNode
{
    int val;
    BSTNode *parent, *left, *right;

public:
    BSTNode(int v) : val(v), parent(), left(), right() {}
    BSTNode *getParent();
    BSTNode *getLeft();
    BSTNode *getRight();
    void setParent(BSTNode *);
    void setLeft(BSTNode *);
    void setRight(BSTNode *);
    void setVal(int);
    int getVal();
};
class BST
{
public:
    BSTNode *root;
    BST() : root() {}
    void findUnion(BSTNode *root2){
        if(root2==NULL){return;}
        else {
            insert(root2->getVal());    //value will be inserted in the current tree
            findUnion(root2->getLeft());
            findUnion(root2->getRight());
        }
    }
    void insert(int);
    void inOrder(BSTNode *);
    void preOrder(BSTNode *);
    void postOrder(BSTNode *);
    BSTNode *findMin(BSTNode *);
    BSTNode *findMax(BSTNode *);
    BSTNode *search(BSTNode *, int);
    BSTNode *remove(BSTNode *, int);
};
void menu()
{
    cout << "               MENU " << endl;
    cout << " 1- Insert a value: " << endl;
    cout << " 2- Max heapify: " << endl;
    cout << " 3- Build max heap: " << endl;
    cout << " 4- Max heap Sort(Ascending Order): " << endl;
    cout << " 5- Display Heap: " << endl;
    cout << " 6- Exit. " << endl;
}
int ma
int main()
{

    BST tree1;
    BST tree2;
    tree1.insert(1);
    tree1.insert(2);
    tree1.insert(3);
    tree1.insert(4);
    tree1.insert(4);
    tree1.inOrder(tree1.root);
    tree2.insert(4);
    tree2.insert(5);
    tree2.insert(6);
    tree2.insert(7);
    tree2.inOrder(tree2.root);
    cout<<"Finding Union. "<<endl;
    tree2.findUnion(tree1.root);
    tree2.inOrder(tree2.root);

    return 0;
}

BSTNode *BSTNode::getParent()
{
    return parent;
}
BSTNode *BSTNode::getLeft()
{
    return left;
}
BSTNode *BSTNode::getRight()
{
    return right;
}
void BSTNode::setParent(BSTNode *p)
{
    parent = p;
}
void BSTNode::setLeft(BSTNode *l)
{
    left = l;
}
void BSTNode::setRight(BSTNode *r)
{
    right = r;
}
void BSTNode::setVal(int v)
{
    val = v;
}
int BSTNode::getVal()
{
    return val;
}

void BST::insert(int value)
{
    if (search(root, value))
    {
        return;
    }
    BSTNode *p = root,
            *prev = 0;
    while (p != 0)
    {
        prev = p;
        if (value < p->getVal())
            p = p->getLeft();
        else
            p = p->getRight();
    }

    if (root == 0)
        root = new BSTNode(value);
    else if (value < prev->getVal())
    {
        BSTNode *temp = new BSTNode(value);
        temp->setParent(prev);
        prev->setLeft(temp);
    }
    else
    {
        BSTNode *temp = new BSTNode(value);
        temp->setParent(prev);
        prev->setRight(temp);
    }
}
void BST::inOrder(BSTNode *mynode)
{
    if (mynode)
    {
        inOrder(mynode->getLeft());
        cout << mynode->getVal() << " ";
        inOrder(mynode->getRight());
    }
}
void BST::preOrder(BSTNode *mynode)
{
    if (mynode)
    {
        cout << mynode->getVal() << " ";
        preOrder(mynode->getLeft());
        preOrder(mynode->getRight());
    }
}
void BST::postOrder(BSTNode *mynode)
{
    if (mynode)
    {
        postOrder(mynode->getLeft());
        postOrder(mynode->getRight());
        cout << mynode->getVal() << " ";
    }
}
BSTNode *BST::findMin(BSTNode *node)
{
    if (!node)
        return node;
    if (!node->getLeft())
        return node;
    return findMin(node->getLeft());
}
BSTNode *BST::findMax(BSTNode *node)
{
    if (!node)
        return node;
    if (!node->getRight())
        return node;
    return findMax(node->getRight());
}
BSTNode *BST::search(BSTNode *node, int val)
{
    if (node == NULL || node->getVal() == val)
        return node;
    else if (node->getVal() < val)
        search(node->getRight(), val);
    else
        search(node->getLeft(), val);
}
BSTNode *BST::remove(BSTNode *node, int val)
{

    if (node->getVal() > val)
    {
        BSTNode *t = remove(node->getLeft(), val);
        node->setLeft(t);
        if (t)
            t->setParent(node);
    }
    else if (node->getVal() < val)
    {
        BSTNode *t = remove(node->getRight(), val);
        node->setRight(t);
        if (t)
            t->setParent(node);
    }
    else if (node->getLeft() && node->getRight())
    {
        BSTNode *minNode = findMin(node->getRight());
        node->setVal(minNode->getVal());
        BSTNode *temp = remove(node->getRight(), minNode->getVal());
        node->setRight(temp);
        if (temp)
            temp->setParent(node);
    }
    else
    {
        BSTNode *toDel = node;
        if (!node->getLeft()) // single child
            node = node->getRight();
        else if (!node->getRight())
            node = node->getLeft();
        else // when no child
            node = NULL;
        delete toDel;
    }
    return node;
}
