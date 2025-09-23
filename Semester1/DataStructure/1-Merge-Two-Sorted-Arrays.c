#include <stdio.h>
void main()
{
    int i, j, k, n, m;
    printf("enter the limit of first array");
    scanf("%d", &n);
    int arr1[n];
    printf("enter %d elements in sorted order", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("enter the limit of second array");
    scanf("%d", &m);
    int arr2[m];
    printf("enter %d elements in sorted order", m);
    for (j = 0; j < m; j++)
    {
        scanf("%d", &arr2[j]);
    }
    int arr3[n + m];
    k = 0, i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < m)
    {
        arr3[k++] = arr2[j++];
    }
    printf("merged sorted array is: ");
    for (k = 0; k < m + n; k++)
    {
        printf("%d ,", arr3[k]);
    }
}