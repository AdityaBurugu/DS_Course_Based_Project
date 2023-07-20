#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "STACK.c"
#include "QUEUE.c"

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 20

char line[MAX_LINE_LENGTH];
char *fields[MAX_FIELDS];
int num_fields = 0;

int Execution_Flag=0;

typedef struct 
{
    char name[50];
    char academicYear[10];
    char dob[20];
    char bloodGroup[10];
    char fathersName[50];
    char fathersOccupation[50];
    char fathersCompany[50];
    char mothersName[50];
    char mothersOccupation[50];
    char mothersCompany[50];
    char studentPhone[20];
    char parentsPhone[20];
} Student;

typedef struct Node
{
	struct Node* prev;
    Student student;
    struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;

void inputStudentDetails(Node* newNode)
{
	printf("Name: ");
    scanf("%s", newNode->student.name);
    printf("Enter Academic Year: ");
    scanf("%s",newNode->student.academicYear);
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
    printf("Parent's Phone: ");
    scanf("%s", newNode->student.parentsPhone);
}

int isCSVFileEmpty(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file '%s'\n", filename);
        return 1; // Return 1 to indicate an error.
    }

    // Move the file pointer to the end of the file and check its position.
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);

    fclose(file);

    // If the file size is 0, the file is empty.
    return (fileSize == 0);
}


int Read_CSV(char Filename[50])
{
	FILE *file;

 // Open the CSV file for reading
    file = fopen(Filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Read and process each line of the CSV file
    while (fgets(line, sizeof(line), file)) 
	{
        // Split the line into fields
        char *token = strtok(line, ",");
        num_fields = 0;

        while (token != NULL && num_fields < MAX_FIELDS) {
            fields[num_fields++] = token;
            token = strtok(NULL, ",");
        }
			Node* newNode = (Node*)malloc(sizeof(Node));
			strcpy(newNode->student.name,fields[0]);
			strcpy(newNode->student.academicYear,fields[1]);
			strcpy(newNode->student.dob,fields[2]);
			strcpy(newNode->student.bloodGroup,fields[3]);
			strcpy(newNode->student.fathersName,fields[4]);
			strcpy(newNode->student.fathersOccupation,fields[5]);
			strcpy(newNode->student.fathersCompany,fields[6]);
			strcpy(newNode->student.mothersName,fields[7]);
			strcpy(newNode->student.mothersOccupation,fields[8]);
			strcpy(newNode->student.mothersCompany,fields[9]);
			strcpy(newNode->student.studentPhone,fields[10]);
			strcpy(newNode->student.parentsPhone,fields[11]);

			
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
    }
    // Close the file
    fclose(file);
}

void Get_Birthday_Names(Stack *Birthday_Names ,Queue *Upcomming_Birthdays)
{
	int current_day,current_month,studentcount;
	int birthDay,birthMonth,birthYear;
	struct tm *current_time;
	
	initializeStack(Birthday_Names);
	initializeQueue(Upcomming_Birthdays);
		
	studentcount = count();
	
	if(studentcount>0)
	{
		time_t t = time(NULL);
		current_time = localtime(&t);
		
		//Fetching Current date
		current_day=current_time->tm_mday;
		
		//Fetching Current month
		current_month = current_time->tm_mon + 1;
		
	    Node* current = head;
	    
	    while (current != NULL) {
	        sscanf(current->student.dob, "%d/%d/%d", &birthDay, &birthMonth, &birthYear);
	        
	        if((current_day == birthDay) && (current_month == birthMonth)) 
			{
				push(Birthday_Names,current->student.name);
	        }
	        
	        if((birthDay > current_day) && (current_month == birthMonth))
	        
	        {
	        	enqueue(Upcomming_Birthdays,current->student.name);
			}
	        
	        current = current->next;
	    }	
	}
}

int Get_Age(char Name[20])
{
	int current_year;
	int birthDay, birthMonth, birthYear;
	struct tm *current_time;
	
	time_t t = time(NULL);
	current_time = localtime(&t);
	
	//Fetching Current Year
	current_year = current_time->tm_year + 1900;
	
    Node* current = head;
    
    while (current != NULL) {
        char student_name[20];
        strcpy(student_name,Name);
        
        
        if (strcmp(student_name,current->student.name)==0)
		{
			sscanf(current->student.dob, "%d/%d/%d", &birthDay, &birthMonth, &birthYear);
            return current_year-birthYear;
        }
        current = current->next;
    }
	
	return 0;
}

void Get_DOB(char Name[20],char DOB[20])
{
	int current_year;
	int birthDay, birthMonth, birthYear;
	struct tm *current_time;
	
	time_t t = time(NULL);
	current_time = localtime(&t);
	
	current_year = current_time->tm_year + 1900;
	
    Node* current = head;
    
    while (current != NULL) {
        char student_name[20];
        strcpy(student_name,Name);
        
        
        if (strcmp(student_name,current->student.name)==0)
		{
			sscanf(current->student.dob, "%d/%d/%d", &birthDay, &birthMonth, &birthYear);
    		sprintf(DOB, "%02d/%02d/%04d", birthDay, birthMonth, current_year);
        }
        current = current->next;
    }
}

void Generate_Birthday_Notification(Stack *Birthday_Names, Queue *Upcomming_Birthday_Names)
{
	int i;
	int count=0;
	
	char popped[20];
	char dequeued[20];
	
	char DOB[20];
	
	if(Execution_Flag==1)
	{

		Get_Birthday_Names(Birthday_Names, Upcomming_Birthday_Names);
		
		count = Birthday_Names->top+1;
		printf("----------------------------------------------------\n");
		printf("Today's Events\n");
		printf("----------------------------------------------------\n");
		
		for(i=0;i<count;i++)
		{
			strcpy(popped,pop(Birthday_Names));
			printf("%s is celebrating %d birthday\n",popped,Get_Age(popped));
		}
		if(count==0)
			printf("No Birthday's Today.\n");
				
		printf("----------------------------------------------------\n");
	
	
		printf("Upcomming Events\n");
		printf("----------------------------------------------------\n");
		
		count = Upcomming_Birthday_Names->rear+1;
		for(i=0;i<count;i++)
		{	
			strcpy(dequeued,dequeue(Upcomming_Birthday_Names));
			Get_DOB(dequeued,DOB);
			printf("%s is celebrating their birthday on %s\n",dequeued,DOB);
		}
		if(count==0)
			printf("No Upcomming Events.\n");
				
		printf("----------------------------------------------------\n");
	}
	else
	{
		printf("----------------------------------------------------\n");
		printf("No Records to process this function\n");
		printf("----------------------------------------------------\n");

	}
}

void insertStudent() 
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    printf("Enter student details:\n");
    inputStudentDetails(newNode);

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
    
    Execution_Flag=1;

    printf("Student added successfully!\n");
}

