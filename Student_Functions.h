typedef struct 
{
    char name[50];
    char academicYear[10];
    char dob[20];
    char bloodGroup[10];
    char fathersName[50];
    char fathersOccupation[50];
    char fathersCompany[50];
    char mothersName[50];
    char mothersOccupation[50];
    char mothersCompany[50];
    char studentPhone[20];
    char parentsPhone[20];
} Student;

typedef struct Node
{
	struct Node* prev;
    Student student;
    struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;

void inputStudentDetails(Node* newNode);

void insertStudent();

void printStudentDetails(Node* DataNode);

void displayStudents();

int count();

Node* searchByName(char name[50]);

void searchStudent();

void searchByMonth();

void searchByOccupation();

void searchByBloodGroup();

void searchByPhoneNumber();

void searchByCompany();

void editStudent();

void deleteStudent();

void deleteAll();
