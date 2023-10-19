#include "sevenFunction.h"

//func3
int handover(char* name_giver, char* name_receiver, struct Client *client, int k)
{
	printf("Enter giver name:");
    scanf("%s", name_giver);

	printf("Enter receiver name:");
    scanf("%s", name_receiver);

    while (getchar() != '\n'); // after use scanf, erase '\n'
    

	int i;
	int samecount_receiver = 0;
	for(i =0 ; i < k; i++)
	{
		if(strcmp(client[i].name, name_receiver) == 0 && client[i].delete != 1)
		{
			samecount_receiver++;
		}
	}
	//check receiver is correct
	if(samecount_receiver != 1)
	{
		printf("receiver is not in list\n");
		return 2;
	}

	FILE* file;
    file = fopen("current_time.txt", "w");

    if (file == NULL)
    {
        printf("can't open file.\n");
        fclose(file);
        return 1;
    }

	int delete_months;
	int samecount_giver = 0;
	//
    for (i = 0; i < k; i++)			
    {
        if (strcmp(client[i].name, name_giver) == 0 && client[i].delete != 1)
        {
			// set giver's delete[i] = 1
            client[i].delete = 1;
    		// set giver's month 
			delete_months = client[i].months;
			printf("delete_months is %d\n", delete_months);
			samecount_giver++;
		}
	}

	for(i = 0; i < k; i++)			// func1 third, k =3
	{
    	if (strcmp(client[i].name, name_receiver) == 0 && client[i].delete != 1 && samecount_giver == 1)		//recent plus 1(need?)
		{	
			// get months
			client[i].months += delete_months;
			// get end_month
			client[i].end_month += delete_months;

			if(client[i].end_month > 12)
			{
				client[i].end_month -= 12;
				client[i].end_year += 1;
			}
			// get remainingdays
    		client[i].remainingDays = calculateRemaingDays(client, i);
			samecount_receiver++;
		}

		// fprintf all	( only delete[i] != 1)
        if(client[i].delete != 1)
		{
			fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);
		}
	}
	
	// check giver is correct
	if(samecount_giver ==0)
	{
		printf("giver is not in list\n"); 
	}

    fclose(file); 
	k--;		// giver's information delete
    return 0;

}
