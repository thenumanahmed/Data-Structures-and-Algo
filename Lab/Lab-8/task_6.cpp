
///		//single list task
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkList
{
public:
    Node *head;

    LinkList()
    {
        head = NULL;
    }

    void insertAtBegin(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    int size() const
    {
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            int size = 0;
            Node *iterator = head;
            while (iterator != NULL)
            {
                size++;
                iterator = iterator->next;
            }
            return size;
        }
    }

    void search()
    {
        int value;
        cout << "Enter the value you wanna search:";
        cin >> value;
        bool check = false;
        Node *temp = head;
        if (head->next == NULL)
        {
            if (head->data == value)
            {
                check = true;
            }
            else
            {
                check = false;
            }
        }
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                check = true;
            }
            temp = temp->next;
        }
        if (check)
        {
            cout << "\nFound!\n";
        }
        else
        {
            cout << "\nNot found!\n";
        }
    }

    void deleteNode()
    {
        display();
        int value;
        cout << "Enter the value you wanna delete:";
        cin >> value;
        if (head == NULL)
        {
            return;
        }

        while (head != NULL && head->data == value)
        { // del at head
            Node *del = head;
            head = head->next;
            delete del;
            if (head == NULL)
            {
                return;
            }
        }
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->next != NULL && temp->next->data == value)
            {
                Node *del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    void insertAtEnd()
    {
        int val;
        cout << "Enter the value to insert: ";
        cin >> val;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool Swap(int leftIndex, int rightIndex)
    {
        int sizeOfList = size();
        if ((leftIndex < 0 || leftIndex >= sizeOfList) ||
            (rightIndex < 0 || rightIndex >= sizeOfList) ||
            (leftIndex == rightIndex))
        {
            return false;
        }
        else
        {
            if (leftIndex > rightIndex)
            {
                int temp = leftIndex;
                leftIndex = rightIndex;
                rightIndex = temp;
            }
            int index = 0;
            Node *prevX = NULL, *currX = head,
                 *prevY = head, *currY = head;

            while (index <= rightIndex)
            {
                if (index < leftIndex)
                {
                    prevX = currX;
                    currX = currX->next;
                }
                if (index < rightIndex)
                {
                    prevY = currY;
                    currY = currY->next;
                }
                index++;
            }
            if (leftIndex != 0)
            { // first index not involved
                prevX->next = currY;
                prevY->next = currX;
                Node *temp = currX->next;
                currX->next = currY->next;
                currY->next = temp;
                return true;
            }
            else
            {
                head = currY;
                prevY->next = currX;
                Node *temp = currY->next;
                currY->next = currX->next;
                currX->next = temp;
                return true;
            }
        }
    }

    void insertAfterVal()
    {
        int key, // after key new value will be inserted
            val; // to hold the value of the new node

        cout << "Enter the key after that new node will be inserted: ";
        cin >> key;
        cout << "Enter the value of new node: ";
        cin >> val;

        Node *iter = head;
        if (head == NULL)
        {
            cout << "No node exist will key " << key << endl;
            return;
        }
        while (iter != NULL)
        {
            if (iter->data == key)
            {
                Node *newNode = new Node(val);
                newNode->next = iter->next;
                iter->next = newNode;
            }
            iter = iter->next;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty " << endl;
        }
        else
        {
            cout << endl
                 << "Displaying list....." << endl;
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << endl
                 << endl;
        }
    }
};

void insertAtTail(Node *&ptr, int val)
{
    if (!ptr)
        ptr = new Node(val); // if head if NULL

    else if (!ptr->next)
        ptr->next = new Node(val); // added to last node
    else
        insertAtTail(ptr->next, val);
}


int main()
{
    LinkList l1;
    l1.insertAtBegin(2);
    l1.insertAtBegin(3);
    l1.insertAtBegin(4);
    insertAtTail(l1.head, 5);
    l1.display();
    return 0;
}