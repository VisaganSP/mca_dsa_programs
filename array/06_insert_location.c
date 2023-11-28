// 6. Write a program to insert a number at a given location in an array.
#include <stdio.h>

int main()
{
    int arr[100], noOfElements, position, x;

    printf("||============================================================||\n");
    printf("|| PROGRAM TO INSERT A NUMBER AT A GIVEN LOCATION IN AN ARRAY ||\n");
    printf("||============================================================||\n");
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

    // INSERT A NUMBER AT A GIVEN LOCATION IN AN ARRAY
    printf("Enter the number to be inserted: ");
    scanf("%d", &x);
    printf("\n");

    printf("Enter the position in which the element is to be inserted: ");
    scanf("%d", &position);
    printf("\n");

    if (position > noOfElements)
        printf("Index out of range!...\n");
    else
    {
        for (int i = noOfElements - 1; i >= position - 1; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[position - 1] = x;
        noOfElements++;

        printf("Array after insertion is,\n");
        for (int num = 0; num < noOfElements; num++)
        {
            printf("%d ", arr[num]);
        }
    }
    return 0;
}