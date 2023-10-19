#include "sevenFunction.h"

//func4
int deleteClient(char* name_delete, struct Client *client, int k)
{
	printf("Enter name to delete:");
    scanf("%s", name_delete);

    while (getchar() != '\n'); // after use scanf, erase '\n'
    
	FILE* file;
    file = fopen("current_time.txt", "w");

    if (file == NULL)
    {
        printf("can't open file.\n");
        fclose(file);
        return 1;
    }

	int i;
	int j;
	int delete_months;
	int samecount = 0;


	//check name is correct
	for(i =0 ; i < k; i++)
	{
		if(strcmp(client[i].name, name_delete) == 0 && client[i].delete != 1)
		{
			samecount++;
		}
	}

	if(samecount != 1)
	{
		printf("name is not in list\n");
		return 2;
	}
	//
	for (i = 0; i < k; i++)			
    {
        if (strcmp(client[i].name, name_delete) == 0 && client[i].delete != 1)		//recent plus2
        {
			// set delete[i] = 1
            client[i].delete = 1;
			samecount++;
		}
		
		if(client[i].delete != 1)
		{
			fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);
		}
	}
    
	fclose(file); 
	k--;		// giver's information delete
    return 0;

}

