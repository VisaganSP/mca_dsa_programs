// 2. Write a program to find the average of n numbers using arrays.
#include <stdio.h>

int main()
{
    int arr[100], noOfElements, sum = 0;
    float average = 0;

    printf("||=========================================================||\n");
    printf("|| PROGRAM TO FIND THE AVERAGE OF 'N' NUMBERS USING ARRAYS ||\n");
    printf("||=========================================================||\n");
    printf("\n");

    printf("Enter the number of elements to find average: ");
    scanf("%d", &noOfElements);
    printf("\n");

    for (int num = 0; num < noOfElements; num++)
    {
        printf("Enter %d number: ", num + 1);
        scanf("%d", &arr[num]);
    }
    printf("\n");

    for (int num = 0; num < noOfElements; num++)
        sum += arr[num];
    average = (float)sum / noOfElements;

    printf("The average of the given numbers is: %.2f", average);

    return 0;
}
