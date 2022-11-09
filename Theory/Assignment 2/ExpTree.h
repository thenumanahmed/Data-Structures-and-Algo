#include <iostream>
#include <stack> //for conversion into tree
#include <cmath>
#include <iomanip> //for rand()
#include <ctime>   //for time()
#include <map>     //for assigning values to variables
#include "Node.h"
using namespace std;
class ExpTree
{
    string infix;          // storing the infix expression
    map<char, int> values; // for values assigned

public:
    Node* root;
    ExpTree(string);
    int inPrec(char);
    int outPrec(char);
    string infixToPostfix(string);
    void setinfix(string);
    Node* make_exp_tree(string);
    void displayInfix(Node*);
    void displayPrefix(Node*);
    void displayPostfix(Node*);
    int evaluate(Node*);
    int evaluateExpTree(Node*);
    void menu();
    void destroySubTree(Node*);
    ~ExpTree();
    void display(Node* ptr, int level);
};
void ExpTree::display(Node* ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
            cout << "Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout << "	 ";

        cout << ptr->data;
        display(ptr->left, level + 1);
    }
}
int ExpTree::inPrec(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
    case '%':
        return 4;
    case '^':
        return 5;
    }
}

int ExpTree::outPrec(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 3;
    case '^':
        return 6;
    }
}

string ExpTree::infixToPostfix(string s)
{
    stack<char> c;
    string result = "";

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')|| (s[i] >= '0' && s[i] <= '9'))
        {
            result += s[i];
        }
        else if (s[i] == '(')
        {
            c.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!c.empty() && c.top() != '(')
            {
                result += c.top();
                c.pop();
            }
            if (!c.empty())
            {
                c.pop();    //to pop (
            }
        }
        else
        {
            while (!c.empty() && inPrec(c.top()) > outPrec(s[i]))
            {
                if(c.top()!='(') 
                result += c.top();
                c.pop();
            }
            c.push(s[i]);
        }
    }
    while (!c.empty())
    {
        result += c.top();
        c.pop();
    }
    return result;
}
ExpTree::ExpTree(string infix)
{
    srand(time(0));
    this->infix = infix;
    root = make_exp_tree(infixToPostfix(infix));
}
void ExpTree::setinfix(string infix)
{
    this->infix = infix;
    root = make_exp_tree(infixToPostfix(infix));
}
Node* ExpTree::make_exp_tree(string s)
{
    destroySubTree(root); // for deleting previously assigned nodes
    stack<Node*> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '^' || s[i] == '%')
        {
            Node* newNode = new Node(s[i]);
            newNode->right = st.top();
            st.pop();
            newNode->left = st.top();
            st.pop();
            st.push(newNode); // push the operator node
        }
        else
            st.push(new Node(s[i])); // push the character node
    }
    Node* temp = st.top();
    st.pop();
    return temp;
}
void ExpTree::displayInfix(Node* root)
{
    if (!root)
        return;
    if (root->left && root->right)
    { // if both values on left and right then brackets will be displayed
        cout << "(";
        displayInfix(root->left);
        cout << root->data << " ";
        displayInfix(root->right);
        cout << ")";
    }
    else
    {
        displayInfix(root->left);
        cout << root->data << " ";
        displayInfix(root->right);
    }
}
void ExpTree::displayPrefix(Node* root)
{
    if (!root)
        return;
    cout << root->data << " ";
    displayPrefix(root->left);
    displayPrefix(root->right);
}
void ExpTree::displayPostfix(Node* root)
{
    if (!root)
        return;
    displayPostfix(root->left);
    displayPostfix(root->right);
    cout << root->data << " ";
}
int ExpTree::evaluate(Node* root)
{
    int val = evaluateExpTree(root);
    cout << "Assigned values are: " << endl;
    for (auto i : values)
        cout << i.first << " = " << i.second << endl;
    values.clear(); // claering the map so that next time it will get new random value
    return val;
}
int ExpTree::evaluateExpTree(Node* root)
{
    if (!root) // when root is null
        return 0;
    else if (root->data == '*')
        return evaluateExpTree(root->left) * evaluateExpTree(root->right);
    else if (root->data == '+')
        return evaluateExpTree(root->left) + evaluateExpTree(root->right);
    else if (root->data == '-')
        return evaluateExpTree(root->left) - evaluateExpTree(root->right);
    else if (root->data == '/'){
        try{
            if(evaluateExpTree(root->right) !=0 )
                return evaluateExpTree(root->left) / evaluateExpTree(root->right);
            else 
                throw("Invalid");
        }
        catch(string s){
            cout<<"can't divide by zero. "<<endl;
            exit(0);
        }
    }
    else if (root->data == '^')
        return pow( evaluateExpTree(root->left), evaluateExpTree(root->right));
    else if (root->data == '%')
        try{
            if(evaluateExpTree(root->right) !=0 )
                return evaluateExpTree(root->left) % evaluateExpTree(root->right);
            else 
                throw("Invalid");
        }
        catch(string s){
            cout<<"can't divide by zero. "<<endl;
            exit(0);
        }
    else // operand found
    {
        if (root->data >= '0' && root->data <= '9'  )
            return (root->data-'0');//char to int
        else if (!values.count(root->data)) // when char but value not assigned
        {
            values[root->data] = rand() % 10; // range will be 0 to 9
            return values[root->data];
        }
        else // when char with assigned value
            return values[root->data];
    }
}
void ExpTree::menu()
{
    cout << "  __________    MENU   _____________" << endl;
    cout << "  1- Enter expression. " << endl;
    cout << "  2- Display exp tree. " << endl;
    cout << "  3- Display prefix form of expression. " << endl;
    cout << "  4- Display infix form of expression. " << endl;
    cout << "  5- Display postfix form of expression. " << endl;
    cout << "  6- Evaluate expression. " << endl;
    cout << "  7- Exit. " << endl;
}
void ExpTree::destroySubTree(Node* nodePtr)
{
    if (!nodePtr)
        return;
    if (nodePtr->left)
        destroySubTree(nodePtr->left);
    if (nodePtr->right)
        destroySubTree(nodePtr->right);
    delete nodePtr;
    nodePtr = nullptr;
}
ExpTree::~ExpTree()
{
    destroySubTree(root);
    root = nullptr;
}