#include <stdio.h>

int main()
{
    char arr[100], x;
    int noOfElements, choice, position;

    printf("\nEnter the size of the array: ");
    scanf("%d", &noOfElements);

    printf("\nEnter %d characters: ", noOfElements);
    for (int i = 0; i < noOfElements; i++)
    {
        // printf("%d", i);
        scanf("%s", &arr[i]);
    }

    printf("\n%d Characters are: ", noOfElements);
    for (int i = 0; i < noOfElements; i++)
    {
        printf("\n%c", arr[i]);
    }

    printf("\n");
    printf("1. Insert at first position & Display length\n");
    printf("2. Insert at last position & Display length\n");
    printf("3. Insert at a given position & Display length\n");
    printf("4. Remove an element & Display length\n");
    printf("5. Replace an element & Display length\n");
    printf("6. Check if the list is empty\n");
    printf("7. Display array & length\n");
    printf("8. Quit\n");

    while (1)
    {
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted at first position: ");
            scanf(" %c", &x);

            for (int i = noOfElements - 1; i >= 0; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[0] = x;

            printf("\nThe array list is :");
            for (int i = 0; i <= noOfElements; i++)
            {
                printf("%c, ", arr[i]);
            }

            printf("\nThe length of the array is %d\n", noOfElements += 1);
            break;

        case 2:
            printf("Enter the element to be inserted at last position: ");
            scanf(" %c", &x);

            arr[noOfElements] = x;

            printf("\nThe array list is :");
            for (int i = 0; i <= noOfElements; i++)
            {
                printf("%c, ", arr[i]);
            }

            printf("\nThe length of the array is %d\n", noOfElements += 1);

            break;

        case 7:
            printf("\nThe array list is :");
            for (int i = 0; i <= noOfElements; i++)
            {
                printf("%c, ", arr[i]);
            }

            printf("\nThe length of the array is %d\n", noOfElements);
            break;

        default:
            break;
        }
    }

    return 0;
}