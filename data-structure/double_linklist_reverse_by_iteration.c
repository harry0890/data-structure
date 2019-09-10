#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *prev;
	struct node *next;
} Node;

// Time Complexity: O(n)
void Reverse(Node **head)
{
	Node *current = *head;
	Node *temp = NULL;

	while(current != NULL) {
		temp = current->prev;
		current->prev = current->next; // reverse node1 <- node2
		current->next = temp;
		current = current->prev;
	}
	if(head != NULL)        //                            head
		*head = temp->prev; // NULL <- Node1 <- Node2 <- Node3 -> NULL
	                        //          next <- temp -> prev
}


void Push(Node **head, int val)
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->data = val;
	newnode->prev = NULL;
	if(*head != NULL)
		(* head)->prev = newnode;
	newnode->next = *head;
	*head = newnode;
}

void Print(Node *head)
{
	while(head != NULL) {
		printf("%2d ",head->data);
		head = head->next;
	}
	printf("\n");
}



int main(void)
{
	Node *head = NULL;

	Push(&head, 10);
	Push(&head, 20);
	Push(&head, 30);
	Push(&head, 40);

	Print(head);
	Reverse(&head);
	Print(head);

	return 0;
}
