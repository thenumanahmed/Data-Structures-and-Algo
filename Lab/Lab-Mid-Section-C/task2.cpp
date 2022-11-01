#include<iostream>
using namespace std;

class Node {
public:
    float data;
    char elem;
    Node* next;
    Node() {
        next = NULL;
        data = 0;
        elem = '\0';
    }
    Node(float val, char c){
        next = NULL;
        data = val;
        elem = c;
    }
};
class LinkedStack {
    Node* head;
public:
    LinkedStack() {
        head = NULL;
    }
    
    bool empty() const {
        if (!head) return true;
        return false;
    }
    pair<float,char>  top() {
        pair<float ,char> p1;
        p1.first = head->data;
        p1.second = head->elem;
        return p1;
    }
    void push(float val,char c) {
        Node* newNode;
        newNode = new Node(val,c);
        newNode->next = head;
        head = newNode;
    }
    void pop(){
        if(head) {
            Node* old = head;
            head = head->next;
            delete old;
        }
    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " "<<temp->elem<<endl;
            temp = temp->next;
        }cout << endl;
    }
};
int main() {
    LinkedStack S1;
    S1.push(17.3,'k');
    S1.push(19,'l');
    cout<<S1.top().first<<" ";
    cout<<S1.top().second<<endl;
    S1.pop();
    S1.display();
    return 0;
}