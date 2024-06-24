// 3. Implement circular queue using arrays.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Circular Queue structure definition
struct CircularQueue {
    int items[MAX];
    int front, rear;
};

// Function prototypes
void enqueue(struct CircularQueue *q, int item);
int dequeue(struct CircularQueue *q);
void display(struct CircularQueue *q);

int main() {
    struct CircularQueue q;
    q.front = -1;
    q.rear = -1;
    int choice, value;

    while (1) {
        printf("\n\nCircular Queue Operations:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1)
                    printf("Dequeued value: %d", value);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }

    return 0;
}

// Function to enqueue an element into the circular queue
void enqueue(struct CircularQueue *q, int item) {
    if ((q->front == 0 && q->rear == MAX - 1) || (q->rear == (q->front - 1) % (MAX - 1))) {
        printf("Queue overflow! Cannot enqueue %d\n", item);
    } else {
        if (q->front == -1) {
            q->front = q->rear = 0;
        } else if (q->rear == MAX - 1 && q->front != 0) {
            q->rear = 0;
        } else {
            q->rear++;
        }
        q->items[q->rear] = item;
        printf("%d enqueued into the queue\n", item);
    }
}

// Function to dequeue an element from the circular queue
int dequeue(struct CircularQueue *q) {
    if (q->front == -1) {
        printf("Queue underflow! Cannot dequeue\n");
        return -1;
    }

    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else if (q->front == MAX - 1) {
        q->front = 0;
    } else {
        q->front++;
    }
    return item;
}

// Function to display the elements of the circular queue
void display(struct CircularQueue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    if (q->rear >= q->front) {
        for (int i = q->front; i <= q->rear; i++)
            printf("%d ", q->items[i]);
    } else {
        for (int i = q->front; i < MAX; i++)
            printf("%d ", q->items[i]);
        for (int i = 0; i <= q->rear; i++)
            printf("%d ", q->items[i]);
    }
    printf("\n");
}

