#include <iostream>
using namespace std;

void inputArray(int *&, int);           // to input elements the array
void displayMenu();                     // to display the menu
void removeMenu(int *&, int &);         // for options to remove element or index
void removeIndex(int *&, int &, int);   // for removing an index
void removeEle(int *&, int &, int);     // for removing an element
void indexAt(int *&, int &);            // for getting element at specific index
void display(int *, int);               // for displaying array elements
void updateMenu(int *&, int);           // for options to update element or index
void updateEle(int *, int, int, int);   // for updating an element
void updateIndex(int *, int, int, int); // for updating an index
void insert(int *&, int &);             // for inserting an element in the array
void search(int *, int);                // for searching an element

int main()
{
    int size = 0; // to store the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;
    int *arr = nullptr;
    inputArray(arr, size);

    bool flag = true;
    while (flag)
    {
        char choice;
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            insert(arr, size);
            break;

        case '2':
            removeMenu(arr, size);
            break;

        case '3':
            updateMenu(arr, size);
            break;

        case '4':
            search(arr, size);
            break;

        case '5':
            indexAt(arr, size);
            break;

        case '6':
            display(arr, size);
            break;

        case '7':
            flag = false; // will cause the program to exit
            break;

        default:
            cout << "Invalid choice!   TRY AGAIN" << endl;
        }
    }

    return 0;
}

// Function Definitions

