// 7. Write a program to insert a number in an array that is already sorted in ascending order.
#include <stdio.h>

int main()
{
    int arr[100], noOfElements, x, temp;

    printf("||==================================================================================||\n");
    printf("|| PROGRAM TO INSERT A NUMBER IN AN ARRAY THAT IS ALREADY SORTED IN ASCENDING ORDER ||\n");
    printf("||==================================================================================||\n");
    printf("\n");

    printf("Enter the number of elements you want to store in the array: ");
    scanf("%d", &noOfElements);
    printf("\n");

    for (int num = 0; num < noOfElements; num++)
    {
        printf("Enter %d number: ", num + 1);
        scanf("%d", &arr[num]);
    }
    printf("\n");

    printf("Array before insertion is,\n");
    for (int num = 0; num < noOfElements; num++)
    {
        printf("%d ", arr[num]);
    }
    printf("\n\n");

    // INSERT A NUMBER IN AN ARRAY THAT IS ALREADY SORTED IN ASCENDING ORDER
    printf("Enter the element to be inserted: ");
    scanf("%d", &x);

    // Insertion goes here at the end of the list
    arr[noOfElements] = x;
    noOfElements++;

    // Sorting the array in ascending order
    for (int i = 0; i < noOfElements; i++)
    {
        for (int j = i + 1; j < noOfElements; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Array after insertion is,\n");
    for (int num = 0; num < noOfElements; num++)
    {
        printf("%d ", arr[num]);
    }
    printf("\n\n");

    return 0;
}