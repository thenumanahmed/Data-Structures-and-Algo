#include <iostream>
#include <algorithm>
using namespace std;

void max_heapify(int Arr[], int i, int N)
{
    int left = 2 * i; // left child
    int right = 2 * i + 1;
    int largest =i; // right child
    if (left < N && Arr[left] > Arr[largest])
        largest = left;
    if (right < N && Arr[right] > Arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(Arr[i], Arr[largest]);
        max_heapify(Arr, largest, N);
    }
}

void build_maxheap(int Arr[], int N)
{
    for (int i = N / 2; i >= 1; i--)
    {
        max_heapify(Arr, i, N);
    }
}

void max_heap_sort(int arr[], int i, int j)
{
    build_maxheap(arr,j);
    if (i < j)
    {
        if (arr[i] < arr[j])
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        max_heap_sort(arr, i + 1, j - 1);
    }
    
}
void display(int array[], int SIZE)
{
    for (int i = 1; i < SIZE; i++)
        cout << array[i] << "  ";
        cout<<endl;
}
int main()
{
    const int SIZE = 8; // Note that we are using 1-based indexing to store binary tree.

    // Note that max_heapify only heapifies a given node and its decendants
    // int array [SIZE] =  {-1, 8, 7, 6, 3, 2, 4, 5};               // -1 due to 1-based indexing
    // cout << "max_heap on Array:  {8, 7, 6, 3, 2, 4, 5}." << endl;
    // max_heapify (array,1,SIZE-1);

    // build_maxheap heapifies the whole tree
    int array[SIZE] = {-1, 4, 7, 8, 3, 9, 6, 5}; // -1 due to 1-based indexing
    cout << "build_maxheap on Array:  {4, 7, 8, 3, 9, 6, 5}." << endl;
    build_maxheap(array, SIZE - 1);

    // display the array
    cout << "Array after heapification: ";
    display(array,SIZE);

    max_heap_sort(array, 1, 7);
    cout << "Array after heapsort: ";
    display(array,SIZE);

    return 0;
}