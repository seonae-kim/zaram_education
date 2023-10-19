#include "client_manager.h"

int calculateRemaingDays(struct Client* client, int k)
{
    struct tm startTime, endTime;
	time_t startTimestamp, endTimestamp;

	//get startTime
	startTime.tm_year = client[k].start_year - 1900;
	startTime.tm_mon = client[k].start_month - 1;
	startTime.tm_mday = client[k].start_day;
	startTime.tm_hour = client[k].start_hour;
	startTime.tm_min = client[k].start_min;
	startTime.tm_sec = 0;
	startTime.tm_isdst = -1;

	//get endTime
	endTime.tm_year = client[k].end_year - 1900;
	endTime.tm_mon = client[k].end_month - 1;
	endTime.tm_mday = client[k].end_day;
	endTime.tm_hour = client[k].end_hour;
	endTime.tm_min = client[k].end_min;
	endTime.tm_sec = 0;
	endTime.tm_isdst = -1;

	// change startTime, endTime to time type
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
	 // get current time (timeInfo)
    time_t currentTime;			//currentTime's type is "time_t"
    time(&currentTime);			//use time function
    struct tm* timeInfo;		// tm= struct, timeInfo= struct pointer	
    timeInfo = localtime(&currentTime); // current time

	struct tm startTime, endTime;
	time_t startTimestamp, endTimestamp;

	//get startTime
	startTime.tm_year = timeInfo->tm_year - 1900;
	startTime.tm_mon = timeInfo->tm_mon - 1;
	startTime.tm_mday = timeInfo->tm_mday;
	startTime.tm_hour = timeInfo->tm_hour;
	startTime.tm_min = timeInfo->tm_min;
	startTime.tm_sec = 0;
	startTime.tm_isdst = -1;

	//get endTime
	endTime.tm_year = client[k].end_year - 1900;
	endTime.tm_mon = client[k].end_month - 1;
	endTime.tm_mday = client[k].end_day;
	endTime.tm_hour = client[k].end_hour;
	endTime.tm_min = client[k].end_min;
	endTime.tm_sec = 0;
	endTime.tm_isdst = -1;

	// change startTime, endTime to time type
	startTimestamp = mktime(&startTime);
	endTimestamp = mktime(&endTime);

	if (startTimestamp == -1 || endTimestamp == -1)
	{
		printf("it is error");
		return -1;
	}
	
	double diffInSeconds = difftime(endTimestamp, startTimestamp);
	int diffInDays = (int)(diffInSeconds / (60 * 60 * 24));

	return diffInDays;	//it is okay to same with CalculateRemainingDays?
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
    /////get name, age, months
    printf("Enter name:");
    scanf("%s", client[k].name);

    printf("Enter age:");
    scanf("%d", &client[k].age);

    printf("Enter months:");
    scanf("%d", &client[k].months);

    while (getchar() != '\n'); // after use scanf, erase '\n'

    //중복된 이름 입력 방지
    int i;
    for (i = 0; i < k; i++)
    {
        //if (strcmp(client[i].name, client[k].name) == 0)
        if (strcmp(client[i].name, client[k].name) == 0 && client[i].delete != 1)
        {
            printf("중복이니 다시입력\n");
			client[k].delete = 1;		// 1: wndqhr >> 6
            return 1;
        }
    }

    // get current time (timeInfo)
    time_t currentTime;			//currentTime's type is "time_t"
    time(&currentTime);			//use time function
    struct tm* timeInfo;		// tm= struct, timeInfo= struct pointer	
    timeInfo = localtime(&currentTime); // current time
    
    //file open and close
    char line[100]; // file's line
    char dateTimeString[100];
    FILE* file;

    file = fopen("current_time.txt", "a");

    if (file == NULL)
    {
        printf("can't open file.\n");
        fclose(file);
        return 1;
    }

	
    // get start_year
    client[k].start_year = timeInfo->tm_year + 1900;
	
	// get start_month
	client[k].start_month = timeInfo->tm_mon +1;

	// get start_day
	client[k].start_day = timeInfo->tm_mday;

	// get start_hour
	client[k].start_hour = timeInfo->tm_hour;

	// get start_min
	client[k].start_min = timeInfo->tm_min;

	//get endTime
	calculateEndTime(client, k, timeInfo);

    // get remainingdays
    client[k].remainingDays = calculateRemaingDays(client, k);
		
    // store to file all
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

int TRANSFER_MONTHS(char* name_giver, char* name_receiver, struct Client* client, int k)
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

int DELETE_CLIENT(char* name_delete, struct Client* client, int k)
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

int SEARCH_CLIENT(char* name_search, struct Client* client, int k)
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
