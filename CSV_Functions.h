#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 12

char line[MAX_LINE_LENGTH];

int num_fields;

int isCSVFileEmpty(const char* filename);

int Read_CSV(const char* Filename);

void writeStudentDataToCSV(const char* filename);
