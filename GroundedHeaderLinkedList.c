#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct node {
    int data;
    struct node* next;  // Pointer to the next node
} node;

// Function to create a grounded header linked list (header node has no data)
node* createList() {
    node* header = (node*) malloc(sizeof(node));  // Allocate memory for header node
    header->next = NULL;  // Header node's next initially points to NULL
    return header;
}

// Function to add a node at the end of the grounded header linked list
void addNode(int data, node* header) {
    node* newNode = (node*) malloc(sizeof(node));  // Allocate memory for new node
    newNode->data = data;
    newNode->next = NULL;  // New node's next will be NULL since it's the last node

    // Traverse to the last node in the list starting from the header node
    node* temp = header;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Add the new node at the end
    temp->next = newNode;
}

// Function to print all elements in the grounded header linked list
void printList(node* header) {
    node* temp = header->next;  // Start from the first real node, skipping the header
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Grounded Header Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");  // End of the list
}

int main() {
    // Create a grounded header linked list (header node present)
    node* header = createList();

    // Add nodes to the list
    addNode(5, header);
    addNode(10, header);
    addNode(15, header);

    // Print the list
    printList(header);  // Should print: 5 -> 10 -> 15 -> NULL

    return 0;
}
