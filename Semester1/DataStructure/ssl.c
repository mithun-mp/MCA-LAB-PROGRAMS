#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;   
};
struct Node* top=NULL;

void push(int elem)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("stack overflow\n");
        return;
    }
    newNode->data = elem;
    newNode->next =top;
    top = newNode;
    printf("pushed to stack\n");

}
void pop()
{
    if(top==NULL)
    {
        printf("stack underflow\n");
    }
    struct Node* temp =top;
    printf("%d popped from stack\n",temp->data);
    top =top->next;
    free(temp);

    
}
void display()
{
    if(top==NULL)
    {
        printf("stack is empty");
        return;

    }
    struct Node* temp = top;
    printf("stack elements are\n");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
}

void search(int key)
{
    if(top==NULL)
    {
        printf("stack is empty\n");
    }
    struct Node* temp = top;
    int pos=1;
    int found =0;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            printf("%d--element found at %d position\n",key,pos);
            found++;
        }
        temp = temp->next;
        pos++;
        
    }
    if(found!=0)
    {
        printf("element not found\n");
    }
}


int main()
{
    int choice,elem,key;
    do
    {
        printf("\n<----please enter your choice--->\n");
        printf("\n1.push to stack");
        printf("\n2.pop from stack");
        printf("\n3.display stack");
        printf("\n4.search in stack");
        printf("\n5.exit---------->");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("enter a value to push\n");
            scanf("%d",&elem);
            push(elem);
        break;
        case 2:
            pop();
        break;
        case 3:
            display();
        break;
        case 4:
            printf("enter element to search");
            while(getchar()!='\n');
            scanf("%d",&key);
            search(key);
        break;
        case 5:
            printf(" Exiting from stack operations.............................\n");
        break;
        default:
            printf("Invalid choice,......Try again........\n");
    }
}
    while(choice!=5);
    return 0;
}

