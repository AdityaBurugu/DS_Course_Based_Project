//
// Created by aditya on 8/11/25.
//

#include "Utilities.h"

/* ---------- Utility functions ---------- */

/* Trim leading/trailing whitespace in-place */
void trim(char *s) {
    if (!s) return;
    // Trim leading
    char *start = s;
    while (isspace((unsigned char)*start)) start++;
    if (start != s) memmove(s, start, strlen(start) + 1);

    // Trim trailing
    size_t len = strlen(s);
    while (len > 0 && isspace((unsigned char)s[len - 1])) {
        s[len - 1] = '\0';
        len--;
    }
}

/* Read a line from stdin into buf (size bytes), trimming newline; returns 0 on success, nonzero on EOF */
int read_line_stdin(char *buf, size_t size) {
    if (!fgets(buf, (int)size, stdin)) return -1;
    buf[strcspn(buf, "\n")] = '\0';
    return 0;
}

/* Case-insensitive lowercase in-place */
void str_to_lower_inplace(char *s) {
    if (!s) return;
    for (; *s; ++s) *s = (char)tolower((unsigned char)*s);
}

/* Safe copy into destination with null-termination */
void safe_strcpy(char *dst, size_t dst_size, const char *src) {
    if (dst_size == 0) return;
    if (!src) {
        dst[0] = '\0';
        return;
    }
    // use snprintf to ensure null-termination
    snprintf(dst, dst_size, "%s", src);
}