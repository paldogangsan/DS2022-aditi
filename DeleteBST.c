#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


struct node {
    int val;
    struct node * left; //smol branch
    struct node * right; // big branch
};


typedef struct node * NodeAddress;

struct node * root = NULL;

NodeAddress search (struct node * root, int input);
NodeAddress delete (int value);
NodeAddress successor (NodeAddress node);
struct node * newinput(int input, NodeAddress n);

NodeAddress new(int input){
   
    struct node * y = (struct node *)malloc(sizeof(struct node));
  
    y -> val = input;
    y -> left = NULL;
    y -> right = NULL;
    assert(y -> right == NULL && y -> left == NULL);
    return y;
  
}

struct node * newinput(int input, NodeAddress n){
    //if the root is NULL, put the new node 
    if (n == NULL){
        return new(input);
    }
    if (input > n -> val){
        (n -> right) = newinput(input, n -> right);
    }
    else{
        (n -> left) = newinput(input, n -> left);
    }
    return n;

}

NodeAddress successor (NodeAddress node){
    node = node -> left;
    while(node){
        node = node -> right;
    }
    return node;
}

NodeAddress search (struct node * root, int input){
    if (root == NULL) {
        return root;
    }
    else if(input > root -> val){
        return search(root -> right, input);
    }
    else if(input < root -> val){
        return search(root -> left, input);
    }
    else{
        return root;
    }
}

NodeAddress delete (int value){
  
    NodeAddress node = search(root, value);

    if(node == NULL){
        return NULL;
    }
   

    if(node -> right == NULL){
        NodeAddress temp = node -> left;
        free(node);
    }
    else if(node -> left == NULL){
        NodeAddress temp = node -> right;
        free(node);
    }
  
    else{
        NodeAddress next = successor(node);
        node -> val = next -> val;             
        free(next);
    }
}

NodeAddress arrayToBST (int k){
    int data;           //store value of the BST node
    int array[k];       
    printf("Enter the values of the BST:");

    for (int i = 0; i < k; i++){        
        scanf("%d", &array[i]);
    }

    root = new(array[0]);
  

    for(int i = 1; i < k; i++){       
        root = newinput(array[i], root);
    }
    return root;
}


void printBST(struct node *root)
{
    // If the root node is NULL, return
    if (root != NULL){
        
        printf("-> %d\n", root->val);
        printBST(root->left);
        printBST(root->right);
        //free(root);
    }
}

void main(){
    
    int k;
    NodeAddress root;
    printf("Enter total number of nodes in the BST: \n");
    scanf("%d", &k);

    root = arrayToBST(k);
    printBST(root);

    int del;
    printf("Enter value to be deleted. ");
    scanf("%d", &del);
    printf("%d", del);
    delete(del);
    printBST(root);

   
}

