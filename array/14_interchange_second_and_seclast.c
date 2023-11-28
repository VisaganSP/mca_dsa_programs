// 14. Write a program to interchange the second element with the second last element.
#include <stdio.h>

int main()
{
    int arr[100], noOfElements, temp;

    printf("||========================================================================||\n");
    printf("|| PROGRAM TO INTERCHANGE THE SECOND ELEMENT WITH THE SECOND LAST ELEMENT ||\n");
    printf("||========================================================================||\n");
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

    printf("Array before interchange is,\n");
    for (int num = 0; num < noOfElements; num++)
    {
        printf("%d ", arr[num]);
    }
    printf("\n\n");

    // INTERCHANGE THE SECOND AND LAST SECOND ELEMENT FROM THE ARRAY
    temp = arr[1];
    arr[1] = arr[noOfElements - 2];
    arr[noOfElements - 2] = temp;

    printf("Array after interchange is,\n");
    for (int num = 0; num < noOfElements; num++)
    {
        printf("%d ", arr[num]);
    }
    printf("\n\n");

    return 0;
}