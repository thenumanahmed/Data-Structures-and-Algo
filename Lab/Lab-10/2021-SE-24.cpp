#include <iostream>
using namespace std;

class BSTNode
{
    int val;
    BSTNode *parent, *left, *right;

public:
    BSTNode(int v) : val(v) {}
    BSTNode *getParent()
    {
        return parent;
    }
    BSTNode *getLeft()
    {
        return left;
    }
    BSTNode *getRight()
    {
        return right;
    }
    void setParent(BSTNode *p)
    {
        parent = p;
    }
    void setLeft(BSTNode *l)
    {
        left = l;
    }
    void setRight(BSTNode *r)
    {
        right = r;
    }
    void setInfo(int v)
    {
        val = v;
    }
    int getInfo()
    {
        return val;
    }
};
class BST
{
public:
    BSTNode *root;
    BST() : root() {}
    void insert(int value)
    {
        if (search(root, value))
            return;
        BSTNode *p = root,
                *prev = 0;
        while (p != 0)
        {
            prev = p;
            if (value < p->getInfo())
                p = p->getLeft();
            else
                p = p->getRight();
        }

        if (root == 0)
            root = new BSTNode(value);
        else if (value < prev->getInfo())
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

    void inOrder(BSTNode *mynode)
    {
        if (mynode)
        {
            inOrder(mynode->getLeft());
            cout << mynode->getInfo() << " ";
            inOrder(mynode->getRight());
        }
    }
    void preOrder(BSTNode *mynode)
    {
        if (mynode)
        {
            cout << mynode->getInfo() << " ";
            preOrder(mynode->getLeft());
            preOrder(mynode->getRight());
        }
    }
    void postOrder(BSTNode *mynode)
    {
        if (mynode)
        {
            postOrder(mynode->getLeft());
            postOrder(mynode->getRight());
            cout << mynode->getInfo() << " ";
        }
    }

    BSTNode *findMin(BSTNode *node)
    {
        if (!node)
            return node;
        if (!node->getLeft())
            return node;
        return findMin(node->getLeft());
    }
    BSTNode *findMax(BSTNode *node)
    {
        if (!node)
            return node;
        if (!node->getRight())
            return node;
        return findMax(node->getRight());
    }
    BSTNode *search(BSTNode *node, int val)
    {
        if (node == NULL || node->getInfo() == val)
            return node;
        else if (node->getInfo() < val)
            search(node->getRight(), val);
        else
            search(node->getLeft(), val);
    }

    BSTNode *remove(BSTNode *node, int val)
    {

        if (node->getInfo() > val)
        {
            BSTNode *t = remove(node->getLeft(), val);
            node->setLeft(t);
            if (t)
                t->setParent(node);
        }
        else if (node->getInfo() < val)
        {
            BSTNode *t = remove(node->getRight(), val);
            node->setRight(t);
            if (t)
                t->setParent(node);
        }
        else if (node->getLeft() && node->getRight())
        {
            BSTNode *minNode = findMin(node->getRight());
            node->setInfo(minNode->getInfo());
            BSTNode *temp = remove(node->getRight(), minNode->getInfo());
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
    void displayMenu()
    {
        cout << "          MENU        " << endl;
        cout << "1- Preorder Display. " << endl;
        cout << "3- Postorder Display. " << endl;
        cout << "3- Inorder Display. " << endl;
    }

    void menu()
    {
        cout << "          MENU        " << endl;
        cout << "1- Insert a node. " << endl;
        cout << "2- Delete a node. " << endl;
        cout << "3- Display tree. " << endl;
        cout << "4- Find Max Node. " << endl;
        cout << "5- Find Min Node. " << endl;
        cout << "6- Search a node. " << endl;
        cout << "7- Exit " << endl;
    }
};

int main()
{
    BST mybst;
    bool flag = true;
    int temp = 0; // for storing values for insertion , deletion etc
    char choice;
    do
    {
        mybst.menu();
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == '1')
        {
            cout << "Enter a value to insert: " << endl;
            cin >> temp;
            mybst.insert(temp);
        }
        else if (choice == '2')
        {
            cout << "Enter a value to delete: ";
            cin >> temp;
            mybst.remove(mybst.root, temp);
        }
        else if (choice == '3')
        {
            char c;
            do
            {
                mybst.displayMenu();
                cout << "Enter choice:";
                cin >> c;
                if (c == '1')
                {
                    cout << "Pre Order: ";
                    mybst.preOrder(mybst.root);
                    cout << endl;
                }
                else if (c == '2')
                {
                    cout << "Post Order:: ";
                    mybst.postOrder(mybst.root);
                    cout << endl;
                }
                else if (c == '3')
                {
                    cout << "In Order: ";
                    mybst.inOrder(mybst.root);
                    cout << endl;
                }
            } while (c != '1' && c != '2' && c != '3');
        }
        else if (choice == '4')
        {
            cout << "Max: " << mybst.findMax(mybst.root)->getInfo() << endl;
        }
        else if (choice == '5')
        {
            cout << "Min: " << mybst.findMin(mybst.root)->getInfo() << endl;
        }
        else if (choice == '6')
        {
            cout << "Enter the value to search: ";
            cin >> temp;
            if (mybst.search(mybst.root, temp))
                cout << "Found" << endl;
            else
                cout << "Not Found." << endl;
        }
        else
            cout << "Invalid choice: " << endl;
    } while (choice != '7');

    return 0;
}
