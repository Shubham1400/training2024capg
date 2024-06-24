// 7. Implement Circular Double Linked List

#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n\nCircular Doubly Linked List Operations:");
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Delete by value");
        printf("\n4. Display list");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }

    return 0;
}

// Function to insert a new node at the beginning of the circular doubly linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head_ref = new_node;
    } else {
        struct Node* last = (*head_ref)->prev;
        new_node->next = *head_ref;
        new_node->prev = last;
        last->next = new_node;
        (*head_ref)->prev = new_node;
        *head_ref = new_node;
    }
    printf("%d inserted at beginning\n", new_data);
}

// Function to insert a new node at the end of the circular doubly linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head_ref = new_node;
    } else {
        struct Node* last = (*head_ref)->prev;
        new_node->next = *head_ref;
        new_node->prev = last;
        last->next = new_node;
        (*head_ref)->prev = new_node;
    }
    printf("%d inserted at end\n", new_data);
}

// Function to delete the first occurrence of a given key in the circular doubly linked list
void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) {
        printf("%d not found in the list\n", key);
        return;
    }

    struct Node *temp = *head_ref;

    while (temp->data != key) {
        temp = temp->next;
        if (temp == *head_ref) {
            printf("%d not found in the list\n", key);
            return;
        }
    }

    if (temp->next == temp && temp->prev == temp) {
        *head_ref = NULL;
        free(temp);
        printf("%d deleted\n", key);
        return;
    }

    if (temp == *head_ref) {
        struct Node* last = (*head_ref)->prev;
        *head_ref = temp->next;
        last->next = *head_ref;
        (*head_ref)->prev = last;
        free(temp);
    } else if (temp->next == *head_ref) {
        struct Node* prev = temp->prev;
        prev->next = *head_ref;
        (*head_ref)->prev = prev;
        free(temp);
    } else {
        struct Node* prev = temp->prev;
        struct Node* next = temp->next;
        prev->next = next;
        next->prev = prev;
        free(temp);
    }
    printf("%d deleted\n", key);
}

// Function to display the contents of the circular doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular doubly linked list: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("...\n");
}

