#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "CBP-1 BirthDay_Notification.h"

Student students[100];

int main() 
{

	
    FILE *file;
    
    time_t t = time(NULL);
	current_time = localtime(&t);
	
	//Fetching Current date
	current_day=current_time->tm_mday;
		
	//Fetching Current month
	current_month = current_time->tm_mon + 1;
	

    // Open the CSV file for reading
    file = fopen("Dates.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Read and process each line of the CSV file
    while (fgets(line, sizeof(line), file)) 
	{
        // Split the line into fields
        char *token = strtok(line, ",");
        num_fields = 0;

        while (token != NULL && num_fields < MAX_FIELDS) {
            fields[num_fields++] = token;
            token = strtok(NULL, ",");
        }

        // Process the fields (e.g., copy them)
        for (index_val = 0; index_val < num_fields; index_val++) 
		{
            strcpy(students[student_count].name,fields[0]);
            students[student_count].date=atoi(fields[1]);
            students[student_count].month=atoi(fields[2]);
        }
        printf("\n");
        student_count++;
        
    }
    // Close the file
    fclose(file);
    
/////////////////////////////////////////////////////////////////////////////
  
    printf("Today's Events\n");
    count_birthday_match=0;
    for(index_val=0;index_val<student_count;index_val++)
    {    	
		birth_day=students[index_val].date;
		birth_month=students[index_val].month;
    	
		if((current_day == birth_day) && (current_month == birth_month))
		{
    		//printf("Happy birthday %s!\n",students[index_val].name);
    		sprintf(list_birthday_names[count_birthday_match],"%s",students[index_val].name);
    		count_birthday_match=count_birthday_match+1;
    		flag=1;
    	}
	}
			
	if(flag==0) 
	{
        printf("No Birthday's Today.\n");
    }
    else
    {
    	for(index_val=0;index_val<count_birthday_match-1;index_val++)
    	{
    		printf("%s,",list_birthday_names[index_val]);
		}
		if(count_birthday_match==1)
			printf("%s is Celebrating their Birthday",list_birthday_names[index_val]);
		else
			printf("%s are Celebrating their Birthdays",list_birthday_names[index_val]);
	}
	
	//count_birthday_match_in_month=0;
	printf("\nUpcomming Birthdays in this Month\n");
	
	for(index_val=0;index_val<student_count;index_val++)
    {    	
		birth_day=students[index_val].date;
		birth_month=students[index_val].month;
    	
		if((current_day < birth_day) && (current_month == birth_month))
		{
    		printf("%s is Celebrating their birthday on %d/%d\n",students[index_val].name,students[index_val].date,students[index_val].month);
    		flag=1;
    	}
	}
			
	if(flag==0) 
	{
        printf("No Birthday's Today.\n");
    }

    return 0;
}
