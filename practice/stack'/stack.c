#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct stack {
    int *top;
    int *base;
    int size;
} stack;

// Function to create the stack
void create(stack *s) {
    s->base = (int *)malloc(MAX_SIZE * sizeof(int));
    if (s->base == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    s->top = s->base;
    s->size = MAX_SIZE;
}

// Function to push an element onto the stack
int push(stack *s, int t) {
    if (s->top - s->base >= s->size) {
        printf("Stack Overflow\n");
        return -1;
    }
    *(s->top) = t;
    s->top++;
    return 0;
}

// Function to pop an element from the stack
int pop(stack *s) {
    if (s->top == s->base) {
        printf("Stack Underflow\n");
        return -1;
    }
    s->top--;
    return *(s->top);
}

int main() {
    int a, t;
    stack s;

    create(&s);  // Pass the address of the stack
    printf("Enter a number: ");
    scanf("%d", &a);

    // Convert to binary and push onto the stack
    while (a > 0) {
        t = a % 2;
        push(&s, t);  // Pass the address of the stack
        a = a / 2;
    }

    printf("Binary representation: ");
    // Pop and print the binary representation
    while (s.top > s.base) {
        t = pop(&s);  // Pass the address of the stack
        printf("%d", t);
    }
    printf("\n");

    // Free the allocated memory
    free(s.base);

    return 0;
}
