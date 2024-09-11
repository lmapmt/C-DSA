#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;  // Pointer to the next node
} node;

// Function to add a node at the beginning of the linked list
void addNode(int data, struct node** head) {
    // Allocate memory for a new node
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    
    // Assign the data to the new node
    newNode->data = data;
    
    // Link the new node to the current head of the list
    newNode->next = *head;
    
    // Update the head to point to the new node
    *head = newNode;
}

// Function to print all the elements in the linked list
void printList(struct node* head) {
    struct node* current = head;
    
    // Traverse the list and print each node's data
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");  // End of the list
}

int main() {
    // Create an empty list (head is NULL)
    struct node* head = NULL;
    
    // Add a few nodes to the list
    addNode(3, &head);  // Add a node with data = 3
    addNode(5, &head);  // Add a node with data = 5
    addNode(10, &head); // Add a node with data = 10
    
    // Print the linked list
    printf("Linked list: ");
    printList(head);  // Should print: 10 -> 5 -> 3 -> NULL
    
    return 0;
}
