#include<iostream>
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
	bool isEmpty() {
		if (head == NULL)
			return true;
		return false;
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


bool pres(char a, char b);      
string infixTOPostfix(string); 


int main(){
    cout<<"infix expression:   A + B * C + D"<<endl;
    cout<<"Postfix expression: "<<infixTOPostfix("A + B * C + D")<<endl;
	cout<<"infix expression:   (A + B) * (C + D)"<<endl;
    cout<<"Postfix expression: "<<infixTOPostfix("(A + B) * (C + D)")<<endl;

    return 0;
}
bool pres(char a, char b)
{
    int num1, num2;
    if (a == '+' || a == '-')
    {
        num1 = 1;
    }
    else if (a == '*' || a == '/')
    {
        num1 = 2;
    }
    else if (a == '(' || a == ')')
    {
        num1 = 3;
    }

    if (b == '+' || b == '-')
    {
        num2 = 1;
    }
    else if (b == '*' || b == '/')
    {
        num2 = 2;
    }
    else if (b == '(' || b == ')')
    {
        num2 = 3;
    }
    return num1 < num2;
}
string infixTOPostfix(string infix)
{
    StackList s;
    string ans = "";

    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= '0' && infix[i] <= '9') ||
            (infix[i] >= 'A' && infix[i] <= 'Z') ||
            (infix[i] >= 'a' && infix[i] <= 'z'))
        {
            ans += infix[i];
        }
        else
        {
            if (s.isEmpty())
            {
                s.push(infix[i]);
            }
            else
            {
                if (infix[i] == ')')
                {
                    while (s.peek() != '(')
                    {
                        ans += s.pop();
                    }
                    s.pop(); // to pop (
                }
                else
                {
                    while (!pres(s.peek(), infix[i]) && s.peek() != '(' && !s.isEmpty())
                    {
                        ans += s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    while (!s.isEmpty())
    {
        ans += s.pop();
    }
    return ans;
}