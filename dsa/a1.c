/*1. Implement STACK to perform the below operations using arrays.
a. push
b. pop
c. display*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure definition
struct Stack {
    int items[MAX];
    int top;
};

int main() {
    struct Stack s;
    s.top = -1;
    int choice, value;

    while (1) {
        printf("\n\nStack Operations:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1)
                    printf("Popped value: %d", value);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }

    return 0;
}

// Function to push an element onto the stack
void push(struct Stack *s, int item) {
    if (s->top == MAX - 1) {
        printf("Stack overflow! Cannot push %d\n", item);
    } else {
        s->top++;
        s->items[s->top] = item;
        printf("%d pushed onto the stack\n", item);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    } else {
        int item = s->items[s->top];
        s->top--;
        return item;
    }
}

// Function to display the elements of the stack
void display(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

