#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

void count_of_nodes(struct Node* head){
    int count = 0;
    struct Node *p;
    p = head->link;
    while(head!=NULL){
        count++;
        head = head->link;
    }
    printf("Number of nodes in the linked list: %d\n", count);
}

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

    count_of_nodes(head);
    printList(head);
    int count=0;
    struct Node *p;
    p = head->link;
    while(p!=NULL){
        count++;
        p = p->link;
    }
    printf("\nthis is head %d ", head->data);

    return 0;
}