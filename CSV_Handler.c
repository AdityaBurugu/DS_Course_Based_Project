//
// Created by aditya on 8/11/25.
//

#include "CSV_Handler.h"

/* ---------- Input / CSV helpers ---------- */

/* Read a CSV filename; return true if file is empty or not accessible */
bool isCSVFileEmpty(const char* filename) {
    if (!filename) return true;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        // treat missing file as empty (no records) but print message
        // Caller expects Execution_Flag = false
        return true;
    }
    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return true;
    }
    long sz = ftell(file);
    fclose(file);
    return (sz <= 0);
}

/* Parse CSV line into fields[] using comma delimiter. This is a simple CSV (no quoted fields).
 * Returns number of fields parsed.
 */
int parse_csv_line(char *line, char *out_fields[], int max_fields) {
    int n = 0;
    char *token = strtok(line, ",");
    while (token != NULL && n < max_fields) {
        trim(token);
        out_fields[n++] = token;
        token = strtok(NULL, ",");
    }
    return n;
}

/* Read CSV and populate linked list. Returns number of records read. */
int Read_CSV(const char *Filename)
{
    if (!Filename) return 0;
    FILE *file = fopen(Filename, "r");
    if (file == NULL) {
        // no file or cannot open
        return 0;
    }

    int records = 0;
    while (fgets(linebuf, sizeof linebuf, file)) {
        // remove trailing newline
        linebuf[strcspn(linebuf, "\n")] = '\0';
        // make a copy because parse_csv_line uses strtok which modifies buffer
        char work[MAX_LINE_LENGTH];
        safe_strcpy(work, sizeof work, linebuf);

        int n = parse_csv_line(work, fields, MAX_FIELDS);
        if (n < EXPECTED_FIELDS) {
            // skip malformed lines
            continue;
        }

        Node *newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            fprintf(stderr, "Memory allocation failed\n");
            fclose(file);
            return records;
        }

        // Use safe copies
        safe_strcpy(newNode->student.name, sizeof newNode->student.name, fields[0]);
        safe_strcpy(newNode->student.academicYear, sizeof newNode->student.academicYear, fields[1]);
        safe_strcpy(newNode->student.dob, sizeof newNode->student.dob, fields[2]);
        safe_strcpy(newNode->student.bloodGroup, sizeof newNode->student.bloodGroup, fields[3]);
        safe_strcpy(newNode->student.fathersName, sizeof newNode->student.fathersName, fields[4]);
        safe_strcpy(newNode->student.fathersOccupation, sizeof newNode->student.fathersOccupation, fields[5]);
        safe_strcpy(newNode->student.fathersCompany, sizeof newNode->student.fathersCompany, fields[6]);
        safe_strcpy(newNode->student.mothersName, sizeof newNode->student.mothersName, fields[7]);
        safe_strcpy(newNode->student.mothersOccupation, sizeof newNode->student.mothersOccupation, fields[8]);
        safe_strcpy(newNode->student.mothersCompany, sizeof newNode->student.mothersCompany, fields[9]);
        safe_strcpy(newNode->student.studentPhone, sizeof newNode->student.studentPhone, fields[10]);
        safe_strcpy(newNode->student.parentsPhone, sizeof newNode->student.parentsPhone, fields[11]);

        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        records++;
    }

    fclose(file);
    return records;
}

/* Writing CSV back */
void writeStudentDataToCSV(const char* filename) {
    if (!filename) return;
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