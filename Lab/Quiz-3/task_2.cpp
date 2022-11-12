#include <iostream>
#include <climits>
using namespace std;

class Heap
{
public:
    int *arr;
    int noOfElements;
    int size;
    Heap(int size = 50)
    {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = INT_MIN;
        }
        noOfElements = 0;
    }
    int getSize()
    {
        return size;
    }
    void insert(int val)
    {
        if (size == noOfElements)
        {
            cout << "Can't insert value, No space left. " << endl;
        }
        else
        {
            arr[noOfElements] = val;
            noOfElements++;
        }
        buildMaxHeap(arr, noOfElements);
    }
    void maxHeapify(int arr[], int i, int s)
    {
        int left = 2 * i + 1, right = 2 * i + 2;
        int largest = i;
        if (left < s && arr[left] > arr[largest])
            largest = left;
        if (right < s && arr[right] > arr[largest])
            largest = right;
        if (largest != i)
        {
            int temp = arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;
            maxHeapify(arr, largest, s);
        }
    }

    void buildMaxHeap(int arr[], int s)
    {
        for (int i = s / 2 + 1; i >= 0; i--) // based on 1 based indexing
            maxHeapify(arr, i, s);
    }

    void maxHeapSort(int arr[], int s)
    {
        buildMaxHeap(arr, s);
        for (int i = s - 1; i >= 1; i--)
        {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            maxHeapify(arr, 0, i);
        }
    }
    void display()
    {
        if (!noOfElements)
            cout << "Heap is empty.. " << endl;
        else
        {
            cout << "Displaying Heap: ";
            for (int i = 0; i < noOfElements; ++i)
            {
                cout << arr[i] << "  ";
            }
            cout << endl;
        }
    }
    void menu()
    {
        cout << "               MENU " << endl;
        cout << " 1- Insert a value: " << endl;
        cout << " 2- Max heapify: " << endl;
        cout << " 3- Build max heap: " << endl;
        cout << " 4- Max heap Sort(Ascending Order): " << endl;
        cout << " 5- Display Heap: " << endl;
        cout << " 6- Exit. " << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    Heap h(size);
    do
    {
        h.menu();
        char  choice = '\0';
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == '1')
        {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            h.insert(val);
        }
        else if (choice == '2')
        {
            h.maxHeapify(h.arr,0,h.noOfElements);
        }
        else if (choice == '3')
        {
            h.buildMaxHeap(h.arr,h.noOfElements);
        }
        else if (choice == '4')
        {
            cout << "Max heap sort function called. " << endl;
            h.maxHeapSort(h.arr, h.noOfElements);
        }
        else if (choice == '5')
        {
            h.display();
        }
        else if (choice == '6')
        {
            break;
        }
        else
        {
            cout << "invalid choice entered ........... " << endl;
        }
    } while (true);
    return 0;
}