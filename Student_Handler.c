//
// Created by aditya on 8/11/25.
//

#include "Student_Handler.h"

/* ---------- Core operations ---------- */

void inputStudentDetails(Node* newNode)
{
    if (!newNode) return;

    printf("Name: ");
    read_line_stdin(newNode->student.name, sizeof newNode->student.name);

    printf("Enter Academic Year: ");
    read_line_stdin(newNode->student.academicYear, sizeof newNode->student.academicYear);

    printf("Date of Birth (DoB) (eg: 01/07/2000): ");
    read_line_stdin(newNode->student.dob, sizeof newNode->student.dob);

    printf("Blood Group: ");
    read_line_stdin(newNode->student.bloodGroup, sizeof newNode->student.bloodGroup);

    printf("Father's Name: ");
    read_line_stdin(newNode->student.fathersName, sizeof newNode->student.fathersName);

    printf("Father's Occupation: ");
    read_line_stdin(newNode->student.fathersOccupation, sizeof newNode->student.fathersOccupation);

    printf("Father's Company: ");
    read_line_stdin(newNode->student.fathersCompany, sizeof newNode->student.fathersCompany);

    printf("Mother's Name: ");
    read_line_stdin(newNode->student.mothersName, sizeof newNode->student.mothersName);

    printf("Mother's Occupation: ");
    read_line_stdin(newNode->student.mothersOccupation, sizeof newNode->student.mothersOccupation);

    printf("Mother's Company: ");
    read_line_stdin(newNode->student.mothersCompany, sizeof newNode->student.mothersCompany);

    printf("Student Phone: ");
    read_line_stdin(newNode->student.studentPhone, sizeof newNode->student.studentPhone);

    printf("Parent's Phone: ");
    read_line_stdin(newNode->student.parentsPhone, sizeof newNode->student.parentsPhone);
}

/* Count nodes */
int count_nodes(void)
{
    int c = 0;
    Node *cur = head;
    while (cur) {
        ++c;
        cur = cur->next;
    }
    return c;
}

