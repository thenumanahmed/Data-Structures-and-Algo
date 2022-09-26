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
	int size;
	int totalSize;

public:
	StackList(int s = 5)
	{
		size = 0;
		totalSize = s;
		head = NULL;
	}
	void push()
	{

		if (!isFull())
		{
			int val;
			cout << "Enter a value to push: ";
			cin >> val;
			Node *newNode = new Node(val);
			newNode->next = head;
			head = newNode;
			size++;
		}
		else
		{
			cout << "			Stack is full!\n";
		}
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
	bool isFull()
	{
		return (size == totalSize);
	}
	int getSize()
	{
		return size;
	}
	int pop()
	{ // check before call that stack is not empty
		int returnVal = head->data;
		Node *toDel = head;
		head = head->next;
		delete toDel;
		--size;
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

void printMenu()
{
	cout << " SELECT THE OPERATION TO PERFORM ON STACK " << endl;
	cout << "1- Push." << endl;
	cout << "2- Pop." << endl;
	cout << "3- isEmpty." << endl;
	cout << "4- isFull." << endl;
	cout << "5- Size." << endl;
	cout << "6- Display." << endl;
	cout << "7- Exit" << endl;
}
int main()
{
	char choice;
	int size = 0;
	cout << "Enter the size of Stack: ";
	cin >> size;
	StackList st(size);

	do
	{
		printMenu();
		cin >> choice;
		if (choice == '1')
			st.push();
		else if (choice == '2'){
			if(!st.isEmpty())
			st.pop();
			else{
				cout<<"		Stack is Empty "<<endl;
			}
		}

		else if (choice == '3')
		{
			if (st.isEmpty())
				cout << "			Stack is empty" << endl;
			else
				cout << "			Stack is not empty" << endl;
		}
		else if (choice == '4')
		{
			if (st.isFull())
				cout << "			Stack is empty" << endl;
			else
				cout << "			Stack is not empty" << endl;
		}
		else if (choice == '5')
			cout << "Size: " << st.getSize() << endl;

		else if (choice == '6')
			st.display();
		else if(choice!='7')
			cout << "ENTER A VALID CHOICE: " << endl;
	} while (choice != '7');

	return 0;
}