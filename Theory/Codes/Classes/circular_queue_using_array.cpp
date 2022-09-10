#include<iostream>
using namespace std;
#define MAX_SIZE 5
class Queue {
private:
	int* myqueue;
	int front;
	int rear;
	int noElements;
public:
	Queue() {
		myqueue = new int[MAX_SIZE];
		front = -1;
		rear = -1;
		noElements = 0;
	}
	bool isFull();
	void enqueue(int x);
	int dequeue();
	bool isEmpty();
	void display();
};
bool Queue::isFull() {
	return noElements == MAX_SIZE;
}
bool Queue::isEmpty() {
	return noElements == 0;
}
int Queue::dequeue() {
	int x = myqueue[front];
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else{
		front = (front + 1) % MAX_SIZE;
		noElements = noElements - 1;
	}
	return x;
}
void Queue::enqueue(int x) {
	if (front == -1) front = 0;
	rear = (rear + 1) % MAX_SIZE;
	myqueue[rear] = x;
	noElements = noElements + 1;
}
void Queue::display() {
	int index = front;
	for (int i = 0; i < noElements;i++) {
		cout << myqueue[index]<<" ";
		index = (index + 1) % MAX_SIZE;
	}
	/*if (front <= rear) {
		for (int i = front; i <= rear; i++) {
			cout << myqueue[i] << " ";
		}cout << endl;
	}
	else {
		for (int i = front; i < MAX_SIZE; i++) {
			cout << myqueue[i] << " ";
		}
		for (int i = 0; i <= rear; i++) {
			cout << myqueue[i] << " ";
		}cout << endl;
	}*/
}


int main() {
	Queue st;
	st.enqueue(44);
	st.enqueue(44);
	st.enqueue(44);
	st.dequeue();
	st.dequeue();
	st.dequeue();
	st.display();
	/*st.enqueue(4);
	st.enqueue(3);
	st.display();
	st.dequeue();
	st.dequeue();
	st.display();
	st.enqueue(333);
	st.enqueue(444);
	st.display();*/
	return 0;
}