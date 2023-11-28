#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

struct student
{
    int registerNumber;
    char name[50];
};

int main()
{
    int noOfStudents, choice, registerNumberLoc;
    struct student stuArr[100], x;

    printf("Enter total size of the students in a class: ");
    scanf("%d", &noOfStudents);

    for (int i = 0; i < noOfStudents; i++)
    {
        printf("\nEnter %d student register number: ", i + 1);
        scanf("%d", &stuArr[i].registerNumber);

        printf("\nEnter %d student name: ", i + 1);
        scanf("%s", &stuArr[i].name);
    }

    printf("\nStudent details are:");
    for (int i = 0; i < noOfStudents; i++)
    {
        printf("\nStudent Register number: %d, Student Name: %s", stuArr[i].registerNumber, stuArr[i].name);
    }

    printf("\n1. Insert at first position & display Students length\n");
    printf("2. Insert at last position & display Students length\n");
    printf("3. Remove a Student detail with the given register number & display Students length\n");
    printf("4. Quit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // insert at first position
            printf("\nEnter the student detail to be inserted at first position: ");

            printf("\nEnter student register number: ");
            scanf("%d", &x.registerNumber);

            printf("\nEnter student name: ");
            scanf("%s", &x.name);

            for (int i = noOfStudents - 1; i >= 0; i--)
            {
                stuArr[i + 1] = stuArr[i];
            }
            stuArr[0] = x;
            noOfStudents++;

            printf("\nThe length of the array is %d\n", noOfStudents);

            printf("\nStudent details are:");
            for (int i = 0; i < noOfStudents; i++)
            {
                printf("\nStudent Register number: %d, Student Name: %s", stuArr[i].registerNumber, stuArr[i].name);
            }
            break;

        case 2:
            // insert at last position
            printf("\nEnter the student detail to be inserted at last position: ");

            printf("\nEnter student register number: ");
            scanf("%d", &x.registerNumber);

            printf("\nEnter student name: ");
            scanf("%s", &x.name);

            stuArr[noOfStudents] = x;
            noOfStudents++;

            printf("\nThe length of the array is %d\n", noOfStudents);

            printf("\nStudent details are:");
            for (int i = 0; i < noOfStudents; i++)
            {
                printf("\nStudent Register number: %d, Student Name: %s", stuArr[i].registerNumber, stuArr[i].name);
            }
            break;

        case 3:
            // remove a student detail with the given register number
            int i;
            printf("\nEnter the register number of student to be removed: ");
            scanf("%d", &registerNumberLoc);

            // x = stuArr[registerNumberLoc];
            for (i = 0; i < noOfStudents; i++)
            {
                if (stuArr[i].registerNumber == registerNumberLoc)
                {
                    break;
                }
            }

            if (i == noOfStudents)
            {
                printf("Student not found\n");
            }
            else
            {
                for (int j = i; j < noOfStudents - 1; j++)
                {
                    stuArr[j] = stuArr[j + 1];
                }

                printf("The length of the student details is %d\n", noOfStudents -= 1);
            }

            printf("\nStudent details are:");
            for (int i = 0; i < noOfStudents; i++)
            {
                printf("\nStudent Register number: %d, Student Name: %s", stuArr[i].registerNumber, stuArr[i].name);
            }
            printf("\n");
            break;

        case 4:
            // quit
            return 0;

        default:
            // invalid choice
            printf("Invalid choice\n");
        }
    }

    return 0;
}