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
	
	current_day=current_time->tm_mday;
	
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

        // Process the fields (e.g., print them)
        for (i = 0; i < num_fields; i++) {
            //printf("Field %d: %s\n", i + 1, fields[i]);
            strcpy(students[count].name,fields[0]);
            students[count].date=atoi(fields[1]);
            students[count].month=atoi(fields[2]);
        }
        printf("\n");
        count++;
        
    }
    // Close the file
    fclose(file);
    
    
    for(i=0;i<count;i++)
    {
    	printf("%s\n",students[i].name);
    	
		birth_day=students[i].date;
		birth_month=students[i].month;
    	

		if ((current_day == birth_day))
		{
			if((current_month == birth_month))
        		printf("Happy birthday %s!\n",students[i].name);
    	}
	 	else 
		{
        	printf("No birthday today.\n");
    	}

	}

    return 0;
}