void printStudentDetails(Node* DataNode)
{
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

void displayStudents() 
{
    if (head == NULL) 
	{
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

int count()
{
	int count = 0;
	if (head == NULL) 
	{
        return 0;
    }

    Node* current = head;
    while (current != NULL) {
        count=count+1;

        current = current->next;
    }
    
    return count;
}

Node* searchByName(char name[50]) {
	
	char saved_name[20];
    Node* current = head;

    while (current != NULL) {
    	strcpy(saved_name,current->student.name);
        if (strcmp(strlwr(saved_name), strlwr(name)) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void searchStudent() 
{
	int studentcount = count();
	if(studentcount>0)
	{
		Execution_Flag=1;
	    char searchName[50];
	    printf("Enter the student's name to search: ");
	    scanf("%s", searchName);
	
	    Node* friendNode = searchByName(searchName);
	
	    if (friendNode != NULL) {
	        printf("\nMatch found!\n");
	        printStudentDetails(friendNode);
	        printf("----------------------------------------------------\n");
	    } else {
	    	printf("----------------------------------------------------\n");
	        printf("No student found with the provided name.\n");
	        printf("----------------------------------------------------\n");
	    }
	}
	else
	{
		Execution_Flag=0;
		printf("----------------------------------------------------\n");
		printf("No Records to process this function\n");
		printf("----------------------------------------------------\n");

	}
}

void searchByMonth() 
{
	int studentcount = count();
	if(studentcount>0)
	{
		Execution_Flag=1;
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
	            printStudentDetails(current);
	            printf("----------------------------------------------------\n");
	
	            found = 1;
	        }
	        current = current->next;
	    }
	
	    if (!found) {
	    	printf("----------------------------------------------------\n");
	        printf("No student found with a birthday in the specified month.\n");
	    	printf("----------------------------------------------------\n");
	    }
	}
	else
	{
		Execution_Flag=0;
		printf("----------------------------------------------------\n");
		printf("No Records to process this function\n");
		printf("----------------------------------------------------\n");

	}
}

void searchByOccupation() 
{
	int studentcount = count();
	if(studentcount>0)
	{
		Execution_Flag=1;
	    char searchOccupation[50];
	    printf("Enter the occupation to search: ");
	    scanf("%s", searchOccupation);
		char saved_fathers_occupation[20];
		char saved_mothers_occupation[20];
	    Node* current = head;
	    int found = 0;
	
	    printf("Parents with the specified occupation:\n");
	    printf("----------------------------------------------------\n");
	    while (current != NULL) {
	    	strcpy(saved_fathers_occupation,current->student.fathersOccupation);
	    	strcpy(saved_mothers_occupation,current->student.mothersOccupation);
	        if (strcmp(strlwr(saved_fathers_occupation), strlwr(searchOccupation)) == 0 ||
	            strcmp(strlwr(saved_mothers_occupation), strlwr(searchOccupation)) == 0) {
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
	else
	{
		Execution_Flag=0;
		printf("----------------------------------------------------\n");
		printf("No Records to process this function\n");
		printf("----------------------------------------------------\n");

	}
}

void searchByBloodGroup() 
{
	int studentcount = count();
	if(studentcount>0)
	{
		Execution_Flag=1;
	    char searchBloodGroup[50];
	    printf("Enter the blood group to search: ");
	    scanf("%s", searchBloodGroup);
		char saved_blood_group[20];
	    Node* current = head;
	    int found = 0;
	
	    printf("Students with the specified Blood Group:\n");
	    printf("----------------------------------------------------\n");
	    while (current != NULL) {
	    	strcpy(saved_blood_group,current->student.bloodGroup);
	        if (strcmp(strlwr(saved_blood_group), strlwr(searchBloodGroup)) == 0) {
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
	else
	{
		Execution_Flag=0;
		printf("----------------------------------------------------\n");
		printf("No Records to process this function\n");
		printf("----------------------------------------------------\n");

	}
}

void searchByPhoneNumber() 
{
	int studentcount = count();
	if(studentcount>0)
	{
		Execution_Flag=1;
	    char searchPhoneNumber[50];
	    printf("Enter the contact number to search: ");
	    scanf("%s", searchPhoneNumber);
	
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
	else
	{
		Execution_Flag=0;
		printf("----------------------------------------------------\n");
		printf("No Records to process this function\n");
		printf("----------------------------------------------------\n");

	}
}


void searchByCompany() 
{
	int studentcount = count();
	if(studentcount>0)
	{
		Execution_Flag=1;
	    char searchCompany[50];
	    printf("Enter the company name to search: ");
	    scanf("%s", searchCompany);
		char saved_fathers_company[20];
		char saved_mothers_company[20];
	    Node* current = head;
	    int found = 0;
	
	    printf("Parents working for the specified company:\n");
	    printf("----------------------------------------------------\n");
	    while (current != NULL) {
	    	strcpy(saved_fathers_company,current->student.fathersCompany);
	    	strcpy(saved_mothers_company,current->student.mothersCompany);
	        if (strcmp(strlwr(saved_fathers_company), strlwr(searchCompany)) == 0 ||
	        	strcmp(strlwr(saved_mothers_company), strlwr(searchCompany)) == 0) 
			{
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
	else
	{
		Execution_Flag=0;
		printf("----------------------------------------------------\n");
		printf("No Records to process this function\n");
		printf("----------------------------------------------------\n");

	}
}

void editStudent() 
{
	int studentcount = count();
	if(studentcount>0)
	{
		Execution_Flag=1;
	    char searchName[50];
	    printf("Enter the student name to edit: ");
	    scanf("%s", searchName);
	
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
	else
	{
		Execution_Flag=0;
		printf("----------------------------------------------------\n");
		printf("No Records to process this function\n");
		printf("----------------------------------------------------\n");

	}
}

void deleteStudent() 
{
	int studentcount = count();
	if(studentcount>0)
	{
		Execution_Flag=1;
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
	    	printf("----------------------------------------------------\n");
	        printf("No student found with the provided name.\n");
	        printf("----------------------------------------------------\n");
	    }
	}
	else
	{
		Execution_Flag=0;
		printf("----------------------------------------------------\n");
		printf("No Records to process this function\n");
		printf("----------------------------------------------------\n");

	}
}

void deleteAll() 
{
	int studentcount = count();
	if(studentcount>0)
	{
	    Node* current = head;
	    while (current != NULL) {
	        Node* nextNode = current->next;
	        free(current);
	        current = nextNode;
	    }
	    head = NULL;
	    tail = NULL;
	    
		printf("----------------------------------------------------\n");
	    printf("All students and their records have been deleted.\n");
	    printf("----------------------------------------------------\n");
	}
	else
	{
		printf("----------------------------------------------------\n");
		printf("No Records to process this function\n");
		printf("----------------------------------------------------\n");

	}
	Execution_Flag=0;
}

void writeStudentDataToCSV(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open the file '%s' for writing\n", filename);
        return;
    }

    Node* current = head;

    while (current != NULL) {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
                current->student.name,
                current->student.academicYear,
                current->student.dob,
                current->student.bloodGroup,
                current->student.fathersName,
                current->student.fathersOccupation,
                current->student.fathersCompany,
                current->student.mothersName,
                current->student.mothersOccupation,
                current->student.mothersCompany,
                current->student.studentPhone,
                current->student.parentsPhone);

        current = current->next;
    }
    fclose(file);
}

int main() 
{
	char filename[20]="Students.csv";
	if (isCSVFileEmpty(filename)) {
        printf("No Records found from '%s'\n", filename);
        Execution_Flag=0;
    } else {
    	Read_CSV(filename);
        printf("Data Fetched from '%s'\n", filename);
        Execution_Flag=1;
    }
	
	Stack BirthdayNames;
	Queue UpcommingBirthdayNames;
    int choice;
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
        scanf("%d", &choice);

        switch (choice) {
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
            		printf("No students found in the list.\n");
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
        printf("\n");
    } while (choice != 14);

    return 0;
}

