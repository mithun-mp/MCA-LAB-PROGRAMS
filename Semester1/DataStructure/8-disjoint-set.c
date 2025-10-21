#include <stdio.h>
#define MAX 100

int parent[MAX];

void create(int n) {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if(parent[x] == x)
        return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if(rootA != rootB)
        parent[rootB] = rootA;
}

int main() {
    int n, u, v, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    create(n);

    while(1) {
        printf("\n1. Union\n2. Find\n3. Exit\nChoose operation: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter two elements to union: ");
            scanf("%d %d", &u, &v);
            unionSets(u, v);
            printf("Union done.\n");
        }
        else if(choice == 2) {
            printf("Enter element to find its set: ");
            scanf("%d", &u);
            printf("Representative of %d is %d\n", u, find(u));
        }
        else if(choice == 3) {
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
