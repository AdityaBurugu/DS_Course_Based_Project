//
// Created by aditya on 8/12/25.
//

#include "Birthday_Event_Handler.h"

/* ---------- Birthday related functions (use your Stack/Queue APIs) ---------- */

void Get_Birthday_Names(Stack *Birthday_Names ,Queue *Upcomming_Birthdays)
{
    int current_day, current_month;
    int birthDay, birthMonth, birthYear;

    initializeStack(Birthday_Names);
    initializeQueue(Upcomming_Birthdays);

    int studentcount = count_nodes();
    if (studentcount <= 0) return;

    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);
    current_day = current_time->tm_mday;
    current_month = current_time->tm_mon + 1;

    Node* current = head;
    while (current != NULL) {
        if (sscanf(current->student.dob, "%d/%d/%d", &birthDay, &birthMonth, &birthYear) >= 2) {
            if ((current_day == birthDay) && (current_month == birthMonth)) {
                push(Birthday_Names, current->student.name);
            } else if ((birthDay > current_day) && (current_month == birthMonth)) {
                enqueue(Upcomming_Birthdays, current->student.name);
            }
        }
        current = current->next;
    }
}

int Get_Age(const char *Name)
{
    if (!Name) return 0;
    int current_year;
    int birthDay = 0, birthMonth = 0, birthYear = 0;

    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);
    current_year = current_time->tm_year + 1900;

    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->student.name, Name) == 0) {
            if (sscanf(current->student.dob, "%d/%d/%d", &birthDay, &birthMonth, &birthYear) == 3) {
                return current_year - birthYear;
            }
        }
        current = current->next;
    }
    return 0;
}

void Get_DOB(const char *Name, char DOB_out[DOB_SZ])
{
    if (!Name || !DOB_out) return;
    int birthDay = 0, birthMonth = 0, birthYear = 0;

    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);
    int current_year = current_time->tm_year + 1900;

    Node* current = head;
    DOB_out[0] = '\0';
    while (current != NULL) {
        if (strcmp(current->student.name, Name) == 0) {
            if (sscanf(current->student.dob, "%d/%d/%d", &birthDay, &birthMonth, &birthYear) >= 2) {
                snprintf(DOB_out, DOB_SZ, "%02d/%02d/%04d", birthDay, birthMonth, current_year);
                return;
            }
        }
        current = current->next;
    }
}

/* Generates notifications using Stack and Queue APIs */
void Generate_Birthday_Notification(Stack *Birthday_Names, Queue *Upcomming_Birthday_Names)
{
    if (!Execution_Flag) {
        printf("----------------------------------------------------\n");
        printf("No Records to process this function\n");
        printf("----------------------------------------------------\n");
        return;
    }

    Get_Birthday_Names(Birthday_Names, Upcomming_Birthday_Names);

    int count_today = Birthday_Names->top + 1;
    printf("----------------------------------------------------\n");
    printf("Today's Events\n");
    printf("----------------------------------------------------\n");
    if (count_today <= 0) {
        printf("No Birthday's Today.\n");
    } else {
        for (int i = 0; i < count_today; ++i) {
            char popped[NAME_SZ];
            safe_strcpy(popped, sizeof popped, pop(Birthday_Names));
            printf("%s is celebrating %d birthday\n", popped, Get_Age(popped));
        }
    }
    printf("----------------------------------------------------\n");

    int count_up = Upcomming_Birthday_Names->rear + 1;
    printf("Upcomming Events\n");
    printf("----------------------------------------------------\n");
    if (count_up <= 0) {
        printf("No Upcomming Events.\n");
    } else {
        for (int i = 0; i < count_up; ++i) {
            char dequeued[NAME_SZ];
            char DOB[DOB_SZ];
            safe_strcpy(dequeued, sizeof dequeued, dequeue(Upcomming_Birthday_Names));
            Get_DOB(dequeued, DOB);
            printf("%s is celebrating their birthday on %s\n", dequeued, DOB);
        }
    }
    printf("----------------------------------------------------\n");
}