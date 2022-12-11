#include<iostream>
using namespace std;

void maxHeapify(int arr[],int i ,int size) {
	int left = 2 * i,right = 2 * i+1;
	int largest = i;
	if (left<size && arr[left]>arr[largest]) 
		largest = left;
	if (right<size && arr[right]>arr[largest])
		largest = right;
	if (largest != i) {
		int temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		maxHeapify(arr, largest, size);
	}
}
void minHeapify(int arr[], int i, int size) {
	int left = 2 * i, right = 2 * i + 1;
	int largest = i;
	if (left<size && arr[left]<arr[largest])
		largest = left;
	if (right<size && arr[right]<arr[largest])
		largest = right;
	if (largest != i) {
		int temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		minHeapify(arr, largest, size);
	}
}

void buildMaxHeap(int arr[],int size) {
	for (int i = size / 2; i >= 1; i--) 
		maxHeapify(arr, i, size);
}
void buildMinHeap(int arr[],int size) {
	for (int i = size / 2; i >= 1; i--) 
		minHeapify(arr, i, size);
}

void display(int *arr, int size) {
	for (int i = 1; i < size; i++) 
		cout << arr[i] << " ";
		cout << endl;
}


void maxHeapSort(int arr[], int size) {
	buildMaxHeap(arr, size);
	for (int i = size-1; i >= 2; i--) {
		int temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		maxHeapify(arr,1,i );
	}
}
void minHeapSort(int arr[], int size) {
	buildMinHeap(arr, size);
	for (int i = size-1; i >= 2; i--) {
		int temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		minHeapify(arr,1,i );
	}
}
int main()
{
	const int SIZE = 8; 

	int array[SIZE] = { -1, 4, 7, 8, 3, 9, 6, 5 }; 
	display(array, SIZE);
	cout << "Calling Max heap Function. "<<endl;
	buildMaxHeap(array, SIZE - 1);
	display(array, SIZE);

	cout << "Array after max heapify: ";
	maxHeapify(array,1, SIZE);
	display(array, SIZE);
	
	cout << "Array after min heapify: ";
	minHeapify(array,1, SIZE);
	display(array, SIZE);

	minHeapSort(array, 8);
	cout << "Array after min heapsort: ";
	display(array, SIZE);
	
	maxHeapSort(array, 8);
	cout << "Array after max heapsort: ";
	display(array, SIZE);

	return 0;
}