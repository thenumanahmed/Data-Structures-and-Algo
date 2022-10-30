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
    friend class Stack;


};

class Stack{
    private:
    Node* head;
    public:
        Stack(){
            head=new Node();
        }
        void insert(int v){
            Node* node = new Node(v);
            node->next=head->next;
            head->next=node;
        }
        void display(){
            Node* curr = head;
            while(curr->next!=NULL){
                cout<<curr->next->data<<"   ";
                curr=curr->next;
            }
        }
        Node* getFirstNode(){return head->next;}
        void reverseDisplay(Node* curr ){
            if(curr==NULL){
                return ;
            }
            reverseDisplay(curr->next);
            cout<<curr->data<<"    ";
        }
};





int main(){
    Stack s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    cout<<"Simple Order Display "<<endl;
    s.display();

    cout<<endl<<"Displaying in Reverse ordre "<<endl;
    s.reverseDisplay(s.getFirstNode());
}