//
// Created by aditya on 8/11/25.
//

#ifndef STUDENT_DATA_MANAGEMENT_SYSTEM_UTILITIES_H
#define STUDENT_DATA_MANAGEMENT_SYSTEM_UTILITIES_H

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void trim(char *s);

/* Read a line from stdin into buf (size bytes), trimming newline; returns 0 on success, nonzero on EOF */
int read_line_stdin(char *buf, size_t size);

/* Case-insensitive lowercase in-place */
void str_to_lower_inplace(char *s);

/* Safe copy into destination with null-termination */
void safe_strcpy(char *dst, size_t dst_size, const char *src);

#endif //STUDENT_DATA_MANAGEMENT_SYSTEM_UTILITIES_H