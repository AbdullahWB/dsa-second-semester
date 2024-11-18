#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void count_of_nodes(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->link;
    }
    printf("Number of nodes in the linked list: %d\n", count);
}

struct Node* add_beginning(struct Node *head, int data){
    struct Node *ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->link = NULL;

    ptr->link = head;
    head = ptr;
    return head;
}

void add_beg(struct node **head, int data){
    struct Node *ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->link = NULL;

    ptr->link = *head;
    *head = ptr;
}

void add_at_end(struct Node *head, int data)
{
    struct Node *ptr, *temp;
    ptr = head;
    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->link = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->link;
    }
}

int main()
{
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 40;
    head->link = NULL;

    add_at_end(head, 70);
    add_at_end(head, 80);
    add_at_end(head, 90);
    count_of_nodes(head);
    // head = add_beginning(head, 30);
    add_beg(&head, 30);
    printList(head);
    // printf("\nthis is head %d ", head->data);

    return 0;
}