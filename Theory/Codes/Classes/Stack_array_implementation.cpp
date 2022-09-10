#include<iostream>
using namespace std;
class stack {
private:
	int* arr;
	int size = 5;
	int length = 0;
public:
	stack() {
		arr = new int[size];
	}
	void push(int value) {
		if (length < size) {
			arr[length] = value;
			length++;
		}
		else {
			cout << "Jan choro bhai!\n";
		}
	}
	bool isEmpty() {
		if (length == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void topOfStack() {
		if (isEmpty()) {
			cout << "Stack is empty\n";
		}
		else {
			cout << arr[length - 1] << endl;;
		}
	}
	bool isFull() {
		if (length == size) {
			return true;
		}
		else {
			return false;
		}
	}
	void pop() {
		if (isEmpty()) {
			cout << "Stack is empty.\n";
		}
		else {
			length--;
		}
	}
	void display() {
		for (int i = length-1; i >= 0 ; i--)
		{
			cout << arr[i] << "\n";
		}
		cout << endl;
	}
};

int main() {
	stack s;
	s.push(0);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.display();

	s.pop();
	s.display();

	return 0;
}