#include "sevenFunction.h"

//func2
int addMonths(char* name_func2, int months_func2, struct Client* client, int k)
{
    printf("Enter name:");
    scanf("%s", name_func2);

    printf("Enter months:");
    scanf("%d", &months_func2);

    while (getchar() != '\n'); // after use scanf, erase '\n'

    //test
    printf("%s\n", name_func2);
    printf("%d\n", months_func2);


    //file open and close
    FILE* file;

    file = fopen("current_time.txt", "w");

    if (file == NULL)
    {
        printf("can't open file.\n");
        fclose(file);
        return 1;
    }

    //검사 
    int i;
	int samecount = 0;
    for (i = 0; i < k; i++)		// <= ??
    {
        if (strcmp(client[i].name, name_func2) == 0 && client[i].delete != 1)
        {
			//get months
			client[i].months += months_func2;

			// update end_month
            client[i].end_month += months_func2;
    	
			// get end_month	
			if (client[i].end_month > 12)
			{
				client[i].end_year += 1;
				client[i].end_month -= 12;
			}       

            // get remainingdays
    		client[i].remainingDays = calculateRemaingDays(client, i);

			// here
            fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);
 		
			//samecount plus
			samecount++;
		}

        else if (client[i].delete != 1)
        {
        	fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);
        }			
    }

	// when use func2 and no name in list.
	if(samecount ==0)
	{
		printf("there isn't name in list"); 
	}
    fclose(file);
                  
    return 0;
}
