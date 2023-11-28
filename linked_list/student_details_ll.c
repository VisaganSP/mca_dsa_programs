#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[50];
    int reg_no;
    char gender;
    struct Student *next;
};

void insertStudent(struct Student *head, char name[], int reg_no, char gender)
{
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));

    if (newStudent == NULL)
    {
        printf("\nMemory allocation failed. Can't able to insert\n");
    }
    strcpy(newStudent->name, name);
    newStudent->reg_no = reg_no;
    newStudent->gender = gender;
    newStudent->next = NULL;

    if (head == NULL)
    {
        head = newStudent;
    }
    else
    {
        struct Student *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newStudent;
    }
}

void printStudents(struct Student *head)
{
    struct Student *current = head;

    if (head == NULL)
    {
        printf("Linked List is Empty!...");
    }
    else
    {
        while (current != NULL)
        {
            printf("\nName: %s, Registration Number: %d, Gender: %c\n", current->name, current->reg_no, current->gender);
            current = current->next;
        }
    }
}

void splitByGender(struct Student *original, struct Student *males, struct Student *females)
{
    struct Student *current = original;

    while (current != NULL)
    {
        if (current->gender == 'M')
        {
            insertStudent(males, current->name, current->reg_no, current->gender);
        }
        else if (current->gender == 'F')
        {
            insertStudent(females, current->name, current->reg_no, current->gender);
        }
        current = current->next;
    }
}

void insertStudentByGender(struct Student *males, struct Student *females, char name[], int reg_no, char gender)
{
    if (gender == 'M')
    {
        insertStudent(males, name, reg_no, gender);
    }
    else if (gender == 'F')
    {
        insertStudent(females, name, reg_no, gender);
    }
    else
    {
        printf("\nInvalid gender. Student not inserted. Male - M & Female - F\n");
    }
}

int main()
{
    int choice, reg_no;
    char name[50];
    char gender;

    struct Student *head = NULL;
    struct Student *maleList = NULL;
    struct Student *femaleList = NULL;

    // Initially insert 5 student details
    insertStudent(head, "Alice", 1001, 'F');
    insertStudent(head, "Visagan", 1002, 'M');
    insertStudent(head, "Yuva", 1003, 'F');
    insertStudent(head, "Tamil", 1004, 'M');
    insertStudent(head, "Eve", 1005, 'F');

    while (choice != 7)
    {
        printf("\n");
        printf("\n1. Insert a new student");
        printf("\n2. Insert a new student according to thier gender");
        printf("\n3. Split the linked list into separate list based on gender");
        printf("\n4. Display all students");
        printf("\n5. Display only male students");
        printf("\n6. Display only female students");
        printf("\n7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter student name: ");
            scanf("%s", &name);
            printf("\nEnter student register number: ");
            scanf("%d", &reg_no);
            printf("\nEnter student gender: ");
            scanf(" %c", &gender);

            insertStudent(head, name, reg_no, gender);
            break;

        case 2:
            printf("\nEnter student name: ");
            scanf("%s", &name);
            printf("\nEnter student register number: ");
            scanf("%d", &reg_no);
            printf("\nEnter student gender: ");
            scanf("%c", &gender);

            insertStudentByGender(maleList, femaleList, name, reg_no, gender);
            break;

        case 3:
            // maleList->next = NULL;
            // femaleList->next = NULL;

            splitByGender(head, maleList, femaleList);

            // Print the lists of males and females
            printf("\nList of Male Students:\n");
            printStudents(maleList);

            printf("\nList of Female Students:\n");
            printStudents(femaleList);
            break;

        case 4:
            // Print the lists of all students
            printf("\nList of all Students are:\n");
            printStudents(head);
            break;

        case 5:
            // maleList->next = NULL;
            // femaleList->next = NULL;

            // Print the lists of males
            // splitByGender(head, maleList, femaleList);

            printf("\nList of Male Students are:\n");
            printStudents(maleList);
            break;

        case 6:
            // maleList->next = NULL;
            // femaleList->next = NULL;

            // Print the lists of males
            // splitByGender(head, maleList, femaleList);

            printf("\nList of Female Students are:\n");
            printStudents(femaleList);
            break;

        default:
            break;
        }
    }

    // Print the original list of students
    // printf("Original List of Students:\n");
    // printStudents(head);

    // // Split the original list into two lists based on gender
    // splitByGender(head, &maleList, &femaleList);

    // // Print the lists of males and females
    // printf("\nList of Males:\n");
    // printStudents(maleList);

    // printf("\nList of Females:\n");
    // printStudents(femaleList);

    // // Insert a new student
    // insertStudentByGender(&maleList, &femaleList, "Bob", 1006, 'M');
    // insertStudentByGender(&maleList, &femaleList, "Priya", 1006, 'F');

    // // Print the lists of males and females
    // printf("List of Males:\n");
    // printStudents(maleList);

    // printf("\nList of Females:\n");
    // printStudents(femaleList);
    return 0;
}