#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node* next;
} Node;

int main() {
    char c1;
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    struct node* p = head;
    
    printf("Enter characters to add to the list (use '#' to stop):\n");
    while (1) {
        scanf(" %c", &c1);
        if (c1 == '#') {
            break;
        }

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = c1;
        newNode->next = NULL;
        p->next = newNode;
        p = p->next;
    }

    printf("Linked list: ");
    p = head->next;
    while (p) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");

    p = head;
    while (p != NULL) {
        struct node* next = p->next;
        free(p);
        p = next;
    }

    return 0;
}
