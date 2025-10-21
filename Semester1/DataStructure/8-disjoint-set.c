#include <stdio.h>
#define MAX 100

int parent[MAX];

void makeSet(int n) {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if(parent[x] == x) {
        return x;
    } else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void unionSets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if(rootA != rootB) {
        parent[rootB] = rootA;
    }
}

void display(int n) {
    printf("Element : Parent\n");
    for(int i = 1; i <= n; i++) {
        printf("%d : %d\n", i, find(i));
    }
}

int main() {
    int n, u, v, choice;
    scanf("%d", &n);

    makeSet(n);

    while(1) {
        scanf("%d", &choice);

        if(choice == 1) {
            scanf("%d %d", &u, &v);
            unionSets(u, v);
        }
        else if(choice == 2) {
            scanf("%d", &u);
            printf("%d\n", find(u));
        }
        else if(choice == 3) {
            display(n);
        }
        else if(choice == 4) {
            break;
        }
    }

    return 0;
}
