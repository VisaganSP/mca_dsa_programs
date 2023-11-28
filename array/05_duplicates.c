// 5. Write a program to find whether the array of integers contains a duplicate number.
#include <stdio.h>

int main()
{
    int arr[100], noOfElements, isDuplicateFound = 0;

    printf("||===========================================================================||\n");
    printf("|| PROGRAM TO FIND WHETHER THE ARRAY OF INTEGERS CONTAINS A DUPLICATE NUMBER ||\n");
    printf("||===========================================================================||\n");
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

    // FINDING WHETHER THE ARRAY OF INTEGERS CONTAINS A DUPLICATE NUMBER
    for (int i = 0; i < noOfElements; i++)
    {
        for (int j = i + 1; j < noOfElements; j++)
        {
            if (arr[i] == arr[j])
                isDuplicateFound = 1;
        }
    }

    if (isDuplicateFound == 1)
        printf("Array contains duplicate elements");
    else
        printf("Array contains no duplicate elements");

    return 0;
}