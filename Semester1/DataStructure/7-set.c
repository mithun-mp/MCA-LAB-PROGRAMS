#include <stdio.h>
#define MAX 50

int main()
{
    int U[MAX], A[MAX], B[MAX];
    int bitA[MAX] = {0}, bitB[MAX] = {0};  
    int nU, nA, nB, i, j;

    printf("Enter number of elements in Universal Set: ");
    scanf("%d", &nU);

    printf("Enter elements of Universal Set:\n");
    for (i = 0; i < nU; i++)
    {
        scanf("%d", &U[i]);
    }

    printf("Enter number of elements in Set A: ");
    scanf("%d", &nA);

    printf("Enter elements of Set A:\n");
    for (i = 0; i < nA; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter number of elements in Set B: ");
    scanf("%d", &nB);

    printf("Enter elements of Set B:\n");
    for (i = 0; i < nB; i++)
    {
        scanf("%d", &B[i]);
    }
    for (i = 0; i < nU; i++)
    {
        bitA[i] = 0;
        bitB[i] = 0;

        for (j = 0; j < nA; j++)
        {
            if (U[i] == A[j])
            {
                bitA[i] = 1;
                break;  
            }
        }

        for (j = 0; j < nB; j++)
        {
            if (U[i] == B[j])
            {
                bitB[i] = 1;
                break;
            }
        }
    }

    int unionSet[MAX], intersectionSet[MAX], differenceSet[MAX];

    for (i = 0; i < nU; i++)
    {
        unionSet[i] = bitA[i] | bitB[i];
        intersectionSet[i] = bitA[i] & bitB[i];
        differenceSet[i] = bitA[i] & (!bitB[i]); 
    }

    printf("\nUnion (A ∪ B) Bit String: ");
    for (i = 0; i < nU; i++)
        printf("%d", unionSet[i]);

    printf("\nIntersection (A ∩ B) Bit String: ");
    for (i = 0; i < nU; i++)
        printf("%d", intersectionSet[i]);

    printf("\nDifference (A - B) Bit String: ");
    for (i = 0; i < nU; i++)
        printf("%d", differenceSet[i]);

    printf("\n\nUnion (A ∪ B) = { ");
    for (i = 0; i < nU; i++)
    {
        if (unionSet[i])
            printf("%d ", U[i]);
    }
    printf("}");

    printf("\nIntersection (A ∩ B) = { ");
    for (i = 0; i < nU; i++)
    {
        if (intersectionSet[i])
            printf("%d ", U[i]);
    }
    printf("}");

    printf("\nDifference (A - B) = { ");
    for (i = 0; i < nU; i++)
    {
        if (differenceSet[i])
            printf("%d ", U[i]);
    }
    printf("}\n");

    return 0;
}
