#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "CBP-1 BirthDay_Notification.h"


Student students[100];
int main() {
	
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
        for (index = 0; index < num_fields; index++) 
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
    
    
    for(index=0;index<student_count;index++)
    {    	
		birth_day=students[index].date;
		birth_month=students[index].month;
    	

		if ((current_day == birth_day))
		{
			if((current_month == birth_month))
        		printf("Happy birthday %s!\n",students[index].name);
        		flag=1;
    	}
	}
	
	if(flag==0) 
	{
        printf("No birthday today.\n");
    }

    return 0;
}
