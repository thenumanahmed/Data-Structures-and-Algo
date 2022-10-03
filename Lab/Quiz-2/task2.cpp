	///		task 2
#include<iostream>
using namespace std;

class node {
private:
	int data;
	node* next;
public:
	node(int value = 0) {
		data = value;
		next = NULL;
	}
	friend class CircularLL;
};


class CircularLL {
private:
	node* head;
	int length;
public:
	CircularLL() {
		head = new node();
		head->next = head;
		length = 0;
	}
	void insert(int value) {
		node* newNode = new node(value);  //head->head
		newNode->next = head->next;       //0->head
		head->next = newNode;             //head->0->head
		length++;
	}

	void insertAtEnd(int value) {
		if (head->next == head) {
			insert(value);
		}
		else {
			node* newNode = new node(value);  //head->1->2->3->head
			node* i = head->next;
			while (i->next != head) {
				i = i->next;
			}
			i->next = newNode;
			newNode->next = head;
		}
		length++;
	}
	void selectAndRemove() {
		if (length <= 0) {
			return;
		}
		int m;
		cout << "Enter the value of M: ";
		cin >> m;
		node* temp = head;
		int i = 0;
		while (length> 1 && length >= m) {
			i = 0;
			for (; i < length; i++) {
				temp = temp->next;
				if (i == m) {
					if(temp == head) temp = temp->next;
					temp = temp->next;
					int del = temp->data;
					cout << "removing " << del << endl;
					deleteNode(del);
					display();
					i = 0;
				}
			}
			
		}
		cout << "Selected " << head->next->data<<endl;
	}

	void deleteNode(int value) {
		node* i = head;
		while (i->next != head) {
			if (i->next->data == value) {
				node* del = i->next;
				i->next = i->next->next;
				delete del;

			}
			else {
				i = i->next;
			}
		}
		length--;
	}

	void display() {
		node* i = head->next;
		while (i != head) {
			cout << i->data << " ";
			i = i->next;
		}cout << endl;
	}
};

int main() {
	CircularLL leaders;
	leaders.insertAtEnd(1);
	leaders.insertAtEnd(2);
	leaders.insertAtEnd(3);
	leaders.insertAtEnd(4);
	leaders.insertAtEnd(5);
	leaders.insertAtEnd(6);
	leaders.insertAtEnd(7);
	leaders.insertAtEnd(8);
	leaders.insertAtEnd(9);
	leaders.insertAtEnd(10);
	leaders.display();
	leaders.selectAndRemove();
	

	return 0;
}




