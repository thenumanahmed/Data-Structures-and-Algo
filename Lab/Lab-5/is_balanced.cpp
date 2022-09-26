#include <iostream>
using namespace std;

class StackList;
class Node
{
	int data;
	Node *next;

public:
	Node(int val)
	{
		data = val;
		next = NULL;
	}
	void setData(int val)
	{
		data = val;
	}
	int getData()
	{
		return data;
	}
	void setNext(Node *node)
	{
		next = node;
	}
	Node *getNext()
	{
		return next;
	}
	friend class StackList;
};

class StackList
{
	Node *head;

public:
	StackList()
	{
		head = NULL;
	}
	void push(int val)
	{
		Node *newNode = new Node(val);
		newNode->next = head;
		head = newNode;
	}
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		return false;
	}
	int peek()
	{ // check before call that stack is not empty
		return head->data;
	}
	~StackList()
	{
		Node *temp = head;
		while (temp != NULL)
		{
			Node *todel = temp;
			temp = temp->next;
			delete todel;
		}
	}
	int pop()
	{ // check before call that stack is not empty
		int returnVal = head->data;
		Node *toDel = head;
		head = head->next;
		delete toDel;
		return returnVal;
	}
	void display()
	{
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
bool isBalanced(string str)
{
	StackList st;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			st.push(str[i]);
		else if ((str[i] == ')' || str[i] == ']' || str[i] == '}') && !st.isEmpty())
		{
			if ((str[i] == ')' && st.peek() == '(') ||
				(str[i] == ']' && st.peek() == '[') ||
				(str[i] == '}' && st.peek() == '{'))
				st.pop();
			else
				st.push(str[i]);
		}
	}
	return st.isEmpty();
}

int main()
{
	cout << "|                 Checking the expressions                      |" << endl;
	cout << endl
		 << "{}{}{{})"
		 << "    ";
	if (isBalanced("{}{}{{})"))
		cout << "       Sequence is Right. " << endl;
	else
		cout << "       Wrong Sequence. " << endl;

	cout << endl
		 << "{{{(})}}"
		 << "   ";
	if (isBalanced("{{{(})}}"))
		cout << "        Sequence is Right. " << endl;
	else

		cout << "        Wrong Sequence. " << endl;
	cout << endl
		 << "{{{()}}}{}(()){}"
		 << "   ";
	if (isBalanced("{{{()}}}{}(()){}"))
		cout << "Sequence is Right. " << endl;
	else
		cout << "Wrong Sequence. " << endl;
	return 0;
}