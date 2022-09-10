#include<iostream>

using namespace std;

class node {
private:
	node* next;
	int data;
public:
	node(int value = 0) {
		data = value;
		next = NULL;
	}
	friend class garage;
	friend class road;
};

class garage {
private:
	node* head;
public:
	garage() {
		head = NULL;
	}
	void enter_garage(int value) {
		node* newNode = new node(value);
		newNode->next = head;
		head = newNode;
		return;
	}
	int exit_garage() {
			node* del = head;
			int data = head->data;
			head = head->next;
			delete del;
			return data;
	}
	void display() {
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	bool isEmpty() {
		return head == NULL;
	}
	int top() {
		return head->data;
	}
};

class road {
private:
	node* front;
	node* back;
public:
	road() {
		front = NULL;
		back = NULL;
	}
	void on_road(int value) {
		node* newNode = new node(value);
		if (back == NULL) {
			back = front = newNode;
			return;
		}
		back->next = newNode;
		back = newNode;
	}
	int dequeue() {
		node* temp = front;
		int data = front->data;
		front = front->next;
		delete temp;
		return data;
	}
	bool isEmpty() {
		return front == NULL;
	}
	int front() {
		return front->data;
	}
};



int main() {
	garage g;
	road r;

	return 0;
}