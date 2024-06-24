#include <stdio.h>
#include <stdlib.h>

// Node structure for Singly Linked List
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to delete at the beginning
void delete_at_beginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete at the end
void delete_at_end(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    struct Node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

// Function to delete at a given position
void delete_at_position(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }
    struct Node *prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to delete before a given position
void delete_before_position(struct Node **head, int position) {
    if (position <= 1) {
        printf("No node exists before position %d\n", position);
        return;
    }
    delete_at_position(head, position - 1);
}

// Function to delete after a given position
void delete_after_position(struct Node **head, int position) {
    delete_at_position(head, position + 1);
}

// Function to delete a given number
void delete_number(struct Node **head, int number) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    if (temp->data == number) {
        *head = temp->next;
        free(temp);
        return;
    }
    struct Node *prev = NULL;
    while (temp != NULL && temp->data != number) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Number not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to delete at the middle
void delete_at_middle(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *slow = *head, *fast = *head, *prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    if (prev != NULL) {
        prev->next = slow->next;
        free(slow);
    }
}

// Function to delete at penultimate node
void delete_at_penultimate(struct Node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("List too short\n");
        return;
    }
    struct Node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    struct Node *penultimate = temp;
    struct Node *last = temp->next;
    penultimate->next = NULL;
    free(last);
}

// Function to print the list
void print_list(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);

    print_list(head);

    delete_at_beginning(&head);
    print_list(head);

    delete_at_end(&head);
    print_list(head);

    delete_at_position(&head, 2);
    print_list(head);

    delete_before_position(&head, 2);
    print_list(head);

    delete_after_position(&head, 1);
    print_list(head);

    delete_number(&head, 3);
    print_list(head);

    delete_at_middle(&head);
    print_list(head);

    head->next = create_node(6);  // Adding nodes to demonstrate penultimate deletion
    head->next->next = create_node(7);

    delete_at_penultimate(&head);
    print_list(head);

    return 0;
}

