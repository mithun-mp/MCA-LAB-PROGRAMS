#include <stdio.h>
#include <stdlib.h>

// Define Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Head pointer of the list
struct Node* head = NULL;

// Function to create a new node with given data
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);  // exit since cannot proceed
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning of the list
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at the beginning\n", value);
}

// Insert at the end of the list
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        // Move to last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at the end\n", value);
}

// Insert at a specific position (1-based position)
void insertAtPosition(int value, int position) {
    if (position <= 1) {
        insertAtBeginning(value);
        return;
    }
    struct Node* temp = head;
    int i = 1;
    // Move to node at position-1 or until end
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        // position is beyond length, insert at end
        insertAtEnd(value);
    } else if (temp->next == NULL) {
        // inserting at end
        insertAtEnd(value);
    } else {
        struct Node* newNode = createNode(value);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        printf("%d inserted at position %d\n", value, position);
    }
}

// Delete from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty, cannot delete from beginning\n");
        return;
    }
    struct Node* temp = head;
    int val = temp->data;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("%d deleted from beginning\n", val);
}

// Delete from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty, cannot delete from end\n");
        return;
    }
    struct Node* temp = head;
    // Move to last
    while (temp->next != NULL) {
        temp = temp->next;
    }
    int val = temp->data;
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        // it was the only node
        head = NULL;
    }
    free(temp);
    printf("%d deleted from end\n", val);
}

// Delete a node by key (first occurrence)
void deleteByKey(int key) {
    if (head == NULL) {
        printf("List is empty, cannot delete key %d\n", key);
        return;
    }
    struct Node* temp = head;
    // search for the node with given key
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key %d not found in list\n", key);
        return;
    }
    // If node to delete is head
    if (temp->prev == NULL) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    printf("Node with key %d deleted\n", key);
    free(temp);
}

// Traverse the list forward
void traverseForward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Forward traversal: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Traverse the list backward
void traverseBackward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    // Move to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Backward traversal: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Search for an element and report its first position
void search(int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found\n", key);
}

// Main menu
int main() {
    int choice, value, position, key;

    do {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete by Key\n");
        printf("7. Traverse Forward\n");
        printf("8. Traverse Backward\n");
        printf("9. Search Element\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter position and value to insert: ");
                scanf("%d %d", &position, &value);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteByKey(key);
                break;
            case 7:
                traverseForward();
                break;
            case 8:
                traverseBackward();
                break;
            case 9:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 10:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 10);

    return 0;
}
