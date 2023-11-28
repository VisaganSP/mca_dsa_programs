// 11. Write a program to read an array of n numbers and then find the smallest number using functions.
#include <stdio.h>

int smallestElement(int arr[], int noOfElements)
{
    int position = 0, smallest = arr[0];

    for (int loc = 0; loc < noOfElements - 1; loc++)
    {
        if (smallest > arr[loc])
        {
            smallest = arr[loc];
            position = loc;
        }
    }

    return position;
}

int main()
{
    int arr[100], noOfElements, position;

    printf("||================================================================================||\n");
    printf("|| PROGRAM TO FIND THE SMALLEST NUMBER USING FUNCTIONS IN AN ARRAY OF 'N' NUMBERS ||\n");
    printf("||================================================================================||\n");

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

    position = smallestElement(arr, noOfElements);
    printf("The Smallest element in the given array is %d and the position is %d", arr[position], position + 1);

    return 0;
}