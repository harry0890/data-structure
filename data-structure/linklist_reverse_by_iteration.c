#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct _Node {
	int data;
	struct _Node *next;
} Node;

//Time Complexity: O(n)
//Space Complexity: O(1)
void reverse(Node **head)
{
	Node *prev = NULL;
	Node *current = *head;
	Node *next = NULL;

	while(current != NULL) {
		next = current->next; // store next node for link
		current->next = prev; // prev reverse to NULL or other node
		prev = current; // move to next node
		current = next; // move to next node
	}
	*head = prev;
}


void push(Node **head, int val)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	if(new_node == NULL) {
		perror("memory allocate new node fail\n");
	}
	
	new_node->data = val;
	new_node->next = (*head);
	*head = new_node;
}

void print(Node *head)
{
	while(head != NULL) {
		printf("%2d ", head->data);
		head = head->next;
	}
	printf("\n");
}


int main(void)
{
	Node *head = NULL;

	push(&head, 10);
	push(&head, 20);
	push(&head, 30);
	push(&head, 40);

	print(head);

	reverse(&head);

	print(head);

	return 0;
}
