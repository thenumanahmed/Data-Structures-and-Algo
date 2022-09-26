#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;


class StackList;
class Node {
	int data;
	Node* next;
public:
	Node(int val) {
		data = val;
		next = NULL;
	}
	void setData(int val) {
		data = val;
	}
	int getData() {
		return data;
	}
	void setNext(Node* node) {
		next = node;
	}
	Node* getNext() {
		return next;
	}
	friend class StackList;
};

class StackList {
	Node* head;
public:
	StackList() {
		head = NULL;
	}
	void push(int val) {
		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;
	}
	int peek() {		// check before call that stack is not empty
		return head->data;
	}
	~StackList() {
		Node* temp = head;
		while (temp != NULL) {
			Node* todel = temp;
			temp = temp->next;
			delete todel;
		}
	}
	bool isEmpty() {
		return (head == NULL);
	}
	int pop() {		// check before call that stack is not empty
		int returnVal = head->data;
		Node* toDel = head;
		head = head->next;
		delete toDel;
		return returnVal;
	}
	void display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int postfixEvaluation(string s) {
	int length = s.length();
	StackList evaluate;
	int i = 0;
	while (i < length) {
		if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '^'||s[i] == '%') {
			int b = evaluate.pop();
			int a = evaluate.pop();
			if (s[i] == '*') 
				evaluate.push(a*b);
			else if (s[i] == '-') 
				evaluate.push(a - b);
			else if (s[i] == '+') 
				evaluate.push(a + b);
			else if (s[i] == '/') 
				evaluate.push(a / b);
			else if (s[i] == '^') 
				evaluate.push( pow(a,b));
            else if (s[i] == '%') 
				evaluate.push(a % b);
		}
		else	
			evaluate.push(int(s[i]-'0'));
		i++;
	}
	return evaluate.pop();
}

int prefixEvaluate(string s) {
	int length = s.length();
	StackList evaluate;
	int i = length-1;
	while (i >=0) {
		if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '^'||s[i] == '%') {
			int b = evaluate.pop();
			int a = evaluate.pop();
			if (s[i] == '*') 
				evaluate.push(a*b);
			else if (s[i] == '-') 
				evaluate.push(a - b);
			else if (s[i] == '+') 
				evaluate.push(a + b);
			else if (s[i] == '/') 
				evaluate.push(a / b);
			else if (s[i] == '^') 
				evaluate.push(a ^ b);
            else if (s[i] == '%') 
				evaluate.push(a % b);
		}
		else	
			evaluate.push(int(s[i]-'0'));
		i--;
	}
	return evaluate.pop();
}

int main(){
    cout<<"Evaluating   683*+8- "<<endl;
    cout<<"Ans = " << postfixEvaluation("683*+8-")<<endl;

    return 0;
}