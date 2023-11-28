// 13. Write a program that reads an array of 100 integers. Display all the pairs of elements whose sum is 50.
#include <stdio.h>

int main()
{
    int arr[100], noOfElements;

    printf("||==============================================================||\n");
    printf("|| PROGRAM TO DISPLAY ALL THE PAIRS OF ELEMENTS WHOSE SUM IS 50 ||\n");
    printf("||==============================================================||\n");

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

    for (int i = 0; i < noOfElements; i++)
        for (int j = i + 1; j < noOfElements; j++)
            if (arr[i] + arr[j] == 50)
                printf("(%d, %d)", arr[i], arr[j]);

    return 0;
}