// C program to count number of nodes in a circular linked
// list.
#include <stdio.h>
#include <stdlib.h>

/*structure for a node*/
typedef struct Node {
	int data;
	struct Node* next;
} Node;

/* Function to insert a node at the beginning of a Circular
linked list */
void push(Node** head_ref, int data)
{
	Node* ptr1 = (Node*)malloc(sizeof(Node));
	Node* temp = *head_ref;
	ptr1->data = data;
	ptr1->next = *head_ref;

	/* If linked list is not NULL then set the next of last
	* node */
	if (*head_ref != NULL) {
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; /*For the first node */
	*head_ref = ptr1;
}

/* Function to count nodes in a given Circular
linked list */

int countNodes(Node* head)
{
	Node* temp = head;
	int result = 0;
	if (head != NULL) {
		do {
			temp = temp->next;
			result++;
		} while (temp != head);
	}

	return result;
}

/* Driver program to test above functions */
int main()
{
	/* Initialize lists as empty */
	Node* head = NULL;
	push(&head, 12);
	push(&head, 56);
	push(&head, 2);
	push(&head, 11);
	printf("%d", countNodes(head));
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
