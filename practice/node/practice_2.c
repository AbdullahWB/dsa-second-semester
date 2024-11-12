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
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 40;
    head->link = NULL;

    struct Node* second = malloc(sizeof(struct Node));
    second->data = 50;
    second->link = NULL;
    head->link = second;

    second = malloc(sizeof(struct Node));
    second->data = 60;
    second->link = NULL;

    head->link->link = second;

    printList(head);

    return 0;
}