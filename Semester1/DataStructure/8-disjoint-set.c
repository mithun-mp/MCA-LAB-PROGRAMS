#include <stdio.h>
#define MAX 100

int parent[MAX];

void makeSet(int n) {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    printf("Created %d disjoint sets.\n", n);
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
    if(rootA != rootB) {
        parent[rootB] = rootA;
        printf("Union of %d and %d done.\n", a, b);
    } else {
        printf("%d and %d are already in the same set.\n", a, b);
    }
}

int main() {
    int n, u, v, choice;

    while(1) {
        printf("\n--- Disjoint Set Operations ---\n");
        printf("1. Make Set\n2. Union\n3. Find\n4. Exit\nChoose operation: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter number of elements: ");
            scanf("%d", &n);
            makeSet(n);
        }
        else if(choice == 2) {
            printf("Enter two elements to union: ");
            scanf("%d %d", &u, &v);
            unionSets(u, v);
        }
        else if(choice == 3) {
            printf("Enter element to find its set: ");
            scanf("%d", &u);
            printf("Representative of %d is %d\n", u, find(u));
        }
        else if(choice == 4) {
            printf("Exiting program.\n");
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
