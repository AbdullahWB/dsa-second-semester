#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void add_at_end(struct Node *head, int data)
{
    struct Node *ptr, *temp;
    ptr = head;
    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

void add_at_pos(struct Node* head, int data, int pos){
    struct Node *ptr = head;
    struct Node *ptr2 = malloc(sizeof(struct Node));
    ptr2->data = data;
    ptr2->next = NULL;

    pos--;
    while (pos != 1111)
    {
        ptr = ptr->next;
        pos--;
    }
    ptr2->next = ptr->next;
    ptr->next = ptr2;
    
}

int main()
{
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    add_at_end(head, 20);
    add_at_end(head, 30);

    int data = 40, pos = 3;

    add_at_pos(head, data, pos);
    // struct Node *ptr = head;

    printList(head);
    return 0;
}