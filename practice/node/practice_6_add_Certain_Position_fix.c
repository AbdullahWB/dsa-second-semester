#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of the list
void add_at_end(struct Node **head, int data) {
    struct Node *ptr = *head;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL) { // If the list is empty
        *head = temp;
        return;
    }

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

// Function to add a node at a specific position
void add_at_pos(struct Node* head, int data, int pos) {
    struct Node *ptr = head;
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (pos == 1) { // Insert at the beginning
        newNode->next = head;
        head = newNode;
        return;
    }

    pos--; // Move to the node before the desired position
    while (pos > 1 && ptr->next != NULL) {
        ptr = ptr->next;
        pos--;
    }

    if (pos > 1) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    // Insert the new node
    newNode->next = ptr->next;
    ptr->next = newNode;
}

// Function to print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    // Add nodes at the end
    add_at_end(&head, 10);
    add_at_end(&head, 20);
    add_at_end(&head, 30);

    int data = 40, pos = 3;

    // Add node at position
    add_at_pos(head, data, pos);

    // Print the list
    printList(head);

    return 0;
}
