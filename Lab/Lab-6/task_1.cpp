#include <iostream>
using namespace std;

class arrQueue
{
    int noOfElements;
    int front;
    int back;
    int *arr;
    int arrSize;

public:
    arrQueue(int s = 5)
    {
        noOfElements = 0;
        front = back = -1;
        arrSize = s;
        arr = new int[arrSize];
    }
    int getNoOfElements()
    {
        return noOfElements;
    }
    int getSize()
    {
        return arrSize;
    }
    bool isEmpty()
    {
        return noOfElements == 0;
    }
    bool isFull()
    {
        return noOfElements == arrSize;
    }
    void enqueue()
    {
        if (isFull())
        {
            cout << endl
                 << "No more space to enqueue." << endl;
            return;
        }
        int val;
        cout << "Enter the value to enqueue: ";
        cin >> val;
        if (isEmpty())
            front = 0;
        back = (back + 1) % arrSize;
        arr[back] = val;
        noOfElements++;
        cout << endl
             << "Enqueue operation successfully Executed." << endl;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << endl
                 << "No Element available to Dequeue" << endl;
            return;
        }
        if (front == back)
        {
            front = -1;
            back = -1;
        }
        else
            front = (front + 1) % arrSize;
        cout << endl
             << "Dequeue operation successfully Executed. " << endl;
        noOfElements--;
    }
    void display()
    {
        for (int i = 0; i < noOfElements; i++)
        {
            cout << arr[(i + front) % arrSize] << " ";
        }
        cout << endl;
    }
    void displayMenu()
    {
        cout << endl;
        cout << "                     MENU                  " << endl;
        cout << " 1- Display Queue.                         " << endl;
        cout << " 2- Enqueue an element.                    " << endl;
        cout << " 3- Dequeue an element.                    " << endl;
        cout << " 4- Check Queue isFull?                    " << endl;
        cout << " 5- Check Queue isEmpty?                   " << endl;
        cout << " 6- Check the total size of array.         " << endl;
        cout << " 7- Chcek No of Elements stored in array.  " << endl;
        cout << " 8- Exit.								    " << endl;
    }
};

int main()
{
    int size = 0;
    cout << "Enter the size of array: ";
    cin >> size;
    arrQueue q(size);
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
            if (q.isFull())
                cout << "The queue is full." << endl;
            else
                cout << "The queue is not full yet." << endl;
        else if (choice == '5')
            if (q.isEmpty())
                cout << "The queue is empty." << endl;
            else
                cout << "The queue is not empty." << endl;
        else if (choice == '6')
            cout << "The Total Size of Queue is: " << q.getSize() << endl;
        else if (choice == '7')
            cout << "The No of Elements in Queue are: " << q.getNoOfElements() << endl;
        else if (choice == '8')
            cout << "Thanks For using our service. " << endl;
        else
            cout << "INVALID CHOICE " << endl;
    } while (choice != '8');

    return 0;
}
