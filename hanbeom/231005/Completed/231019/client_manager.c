#include "client_manager.h"

int calculateRemaingDays(struct Client* client, int k)
{
    struct tm startTime, endTime;
	time_t startTimestamp, endTimestamp;

	startTime.tm_year = client[k].start_year - 1900;
	startTime.tm_mon = client[k].start_month - 1;
	startTime.tm_mday = client[k].start_day;
	startTime.tm_hour = client[k].start_hour;
	startTime.tm_min = client[k].start_min;
	startTime.tm_sec = 0;
	startTime.tm_isdst = -1;

	endTime.tm_year = client[k].end_year - 1900;
	endTime.tm_mon = client[k].end_month - 1;
	endTime.tm_mday = client[k].end_day;
	endTime.tm_hour = client[k].end_hour;
	endTime.tm_min = client[k].end_min;
	endTime.tm_sec = 0;
	endTime.tm_isdst = -1;

	startTimestamp = mktime(&startTime);
	endTimestamp = mktime(&endTime);

	if (startTimestamp == -1 || endTimestamp == -1)
	{
		printf("it is error");
		return -1;
	}
	
	double diffInSeconds = difftime(endTimestamp, startTimestamp);
	int diffInDays = (int)(diffInSeconds / (60 * 60 * 24));

	return diffInDays;
}

int updateRemaingDays(struct Client* client, int k)
{
    time_t currentTime;			
    time(&currentTime);			
    struct tm* timeInfo;			
    timeInfo = localtime(&currentTime); 

	struct tm startTime, endTime;
	time_t startTimestamp, endTimestamp;

	startTime.tm_year = timeInfo->tm_year;
	startTime.tm_mon = timeInfo->tm_mon;
	startTime.tm_mday = timeInfo->tm_mday;
	startTime.tm_hour = timeInfo->tm_hour;
	startTime.tm_min = timeInfo->tm_min;
	startTime.tm_sec = 0;
	startTime.tm_isdst = -1;

	endTime.tm_year = client[k].end_year - 1900;
	endTime.tm_mon = client[k].end_month - 1;
	endTime.tm_mday = client[k].end_day;
	endTime.tm_hour = client[k].end_hour;
	endTime.tm_min = client[k].end_min;
	endTime.tm_sec = 0;
	endTime.tm_isdst = -1;

	startTimestamp = mktime(&startTime);
	endTimestamp = mktime(&endTime);

	if (startTimestamp == -1 || endTimestamp == -1)
	{
		printf("it is error");
		return -1;
	}
	
	double diffInSeconds = difftime(endTimestamp, startTimestamp);
	int diffInDays = (int)(diffInSeconds / (60 * 60 * 24));

	return diffInDays;	
}

void calculateEndTime(struct Client* client, int k, struct tm* timeInfo)
{
	client[k].end_year = timeInfo->tm_year + 1900;
	client[k].end_month = timeInfo->tm_mon + 1 + (client[k].months);

	if (client[k].end_month > 12)
	{
		client[k].end_year += 1;
		client[k].end_month -= 12;
	}

	client[k].end_day = timeInfo->tm_mday;
	client[k].end_hour = timeInfo->tm_hour;
	client[k].end_min = timeInfo->tm_min;
}

int ADD_CLIENT(struct Client* client, int k)
{
    printf("Enter name:");
    scanf("%s", client[k].name);

    printf("Enter age:");
    scanf("%d", &client[k].age);

    printf("Enter months:");
    scanf("%d", &client[k].months);

    while (getchar() != '\n'); 

    int i;
    for (i = 0; i < k; i++)
    {
        if (strcmp(client[i].name, client[k].name) == 0 && client[i].delete != 1)
        {
            printf("중복이니 다시입력\n");
			client[k].delete = 1;		
            return 1;
        }
    }

    time_t currentTime;			
    time(&currentTime);			
    struct tm* timeInfo;			
    timeInfo = localtime(&currentTime); 
    
    char line[100]; 
    char dateTimeString[100];
    FILE* file;

    file = fopen("current_time.txt", "a");

    if (file == NULL)
    {
        printf("can't open file.\n");
        fclose(file);
        return 1;
    }
	
    client[k].start_year = timeInfo->tm_year + 1900;
	
	client[k].start_month = timeInfo->tm_mon +1;

	client[k].start_day = timeInfo->tm_mday;

	client[k].start_hour = timeInfo->tm_hour;

	client[k].start_min = timeInfo->tm_min;

	calculateEndTime(client, k, timeInfo);

    client[k].remainingDays = calculateRemaingDays(client, k);
		
    fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[k].name, client[k].age, client[k].months, client[k].start_year, client[k].start_month, client[k].start_day, client[k].start_hour, client[k].start_min, client[k].end_year, client[k].end_month, client[k].end_day, client[k].end_hour, client[k].end_min, client[k].remainingDays);
    fclose(file);
    return 0;
}

