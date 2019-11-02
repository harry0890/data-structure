#include <stdio.h> 
#include <stdlib.h> 

typedef struct node 
{ 
    int data; 
    struct node *next; 
}Node; 

void push(Node** head_ref, int new_data) 
{ 
    Node* new_node = (Node *)malloc(sizeof(Node)); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 

void deleteNode(Node **head_ref, int key) 
{
    Node* temp = *head_ref, *prev; 

    if (temp == NULL) return; 

    if (temp->data == key) { 
        *head_ref = temp->next;
        free(temp); 
        return; 
    } 
	 
    while (temp != NULL && temp->data != key) { 
        prev = temp; 
        temp = temp->next; 
    } 

    prev->next = temp->next;  
    free(temp);
} 

void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        printf(" %d ", node->data); 
        node = node->next; 
    } 
} 

int main() 
{
    Node* head = NULL; 
  
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
  
    puts("Created Linked List: "); 
    printList(head); 
    deleteNode(&head, 3); 
    puts("\nLinked List after Deletion of 1: "); 
    printList(head); 
    return 0; 
}
