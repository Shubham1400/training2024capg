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

// Function to delete at the beginning
void delete_at_beginning_dll(struct DNode **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct DNode *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete at the end
void delete_at_end_dll(struct DNode **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct DNode *temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Function to delete at a given position
void delete_at_position_dll(struct DNode **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct DNode *temp = *head;
    if (position == 1) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

// Function to delete before a given position
void delete_before_position_dll(struct DNode **head, int position) {
    if (position <= 1) {
        printf("No node exists before position %d\n", position);
        return;
    }
    delete_at_position_dll(head, position - 1);
}

// Function to delete after a given position
void delete_after_position_dll(struct DNode **head, int position) {
    delete_at_position_dll(head, position + 1);
}

// Function to delete a given number
void delete_number_dll(struct DNode **head, int number) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct DNode *temp = *head;
    while (temp != NULL && temp->data != number) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Number not found\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    free(temp);
}

// Function to delete at the middle
void delete_at_middle_dll(struct DNode **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct DNode *slow = *head, *fast = *head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (slow->prev != NULL) {
        slow->prev->next = slow->next;
    } else {
        *head = slow->next;
    }
    if (slow->next != NULL) {
        slow->next->prev = slow->prev;
    }
    free(slow);
}

// Function to delete at penultimate node
void delete_at_penultimate_dll(struct DNode **head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("List too short\n");
        return;
    }
    struct DNode *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    struct DNode *penultimate = temp;
    struct DNode *last = temp->next;
    penultimate->next = NULL;
    free(last);
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
    head = create_dnode(1);
    head->next = create_dnode(2);
    head->next->prev = head;
    head->next->next = create_dnode(3);
    head->next->next->prev = head->next;
    head->next->next->next = create_dnode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = create_dnode(5);
    head->next->next->next->next->prev = head->next->next->next;

    print_list_dll(head);

    delete_at_beginning_dll(&head);
    print_list_dll(head);

    delete_at_end_dll(&head);
    print_list_dll(head);

    delete_at_position_dll(&head, 2);
    print_list_dll(head);

    delete_before_position_dll(&head, 2);
    print_list_dll(head);

    delete_after_position_dll(&head, 1);
    print_list_dll(head);

    delete_number_dll(&head, 3);
    print_list_dll(head);

    delete_at_middle_dll(&head);
    print_list_dll(head);

    head->next = create_dnode(6);  // Adding nodes to demonstrate penultimate deletion
    head->next->prev = head;
    head->next->next = create_dnode(7);
    head->next->next->prev = head->next;

    delete_at_penultimate_dll(&head);
    print_list_dll(head);

    return 0;
}

