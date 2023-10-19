#include "sevenFunction.h"

int searchList(struct Client *client, int k)
{
	
	int i;
    for (i = 0; i < k; i++)			
    {
        if(client[i].delete != 1)
		{
		printf("%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);	
		}
	}
    return 0;
}