// to display the menu
void displayMenu()
{
    cout << "1- Insert an element." << endl;
    cout << "2- Remove an element or index." << endl;
    cout << "3- Update an element or index." << endl;
    cout << "4- Search an element." << endl;
    cout << "5- Search element at an index." << endl;
    cout << "6- Display an array." << endl;
    cout << "7- Exit" << endl;
}
// to input elements the array
void inputArray(int *&arr, int size)
{
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element no " << i + 1 << " : ";
        cin >> arr[i];
    }
}
// for options to update element or index
void updateMenu(int *&arr, int size)
{
    int tempEle, // for storing element that is to be updated
        newEle;  // for storing the new element to be placed
    while (true)
    {
        char choice;
        cout << "Enter 'e' to update the element and 'i' to update the index: " << endl;
        cout << "Disclaimer! if you select element all duplicates will also be updated.  " << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 'I' || choice == 'i')
        {
            int index = 0;
            cout << "Enter the index to be updated: ";
            cin >> index;

            cout << "Enter the value to place at index " << index << ": ";
            cin >> newEle;

            updateIndex(arr, size, index, newEle);
            break;
        }
        else if (choice == 'E' || choice == 'e')
        {
            cout << "Enter the element to be updated: ";
            cin >> tempEle;

            cout << "Enter the new element: ";
            cin >> newEle;

            updateEle(arr, size, tempEle, newEle);
            break;
        }
        else
        {
            cout << "Invalid choice. Try Again." << endl;
        }
    }
}
// for getting element at specific index
void indexAt(int *&arrOrig, int &size)
{
    int index;
    cout << "Enter the index to get element: ";
    cin >> index;
    if (index < size && index >= 0)
    {
        cout << "The element at index " << index << " is: " << arrOrig[index] << endl;
    }
    else
    {
        cout << "Index does not exist." << endl;
    }
}
// for searching an element
void search(int *arr, int size)
{
    int element = 0; // for storing element that is to be searched
    cout << "Enter the element to be found: " << endl;
    cin >> element;
    int first, last, middle;
    int index = -1;
    first = 0;
    last = size - 1;
    middle = (first + last) / 2;
    while (first <= last)
    {
        if (arr[middle] < element)
            first = middle + 1;
        else if (arr[middle] == element)
        {
            index = middle;
            break;
        }
        else
            last = middle - 1;
        middle = (first + last) / 2;
    }
    if (index == -1)
    {
        cout << element << " does not found." << endl;
    }
    else
    {
        cout << element << " is present at index " << index << endl;
    }
}
// for displaying array elements
void display(int *arr, int size)
{ // display the array
    cout << endl
         << "Displaying Array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Value at index " << i << " is " << arr[i] << " " << endl;
    }
    cout << endl;
}
// for options to remove element or index
void removeMenu(int *&arrOrig, int &size)
{
    while (true)
    {
        char choice;
        cout << "Enter 'e' to  remove the element and 'i' to remove the index: " << endl;
        cout << "Disclaimer! if you select element all duplicates will also be removed.  " << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 'I' || choice == 'i')
        {
            int tempIndex;
            cout << "Enter the index to be removed: ";
            cin >> tempIndex;
            removeIndex(arrOrig, size, tempIndex);
            break;
        }
        else if (choice == 'E' || choice == 'e')
        {
            int tempEle = 0;
            cout << "Enter the element to be removed: ";
            cin >> tempEle;
            removeEle(arrOrig, size, tempEle);
            break;
        }
        else
        {
            cout << "Invalid choice. Try Again." << endl;
        }
    }
}
// for removing an element
void removeEle(int *&arrOrig, int &size, int ele)
{
    int flag = 0;
    while (true)
    {
        int index = -1;
        for (int i = 0; (i < size); i++)
        {
            if (arrOrig[i] == ele)
            {
                index = i;
            }
        }
        if (index == -1)
        {
            break;
        }
        else
        {
            flag++;
            int *arr = new int[size - 1];
            for (int i = 0; i < size; i++)
            {
                if (i < index)
                {
                    arr[i] = arrOrig[i];
                }
                else if (i >= index)
                {
                    arr[i] = arrOrig[i + 1];
                }
            }
            size--; // size is reduced in main function
            delete[] arrOrig;
            arrOrig = arr;
        }
    }
    if (flag == 0)
    {
        cout << "Element not found! " << endl;
    }
    else if (flag == 1)
    {
        cout << flag << " element removed successfully. " << endl;
    }
    else
    {
        cout << flag << " elements removed successfully. " << endl;
    }
}
// for removing an index
void removeIndex(int *&arrOrig, int &size, int index)
{
    if (index >= 0 || index < size)
    {
        int *arr = new int[size - 1];
        for (int j = 0; j < size; j++)
        {
            if (j < index)
            {
                arr[j] = arrOrig[j];
            }
            else if (j >= index)
            {
                arr[j] = arrOrig[j + 1];
            }
        }
        delete[] arrOrig;
        arrOrig = arr;
        size--; // size is reduced in main function
    }
    else
    {
        cout << "Index does not exist. " << endl;
    }
}
// for inserting an element in the array
void insert(int *&arrOrig, int &size)
{                // insert
    int tempEle, // to store the element to be inserted
        index;   // to store the index at which element is to be inserted

    while (true)
    {
        cout << "Enter the element to insert: ";
        cin >> tempEle;

        char choice;
        cout << "Enter 'h' to insert at head and 't' to insert at tail: ";
        cin >> choice;

        if (choice == 'H' || choice == 'h')
        {
            index = 0;
            break;
        }
        else if (choice == 'T' || choice == 't')
        {
            index = size;
            break;
        }
        else
        {
            cout << "Invalid choice. Try Again." << endl;
        }
    }

    int *arr = new int[size + 1];
    for (int i = 0; i < size + 1; i++)
    {
        if (i == index)
        {
            arr[i] = tempEle;
        }
        else if (i < index)
        {
            arr[i] = arrOrig[i];
        }
        else if (i > index)
        {
            arr[i] = arrOrig[i - 1];
        }
    }
    size++;
    delete[] arrOrig;
    arrOrig = arr; // swapping the address
    cout << "Element inserted successfully. " << endl;
}
// for updating an index
void updateIndex(int *arr, int size, int index, int newEle)
{
    if (index < 0 || index >= size)
    {
        cout << "Index does not exist." << endl;
    }
    else
    {
        arr[index] = newEle;
        cout << "Element updated at index " << index << endl;
    }
}
// for updating an element
void updateEle(int *arr, int size, int ele, int newEle)
{
    bool updated = false;
    // all elements wil be updated
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ele)
        {
            arr[i] = newEle;
            updated = true;
        }
    }
    if (updated)
    {
        cout << "Element updated. " << endl;
    }
    else
    {
        cout << "No element found to update. " << endl;
    }
}