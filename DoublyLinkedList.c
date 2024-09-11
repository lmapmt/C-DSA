#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a doubly linked list
typedef struct node {
    int data;
    struct node* next;  // Pointer to the next node
    struct node* prev;  // Pointer to the previous node
} node;

// Function to add a node at the beginning of the doubly linked list
void addNode(int data, struct node** head) {
    // Allocate memory for a new node
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    
    // Assign data to the new node
    newNode->data = data;
    
    // Set the new node's next to the current head
    newNode->next = *head;
    newNode->prev = NULL;  // Since this is the first node, previous is NULL
    
    // If the list is not empty, set the previous head's prev to the new node
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    
    // Update the head to point to the new node
    *head = newNode;
}

// Function to print the doubly linked list in the forward direction
void printListForward(struct node* head) {
    struct node* current = head;
    printf("List (Forward): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to print the doubly linked list in the reverse direction
void printListBackward(struct node* head) {
    // Go to the last node
    struct node* current = head;
    if (current == NULL) return; // If the list is empty, return
    while (current->next != NULL) {
        current = current->next;
    }

    // Traverse the list backward
    printf("List (Backward): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

int main() {
    // Initialize the head of the list
    struct node* head = NULL;
    
    // Add a few nodes to the doubly linked list
    addNode(3, &head);
    addNode(5, &head);
    addNode(10, &head);
    
    // Print the list forward and backward
    printListForward(head);    // Should print: 10 -> 5 -> 3 -> NULL
    printListBackward(head);   // Should print: 3 -> 5 -> 10 -> NULL
    
    return 0;
}
