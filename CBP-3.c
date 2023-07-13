#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[50];
    char dob[20];
    char bloodGroup[10];
    char fathersName[50];
    char fathersOccupation[50];
    char fathersCompany[50];
    char mothersName[50];
    char mothersOccupation[50];
    char mothersCompany[50];
    char studentPhone[20];
    char fathersPhone[20];
    char mothersPhone[20];
} Student;

typedef struct Node
{
	struct Node* prev;
    Student student;
    struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;

void insertStudent() 
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    printf("Enter student details:\n");
    printf("Name: ");
    scanf("%s", newNode->student.name);
    printf("Date of Birth (DoB)(eg:01/07/2000): ");
    scanf("%s", newNode->student.dob);
    printf("Blood Group: ");
    scanf("%s", newNode->student.bloodGroup);
    printf("Father's Name: ");
    scanf("%s", newNode->student.fathersName);
    printf("Father's Occupation: ");
    scanf("%s", newNode->student.fathersOccupation);
    printf("Father's Company: ");
    scanf("%s", newNode->student.fathersCompany);
    printf("Mother's Name: ");
    scanf("%s", newNode->student.mothersName);
    printf("Mother's Occupation: ");
    scanf("%s", newNode->student.mothersOccupation);
    printf("Mother's Company: ");
    scanf("%s", newNode->student.mothersCompany);
    printf("Student Phone: ");
    scanf("%s", newNode->student.studentPhone);
    printf("Father's Phone: ");
    scanf("%s", newNode->student.fathersPhone);
    printf("Mother's Phone: ");
    scanf("%s", newNode->student.mothersPhone);

    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    printf("Student added successfully!\n");
}

void displayStudents() {
    if (head == NULL) {
        printf("No students found in the list.\n");
        return;
    }

    Node* current = head;
    printf("Student List:\n");
    printf("----------------------------------------------------\n");
    while (current != NULL) {
        printf("Name: %s\n", current->student.name);
        printf("Date of Birth (DoB)(eg:01/07/2000): %s\n", current->student.dob);
        printf("Blood Group: %s\n", current->student.bloodGroup);
        printf("Father's Name: %s\n", current->student.fathersName);
        printf("Father's Occupation: %s\n", current->student.fathersOccupation);
        printf("Father's Company: %s\n", current->student.fathersCompany);
        printf("Mother's Name: %s\n", current->student.mothersName);
        printf("Mother's Occupation: %s\n", current->student.mothersOccupation);
        printf("Mother's Company: %s\n", current->student.mothersCompany);
        printf("Student Phone: %s\n", current->student.studentPhone);
        printf("Father's Phone: %s\n", current->student.fathersPhone);
        printf("Mother's Phone: %s\n", current->student.mothersPhone);
        printf("----------------------------------------------------\n");

        current = current->next;
    }
}

