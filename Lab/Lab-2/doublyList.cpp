#include"dnode.h"
using namespace std;
class DoublyLinklist{
    DNode *head;
    DNode *tail;
    public:
    DoublyLinklist(){
        head = tail = NULL;
    }
    void insertAtHead(int val){
        DNode*newDNode  = new DNode(val);
        newDNode->setNext(head);
        if(head==NULL){
            tail = newDNode;
        }
        else{
            head->setPrev(newDNode);
        }
        head=newDNode;
    }
    void insertAtTail(int val){
        DNode*newDNode  = new DNode(val);
        if(head == NULL) head = tail = newDNode;
        else{
            tail->setNext(newDNode);
            newDNode->setPrev(tail);
            tail = newDNode;
        }
    }
    void deleteFromTail(){
        if(head==NULL) return;
        DNode*toDel = tail;
        tail=tail->getPrev();
        delete toDel;
    }
    void deleteFromHead(){
        if(head==NULL) return;
        DNode*toDel=head;
        if(head==tail)
            head = tail = NULL;
        else{
            head= head->getNext();
            head->setPrev(NULL);
        }
        delete toDel;
    }
    void display(){
        DNode*temp = head;
        while(temp!=NULL){
            cout<<temp->getData()<<" ";
            temp =temp->getNext(); 
        }cout<<endl;
    }
};

int main(){
    DoublyLinklist d1;
    d1.insertAtHead(2);
    d1.insertAtHead(3);
    d1.insertAtHead(4);
    d1.insertAtHead(5);
    d1.display();
    cout<<"Deleting from head"<<endl;
    d1.deleteFromHead();
    d1.display();
    return 0;
}