#include <iostream>
using namespace std;
class StackArray
{
private:
	int *arr;
	int totalSize;
	int size = 0;

public:
	StackArray(int a = 5)
	{
		totalSize = a;
		arr = new int[totalSize];
	}
	
	int getSize()
	{
		return size;
	}
	void push()
	{

		if (!isFull())
		{
			int value;
			cout<<"Enter a value to push: ";
			cin >>value;
			arr[size] = value;
			size++;
		}
		else
		{
			cout << "			Stack is full!\n";
		}
	}
	bool isEmpty()
	{
		return (size == 0);
	}
	void topOfStack()
	{
		if (isEmpty())
		{
			cout << "			Stack is empty\n";
		}
		else
		{
			cout << arr[size - 1] << endl;
			;
		}
	}
	bool isFull()
	{
		if (size == totalSize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << "			Stack is empty.\n";
		}
		else
		{
			size--;
		}
	}
	void display()
	{
		for (int i = size - 1; i >= 0; i--)
		{
			cout << arr[i] << "\n";
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
	StackArray st(size);

	do
	{
		printMenu();
		cin >> choice;
		if (choice == '1')
			st.push();
		else if (choice == '2')
			st.pop();

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