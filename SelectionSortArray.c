#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int temp;

void swap(int arr[], int index, int j){
    temp= arr[index];
    arr[index]=arr[j];
    arr[j]=temp;

}

void selectionSort(int arr[], int n){
    int i,j,index;

    for (i=0; i<=n-2; i++)
        index=i;
        for (j=i+1; j<=n-1; j++)
            if (arr[j] < arr[index])
                swap(arr, index ,j);

}

void print(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//main driver program
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    print(arr, n);
    return 0;
}
