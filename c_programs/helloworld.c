#include <stdio.h>

int main()
{
    float arr[100], x;
    int n, i, choice, pos;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    printf("\nThe array list is :");
    for (i = 0; i < n; i++)
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
            printf("\n");
            printf("Enter the element to be inserted: ");
            scanf("%f", &x);
            for (i = n - 1; i >= 0; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[0] = x;
            printf("\nThe array list is :");
            for (i = 0; i <= n; i++)
            {
                printf("%.1f, ", arr[i]);
            }

            printf("\nThe length of the array is %d\n", n += 1);
            break;

        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%f", &x);

            arr[n] = x;
            printf("\nThe array list is :");
            for (i = 0; i <= n; i++)
            {
                printf("%.1f, ", arr[i]);
            }
            printf("\n");
            printf("\nThe length of the array is %d\n", n += 1);
            break;

        case 3:
            printf("Enter the element to be inserted: ");
            scanf("%f", &x);

            printf("Enter the position where the element is to be inserted: ");
            scanf("%d", &pos);

            for (i = n - 1; i >= pos - 1; i--)
            {
                arr[i + 1] = arr[i];
            }

            arr[pos - 1] = x;
            printf("\nThe array list is :");
            for (i = 0; i <= n; i++)
            {
                printf("%.1f, ", arr[i]);
            }
            printf("\n");
            printf("The length of the array is %d\n", n += 1);
            break;

        case 4:
            printf("Enter the index of the element to be removed: ");
            scanf("%d", &pos);
            x = arr[pos];
            for (i = 0; i < n; i++)
            {
                if (arr[i] == x)
                {
                    break;
                }
            }

            if (i == n)
            {
                printf("Element not found\n");
            }
            else
            {
                for (int j = i; j < n - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }

                printf("The length of the array is %d\n", n -= 1);
            }
            printf("\nThe array list is :");
            for (i = 0; i < n; i++)
            {
                printf("%.1f, ", arr[i]);
            }
            printf("\n");
            break;

        case 5:
            printf("Enter the index of the element to be removed: ");
            scanf("%d", &pos);
            x = arr[pos];

            for (i = 0; i < n; i++)
            {
                if (arr[i] == x)
                {
                    break;
                }
            }

            if (i == n)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Enter the new element: ");
                scanf("%f", &x);

                arr[i] = x;

                printf("The length of the array is %d\n", n);
            }
            printf("\nThe array list is :");
            for (i = 0; i < n; i++)
            {
                printf("%.1f, ", arr[i]);
            }
            printf("\n");
            break;

        case 6:
            if (n == 0)
            {
                printf("The list is empty\n");
            }
            else
            {
                printf("The list is not empty\n");
            }
            break;

        case 7:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}