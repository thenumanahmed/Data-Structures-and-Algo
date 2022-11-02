#include <iostream>
using namespace std;

void maxHeapify(int arr[], int i, int size)
{
    int left = 2 * i, right = 2 * i + 1;
    int largest = i;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, largest, size);
    }
}


void buildMaxHeap(int arr[], int size)
{
    for (int i = size / 2; i >= 1; i--)
        maxHeapify(arr, i, size);
}


void display(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void maxHeapSort(int arr[], int size)
{
    buildMaxHeap(arr, size);
    for (int i = size - 1; i >=2 ; i--)
    {
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, 1, i);
    }
}
int main()
{
    const int SIZE = 8;

    int array[SIZE] = {-1, 4, 7, 8, 3, 9, 6, 5};
    display(array, SIZE);
    cout << "Calling Max heap Function. " << endl;
    buildMaxHeap(array, SIZE - 1);
    display(array, SIZE);

    cout << "Max Heapify: ";
    maxHeapify(array, 1, SIZE);
    display(array, SIZE);

    cout << "Max Heapsort: ";
    maxHeapSort(array, 8);
    display(array, SIZE);

    return 0;
}