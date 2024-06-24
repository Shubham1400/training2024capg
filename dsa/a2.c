/*2. Implement QUEUE to perform the below operations using arrays.
a. enqueue
b. dequeue
c. display*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure definition
struct Queue {
    int items[MAX];
    int front, rear;
};

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    int choice, value;

    while (1) {
        printf("\n\nQueue Operations:");
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

// Function to enqueue an element into the queue
void enqueue(struct Queue *q, int item) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow! Cannot enqueue %d\n", item);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = item;
        printf("%d enqueued into the queue\n", item);
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue underflow! Cannot dequeue\n");
        return -1;
    } else {
        int item = q->items[q->front];
        q->front++;
        return item;
    }
}

// Function to display the elements of the queue
void display(struct Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

