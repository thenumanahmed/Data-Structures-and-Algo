#include <iostream>
#include <queue>
using namespace std;
class BSTNode
{
	int val;
	BSTNode *parent, *left, *right;

public:
	BSTNode(int v) : val(v), parent(), left(), right() {}
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
	void setVal(int v)
	{
		val = v;
	}
	int getVal()
	{
		return val;
	}
};
class BST
{
public:
	BSTNode *root;
	BST() : root() {}
	void insert(int);
	void inOrder(BSTNode *);
	void preOrder(BSTNode *);
	void postOrder(BSTNode *);
	int height(BSTNode *);
	BSTNode *findMin(BSTNode *);
	BSTNode *findMax(BSTNode *);
	BSTNode *search(BSTNode *, int);
	BSTNode *remove(BSTNode *, int);
	void displayMenu();
	void menu();
	void levelOrderDisplay(queue<BSTNode *> &); // displaying nodes according to level
	void descendingOrderDisplay(BSTNode *);		// Descending order
	int diff(BSTNode *);						// returns difference of heights of left and right child
	void checkBalance(BSTNode *);				// check the balance and displays technique for balancing the tree
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
				else if (c == '4')
				{
					cout << "Descending Order: ";
					mybst.descendingOrderDisplay(mybst.root);
					cout << endl;
				}
				else if (c == '5')
				{
					cout << "Level Order: ";
					queue<BSTNode *> q;
					if (mybst.root)
						q.push(mybst.root);
					mybst.levelOrderDisplay(q);
					cout << endl;
				}
				else if (c == '6')
				{
					cout << " Back to main menu. " << endl;
				}
				else
				{
					cout << "Invalid choice." << endl;
				}
			} while (c != '6');
		}
		else if (choice == '4')
		{
			cout << "Max: " << mybst.findMax(mybst.root)->getVal() << endl;
		}
		else if (choice == '5')
		{
			cout << "Min: " << mybst.findMin(mybst.root)->getVal() << endl;
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
		else if (choice == '7')
		{
			cout << "Height of tree is: " << mybst.height(mybst.root) << endl;
		}
		else if (choice == '8')
		{
			cout << "Checking Balance: " << endl;
			mybst.checkBalance(mybst.root);
		}
		else if (choice == '9')
		{
			break;
		}
		else
			cout << "Invalid choice: " << endl;
	} while (choice != '9');

	return 0;
}
void BST::checkBalance(BSTNode *root)
{
	if (!root)
		return;					   // when node is null
	checkBalance(root->getLeft()); // recursive call for left subtree
	cout << "  " << root->getVal() << "  ";
	int parent_Balance = diff(root);
	if (parent_Balance > 1 && diff(root->getLeft()) > 0)
		cout << " requires LL rotation" << endl;
	else if (parent_Balance > 1)
		cout << " requires LR rotation" << endl;
	else if (parent_Balance < -1 && diff(root->getRight()) > 0)
		cout << " requires RL rotation" << endl;
	else if (parent_Balance < -1)
		cout << " requires RR rotation" << endl;
	else // when parent_Balance is 0
		cout << " is balanced" << endl;
	checkBalance(root->getRight()); // recursive call for right subtree
}
void BST::insert(int value)
{
	if (search(root, value))
		cout << "Already Exist." << endl;
	return;
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
int BST::height(BSTNode *temp)
{
	int h = 0; // if node is null height will be zero
	if (temp != NULL)
		h = max(height(temp->getLeft()), height(temp->getRight())) + 1;
	return h;
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
void BST::levelOrderDisplay(queue<BSTNode *> &q)
{
	if (q.empty() == NULL)
		return;
	if (q.front()->getLeft())
		q.push(q.front()->getLeft());
	if (q.front()->getRight())
		q.push(q.front()->getRight());
	cout << q.front()->getVal() << " " << endl;
	q.pop();
	if (!q.empty())
		levelOrderDisplay(q);
}
void BST::displayMenu()
{
	cout << "          MENU        " << endl;
	cout << "1- Preorder Display. " << endl;
	cout << "2- Postorder Display. " << endl;
	cout << "3- Inorder Display. " << endl;
	cout << "4- Descending Order Display. " << endl;
	cout << "5- Level Order Display. " << endl;
	cout << "6- Back To Main Menu. " << endl;
}
void BST::menu()
{
	cout << "          MENU        " << endl;
	cout << "1- Insert a node. " << endl;
	cout << "2- Delete a node. " << endl;
	cout << "3- Display tree. " << endl;
	cout << "4- Find Max Node. " << endl;
	cout << "5- Find Min Node. " << endl;
	cout << "6- Search a node. " << endl;
	cout << "7- Height of Tree " << endl;
	cout << "8- Check Balance " << endl;
	cout << "9- Exit " << endl;
}
void BST::descendingOrderDisplay(BSTNode *root)
{
	if (root == NULL)
		return;
	descendingOrderDisplay(root->getRight());
	cout << root->getVal() << " ";
	descendingOrderDisplay(root->getLeft());
}
int BST::diff(BSTNode *temp)
{
	return height(temp->getLeft()) - height(temp->getRight());
}