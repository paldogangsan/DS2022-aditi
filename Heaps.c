#include <stdio.h>
#include <stdlib.h>


// swap the positions
void swap(int* a, int* b)
{

	int temp = *a;

	*a = *b;

	*b = temp;
}


void heapify(int arr[], int N, int i)
{
	// Find largest among root, left child and right child

	// Initialize largest as root
	int largest = i;

	// leftchild = 2*i + 1
	int left = 2 * i + 1;

	// rightchild = 2*i + 2
	int right = 2 * i + 2;

	if (left < N && arr[left] > arr[largest])
		largest = left;
	if (right < N && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {

		swap(&arr[i], &arr[largest]);
		heapify(arr, N, largest);
	}
}

// heapsort function
void heapSort(int arr[], int N)
{

	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);
	for (int i = N - 1; i >= 0; i--) {

		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver's code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	heapSort(arr, N);
	printf("Sorted array is\n");
	printArray(arr, N);
}

