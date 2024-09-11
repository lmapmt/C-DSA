#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a circular singly linked list
typedef struct node {
    int data;
    struct node* next;  // Pointer to the next node
} node;

// Function to add a node at the end of the circular linked list
void addNode(int data, struct node** head) {
    // Allocate memory for a new node
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    
    // Assign data to the new node
    newNode->data = data;
    newNode->next = NULL;  // Temporarily set next to NULL
    
    // If the list is empty, make the new node point to itself and set it as the head
    if (*head == NULL) {
        newNode->next = newNode;  // Points to itself
        *head = newNode;
    } else {
        // Otherwise, find the last node and update its next to point to the new node
        struct node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;  // Point new node's next to the head to complete the circle
    }
}

// Function to print all the elements in the circular linked list
void printList(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Stop when we loop back to the head

    printf("(back to head)\n");
}

int main() {
    // Initialize an empty circular linked list
    struct node* head = NULL;
    
    // Add nodes to the list
    addNode(3, &head);
    addNode(5, &head);
    addNode(10, &head);
    
    // Print the circular linked list
    printList(head);  // Should print: 3 -> 5 -> 10 -> (back to head)
    
    return 0;
}
