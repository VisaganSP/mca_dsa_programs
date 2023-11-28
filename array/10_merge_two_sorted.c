// 10. Write a program to merge two sorted arrays.
#include <stdio.h>

int main()
{
    int arr1[100], arr2[100], mergeArr[100];
    int noOfElementsArr1, noOfElementsArr2, index = 0, temp;

    printf("||======================================||\n");
    printf("|| PROGRAM TO MERGE TO TWO SORTED ARRAY ||\n");
    printf("||======================================||\n");
    printf("\n");

    printf("Enter the number of elements you want to store in the array 1: ");
    scanf("%d", &noOfElementsArr1);
    printf("\n");

    for (int num = 0; num < noOfElementsArr1; num++)
    {
        printf("Enter %d number: ", num + 1);
        scanf("%d", &arr1[num]);
    }
    printf("\n");

    printf("Enter the number of elements you want to store in the array 2: ");
    scanf("%d", &noOfElementsArr2);
    printf("\n");

    for (int num = 0; num < noOfElementsArr2; num++)
    {
        printf("Enter %d number: ", num + 1);
        scanf("%d", &arr2[num]);
    }
    printf("\n");

    // MERGE GOES HERE
    for (int i = 0; i < noOfElementsArr1; i++)
    {
        mergeArr[index] = arr1[i];
        index++;
    }

    for (int i = 0; i < noOfElementsArr2; i++)
    {
        mergeArr[index] = arr2[i];
        index++;
    }

    // SORTING THE MERGED ARRAY GOES HERE
    for (int i = 0; i < index; i++)
    {
        for (int j = i + 1; j < index; j++)
        {
            if (mergeArr[i] > mergeArr[j])
            {
                temp = mergeArr[i];
                mergeArr[i] = mergeArr[j];
                mergeArr[j] = temp;
            }
        }
    }

    printf("Arrays after merge is,\n");
    for (int num = 0; num < index; num++)
    {
        printf("%d ", mergeArr[num]);
    }
    printf("\n\n");

    return 0;
}