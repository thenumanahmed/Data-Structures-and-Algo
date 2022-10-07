#include <iostream>
using namespace std;

class Queue; // forward decalaration
class Node
{
    int data;
    Node *next;

public:
    Node(int val = 0)
    {
        data = val;
        next = NULL;
    }
    friend class Queue;
};

class Queue
{
    Node *front;
    Node *back;
    int length;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
        length = 0;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    void enqueue()
    {
        int val = 0;
        cout << "Enter the value to Enqueue: ";
        cin >> val;
        Node *temp = new Node(val);
        if (isEmpty())
        {
            front = back = temp;
        }
        else
        {
            back->next = temp;
            back = temp;
        }
        length++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << endl
                 << "No Element to Dequeue" << endl;
            return;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            length--;
            if (front == NULL)
                back == NULL;
        }
    }
    int getLength()
    {
        return length;
    }
    void displayMenu()
    {
        cout << endl;
        cout << "                     MENU                  " << endl;
        cout << " 1- Display Queue.                         " << endl;
        cout << " 2- Enqueue an element.                    " << endl;
        cout << " 3- Dequeue an element.                    " << endl;
        cout << " 4- Check Queue isEmpty?                   " << endl;
        cout << " 5- Check no of nodes in Queue.		    " << endl;
        cout << " 6- Exit.								    " << endl;
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
            Node *temp = front;
            while (temp != nullptr)
            {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue q;
    char choice = '1';
    do
    {
        q.displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == '1')
            q.display();
        else if (choice == '2')
            q.enqueue();
        else if (choice == '3')
            q.dequeue();
        else if (choice == '4')
            if (q.isEmpty())
                cout << "The queue is empty." << endl;
            else
                cout << "The queue is not empty." << endl;
        else if (choice == '5')
            cout << "The Total Size of Queue is: " << q.getLength() << endl;
        else if (choice == '6')
            cout << "Thanks For using our service. " << endl;
        else
            cout << "           INVALID CHOICE        " << endl;
    } while (choice != '6');

    return 0;
}
