
			//	task 1
#include<iostream>
using namespace std;

class Queue;		//forward decalaration
class Stack;		//forward declaration
void showTrucks(string);	//forward decalaration

class Node {
	int id;
	Node* next;
public:

	Node(int val = 0) {
		id = val;
		next = nullptr;
	}
	int getId() {
		return id;
	}
	Node* getNext() {
		return next;
	}
	friend class Stack;
	friend void showTrucks(string);
	friend class Queue;

};

class Stack {
	Node* head;
public:
	Stack() {
		head = NULL;
	}
	bool isEmpty()
	{
		return head == nullptr;
	}
	void push(int id) {
		Node* newNode = new Node(id);
		newNode->next = head;
		head = newNode;
	}
	void pop()
	{
		if (head == nullptr) return;
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	int getHeadId() {
		return head->id;
	}
	Node* getHead() {		//returns the address of 1st node
		return head;
	}
	int top() {		//returns the id of top element
		return head->id;
	}
	void display()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->id << "  ";
			temp = temp->next;
		}cout << endl;
	}
	friend void showTrucks(string );
};

class Queue {
	Node* front;
	Node* back;
public:
	Queue() {
		front = NULL;
		back = NULL;
	}
	bool isEmpty()
	{
		return front == nullptr;
	}
	Node* getFront() {
		return front;
	}
	int getFrontId() {
		return front->id;
	}
	void enqueue(int id) {
		Node* temp = new Node(id);
		if (isEmpty())
		{
			front = back = temp;
		}
		else
		{
			back->next = temp;
			back = temp;
		}
	}

	void dequeue()
	{
		if (isEmpty()) 
		{
			cout<<endl << "No Element to Dequeue" << endl;
			return;
		}
		else
		{
			Node* temp = front;
			front = front->next;
			delete temp;
			if (front == NULL) 
				back = NULL;
		}

	}
	void display()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty!" << endl;
			return;
		}
		else
		{
			cout << "Elements in Queue are:   ";
			Node* temp = front;
			while (temp != nullptr)
			{
				cout << temp->id << "  ";
				temp = temp->next;
			}cout << endl;
		}
	}
};

Stack garage;		//to hold data of trucks in garage
Queue road;			//to hold data of trucks on road
void showTrucks(string);
void on_road(int );
void Enter_Garage(int);
void Exit_Garage(int );

int main() {
	on_road(2);
	on_road(5);
	on_road(10);
	on_road(9);
	on_road(22);
	showTrucks("Road");
	showTrucks("Garage");
	Enter_Garage(2);
	showTrucks("Road");
	showTrucks("Garage");
	Enter_Garage(10);
	Enter_Garage(5);
	Exit_Garage(2);
	Exit_Garage(5);
	showTrucks("Garage");

	return 0;
}

void showTrucks(string name) {
	Node* temp = NULL;
	if (name == "road" || name == "Road") {
		temp = road.getFront();
	}
	else if (name == "garage" || name == "Garage") {
		temp = garage.getHead();
	}
	cout << name << " Vehicle: ";
	if (temp == NULL) {
		cout << "Empty. " << endl;
	}
	else {

		while (temp != nullptr)
		{
			cout << temp->id << "  ";
			temp = temp->next;
		}cout << endl;
	}
}
void on_road(int id) {
	road.enqueue(id);
}
void Enter_Garage(int id) {
	if ((!road.isEmpty()) && road.getFrontId() == id) {
		road.dequeue();
		garage.push(id);
	}
	else {
		cout << "ERROR: " << id << " NO. cannot enter into Garage. " << endl;
	}
}
void Exit_Garage(int id) {
	if ((!garage.isEmpty()) && garage.getHeadId() == id) {
		cout << id << " NO. Vehicle Leaving the Garage. " << endl;
		garage.pop();
	}
	else {
		cout << "ERROR: " << id << " NO. cannot exit Garage. " << endl;
	}
}





















//
//
//
//
//		///		task 2
//#include<iostream>
//using namespace std;
//
//class node {
//private:
//	int data;
//	node* next;
//public:
//	node(int value = 0) {
//		data = value;
//		next = nullptr;
//	}
//	friend class CircularLL;
//};
//
//
//class CircularLL {
//private:
//	node* head;
//	int length;
//public:
//	CircularLL() {
//		head = new node();
//		head->next = head;
//		length = 0;
//	}
//	void insert(int value) {
//		node* newNode = new node(value);  //head->head
//		newNode->next = head->next;       //0->head
//		head->next = newNode;             //head->0->head
//		length++;
//	}
//
//	void insertAtEnd(int value) {
//		if (head->next == head) {
//			insert(value);
//		}
//		else {
//			node* newNode = new node(value);  //head->1->2->3->head
//			node* i = head->next;
//			while (i->next != head) {
//				i = i->next;
//			}
//			i->next = newNode;
//			newNode->next = head;
//		}
//		length++;
//	}
//	void selectAndRemove() {
//		if (length <= 0) {
//			return;
//		}
//		int m;
//		cout << "Enter the value of M: ";
//		cin >> m;
//		node* temp = head;
//		int i = 0;
//		while (length>1) {
//			i = 0;
//			for (; i < length; i++) {
//				temp = temp->next;
//				if (temp == head) {
//					temp = head->next;
//				}
//				if (i == m) {
//					int del = temp->data;
//					temp = temp->next;
//					cout << "removing " << del << endl;
//					deleteNode(del);
//					display();
//					i = 0;
//				}
//			}
//			
//		}
//		cout << "Selected " << head->next->data<<endl;
//	}
//
//	void deleteNode(int value) {
//		node* i = head;
//		while (i->next != head) {
//			if (i->next->data == value) {
//				node* del = i->next;
//				i->next = i->next->next;
//				delete del;
//
//			}
//			else {
//				i = i->next;
//			}
//		}
//		length--;
//	}
//
//	void display() {
//		node* i = head->next;
//		while (i != head) {
//			cout << i->data << " ";
//			i = i->next;
//		}cout << endl;
//	}
//};
//
//int main() {
//	CircularLL leaders;
//	leaders.insertAtEnd(1);
//	leaders.insertAtEnd(2);
//	leaders.insertAtEnd(3);
//	leaders.insertAtEnd(4);
//	leaders.insertAtEnd(5);
//	leaders.insertAtEnd(6);
//	leaders.insertAtEnd(7);
//	leaders.insertAtEnd(8);
//	leaders.insertAtEnd(9);
//	leaders.insertAtEnd(10);
//	leaders.display();
//	leaders.selectAndRemove();
//
//
//
//
//	return 0;
//}
//
//