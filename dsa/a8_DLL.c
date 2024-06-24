#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
};

// Function to create a new node
struct DNode* create_dnode(int data) {
    struct DNode *new_node = (struct DNode*)malloc(sizeof(struct DNode));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Function to insert at the beginning
void insert_at_beginning_dll(struct DNode **head, int data) {
    struct DNode *new_node = create_dnode(data);
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    new_node->next = *head;
    *head = new_node;
}

// Function to insert at the end
void insert_at_end_dll(struct DNode **head, int data) {
    struct DNode *new_node = create_dnode(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct DNode *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// Function to insert at a given position
void insert_at_position_dll(struct DNode **head, int data, int position) {
    if (position == 1) {
        insert_at_beginning_dll(head, data);
        return;
    }
    struct DNode *new_node = create_dnode(data);
    struct DNode *temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    new_node->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// Function to insert before a given position
void insert_before_position_dll(struct DNode **head, int data, int position) {
    insert_at_position_dll(head, data, position - 1);
}

// Function to insert after a given position
void insert_after_position_dll(struct DNode **head, int data, int position) {
    insert_at_position_dll(head, data, position + 1);
}

// Function to insert before a given number
void insert_before_number_dll(struct DNode **head, int data, int number) {
    if (*head == NULL) return;
    if ((*head)->data == number) {
        insert_at_beginning_dll(head, data);
        return;
    }
    struct DNode *temp = *head;
    while (temp->next != NULL && temp->next->data != number) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Number not found\n");
        return;
    }
    struct DNode *new_node = create_dnode(data);
    new_node->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// Function to insert after a given number
void insert_after_number_dll(struct DNode **head, int data, int number) {
    struct DNode *temp = *head;
    while (temp != NULL && temp->data != number) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Number not found\n");
        return;
    }
    struct DNode *new_node = create_dnode(data);
    new_node->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// Function to insert at the middle
void insert_at_middle_dll(struct DNode **head, int data) {
    if (*head == NULL) {
        insert_at_beginning_dll(head, data);
        return;
    }
    struct DNode *slow = *head, *fast = *head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct DNode *new_node = create_dnode(data);
    new_node->next = slow->next;
    if (slow->next != NULL) {
        slow->next->prev = new_node;
    }
    slow->next = new_node;
    new_node->prev = slow;
}

// Function to insert at penultimate node
void insert_at_penultimate_dll(struct DNode **head, int data) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("List too short\n");
        return;
    }
    struct DNode *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    struct DNode *new_node = create_dnode(data);
    new_node->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// Function to print the list
void print_list_dll(struct DNode *head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct DNode *head = NULL;
    insert_at_end_dll(&head, 1);
    insert_at_end_dll(&head, 2);
    insert_at_end_dll(&head, 3);
    insert_at_end_dll(&head, 4);
    print_list_dll(head);

    insert_at_beginning_dll(&head, 0);
    print_list_dll(head);

    insert_at_position_dll(&head, 5, 3);
    print_list_dll(head);

    insert_before_position_dll(&head, 6, 3);
    print_list_dll(head);

    insert_after_position_dll(&head, 7, 3);
    print_list_dll(head);

    insert_before_number_dll(&head, 8, 3);
    print_list_dll(head);

    insert_after_number_dll(&head, 9, 3);
    print_list_dll(head);

    insert_at_middle_dll(&head, 10);
    print_list_dll(head);

    insert_at_penultimate_dll(&head, 11);
    print_list_dll(head);

    return 0;
}

