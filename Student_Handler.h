//
// Created by aditya on 8/11/25.
//

#ifndef STUDENT_DATA_MANAGEMENT_SYSTEM_STUDENT_HANDLER_H
#define STUDENT_DATA_MANAGEMENT_SYSTEM_STUDENT_HANDLER_H

/* ---------- Configuration / sizes ---------- */
#define NAME_SZ 50
#define YEAR_SZ 10
#define DOB_SZ 20
#define BG_SZ 10
#define OCC_SZ 50
#define COMPANY_SZ 50
#define PHONE_SZ 20

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Globals.h"
#include "Utilities.h"

/* ---------- Types ---------- */
typedef struct
{
    char name[NAME_SZ];
    char academicYear[YEAR_SZ];
    char dob[DOB_SZ];
    char bloodGroup[BG_SZ];
    char fathersName[NAME_SZ];
    char fathersOccupation[OCC_SZ];
    char fathersCompany[COMPANY_SZ];
    char mothersName[NAME_SZ];
    char mothersOccupation[OCC_SZ];
    char mothersCompany[COMPANY_SZ];
    char studentPhone[PHONE_SZ];
    char parentsPhone[PHONE_SZ];
} Student;

typedef struct Node
{
    struct Node* prev;
    Student student;
    struct Node* next;
} Node;
static Node *head = NULL;
static Node *tail = NULL;

void inputStudentDetails(Node* newNode);

/* Count nodes */
int count_nodes(void);

/* Case-insensitive search by name */
Node* searchByName(const char *name);

/* Print functions */
void printStudentDetails(const Node* DataNode);

void displayStudents(void);

/* Insert, edit, delete */

void insertStudent(void);

void editStudent(void);

void deleteStudent(void);

void deleteAll(void);
/* ---------- Search helpers ---------- */

void searchStudent(void);

void searchByMonth(void);

void searchByBloodGroup(void);

void searchByPhoneNumber(void);

void searchByOccupation(void);

void searchByCompany(void);

#endif //STUDENT_DATA_MANAGEMENT_SYSTEM_STUDENT_HANDLER_H