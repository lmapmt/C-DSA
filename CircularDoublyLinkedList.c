#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a circular doubly linked list
typedef struct node {
    int data;
    struct node* next;  // Pointer to the next node
    struct node* prev;  // Pointer to the previous node
} node;

// Function to add a node at the end of the circular doubly linked list
void addNode(int data, struct node** head) {
    // Allocate memory for a new node
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;

    // If the list is empty, initialize the new node as the head and make it circular
    if (*head == NULL) {
        newNode->next = newNode;  // Points to itself
        newNode->prev = newNode;  // Points to itself
        *head = newNode;
    } else {
        // Find the last node (just before the head)
        struct node* last = (*head)->prev;

        // Insert the new node at the end and update the circular connections
        last->next = newNode;  // Last node's next points to the new node
        newNode->prev = last;  // New node's prev points to the last node
        newNode->next = *head; // New node's next points to the head
        (*head)->prev = newNode; // Head's prev points to the new node
    }
}

// Function to print the list in the forward direction
void printListForward(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("Circular Doubly Linked List (Forward): ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Function to print the list in the backward direction
void printListBackward(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* last = head->prev;  // Start from the last node
    printf("Circular Doubly Linked List (Backward): ");
    struct node* temp = last;
    do {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("(back to tail)\n");
}

int main() {
    // Initialize an empty circular doubly linked list
    struct node* head = NULL;

    // Add nodes to the list
    addNode(3, &head);
    addNode(5, &head);
    addNode(10, &head);

    // Print the list in both directions
    printListForward(head);    // Should print: 3 -> 5 -> 10 -> (back to head)
    printListBackward(head);   // Should print: 10 -> 5 -> 3 -> (back to tail)

    return 0;
}
