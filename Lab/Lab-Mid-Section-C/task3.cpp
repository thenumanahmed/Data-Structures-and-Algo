#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int d = -1)
    {
        data = d;
        next = NULL;
    }
};
class Queue
{
    Node* head, * tail;
    int length;
    bool isEmpty()
    {
        return (head == NULL);
    }

public:
    Queue()
    {
        head = tail = NULL;
        length = 0;
    }
    void enqueue(int);
    int dequeue();
    void display();
    int getlength() {
        return length;
    }
    void enqueueInAscOrder(int value)
    {
        length++;
        if (head == NULL)
            enqueue(value);
        else if (head->data > value)
        {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            return;
        }
        else{
            Node* temp = head;
            while (temp->next != NULL && temp->next->data < value)
            {
                temp = temp->next;
            }
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
};
int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "ERR.   Empty Queue..";
        return -1;
    }
    else
    {
        Node* temp = head;
        head = head->next;
        int data = temp->data;
        delete temp;
        length--;
        return data;
    }
    
}
void Queue::enqueue(int val)
{
    Node* node = new Node(val);
    if (!isEmpty())
    {
        tail->next = node;
        tail = node;
    }
    else
    {
        head = tail = node;
    }
    length++;
}
void Queue::display()
{
    Node* temp = head;
    cout << endl;
    for (; temp != NULL; temp = temp->next)
    {
        cout << temp->data << " ";
    }
    cout << endl;
}

int main()
{
    Queue q;
    q.enqueueInAscOrder(4);
    q.enqueueInAscOrder(2);
    q.enqueueInAscOrder(3);
    q.enqueueInAscOrder(5);
    q.enqueueInAscOrder(6);
    q.enqueueInAscOrder(8);
    q.display();
    return 0;
}