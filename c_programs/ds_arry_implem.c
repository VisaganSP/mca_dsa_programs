#include <stdio.h>
#include <conio.h>
#define MAX 100

int main()
{
    float arr[MAX], x;
    int choice, position, size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%f", &arr[i]);
    }

    printf("\nThe array list is :");
    for (i = 0; i < size; i++)
    {
        printf("%.1f, ", arr[i]);
    }

    printf("\n");
    printf("1. Insert at first position & Display length\n");
    printf("2. Insert at last position & Display length\n");
    printf("3. Insert at a given position & Display length\n");
    printf("4. Remove an element & Display length\n");
    printf("5. Replace an element & Display length\n");
    printf("6. Check if the list is empty\n");
    printf("7. Quit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            /* Insert at first position & Display length */
            printf("Enter the element to be inserted in first position: ");
            scanf("%d", &x);

            for (i = size - 1; i >= 0; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[0] = x;
            size++;

            printf("The length of the array %d", size);

            printf("The array list is: ");
            for (i = 0; i < size; i++)
            {
                printf("%.1f, ", arr[i]);
            }

            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;

        case 7:
            return 0;

        default:
            printf("Invalid choice\n");
            // break;
        }
    }

    return 0;
}
