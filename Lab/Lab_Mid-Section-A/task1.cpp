#include<iostream>    // Task 1 function is at line 61
#include<conio.h>
using namespace std;

class LinkList;

class Node{
    private:
    int data;
    Node* next;
    public:
        Node(){
            data=-1;
            next=NULL;
        }
        Node(int v){
            data=v;
            next=NULL;

        }
    friend class LinkList;
};

class LinkList{
    private:
        Node* head;
    public:
        LinkList(){
            head = new Node;
            head->next=NULL;
        }
        void insert(int v){
            Node* curr = head;
            while (curr->next!=NULL)
            {
                curr= curr->next;
            }
            curr->next=new Node(v);
        }
        void display(){
            Node* curr = head;
            while(curr->next!=NULL){
                cout<<curr->next->data<<"    ";
                curr=curr->next; 
            }
            cout<<endl;
        }

        Node* getFirstElement(){
            return head->next;
        }
        Node* getLastElement(){
           Node* curr = head;
            while(curr->next!=NULL){
                curr=curr->next; 
            }
            return curr;
        }

        // Task 1
        void append(LinkList& l){
            Node* last=getLastElement();
            last->next=l.getFirstElement();

        }
};
int main(){
    LinkList l1,l2;
    cout<<"First List"<<endl;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.display();

    cout<<"Second List "<<endl;
    l2.insert(4);
    l2.insert(5);
    l2.insert(6);
    l2.display();

    cout<<"After Connecting "<<endl;
    l1.append(l2);
    l1.display();
}