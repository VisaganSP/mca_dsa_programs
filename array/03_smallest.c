// 3. Write a program to print the position of the smallest number of n numbers using arrays.
#include <stdio.h>

int main()
{
    int arr[100], noOfElements;

    printf("||=============================================================================||\n");
    printf("|| PROGRAM TO PRINT THE POSITION OF SMALLEST NUMBER OF 'N' NUMBERS USING ARRAY ||\n");
    printf("||=============================================================================||\n");
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

    // FINDING THE SMALLEST ELEMENT & ITS POSITION
    int smallest = arr[0];
    int position = 0;

    for (int num = 0; num < noOfElements; num++)
    {
        if (smallest > arr[num])
        {
            smallest = arr[num];
            position = num;
        }
    }
    printf("The smallest number is %d, and the position is %d", smallest, position + 1);

    return 0;
}