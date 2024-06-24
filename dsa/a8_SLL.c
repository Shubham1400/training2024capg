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

// Function to insert at the beginning
void insert_at_beginning(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert at the end
void insert_at_end(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to insert at a given position
void insert_at_position(struct Node **head, int data, int position) {
    if (position == 1) {
        insert_at_beginning(head, data);
        return;
    }
    struct Node *new_node = create_node(data);
    struct Node *temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to insert before a given position
void insert_before_position(struct Node **head, int data, int position) {
    insert_at_position(head, data, position - 1);
}

// Function to insert after a given position
void insert_after_position(struct Node **head, int data, int position) {
    insert_at_position(head, data, position + 1);
}

// Function to insert before a given number
void insert_before_number(struct Node **head, int data, int number) {
    if (*head == NULL) return;
    if ((*head)->data == number) {
        insert_at_beginning(head, data);
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL && temp->next->data != number) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Number not found\n");
        return;
    }
    struct Node *new_node = create_node(data);
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to insert after a given number
void insert_after_number(struct Node **head, int data, int number) {
    struct Node *temp = *head;
    while (temp != NULL && temp->data != number) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Number not found\n");
        return;
    }
    struct Node *new_node = create_node(data);
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to insert at the middle
void insert_at_middle(struct Node **head, int data) {
    if (*head == NULL) {
        insert_at_beginning(head, data);
        return;
    }
    struct Node *slow = *head, *fast = *head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node *new_node = create_node(data);
    new_node->next = slow->next;
    slow->next = new_node;
}

// Function to insert at penultimate node
void insert_at_penultimate(struct Node **head, int data) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("List too short\n");
        return;
    }
    struct Node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    struct Node *new_node = create_node(data);
    new_node->next = temp->next;
    temp->next = new_node;
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
    insert_at_end(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);
    print_list(head);

    insert_at_beginning(&head, 0);
    print_list(head);

    insert_at_position(&head, 5, 3);
    print_list(head);

    insert_before_position(&head, 6, 3);
    print_list(head);

    insert_after_position(&head, 7, 3);
    print_list(head);

    insert_before_number(&head, 8, 3);
    print_list(head);

    insert_after_number(&head, 9, 3);
    print_list(head);

    insert_at_middle(&head, 10);
    print_list(head);

    insert_at_penultimate(&head, 11);
    print_list(head);

    return 0;
}

