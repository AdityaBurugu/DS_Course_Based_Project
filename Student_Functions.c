#include "Student_Functions.h"

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

Node* searchByName(char name[50]) 
{
	
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

