#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Define a Queue structure
struct Queue
{
    struct Node *front; // Points to the front of the queue
    struct Node *rear;  // Points to the rear of the queue
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initializeQueue(struct Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

// Function to enqueue (add to the rear of the queue)
void enqueue(struct Queue *q, int data)
{
    struct Node *newNode = createNode(data);
    if (q->rear == NULL)
    { // If the queue is empty
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue (remove from the front of the queue)
int dequeue(struct Queue *q)
{
    if (q->front == NULL)
    { // If the queue is empty
        printf("Queue is empty!\n");
        return -1; // Return an error value
    }
    int data = q->front->data;
    struct Node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
    { // If the queue becomes empty
        q->rear = NULL;
    }

    free(temp); // Free the memory of the dequeued node
    return data;
}

// Function to display the queue
void displayQueue(struct Queue *q)
{
    struct Node *current = q->front;
    if (current == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    struct Queue q;
    initializeQueue(&q);

    // Enqueue elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    // Display queue
    displayQueue(&q);

    // Dequeue elements
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    // Display queue after dequeuing
    displayQueue(&q);

    end = clock(); // End timer

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}
