//
// Created by aditya on 8/12/25.
//

#ifndef STUDENT_DATA_MANAGEMENT_SYSTEM_BIRTHDAY_EVENT_HANDLER_H
#define STUDENT_DATA_MANAGEMENT_SYSTEM_BIRTHDAY_EVENT_HANDLER_H

#include <time.h>

#include "Queue.h"
#include "Stack.h"
#include "Student_Handler.h"

/* ---------- Birthday related functions (use your Stack/Queue APIs) ---------- */

void Get_Birthday_Names(Stack *Birthday_Names ,Queue *Upcomming_Birthdays);

int Get_Age(const char *Name);

void Get_DOB(const char *Name, char DOB_out[DOB_SZ]);
/* Generates notifications using Stack and Queue APIs */
void Generate_Birthday_Notification(Stack *Birthday_Names, Queue *Upcomming_Birthday_Names);

#endif //STUDENT_DATA_MANAGEMENT_SYSTEM_BIRTHDAY_EVENT_HANDLER_H