int UPDATE_MONTHS(char* name_func2, int months_func2, struct Client* client, int k)
{
    printf("Enter name:");
    scanf("%s", name_func2);

    printf("Enter months:");
    scanf("%d", &months_func2);

    while (getchar() != '\n'); 

    printf("%s\n", name_func2);
    printf("%d\n", months_func2);

    FILE* file;

    file = fopen("current_time.txt", "w");

    if (file == NULL)
    {
        printf("can't open file.\n");
        fclose(file);
        return 1;
    }

    int i;
	int samecount = 0;
    for (i = 0; i < k; i++)		
    {
        if (strcmp(client[i].name, name_func2) == 0 && client[i].delete != 1)
        {
			client[i].months += months_func2;

            client[i].end_month += months_func2;
    	
			if (client[i].end_month > 12)
			{
				client[i].end_year += 1;
				client[i].end_month -= 12;
			}       

    		client[i].remainingDays = calculateRemaingDays(client, i);

            fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);
 		
			samecount++;
		}

        else if (client[i].delete != 1)
        {
        	fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);
        }			
    }

	if(samecount ==0)
	{
		printf("there isn't name in list"); 
	}
    fclose(file);
                  
    return 0;
}

int TRANSFER_MONTHS(char* name_giver, char* name_receiver, struct Client* client, int k)
{
	printf("Enter giver name:");
    scanf("%s", name_giver);

	printf("Enter receiver name:");
    scanf("%s", name_receiver);

    while (getchar() != '\n'); 
    

	int i;
	int samecount_receiver = 0;
	for(i =0 ; i < k; i++)
	{
		if(strcmp(client[i].name, name_receiver) == 0 && client[i].delete != 1)
		{
			samecount_receiver++;
		}
	}
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
    
	for (i = 0; i < k; i++)			
    {
        if (strcmp(client[i].name, name_giver) == 0 && client[i].delete != 1)
        {
            client[i].delete = 1;
			delete_months = client[i].months;
			printf("delete_months is %d\n", delete_months);
			samecount_giver++;
		}
	}

	for(i = 0; i < k; i++)			
	{
    	if (strcmp(client[i].name, name_receiver) == 0 && client[i].delete != 1 && samecount_giver == 1)		
		{	
			client[i].months += delete_months;
			client[i].end_month += delete_months;

			if(client[i].end_month > 12)
			{
				client[i].end_month -= 12;
				client[i].end_year += 1;
			}
    		client[i].remainingDays = calculateRemaingDays(client, i);
			samecount_receiver++;
		}

        if(client[i].delete != 1)
		{
			fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);
		}
	}
	
	if(samecount_giver ==0)
	{
		printf("giver is not in list\n"); 
	}

    fclose(file); 
	k--;		
    return 0;

}

int DELETE_CLIENT(char* name_delete, struct Client* client, int k)
{
	printf("Enter name to delete:");
    scanf("%s", name_delete);

    while (getchar() != '\n'); 
    
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
	
	for (i = 0; i < k; i++)			
    {
        if (strcmp(client[i].name, name_delete) == 0 && client[i].delete != 1)		
        {
			
            client[i].delete = 1;
			samecount++;
		}
		
		if(client[i].delete != 1)
		{
			fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);
		}
	}
    
	fclose(file); 
	k--;		
    return 0;

}

int SEARCH_CLIENT(char* name_search, struct Client* client, int k)
{
	printf("Enter name to search:");
    scanf("%s", name_search);

    while (getchar() != '\n'); 
    
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

int PRINT_ALL(struct Client* client, int k)
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

int UPDATE_REMAINING_DAYS(struct Client* client, int k)
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
    	client[i].remainingDays = updateRemaingDays(client, i);

		if(client[i].remainingDays < 0)
		{
			client[i].delete = 1;
		}

        if(client[i].delete != 1)
		{
		printf("%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);	
		
		fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);
		}
	}
	fclose(file);

    return 0;
}
