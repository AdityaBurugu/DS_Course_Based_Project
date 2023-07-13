#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 10


typedef struct {
    char name[50];
	int date;
	int month;
}Student;

char line[MAX_LINE_LENGTH];
char *fields[MAX_FIELDS];
int num_fields = 0;
int index;
int flag=0;
int student_count=0;
int birth_day,birth_month;

int current_day;
int current_month;

struct tm *current_time;
