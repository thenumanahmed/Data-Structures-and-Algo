#include<iostream>
using namespace std;
class LinkedList;		//forward declaration
class Node {
	int data;
	Node* next;
public:
	Node(int val = 0) {
		data = val;
		next = NULL;
	}
	friend class LinkedList;
};
class LinkedList {
	Node* head;
	Node* tail;
	int length;
public:
	LinkedList() {
		length = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
	}
	void insertAtHead(int val) {
		Node* newNode = new Node(val);
		newNode->next = head->next;
		head->next = newNode;
		length++;
	}
	void insertAtTail(int val) {
		Node* newNode = new Node(val);
		Node* temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = tail;
		length++;
	}
	void display() {
		Node* temp = head->next;
		while (temp != tail) {
			cout << temp->data << " ";
			temp = temp->next;
		}cout << endl;
	}
	void append(int num) {
		if (num >= length)
			cout << "Append Failed" << endl;
		else {
			int count = 1;
			Node* temp = head->next;
			while (temp != tail && count < num) {
				temp = temp->next;
				count++;
			}
			if (temp != NULL) {
				Node* prevLast = head->next;
				while (prevLast->next != tail) {
					prevLast = prevLast->next;
				}
				prevLast->next = head->next;
				head->next = temp->next;
				temp->next = tail;
			}
			cout << "Append SuccessFull" << endl;
		}
	}
	void insertSort(int val) {
		//sort();
		Node* newNode = new Node(val);
		Node* temp = head->next;
		Node* prev = head;
		while (temp != tail && (newNode->data > temp->data)) {
			prev = temp;
			temp = temp->next;
		}
		newNode->next = prev->next;
		prev->next = newNode;
	}
	void sort() {
		if (head == NULL) {
			return;
		}
		Node* prev;
		Node* curr;
		bool flag = true;
		while (flag) {
			flag = false;
			prev = head;
			curr = prev->next;
			while (curr != NULL) {
				if (curr->data < prev->data) {
					flag = true;
					int temp = prev->data;		//temp storing vakue
					prev->data = curr->data;
					curr->data = temp;
				}
				prev = prev->next;
				curr = curr->next;
			}
		}
	}
};
int main() {
	LinkedList l1;
	l1.insertAtTail(2);
	l1.insertAtTail(3);
	l1.insertAtTail(5);
	l1.insertAtTail(6);
	l1.display();
	cout << "Now append sort 3" << endl;
	l1.append(3);
	l1.display(); 
	cout << "Now Insert sort 4" << endl;
	l1.insertSort(4);
	l1.display();
	return 0;
}