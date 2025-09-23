#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct Node {
    int data;
    struct Node* prev;  // Points to the previous node
    struct Node* next;  // Points to the next node
};

// Top pointer for stack
struct Node* top = NULL;

// Push operation: Insert element at top
void push(int elem) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = elem;
    newNode->prev = NULL;
    newNode->next = top;  // New node points to old top

    if (top != NULL) {
        top->prev = newNode; // Old top's prev points to new node
    }

    top = newNode;  // Update top to new node
    printf("%d pushed to stack\n", elem);
}

// Pop operation: Remove element from top
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped from stack\n", temp->data);
    top = top->next;  // Move top down

    if (top != NULL) {
        top->prev = NULL;  // Remove link to old top
    }

    free(temp);  // Free memory of removed node
}

// Display operation: Print stack from top to bottom
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements are: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search operation: Find an element in stack
void search(int key) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    int pos = 1, found = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (!found) {
        printf("%d not found in stack\n", key);
    }
}

int main() {
    int choice, elem, key;
    do {
        printf("\n<---- Stack using Doubly Linked List ---->\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Search\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &elem);
                push(elem);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again!\n");
        }
    } while (choice != 5);

    return 0;
}
