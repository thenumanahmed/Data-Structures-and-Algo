#include"node.h"
using namespace std;
class SinglyLinkList{
    Node *head;
    Node *tail;
    public:
    SinglyLinkList(){
        head = tail = NULL;
    }
    void insertAtHead(int val){
        Node*newNode  = new Node(val);
        newNode->setNext(head);
        if(head == NULL) tail = newNode;
        head = newNode;
    }
    void insertAtTail(int val){
        Node*newNode  = new Node(val);
        if(head == NULL) head = tail = newNode;
        else{
            tail->setNext(newNode);
            tail = newNode;
        }
    }
    void deleteFromTail(){
        if(head==NULL) return;
        Node*toDel=tail; 
        if(head==tail){ //when single node is present
            head= tail = NULL;
        }else{
            Node*temp = head;
            while(temp->getNext()!=tail){
                temp=temp->getNext();
            }
            temp->setNext(NULL);
        }
        delete toDel;
    }
    void deleteFromHead(){
        if(head==NULL) return;
        Node*toDel=head;
        if(head==tail)
            head = tail = NULL;
        else
            head= head->getNext();
        delete toDel;
    }
    void display(){
        Node*temp = head;
        while(temp!=NULL){
            cout<<temp->getData()<<"  ";
            temp =temp->getNext(); 
        }cout<<endl;
    }
};

int main(){
    SinglyLinkList s1;
    s1.insertAtHead(2);
    s1.insertAtHead(3);
    s1.insertAtHead(4);
    s1.insertAtHead(5);
    s1.display();
    cout<<"Deleting from head"<<endl;
    s1.deleteFromHead();
    s1.display();
    return 0;
}

