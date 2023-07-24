
#include "Birthday_Functions.h"

void Get_Birthday_Names(Stack *Birthday_Names ,Queue *Upcomming_Birthdays)
{
	int current_day,current_month,studentcount;
	int birthDay,birthMonth;
	struct tm *current_time;
	int target_day,target_month;
	
	int duration = 14;
	
	initializeStack(Birthday_Names);
	initializeQueue(Upcomming_Birthdays);
		
	studentcount = count();
	
	if(studentcount>0)
	{
		time_t t = time(NULL);
		current_time = localtime(&t);
		
		//Fetching Current date
		current_day=current_time->tm_mday;
		
		//Fetching Current month
		current_month = current_time->tm_mon + 1;
		
		target_month = current_month;
    	target_day = current_day + duration;
    	
    	if (target_day > 31) 
		{
	        target_day -= 31;
	        target_month++;
	    }
	
	    if (target_month > 12) 
		{
	        target_month -= 12;
	    }
		
	    Node* current = head;
	    
	    while (current != NULL) {
	        sscanf(current->student.dob, "%d/%d", &birthDay, &birthMonth);
	        
	        if((current_day == birthDay) && (current_month == birthMonth)) 
			{
				push(Birthday_Names,current->student.name);
	        }
	        
	        if (birthMonth == target_month && birthDay <= target_day) 
			{
	            enqueue(Upcomming_Birthdays,current->student.name);
	        }
	        
	        current = current->next;
	    }	
	}
}


int Get_Age(char Name[20])
{
	int current_year;
	int birthDay, birthMonth, birthYear;
	struct tm *current_time;
	
	time_t t = time(NULL);
	current_time = localtime(&t);
	
	//Fetching Current Year
	current_year = current_time->tm_year + 1900;
	
    Node* current = head;
    
    while (current != NULL) {
        char student_name[20];
        strcpy(student_name,Name);
        
        
        if (strcmp(student_name,current->student.name)==0)
		{
			sscanf(current->student.dob, "%d/%d/%d", &birthDay, &birthMonth, &birthYear);
            return current_year-birthYear;
        }
        current = current->next;
    }
	
	return 0;
}

void Get_DOB(char Name[20],char DOB[20])
{
	int current_year;
	int birthDay, birthMonth, birthYear;
	struct tm *current_time;
	
	time_t t = time(NULL);
	current_time = localtime(&t);
	
	current_year = current_time->tm_year + 1900;
	
    Node* current = head;
    
    while (current != NULL) {
        char student_name[20];
        strcpy(student_name,Name);
        
        
        if (strcmp(student_name,current->student.name)==0)
		{
			sscanf(current->student.dob, "%d/%d/%d", &birthDay, &birthMonth, &birthYear);
    		sprintf(DOB, "%02d/%02d/%04d", birthDay, birthMonth, current_year);
        }
        current = current->next;
    }
}

void getLast_Value(int value, char suffix[20])
{
	int last_value = value%10;
	
	switch(last_value)
	{
		case 1:
			strcpy(suffix,"st");
			break;
		case 2:
			strcpy(suffix,"nd");
			break;
		case 3:
			strcpy(suffix,"rd");
			break;	
		case 0:			
		case 4:			
		case 5:			
		case 6:			
		case 7:			
		case 8:			
		case 9:	
			strcpy(suffix,"th");
			break;		
	}
}


void Generate_Birthday_Notification(Stack *Birthday_Names, Queue *Upcomming_Birthday_Names)
{
	int i;
	int count=0;
	
	char popped[20];
	char dequeued[20];
	
	char DOB[20];
	
	int age;
	
	char suffix[20];
	
	if(Execution_Flag==1)
	{

		Get_Birthday_Names(Birthday_Names, Upcomming_Birthday_Names);
		
		count = Birthday_Names->top+1;
		printf("----------------------------------------------------\n");
		printf("Today's Events\n");
		printf("----------------------------------------------------\n");
		
		for(i=0;i<count;i++)
		{
			strcpy(popped,pop(Birthday_Names));
			age = Get_Age(popped);
			getLast_Value(age,suffix);
			printf("%s is celebrating %d%s birthday\n",popped,age,suffix);
		}
		if(count==0)
			printf("No Birthday's Today.\n");
				
		printf("----------------------------------------------------\n");
	
	
		printf("Upcomming Events\n");
		printf("----------------------------------------------------\n");
		
		count = Upcomming_Birthday_Names->rear+1;
		for(i=0;i<count;i++)
		{	
			strcpy(dequeued,dequeue(Upcomming_Birthday_Names));
			Get_DOB(dequeued,DOB);
			printf("%s is celebrating their birthday on %s\n",dequeued,DOB);
		}
		if(count==0)
			printf("No Upcomming Events.\n");
				
		printf("----------------------------------------------------\n");
	}
	else
	{
		printf("----------------------------------------------------\n");
		printf("No Records to process this function\n");
		printf("----------------------------------------------------\n");

	}
}
