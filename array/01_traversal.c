// 1. Write a program to read and display n numbers using an array.
#include <stdio.h>

int main()
{
    int arr[100], noOfElements;

    printf("Enter the number of elements you want to store in your array: ");
    scanf("%d", &noOfElements);
    printf("\n");

    for (int num = 0; num < noOfElements; num++)
    {
        printf("Enter %d number: ", num + 1);
        scanf("%d", &arr[num]);
    }
    printf("\n");

    // TRAVERSAL THROUGH ARRAY
    printf("The array numbers are,\n");
    for (int num = 0; num < noOfElements; num++)
    {
        printf("%d ", arr[num]);
    }
    printf("\n");

    return 0;
}