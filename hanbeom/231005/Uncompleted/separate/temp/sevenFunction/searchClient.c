#include "sevenFunction.h"

int searchClient(char* name_search, struct Client *client, int k)
{
	printf("Enter name to search:");
    scanf("%s", name_search);

    while (getchar() != '\n'); // after use scanf, erase '\n'
    
	int i;
    for (i = 0; i < k; i++)			
    {
        if (strcmp(client[i].name, name_search) == 0 && client[i].delete != 1)
        {
			printf("%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);	
		}
		else if (strcmp(client[i].name, name_search) == 0 && client[i].delete == 1)
		{
			printf("you input deleted name\n");
		}
	}
    return 0;

}
