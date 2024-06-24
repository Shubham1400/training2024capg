// Circular single linked list

#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n\nCircular Singly Linked List Operations:");
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

// Function to insert a new node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = new_node;
    } else {
        while (last->next != *head_ref) {
            last = last->next;
        }
        new_node->next = *head_ref;
        *head_ref = new_node;
        last->next = new_node;
    }
    printf("%d inserted at beginning\n", new_data);
}

// Function to insert a new node at the end of the circular linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = new_node;
    } else {
        while (last->next != *head_ref) {
            last = last->next;
        }
        last->next = new_node;
    }
    printf("%d inserted at end\n", new_data);
}

// Function to delete the first occurrence of a given key in the circular linked list
void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) {
        printf("%d not found in the list\n", key);
        return;
    }

    struct Node *temp = *head_ref, *prev;
    while (temp->data != key) {
        if (temp->next == *head_ref) {
            printf("%d not found in the list\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == *head_ref && temp == *head_ref) {
        *head_ref = NULL;
        free(temp);
        printf("%d deleted\n", key);
        return;
    }

    if (temp == *head_ref) {
        prev = *head_ref;
        while (prev->next != *head_ref) {
            prev = prev->next;
        }
        *head_ref = temp->next;
        prev->next = *head_ref;
        free(temp);
    } else if (temp->next == *head_ref) {
        prev->next = *head_ref;
        free(temp);
    } else {
        prev->next = temp->next;
        free(temp);
    }
    printf("%d deleted\n", key);
}

// Function to display the contents of the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular linked list: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("...\n");
}

