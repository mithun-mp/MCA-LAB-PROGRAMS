#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;
void enqueue(int value)
{
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front)
    {
        printf("Queue is Full! Cannot insert %d\n", value);
    }
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue is Empty! Nothing to delete.\n");
    }
    else
    {
        int deleted = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
        printf("%d deleted from the queue.\n", deleted);
    }
}
void search(int key)
{
    if (front == -1)
    {
        printf("Queue is Empty! Cannot search.\n");
        return;
    }
    int i = front;
    int found = 0;
    while (1)
    {
        if (queue[i] == key)
        {
            printf("Element %d found in the queue.\n", key);
            found = 1;
            break;
        }
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    if (!found)
        printf("Element %d not found in the queue.\n", key);
}
void display()
{
    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Add (Enqueue)\n2. Delete (Dequeue)\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}