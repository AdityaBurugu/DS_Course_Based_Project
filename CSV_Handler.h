//
// Created by aditya on 8/11/25.
//

#ifndef STUDENT_DATA_MANAGEMENT_SYSTEM_CSV_HANDLER_H
#define STUDENT_DATA_MANAGEMENT_SYSTEM_CSV_HANDLER_H

#define EXPECTED_FIELDS 12

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Student_Handler.h"
#include "Globals.h"
#include "Utilities.h"

bool isCSVFileEmpty(const char* filename);

/* Parse CSV line into fields[] using comma delimiter. This is a simple CSV (no quoted fields).
 * Returns number of fields parsed.
 */
int parse_csv_line(char *line, char *out_fields[], int max_fields);

/* Read CSV and populate linked list. Returns number of records read. */
int Read_CSV(const char *Filename);

/* Writing CSV back */
void writeStudentDataToCSV(const char* filename);
#endif //STUDENT_DATA_MANAGEMENT_SYSTEM_CSV_HANDLER_H