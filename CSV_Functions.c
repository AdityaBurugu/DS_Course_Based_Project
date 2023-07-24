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


int Read_CSV(const char* Filename) 
{
    FILE* file;

    // Open the CSV file for reading
    file = fopen(Filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        // Allocate memory for a new node
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            fclose(file);
            return 1;
        }

        // Split the line into fields using strtok
        char* token = strtok(line, ",");
        num_fields = 0;
        while (token != NULL && num_fields < MAX_FIELDS) 
		{
            switch (num_fields) 
			{
                case 0:
                    strcpy(newNode->student.name, token);
                    break;
                case 1:
                    strcpy(newNode->student.academicYear, token);
                    break;
                case 2:
                    strcpy(newNode->student.dob, token);
                    break;
                case 3:
                    strcpy(newNode->student.bloodGroup, token);
                    break;
                case 4:
                    strcpy(newNode->student.fathersName, token);
                    break;
                case 5:
                    strcpy(newNode->student.fathersOccupation, token);
                    break;
                case 6:
                    strcpy(newNode->student.fathersCompany, token);
                    break;
                case 7:
                    strcpy(newNode->student.mothersName, token);
                    break;
                case 8:
                    strcpy(newNode->student.mothersOccupation, token);
                    break;
                case 9:
                    strcpy(newNode->student.mothersCompany, token);
                    break;
                case 10:
                    strcpy(newNode->student.studentPhone, token);
                    break;
                case 11:
                    strcpy(newNode->student.parentsPhone, token);
                    break;
                default:
                    break;
            }

            token = strtok(NULL, ",");
            num_fields++;
        }

        // Free the memory allocated by strtok for the line
        free(token);

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

    return 0;
}

void writeStudentDataToCSV(const char* filename) 
{
    FILE* file = fopen(filename, "w");
    if (file == NULL) 
	{
        printf("Error: Unable to open the file '%s' for writing\n", filename);
        return;
    }

    Node* current = head;

    // Check if the linked list is empty
    if (current == NULL) 
	{
        fclose(file);
        return;
    }

    while (current != NULL) 
	{
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


