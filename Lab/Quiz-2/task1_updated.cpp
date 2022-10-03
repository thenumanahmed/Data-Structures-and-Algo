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
	void push(int value) {
			node* newNode = new node(value);
			newNode->next = head;
			head = newNode;
			return;
	}
    void push(node *newNode) {
			newNode->next = head;
			head = newNode;
			return;
	}
	int pop() {
		node* del = head;
		int data = head->data;
		head = head->next;
		delete del;
		return data;
	}
	void display() {
		cout << "garage:";

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
	void enqueue(int value) {
		node* newNode = new node(value);
		if (back == NULL) {
			back = front = newNode;
			return;
		}
		back->next = newNode;
		back = newNode;
	}
    node* moveFront(){
        node* temp = front;
        front = front->next;
        return temp;
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
	void display() {
		cout << "road:";
		node* temp = front;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}cout << endl;
	}
	int front_data() {
		return front->data;
	}
};

class trucks :public garage, public road {
	garage g;
	road r;
public:
	void on_road(int value) {
		r.enqueue(value);
	}
	void show_truck(string str) {
		if (str == "garage")
			g.display();
		else if (str == "road")
			r.display();
	}
	void enter_garage(int value) {
		if (value == r.front_data()) {
			g.push(r.moveFront());
		}
		else {
			cout << "Can't push! 404\n";
		}
	}
	void exit_garage() {
		g.pop();
	}
};

int main() {
	trucks t;
	t.on_road(2);
	t.on_road(5);
	t.on_road(10);
	t.on_road(9);
	t.on_road(22);

	t.show_truck("road");
	t.show_truck("garage");

	t.enter_garage(2);

	t.show_truck("road");
	t.show_truck("garage");

	t.enter_garage(10);
	t.enter_garage(5);

	t.exit_garage();
	t.exit_garage();

	t.show_truck("garage");
	return 0;
}