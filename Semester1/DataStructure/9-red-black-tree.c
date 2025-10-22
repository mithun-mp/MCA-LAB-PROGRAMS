#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

typedef struct Node {
    int data;
    enum Color color;
    struct Node *left, *right, *parent;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

Node* leftRotate(Node* root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
    return root;
}

Node* rightRotate(Node* root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
    return root;
}

Node* fixViolation(Node* root, Node* z) {
    while (z->parent != NULL && z->parent->color == RED) {
        Node* grandParent = z->parent->parent;
        if (z->parent == grandParent->left) {
            Node* uncle = grandParent->right;
            if (uncle != NULL && uncle->color == RED) {
                grandParent->color = RED;
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z = grandParent;
            } 
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    root = leftRotate(root, z);
                }
                z->parent->color = BLACK;
                grandParent->color = RED;
                root = rightRotate(root, grandParent);
            }
        } else {
            Node* uncle = grandParent->left;
            if (uncle != NULL && uncle->color == RED) {
                grandParent->color = RED;
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z = grandParent;
            }
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    root = rightRotate(root, z);
                }
                z->parent->color = BLACK;
                grandParent->color = RED;
                root = leftRotate(root, grandParent);
            }
        }
    }
    root->color = BLACK;
    return root;
}

Node* bstInsert(Node* root, Node* pt) {
    if (root == NULL)
        return pt;
    if (pt->data < root->data) {
        root->left = bstInsert(root->left, pt);
        root->left->parent = root;
    } else if (pt->data > root->data) {
        root->right = bstInsert(root->right, pt);
        root->right->parent = root;
    }
    return root;
}

Node* insert(Node* root, int data) {
    Node* pt = createNode(data);
    root = bstInsert(root, pt);
    root = fixViolation(root, pt);
    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d(%s) ", root->data, root->color == RED ? "R" : "B");
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d(%s) ", root->data, root->color == RED ? "R" : "B");
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d(%s) ", root->data, root->color == RED ? "R" : "B");
}

int main() {
    Node* root = NULL;
    int choice, val;
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("%d found in tree.\n", val);
                else
                    printf("%d not found.\n", val);
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
