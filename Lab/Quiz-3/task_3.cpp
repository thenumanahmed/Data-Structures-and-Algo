#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class HashTree;
class Node
{
    string name;
    int id;
    float CGPA;

public:
    Node *next;
    Node(string name, int id, float CGPA) : name(name), id(id), CGPA(CGPA), next() {}
    Node *getNext() { return next; }
    void setNext(Node *next) { this->next = next; }
    int getId() { return id; }
    void setId(int id) { this->id = id; }
    void setCGPA(int CGPA) { this->CGPA = CGPA; }
    float getCGPA() { return CGPA; }
    string getName() { return name; }
    friend class HashTree;
};

class HashTree
{
    Node **arr;
    int size; // size of the array
public:
    HashTree(int s = 10)
    {
        size = s;
        arr = new Node *[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = new Node(".", 0, 0.0); // dummy head nodes
        }
    }
    void insert(string name, int id, float CGPA)
    {
        Node *temp = search(name);
        if (temp)
        {
            temp->setId(id);
            temp->setCGPA(CGPA);
            cout << "Record of " << name << " was updated: " << endl;
            return;
        }
        int index = hashFun(name);
        Node *temp = *(arr + index);
        Node *newNode = new Node(name, id, CGPA);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    int hashFun(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.length(); i++)
        {
            code += int(key[i]);
        }
        return (code % size);
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            Node *temp = arr[i]->next; // next pf dummy nodes
            cout << i << "   ";
            while (temp != NULL)
            {
                cout << "[ " << temp->name << " | " << temp->id << " | " << temp->CGPA << " ]";
                temp = temp->next;
                if (temp)
                    cout << " -> ";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
    Node *search(string name)
    {
        int index = hashFun(name);
        Node *temp = *(arr + index);
        temp = temp->next;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                return temp;
            }
            temp = temp->next;
        }
        return 0; // when not found
    }
    void remove(string name)
    {
        int index = hashFun(name);
        Node *prev = *(arr + index);
        Node *temp = prev->next;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    void menu()
    {
        cout << "   MENU " << endl;
        cout << " 1- Insert a Student record in hashtable. " << endl;
        cout << " 2- Remove a Student record from hashtable. " << endl;
        cout << " 3- Display all Student record in hashtable. " << endl;
        cout << " 4- Search a Student record in the hashtable. " << endl;
        cout << " 5- Exit. " << endl;
    }
};
int main()
{
    HashTree tr;
    int id;
    string name;
    float CGPA;
    do
    {
        char choice = '\0';
        tr.menu();
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == '1')
        {
            cout << "Enter the name of Student: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter id of Student: ";
            cin >> id;
            do
            {
                cout << "Enter CGPA of the Student: ";
                cin >> CGPA;
                if (CGPA < 0.0 || CGPA > 4.0)
                {
                    cout << "INVALID CGPA Entered........." << endl;
                }
            } while (CGPA < 0.0 || CGPA > 4.0);
            tr.insert(name, id, CGPA);
        }
        else if (choice == '2')
        {
            cout << "Enter key to remove: ";
            cin >> name;
            tr.remove(name);
        }
        else if (choice == '3')
        {
            tr.display();
        }
        else if (choice == '4')
        {
            cout << "Enter key to search: ";
            cin >> name;
            if (tr.search(name))
                cout << endl
                     << "Record of " << name << " found. " << endl;
            else
                cout << endl
                     << "Record of "
                     << " not found. " << endl;
        }
        else if (choice == '5')
        {
            break;
        }
        else
        {
            cout << "Invalid choice !! " << endl;
        }
    } while (true);

    return 0;
}
