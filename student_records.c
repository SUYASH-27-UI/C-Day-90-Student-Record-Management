#include <stdio.h>

#define FILE_NAME "students.txt"

struct Student
{
    int id;
    char name[50];
    float marks;
};

void addStudent()
{
    struct Student s;
    FILE *file = fopen(FILE_NAME, "a");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &s.id);

    printf("Enter name (one word): ");
    scanf("%49s", s.name);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    fprintf(file, "%d %s %.2f\n",
            s.id, s.name, s.marks);

    fclose(file);

    printf("Student record saved!\n");
}

void viewStudents()
{
    struct Student s;
    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    printf("\nID\tName\tMarks\n");
    printf("-------------------------\n");

    while (fscanf(file, "%d %49s %f",
                  &s.id, s.name, &s.marks) == 3)
    {
        printf("%d\t%s\t%.2f\n",
               s.id, s.name, s.marks);
    }

    fclose(file);
}

void searchStudent()
{
    struct Student s;
    int searchID;
    int found = 0;

    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    printf("Enter student ID to search: ");
    scanf("%d", &searchID);

    while (fscanf(file, "%d %49s %f",
                  &s.id, s.name, &s.marks) == 3)
    {
        if (s.id == searchID)
        {
            printf("Student found!\n");
            printf("ID: %d\n", s.id);
            printf("Name: %s\n", s.name);
            printf("Marks: %.2f\n", s.marks);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student not found.\n");
    }

    fclose(file);
}

int main()
{
    int choice;

    do
    {
        printf("\n===== STUDENT MANAGEMENT =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
