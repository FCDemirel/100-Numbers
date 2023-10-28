#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For random number generator

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Declare pointers to the head and tail of the linked list
struct Node* head = NULL;
struct Node* tail = NULL;

// Function to add a number to the beginning of the list
void addNumber(int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Set new nodes data field to the given number
    newNode->data = data;
    // Make the new node point to the current head of the list
    newNode->next = head;
    // Update the head to point to the new node
    head = newNode;
}

// Function to sort the list from largest to smallest
void sortList() {
    struct Node *current, *index;
    int temp;

    // Check if the list is empty, if there is nothing, return.
    if (head == NULL) {
        return;
    }

    // Bubble Short Algorithm for sorting randomly generated numbers from largest to smallest
    for (current = head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data < index->data) {
                // Swap the data of the current node and the index node if necessary
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

int main() {
    // Random number generator
    srand(time(NULL));
    int a=1;

    // Generate 100 random numbers
    for (int i = 0; i < 100; i++) {
        // To make sure that the numbers generated are in the range 0 and 99.
        int num = rand() % 100;
        // Add the generated number to the list
        addNumber(num);
    }

    sortList();

    // Pointer to the current node
    struct Node* current = head;

    // Print a message indicating that we're displaying the sorted list.
    printf("100 randomly generated numbers sorted from largest to smallest:\n\n");

    // Printing the random generated numbers
    while (current != NULL) {
        // Print the data of the current node.
        printf("%d||%d -- ", a, current->data);
        a ++;
        // Move to the next node in the list.
        current = current->next;
    }

    // Free the allocated memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
