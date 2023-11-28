// 12. Write a program to interchange the largest and the smallest number in an array using functions.
#include <stdio.h>

int *interChangeLargeAndSmall(int arr[], int noOfElements)
{
    int smallest = 0, largest = 0, temp;
    int smallestPos = 0, largestPos = 0;

    smallest = arr[0];
    largest = arr[0];
    for (int loc = 0; loc < noOfElements; loc++)
    {
        if (arr[loc] <= smallest)
        {
            smallest = arr[loc];
            smallestPos = loc;
        }
        if (largest <= arr[loc])
        {
            largest = arr[loc];
            largestPos = loc;
        }
    }

    temp = arr[smallestPos];
    arr[smallestPos] = arr[largestPos];
    arr[largestPos] = temp;

    return arr;
}

int main()
{
    int arr[100], noOfElements, *ptrArr;

    printf("||=======================================================================================||\n");
    printf("|| PROGRAM TO INTERCHANGE THE LARGEST AND THE SMALLEST NUMBER IN AN ARRAY USING FUNCTION ||\n");
    printf("||=======================================================================================||\n");

    printf("\n");

    printf("Enter the number of elements you want to store in the array: ");
    scanf("%d", &noOfElements);
    printf("\n");

    for (int loc = 0; loc < noOfElements; loc++)
    {
        printf("Enter %d number: ", loc + 1);
        scanf("%d", &arr[loc]);
    }
    printf("\n");

    printf("The array before interchange of largest and smallest element is,\n");
    for (int loc = 0; loc < noOfElements; loc++)
    {
        printf("%d ", arr[loc]);
    }
    printf("\n");

    ptrArr = interChangeLargeAndSmall(arr, noOfElements);

    printf("The array after interchange of largest and smallest element is,\n");
    for (int loc = 0; loc < noOfElements; loc++)
    {
        printf("%d ", *(ptrArr + loc));
    }
    printf("\n");

    return 0;
}