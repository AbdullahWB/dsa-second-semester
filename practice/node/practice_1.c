#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

void printList(struct Node* node) 
{ 
	while (node != NULL) { 
		printf(" %d ", node->data); 
		node = node->link; 
	} 
}

int main()
{
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 45;
    head->link = NULL;

    struct Node *current = malloc(sizeof(struct Node));
    current->data = 23;
    current->link = NULL;
    head->link = current;
    printList(head);
    return 0;
}