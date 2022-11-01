#include<iostream>
using namespace std;

class listnode {
public:
    int data;
    listnode* next;
    listnode(int v = 0) {
        data = v;
        next = NULL;
    }
    friend class linkedlist;
};
class linkedlist {
public:
    listnode* head;
    linkedlist();
    ~linkedlist();
    bool empty() const;
    int front();
    void addfront(int);
    void removefront();
    void display();
   
};

void insertInAscOrder(listnode*& head, int value)
{
    if (!head)
    {
        listnode* newNode = new listnode(value);
        head = newNode;
        return;
    }

    else if (head->data > value)
    {
        listnode* newNode = new listnode(value);
        newNode->next = head;
        head = newNode;
        return;
    }
    if (!head->next) {
        listnode* newNode = new listnode(value);
        head->next = newNode;
        return;
    }
    insertInAscOrder(head->next, value);
}
int getNthTerm(listnode* &head, int n) {
    if (!head) return -1;
    if (n == 1) {
        return head->data;
    }
    return getNthTerm(head->next, n - 1);
}
float getMedian(listnode* head) {
    listnode* temp = head;
    int n=0;
    while (temp) {
        n++;
        temp = temp->next;
    }
    float med = 0;
    if (n % 2 != 0) {
        med = getNthTerm(head, n / 2+1);
    }
    else {
        med = (getNthTerm(head, n / 2) + getNthTerm(head, n / 2 + 1)) / 2.0;
    }
    return med;
}

int main() {
    linkedlist l1;
    insertInAscOrder(l1.head,3);
    insertInAscOrder(l1.head,6);
    insertInAscOrder(l1.head,5);
    insertInAscOrder(l1.head,43);
    insertInAscOrder(l1.head,43);
    insertInAscOrder(l1.head,8);
    l1.display();
    cout <<"Median "<< getMedian(l1.head)<<endl;

    return 0;
}

void linkedlist::display() {
    listnode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}
linkedlist::linkedlist()
    : head() { }
linkedlist::~linkedlist()
{
    while (!empty()) removefront();
}
bool linkedlist::empty() const
{
    return head == NULL;
}
int linkedlist::front()
{
    return head->data;
}
void linkedlist::removefront() {
    if (head) {
        listnode* old = head;
        head = old->next;
        delete old;
    }
}
void linkedlist::addfront(int e) {
    listnode* old = head;
    head = new listnode();
    head->data = e;
    head->next = old;
}
