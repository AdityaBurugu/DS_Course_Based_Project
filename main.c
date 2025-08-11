#include <stdio.h>
#include <stdbool.h>

#include "Birthday_Event_Handler.h"
#include "Student_Handler.h"
#include "CSV_Handler.h"
#include "Utilities.h"
#include "Globals.h"
#include "Stack.h"
#include "Queue.h"

/* ---------- Main menu ---------- */

int main(void)
{
    const char filename[] = "Students.csv";

    if (isCSVFileEmpty(filename)) {
        printf("No Records found from '%s'\n", filename);
        Execution_Flag = false;
    } else {
        int read = Read_CSV(filename);
        if (read > 0) {
            printf("Data Fetched from '%s' (%d records)\n", filename, read);
            Execution_Flag = true;
        } else {
            printf("No valid records found in '%s'\n", filename);
            Execution_Flag = false;
        }
    }

    Stack BirthdayNames;
    Queue UpcommingBirthdayNames;

    int choice = 0;
    char choice_str[32];

    do {
        printf("--------- Birthday List of 4-year ECE Students ---------\n");
        printf("1. Birthday Notification\n");
        printf("2. Add a Student\n");
        printf("3. Display Students\n");
        printf("4. Total No of Students\n");
        printf("5. Search Student by Name\n");
        printf("6. Search Students by Month\n");
        printf("7. Search Students by Blood Group\n");
        printf("8. Search Students by Contact Number\n");
        printf("9. Search Parents by Occupation\n");
        printf("10. Search Parents by Company\n");
        printf("11. Edit Student\n");
        printf("12. Delete Student\n");
        printf("13. Delete All Records\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");

        if (read_line_stdin(choice_str, sizeof choice_str) != 0 || sscanf(choice_str, "%d", &choice) != 1) {
            printf("Invalid input. Try again.\n\n");
            continue;
        }

        switch (choice) {
            case 1:
                Generate_Birthday_Notification(&BirthdayNames, &UpcommingBirthdayNames);
                break;
            case 2:
                insertStudent();
                writeStudentDataToCSV(filename);
                break;
            case 3:
                displayStudents();
                break;
            case 4:
                printf("----------------------------------------------------\n");
                {
                    int studentcount = count_nodes();
                    if (studentcount == 0) printf("No students found in the list.\n");
                    else printf("Total no of students : %d\n", studentcount);
                }
                printf("----------------------------------------------------\n");
                break;
            case 5:
                searchStudent();
                break;
            case 6:
                searchByMonth();
                break;
            case 7:
                searchByBloodGroup();
                break;
            case 8:
                searchByPhoneNumber();
                break;
            case 9:
                searchByOccupation();
                break;
            case 10:
                searchByCompany();
                break;
            case 11:
                editStudent();
                writeStudentDataToCSV(filename);
                break;
            case 12:
                deleteStudent();
                writeStudentDataToCSV(filename);
                break;
            case 13:
                deleteAll();
                writeStudentDataToCSV(filename);
                break;
            case 14:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 14);

    /* Clean up memory before exit just in case */
    writeStudentDataToCSV(filename);

    return 0;
}
