#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Maximum size of the circular queue

typedef struct lQueue {
    int *base;  // Pointer to dynamically allocated array
    int front;  // Points to the front element
    int rear;   // Points to the next insertion position
} lQueue;

// Function to create a queue
int createQ(lQueue *q) {
    q->base = (int *)malloc(MAX_SIZE * sizeof(int));
    if (q->base == NULL) {
        printf("Memory allocation failed!\n");
        return -1; // Failure
    }
    q->front = q->rear = 0;
    return 0; // Success
}

// Function to push an element into the queue
int push(lQueue *q, int v) {
    if ((q->rear + 1) % MAX_SIZE == q->front) { // Check if the queue is full
        printf("Queue Overflow!\n");
        return -1; // Failure
    }
    q->base[q->rear] = v;               // Insert the value
    q->rear = (q->rear + 1) % MAX_SIZE; // Update rear pointer
    return 0; // Success
}

// Function to pop an element from the queue
int pop(lQueue *q) {
    if (q->front == q->rear) { // Check if the queue is empty
        printf("Queue Underflow!\n");
        return -1; // Failure
    }
    int v = q->base[q->front];        // Get the value
    q->front = (q->front + 1) % MAX_SIZE; // Update front pointer
    return v; // Return the popped value
}

// Function to display the queue content
void printQueue(lQueue *q) {
    if (q->front == q->rear) { // Check if the queue is empty
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue content: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->base[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    lQueue q;
    createQ(&q); // Initialize the queue

    // Push elements into the queue
    for (int i = 1; i <= 4; i++) {
        push(&q, i);
    }

    // Print the queue content
    printQueue(&q);

    // Pop two elements
    printf("Popped: %d\n", pop(&q));
    printf("Popped: %d\n", pop(&q));

    // Print the queue content after popping
    printQueue(&q);

    // Push more elements
    push(&q, 5);
    push(&q, 6);

    // Print the final queue content
    printQueue(&q);

    // Free allocated memory
    free(q.base);
    return 0;
}