/* Case-insensitive search by name */
Node* searchByName(const char *name) {
    if (!name) return NULL;
    Node* current = head;
    char lowercase_target[NAME_SZ];
    safe_strcpy(lowercase_target, sizeof lowercase_target, name);
    str_to_lower_inplace(lowercase_target);

    while (current != NULL) {
        char saved_name[NAME_SZ];
        safe_strcpy(saved_name, sizeof saved_name, current->student.name);
        str_to_lower_inplace(saved_name);
        if (strcmp(saved_name, lowercase_target) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* Print functions */
void printStudentDetails(const Node* DataNode)
{
    if (!DataNode) return;
    printf("Name: %s\n", DataNode->student.name);
    printf("Academic Year: %s\n", DataNode->student.academicYear);
    printf("Date of Birth (DoB)(eg:01/01/2000): %s\n", DataNode->student.dob);
    printf("Blood Group: %s\n", DataNode->student.bloodGroup);
    printf("Father's Name: %s\n", DataNode->student.fathersName);
    printf("Father's Occupation: %s\n", DataNode->student.fathersOccupation);
    printf("Father's Company: %s\n", DataNode->student.fathersCompany);
    printf("Mother's Name: %s\n", DataNode->student.mothersName);
    printf("Mother's Occupation: %s\n", DataNode->student.mothersOccupation);
    printf("Mother's Company: %s\n", DataNode->student.mothersCompany);
    printf("Student Phone: %s\n", DataNode->student.studentPhone);
    printf("Parent's Phone: %s\n", DataNode->student.parentsPhone);
}

void displayStudents(void)
{
    if (head == NULL) {
        printf("----------------------------------------------------\n");
        printf("No students found in the list.\n");
        printf("----------------------------------------------------\n");
        return;
    }

    Node* current = head;
    printf("Student List:\n");
    printf("----------------------------------------------------\n");
    while (current != NULL) {
        printStudentDetails(current);
        printf("----------------------------------------------------\n");
        current = current->next;
    }
}

/* Insert, edit, delete */

void insertStudent(void)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    memset(newNode, 0, sizeof *newNode);

    printf("Enter student details:\n");
    inputStudentDetails(newNode);

    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    Execution_Flag = true;
    printf("Student added successfully!\n");
}

void editStudent(void)
{
    int studentcount = count_nodes();
    if (studentcount <= 0) {
        Execution_Flag = false;
        printf("----------------------------------------------------\n");
        printf("No Records to process this function\n");
        printf("----------------------------------------------------\n");
        return;
    }

    Execution_Flag = true;
    char searchName[NAME_SZ];
    printf("Enter the student name to edit: ");
    read_line_stdin(searchName, sizeof searchName);

    Node* studentNode = searchByName(searchName);
    if (studentNode != NULL) {
        printf("Enter updated student details:\n");
        inputStudentDetails(studentNode);
        printf("Student details updated successfully!\n");
    } else {
        printf("----------------------------------------------------\n");
        printf("No student found with the provided name.\n");
        printf("----------------------------------------------------\n");
    }
}

void deleteStudent(void)
{
    int studentcount = count_nodes();
    if (studentcount <= 0) {
        Execution_Flag = false;
        printf("----------------------------------------------------\n");
        printf("No Records to process this function\n");
        printf("----------------------------------------------------\n");
        return;
    }

    Execution_Flag = true;
    char searchName[NAME_SZ];
    printf("Enter the student name to delete: ");
    read_line_stdin(searchName, sizeof searchName);

    Node* studentNode = searchByName(searchName);
    if (studentNode != NULL) {
        if (studentNode->prev == NULL) {
            head = studentNode->next;
            if (head) head->prev = NULL;
            else tail = NULL;
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
        printf("----------------------------------------------------\n");
        printf("No student found with the provided name.\n");
        printf("----------------------------------------------------\n");
    }
}

void deleteAll(void)
{
    int studentcount = count_nodes();
    if (studentcount <= 0) {
        printf("----------------------------------------------------\n");
        printf("No Records to process this function\n");
        printf("----------------------------------------------------\n");
    } else {
        Node *cur = head;
        while (cur) {
            Node *next = cur->next;
            free(cur);
            cur = next;
        }
        head = tail = NULL;
        printf("----------------------------------------------------\n");
        printf("All students and their records have been deleted.\n");
        printf("----------------------------------------------------\n");
    }
    Execution_Flag = false;
}

/* ---------- Search helpers ---------- */

void searchStudent(void)
{
    int studentcount = count_nodes();
    if (studentcount <= 0) {
        Execution_Flag = false;
        printf("----------------------------------------------------\n");
        printf("No Records to process this function\n");
        printf("----------------------------------------------------\n");
        return;
    }

    Execution_Flag = true;
    char searchName[NAME_SZ];
    printf("Enter the student's name to search: ");
    read_line_stdin(searchName, sizeof searchName);

    Node* found = searchByName(searchName);
    if (found) {
        printf("\nMatch found!\n");
        printStudentDetails(found);
        printf("----------------------------------------------------\n");
    } else {
        printf("----------------------------------------------------\n");
        printf("No student found with the provided name.\n");
        printf("----------------------------------------------------\n");
    }
}

void searchByMonth(void)
{
    int studentcount = count_nodes();
    if (studentcount <= 0) {
        Execution_Flag = false;
        printf("----------------------------------------------------\n");
        printf("No Records to process this function\n");
        printf("----------------------------------------------------\n");
        return;
    }

    Execution_Flag = true;
    char line[32];
    int searchMonth = 0;
    printf("Enter the month (1-12) to search: ");
    if (read_line_stdin(line, sizeof line) != 0 || sscanf(line, "%d", &searchMonth) != 1 || searchMonth < 1 || searchMonth > 12) {
        printf("Invalid month.\n");
        return;
    }

    Node* current = head;
    int found = 0;
    printf("Students with birthdays in the specified month:\n");
    printf("----------------------------------------------------\n");
    while (current != NULL) {
        int bd = 0, bm = 0, by = 0;
        if (sscanf(current->student.dob, "%d/%d/%d", &bd, &bm, &by) >= 2) {
            if (bm == searchMonth) {
                printStudentDetails(current);
                printf("----------------------------------------------------\n");
                found = 1;
            }
        }
        current = current->next;
    }

    if (!found) {
        printf("----------------------------------------------------\n");
        printf("No student found with a birthday in the specified month.\n");
        printf("----------------------------------------------------\n");
    }
}

void searchByBloodGroup(void)
{
    int studentcount = count_nodes();
    if (studentcount <= 0) {
        Execution_Flag = false;
        printf("----------------------------------------------------\n");
        printf("No Records to process this function\n");
        printf("----------------------------------------------------\n");
        return;
    }

    Execution_Flag = true;
    char searchBloodGroup[BG_SZ];
    printf("Enter the blood group to search: ");
    read_line_stdin(searchBloodGroup, sizeof searchBloodGroup);
    str_to_lower_inplace(searchBloodGroup);

    Node* current = head;
    int found = 0;
    printf("Students with the specified Blood Group:\n");
    printf("----------------------------------------------------\n");
    while (current != NULL) {
        char saved[BG_SZ];
        safe_strcpy(saved, sizeof saved, current->student.bloodGroup);
        str_to_lower_inplace(saved);
        if (strcmp(saved, searchBloodGroup) == 0) {
            printStudentDetails(current);
            printf("----------------------------------------------------\n");
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("----------------------------------------------------\n");
        printf("No student found with the provided blood group.\n");
        printf("----------------------------------------------------\n");
    }
}

void searchByPhoneNumber(void)
{
    int studentcount = count_nodes();
    if (studentcount <= 0) {
        Execution_Flag = false;
        printf("----------------------------------------------------\n");
        printf("No Records to process this function\n");
        printf("----------------------------------------------------\n");
        return;
    }

    Execution_Flag = true;
    char searchPhoneNumber[PHONE_SZ];
    printf("Enter the contact number to search: ");
    read_line_stdin(searchPhoneNumber, sizeof searchPhoneNumber);

    Node* current = head;
    int found = 0;
    printf("Students with the specified Contact Number:\n");
    printf("----------------------------------------------------\n");
    while (current != NULL) {
        if (strcmp(current->student.parentsPhone, searchPhoneNumber) == 0 ||
            strcmp(current->student.studentPhone, searchPhoneNumber) == 0) {
            printStudentDetails(current);
            printf("----------------------------------------------------\n");
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("----------------------------------------------------\n");
        printf("No student found with the provided contact number.\n");
        printf("----------------------------------------------------\n");
    }
}

void searchByOccupation(void)
{
    int studentcount = count_nodes();
    if (studentcount <= 0) {
        Execution_Flag = false;
        printf("----------------------------------------------------\n");
        printf("No Records to process this function\n");
        printf("----------------------------------------------------\n");
        return;
    }

    Execution_Flag = true;
    char searchOccupation[OCC_SZ];
    printf("Enter the occupation to search: ");
    read_line_stdin(searchOccupation, sizeof searchOccupation);
    str_to_lower_inplace(searchOccupation);

    Node* current = head;
    int found = 0;
    printf("Parents with the specified occupation:\n");
    printf("----------------------------------------------------\n");
    while (current != NULL) {
        char saved_f_occ[OCC_SZ], saved_m_occ[OCC_SZ];
        safe_strcpy(saved_f_occ, sizeof saved_f_occ, current->student.fathersOccupation);
        safe_strcpy(saved_m_occ, sizeof saved_m_occ, current->student.mothersOccupation);
        str_to_lower_inplace(saved_f_occ);
        str_to_lower_inplace(saved_m_occ);

        if (strcmp(saved_f_occ, searchOccupation) == 0 || strcmp(saved_m_occ, searchOccupation) == 0) {
            printStudentDetails(current);
            printf("----------------------------------------------------\n");
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("----------------------------------------------------\n");
        printf("No parent found with the specified occupation.\n");
        printf("----------------------------------------------------\n");
    }
}

void searchByCompany(void)
{
    int studentcount = count_nodes();
    if (studentcount <= 0) {
        Execution_Flag = false;
        printf("----------------------------------------------------\n");
        printf("No Records to process this function\n");
        printf("----------------------------------------------------\n");
        return;
    }

    Execution_Flag = true;
    char searchCompany[COMPANY_SZ];
    printf("Enter the company name to search: ");
    read_line_stdin(searchCompany, sizeof searchCompany);
    str_to_lower_inplace(searchCompany);

    Node* current = head;
    int found = 0;
    printf("Parents working for the specified company:\n");
    printf("----------------------------------------------------\n");
    while (current != NULL) {
        char saved_f_comp[COMPANY_SZ], saved_m_comp[COMPANY_SZ];
        safe_strcpy(saved_f_comp, sizeof saved_f_comp, current->student.fathersCompany);
        safe_strcpy(saved_m_comp, sizeof saved_m_comp, current->student.mothersCompany);
        str_to_lower_inplace(saved_f_comp);
        str_to_lower_inplace(saved_m_comp);

        if (strcmp(saved_f_comp, searchCompany) == 0 || strcmp(saved_m_comp, searchCompany) == 0) {
            printStudentDetails(current);
            printf("----------------------------------------------------\n");
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("----------------------------------------------------\n");
        printf("No parent found working for the specified company.\n");
        printf("----------------------------------------------------\n");
    }
}
