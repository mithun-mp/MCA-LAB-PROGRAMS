#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

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

void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at the end\n", value);
}

void insertAtPosition(int value, int position) {
    if (position <= 1) {
        insertAtBeginning(value);
        return;
    }
    struct Node* temp = head;
    int i = 1;
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        insertAtEnd(value);
    } else if (temp->next == NULL) {
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

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty, cannot delete from end\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    int val = temp->data;
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    printf("%d deleted from end\n", val);
}

void deleteByKey(int key) {
    if (head == NULL) {
        printf("List is empty, cannot delete key %d\n", key);
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key %d not found in list\n", key);
        return;
    }
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

void traverseBackward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
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
