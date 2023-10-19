#include "sevenFunction.h"

int updateDays(struct Client *client, int k)
{	
	
	FILE* file;
    file = fopen("current_time.txt", "w");

    if (file == NULL)
    {
        printf("can't open file.\n");
        fclose(file);
        return 1;
    }
	
	
	int i;
    for (i = 0; i < k; i++)			
    {
	    // get remainingdays
    	client[k].remainingDays = updateRemaingDays(client, k);

        if(client[i].delete != 1)
		{
		//cmd
		printf("%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);	
		
		//txt
		fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);
		}
	}
	fclose(file);

    return 0;
}
