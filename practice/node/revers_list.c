#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void add_at_end(struct Node **head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL)
    {
        *head = temp; // Update head if the list is empty
    }
    else
    {
        struct Node *ptr = *head;
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
    printf("\n");
}

void add_at_pos(struct Node *head, int data, int pos)
{
    struct Node *ptr = head;
    struct Node *ptr2 = malloc(sizeof(struct Node));
    ptr2->data = data;
    ptr2->next = NULL;

    if (pos == 1)
    { // Special case: inserting at the first position
        ptr2->next = head;
        head = ptr2;
        return;
    }

    pos--;
    while (pos > 1 && ptr != NULL)
    {
        ptr = ptr->next;
        pos--;
    }
    if (ptr != NULL)
    {
        ptr2->next = ptr->next;
        ptr->next = ptr2;
    }
    else
    {
        printf("Position out of range\n");
        free(ptr2); // Clean up memory if position is invalid
    }
}

struct Node *del_first(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is already empty\n");
    }
    else
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
    return head;
}

struct Node *del_last(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is already empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp = head;
        struct Node *temp2 = head;
        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}

void delete_last(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is already empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void del_pos(struct Node **head, int pos)
{
    struct Node *current = *head;
    struct Node *previous = *head;
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else if (pos == 1)
    {
        *head = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        while (pos != 1)
        {
            previous = current;
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}

struct Node *del_list(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        free(temp);
        head = temp;
    }
    return head;
}

struct node* reverse(struct Node *head){
    struct Node *prev = NULL;
    struct Node *next = NULL;
    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

int main()
{
    struct Node *head = NULL; // Initialize head as NULL
    printf("%d\n", &head);
    add_at_end(&head, 10);
    add_at_end(&head, 20);
    add_at_end(&head, 40);
    add_at_end(&head, 30);
    add_at_end(&head, 50);
    add_at_end(&head, 60);

    int data = 25, pos = 3;
    add_at_pos(head, data, pos);

    printf("List after adding nodes:\n");
    printList(head);
    head = reverse(head);
    printf("List after reversing the list:\n");
    printList(head);

    head = del_first(head);
    head = del_last(head);
    delete_last(head);
    del_pos(&head, pos);

    printf("List after deleting the first node:\n");
    printList(head);
    head = del_list(head);
    printList(head);
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    return 0;
}
