#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubbleSort(int* a, int n) {
    int done, i, swap;

    for (done=0; done<n; done++) {
        swap= 0;
        for(i=0; i<n-1-done; i++) {
            if(a[i]>a[i+1]) {
                //then swap these elements since they are in the wrong order
                int t = a[i];
                a[i]= a[i+1];
                a[i+1]= t;
                swap=1;
            }
        } // i loop ends here
        if (swap==0)
            break;

    } // done loop ends here
}


int * generateArray(int n) {
    int * t = malloc( n * sizeof(int) );
    if (t) {
        for( int i=0; i<n; i++) {t[i]= rand()%1000;}
    }
    return t;
}

void printArray(int *a, int n) {
    printf("Array= ");
    for (int i=0; i<n; i++) {
        printf( i? ", %d" : "%d", a[i]);
    }
    printf(".\n");
}

void printArray1(int *a, int n) {
    for(int i=0; i<n; i++) {
        printf("%d", a[i]);
    }
}

int main(int argc, char **argv) {
    int * a;
    int n = 10;

    srand(time(NULL));

    a= generateArray(n);
    printArray(a,n);

    free(a);
    return 0;
}