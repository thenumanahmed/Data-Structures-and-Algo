#include<iostream>
#include<conio.h>
using namespace std;


class Node{
    private:
    public:
    int data;
    Node* next;
        Node(){
            data=-1;
            next=NULL;
        }
        Node(int v){
            data=v;
            next=NULL;

        }
    friend class Queue;
};

class Queue{
    private:
        Node* head;
        Node* tail;
    public :
     Queue(){
        head = new Node();
        tail = head;
     }
     bool isEmpty(){
        return head->next==NULL;
     }
     Node* getHead(){
        return head;
     }
     void setTail(){
        Node* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        tail=curr;
     }
     void push(int v){
        tail->next = new Node(v);
        tail=tail->next;
     }
     void display(){
        Node* curr = head;
        while(curr->next!=NULL){
            cout<<curr->next->data<<"   ";
            curr=curr->next;

        }
        cout<<endl;
     }

     void pushDesending(Node* curr, int v){
        if(curr->next==NULL){
            curr->next=new Node(v);
            tail = curr->next;
        }
        else if(curr->next->data<v){
            Node* node = new Node(v);
            node->next =curr->next;
            curr->next = node;
        }
        else{
            pushDesending(curr->next,v);
        }
     }
};

int main(){

    Queue q;

    cout<<" Pushing 2 "<<endl;
    q.pushDesending(q.getHead(),2);

    cout<<" Pushing 1 "<<endl;
    q.pushDesending(q.getHead(),1);
    
    cout<<" Pushing 6 "<<endl;
    q.pushDesending(q.getHead(),6);
    
    cout<<" Pushing 5 "<<endl;
    q.pushDesending(q.getHead(),5);
    
    cout<<" Pushing 8 "<<endl;
    q.pushDesending(q.getHead(),8);

    cout<<"Display QUeue :";
    q.display();

}