Node* searchByName(char name[50]) {
    Node* current = head;

    while (current != NULL) {
        if (strcmp(current->student.name, name) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void searchStudent() {
    char searchName[50];
    printf("Enter the friend's name to search: ");
    scanf("%s", searchName);

    Node* friendNode = searchByName(searchName);

    if (friendNode != NULL) {
        printf("\nMatch found!\n");
        printf("Name: %s\n", friendNode->student.name);
        printf("Date of Birth (DoB)(eg:01/07/2000): %s\n", friendNode->student.dob);
        printf("Blood Group: %s\n", friendNode->student.bloodGroup);
        printf("Father's Name: %s\n", friendNode->student.fathersName);
        printf("Father's Occupation: %s\n", friendNode->student.fathersOccupation);
        printf("Father's Company: %s\n", friendNode->student.fathersCompany);
        printf("Mother's Name: %s\n", friendNode->student.mothersName);
        printf("Mother's Occupation: %s\n", friendNode->student.mothersOccupation);
        printf("Mother's Company: %s\n", friendNode->student.mothersCompany);
        printf("Student Phone: %s\n", friendNode->student.studentPhone);
        printf("Father's Phone: %s\n", friendNode->student.fathersPhone);
        printf("Mother's Phone: %s\n", friendNode->student.mothersPhone);
        printf("----------------------------------------------------\n");
    } else {
        printf("No friend found with the provided name.\n");
    }
}

void searchByMonth() {
    int searchMonth;
    printf("Enter the month (1-12) to search: ");
    scanf("%d", &searchMonth);

    Node* current = head;
    int found = 0;

    printf("Students with birthdays in the specified month:\n");
    printf("----------------------------------------------------\n");
    while (current != NULL) {
        int birthMonth;
        sscanf(current->student.dob, "%*[^/]/%d", &birthMonth);

        if (birthMonth == searchMonth) {
            printf("Name: %s\n", current->student.name);
            printf("Date of Birth (DoB)(eg:01/07/2000): %s\n", current->student.dob);
            printf("Blood Group: %s\n", current->student.bloodGroup);
            printf("Father's Name: %s\n", current->student.fathersName);
            printf("Father's Occupation: %s\n", current->student.fathersOccupation);
            printf("Father's Company: %s\n", current->student.fathersCompany);
            printf("Mother's Name: %s\n", current->student.mothersName);
            printf("Mother's Occupation: %s\n", current->student.mothersOccupation);
            printf("Mother's Company: %s\n", current->student.mothersCompany);
            printf("Student Phone: %s\n", current->student.studentPhone);
            printf("Father's Phone: %s\n", current->student.fathersPhone);
            printf("Mother's Phone: %s\n", current->student.mothersPhone);
            printf("----------------------------------------------------\n");

            found = 1;
        }

        current = current->next;
    }

    if (!found) {
        printf("No student found with a birthday in the specified month.\n");
    }
}

void searchByOccupation() {
    char searchOccupation[50];
    printf("Enter the occupation to search: ");
    scanf("%s", searchOccupation);

    Node* current = head;
    int found = 0;

    printf("Parents with the specified occupation:\n");
    printf("----------------------------------------------------\n");
    while (current != NULL) {
        if (strcmp(current->student.fathersOccupation, searchOccupation) == 0 ||
            strcmp(current->student.mothersOccupation, searchOccupation) == 0) {

            printf("Father's Name: %s\n", current->student.fathersName);
            printf("Father's Occupation: %s\n", current->student.fathersOccupation);
            printf("Father's Company: %s\n", current->student.fathersCompany);
            printf("Mother's Name: %s\n", current->student.mothersName);
            printf("Mother's Occupation: %s\n", current->student.mothersOccupation);
            printf("Mother's Company: %s\n", current->student.mothersCompany);
            printf("----------------------------------------------------\n");

            found = 1;
        }

        current = current->next;
    }

    if (!found) {
        printf("No parent found with the specified occupation.\n");
    }
}

void searchByCompany() {
    char searchCompany[50];
    printf("Enter the company name to search: ");
    scanf("%s", searchCompany);

    Node* current = head;
    int found = 0;

    printf("Parents working for the specified company:\n");
    printf("----------------------------------------------------\n");
    while (current != NULL) {
        if (strcmp(current->student.fathersCompany, searchCompany) == 0 ||
            strcmp(current->student.mothersCompany, searchCompany) == 0) 
			{
            printf("Father's Name: %s\n", current->student.fathersName);
            printf("Father's Occupation: %s\n", current->student.fathersOccupation);
            printf("Father's Company: %s\n", current->student.fathersCompany);
            printf("Mother's Name: %s\n", current->student.mothersName);
            printf("Mother's Occupation: %s\n", current->student.mothersOccupation);
            printf("Mother's Company: %s\n", current->student.mothersCompany);
            printf("----------------------------------------------------\n");

            found = 1;
        }

        current = current->next;
    }

    if (!found) {
        printf("No parent found working for the specified company.\n");
    }
}

void editStudent() {
    char searchName[50];
    printf("Enter the student name to edit: ");
    scanf("%s", searchName);

    Node* studentNode = searchByName(searchName);

    if (studentNode != NULL) {
        printf("Enter updated student details:\n");
        printf("Name: ");
        scanf("%s", studentNode->student.name);
        printf("Date of Birth (DoB)(eg:01/07/2000): ");
        scanf("%s", studentNode->student.dob);
        printf("Blood Group: ");
        scanf("%s", studentNode->student.bloodGroup);
        printf("Father's Name: ");
        scanf("%s", studentNode->student.fathersName);
        printf("Father's Occupation: ");
        scanf("%s", studentNode->student.fathersOccupation);
        printf("Father's Company: ");
        scanf("%s", studentNode->student.fathersCompany);
        printf("Mother's Name: ");
        scanf("%s", studentNode->student.mothersName);
        printf("Mother's Occupation: ");
        scanf("%s", studentNode->student.mothersOccupation);
        printf("Mother's Company: ");
        scanf("%s", studentNode->student.mothersCompany);
        printf("Student Phone: ");
        scanf("%s", studentNode->student.studentPhone);
        printf("Father's Phone: ");
        scanf("%s", studentNode->student.fathersPhone);
        printf("Mother's Phone: ");
        scanf("%s", studentNode->student.mothersPhone);

        printf("Student details updated successfully!\n");
    } else {
        printf("No student found with the provided name.\n");
    }
}

void deleteStudent() {
    char searchName[50];
    printf("Enter the student name to delete: ");
    scanf("%s", searchName);

    Node* studentNode = searchByName(searchName);

    if (studentNode != NULL) {
        if (studentNode->prev == NULL) {
            head = studentNode->next;
            if (head != NULL) {
                head->prev = NULL;
            }
        } else if (studentNode->next == NULL) {
            tail = studentNode->prev;
            tail->next = NULL;
        } else {
            studentNode->prev->next = studentNode->next;
            studentNode->next->prev = studentNode->prev;
        }

        free(studentNode);
        printf("Student deleted successfully!\n");
    } else {
        printf("No student found with the provided name.\n");
    }
}

void deleteAll() {
    Node* current = head;
    while (current != NULL) {
        Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    head = NULL;
    tail = NULL;

    printf("All students and their records have been deleted.\n");
}

int main() {
    int choice;
    do {
        printf("--------- Birthday List of 4-year ECE Students ---------\n");
        printf("1. Insert a Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by Name\n");
        printf("4. Search Students by Month\n");
        printf("5. Search Parents by Occupation\n");
        printf("6. Search Parents by Company\n");
        printf("7. Edit Student\n");
        printf("8. Delete Student\n");
        printf("9. Delete All Records\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                searchByMonth();
                break;
            case 5:
                searchByOccupation();
                break;
            case 6:
                searchByCompany();
                break;
            case 7:
                editStudent();
                break;
            case 8:
                deleteStudent();
                break;
            case 9:
                deleteAll();
                break;
            case 10:
                printf("Exiting the program.!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 10);

    return 0;
}

