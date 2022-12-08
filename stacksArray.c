#include <stdlib.h>
#include <stdio.h>

int main(){
    int top = 0;
    int n; //number of elements in stack
    printf("What do you want the stack size to be?: ");
    scanf("%d", n);

    stack = malloc(n*sizeof(int));

    printf("Elements to Push onto stack: \n 1 \n 34 \n 8 \n 90 \n\n\n ");

    push(1);
    push(34);
    push(8);
    push(90);

    printf("The Stack: ")
    printStack(stack);

    return NULL;
}

void push(int k){
    if (top < n){

        stack[top]=k;
        top = top + 1;

    }
    else {printf("The stack is FULL.");}
}