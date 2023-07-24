#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "STACK.c"
#include "QUEUE.c"
#include "Header.h"
#include "Student_Functions.c"
#include "Birthday_Functions.c"
#include "CSV_Functions.c"

int getIntegerInput() 
{
    int number;
    char inputStr[100];
    fgets(inputStr, sizeof(inputStr), stdin);
    while (sscanf(inputStr, "%d", &number) != TRUE)
	{
        printf("Invalid input. Please enter an integer: ");
        fgets(inputStr, sizeof(inputStr), stdin);
    }
    return number;
}

int main() 
{
	strcpy(filename,"Students.csv");
	if (isCSVFileEmpty(filename)) 
	{
        printf("No Records found from '%s'\n", filename);
        Execution_Flag=0;
    } 
	else 
	{
    	Read_CSV(filename);
        printf("Data Fetched from '%s'\n", filename);
        Execution_Flag=1;
    }
	
    do 
	{
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
        choice = getIntegerInput();
        
        if (choice >= 1 && choice <= 14)
	        switch (choice) 
			{
	        	case 1:
	        		Generate_Birthday_Notification(&BirthdayNames,&UpcommingBirthdayNames);
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
	            	int studentcount = count();
	            	if(studentcount==0)
	            		printf("No Records to process this function\n");
	            	else
	            		printf("Total no of students : %d\n",studentcount);
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
	                printf("Exiting the program.!\n");
	                exit(0);
	                break;
	            default:
	                printf("Invalid choice. Please try again.\n");
	        }
	    else
	    	printf("Invalid choice. Please try again.\n");
        printf("\n");
    } while (choice != 14);

    return 0;
}

