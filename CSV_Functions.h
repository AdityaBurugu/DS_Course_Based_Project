#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 20

char line[MAX_LINE_LENGTH];
char *fields[MAX_FIELDS];
int num_fields = 0;

int isCSVFileEmpty(const char* filename);

int Read_CSV(char Filename[50]);

void writeStudentDataToCSV(const char* filename);
