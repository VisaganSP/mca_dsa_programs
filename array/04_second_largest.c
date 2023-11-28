// 4. Write a program to find the second largest of n numbers using an array.
#include <stdio.h>

int main()
{
    int arr[100], noOfElements;

    printf("||===============================================================||\n");
    printf("|| PROGRAM TO FIND THE SECOND LARGEST OF 'N' NUMBERS USING ARRAY ||\n");
    printf("||===============================================================||\n");
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

    // FINDING THE SECOND LARGEST ELEMENT
    int largest = 0, secondLargest;

    for (int num = 0; num < noOfElements; num++)
    {
        if (arr[num] > largest)
        {
            secondLargest = largest;
            largest = arr[num];
        }
        else if (arr[num] > secondLargest)
        {
            secondLargest = arr[num];
        }
    }
    printf("The second largest number in the array is %d", secondLargest);

    return 0;
}