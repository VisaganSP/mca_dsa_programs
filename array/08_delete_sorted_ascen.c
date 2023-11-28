// 8. Write a program to delete a number from an array that is already sorted in ascending order.
#include <stdio.h>

int main()
{
    int arr[100], noOfElements, position, temp;

    printf("||====================================================================================||\n");
    printf("|| PROGRAM TO DELETE A NUMBER FROM AN ARRAY THAT IS ALREADY SORTED IN ASCENDING ORDER ||\n");
    printf("||====================================================================================||\n");

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

    printf("Array before deletion is,\n");
    for (int num = 0; num < noOfElements; num++)
    {
        printf("%d ", arr[num]);
    }
    printf("\n\n");

    // DELETE A NUMBER FROM AN ARRAY THAT IS ALREADY SORTED IN ASCENDING ORDER
    printf("Enter the position of the element to be deleted: ");
    scanf("%d", &position);

    int x = arr[position - 1], loc;

    for (loc = 0; loc < noOfElements - 1; loc++)
    {
        if (arr[loc] == x)
        {
            break;
        }
    }

    if (position == noOfElements)
        printf("Index out of range!...");
    else
    {
        for (int j = loc; j < noOfElements - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        noOfElements--;
    }

    // SORTING IN ASCENDING ORDER
    for (int i = 0; i < noOfElements - 1; i++)
    {
        for (int j = i + 1; j < noOfElements - 1; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Array after deletion is,\n");
    for (int num = 0; num < noOfElements; num++)
    {
        printf("%d ", arr[num]);
    }
    printf("\n\n");
    return 0;
}