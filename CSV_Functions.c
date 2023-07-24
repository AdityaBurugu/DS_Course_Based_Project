#include "CSV_Functions.h"


int isCSVFileEmpty(const char* filename) 
{
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

        while (token != NULL && num_fields < MAX_FIELDS) 
		{
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

		    if (head == NULL) 
			{
		        head = newNode;
		        tail = newNode;
		    } 
			else 
			{
		        tail->next = newNode;
		        newNode->prev = tail;
		        tail = newNode;
		    }
    }
    // Close the file
    fclose(file);
}

void writeStudentDataToCSV(const char* filename) 
{
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open the file '%s' for writing\n", filename);
        return;
    }

    Node* current = head;

    while (current != NULL) {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",
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

