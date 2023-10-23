#define _CRT_SECURE_NO_WARNINGS
#include "client_manager.h"

int checksamename(const struct Client* client, int k, const char* name, int* foundIndex)
{
	int i;
	for(i = 0 ; i < k; i++)
	{
		if (strcmp(client[i].name, name) == 0 && client[i].delete !=1)
		{
			*foundIndex = i;
			return 1;
		}
	}
	return 0;
}

int calculateRemaingDays(struct Client* client, int k, int isUpdate)  //plus
{
    struct tm endTime;
    time_t endTimestamp;

    endTime.tm_year = client[k].end_year - 1900;
    endTime.tm_mon = client[k].end_month - 1;
    endTime.tm_mday = client[k].end_day;
    endTime.tm_hour = client[k].end_hour;
    endTime.tm_min = client[k].end_min;
    endTime.tm_sec = 0;
    endTime.tm_isdst = -1;

    time_t currentTime;
    time(&currentTime);
    struct tm* timeInfo;
    timeInfo = localtime(&currentTime);

    struct tm startTime;
    time_t startTimestamp;

    if (isUpdate) 
	{		
    	startTime = *timeInfo;
    } 
	else 		 
	{
        startTime.tm_year = client[k].start_year - 1900;
        startTime.tm_mon = client[k].start_month - 1;
        startTime.tm_mday = client[k].start_day;
        startTime.tm_hour = client[k].start_hour;
        startTime.tm_min = client[k].start_min;
        startTime.tm_sec = 0;
        startTime.tm_isdst = -1;
    }

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
	
	int foundIndex; // 중복 검사에서 찾은 인덱스
	if (checksamename(client, k, client[k].name, &foundIndex) == 1)
	{
		printf("existed client\n");
		client[k].delete = 1;
		return 1;
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

    client[k].remainingDays = calculateRemaingDays(client, k, 0);
		
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

    int foundIndex = -1;
    int i;

    // 이름에 해당하는 클라이언트를 찾음
    if (checksamename(client, k, name_func2, &foundIndex) == 1)
    {
        if (client[foundIndex].delete != 1)
        {
            // 현재 시간과 클라이언트의 종료 시간을 비교하여 처리
            time_t currentTime;
            time(&currentTime);
            struct tm* timeInfo = localtime(&currentTime);

            struct tm endTime;
            time_t endTimestamp;
            endTime.tm_year = client[foundIndex].end_year - 1900;
            endTime.tm_mon = client[foundIndex].end_month - 1;
            endTime.tm_mday = client[foundIndex].end_day;
            endTime.tm_hour = client[foundIndex].end_hour;
            endTime.tm_min = client[foundIndex].end_min;
            endTime.tm_sec = 0;
            endTime.tm_isdst = -1;
            endTimestamp = mktime(&endTime);

            if (endTimestamp == -1)
            {
                printf("it is error");
                return -1;
            }

            double diffInSeconds = difftime(endTimestamp, currentTime);

            if (diffInSeconds > 0) // 클라이언트가 아직 유효한 경우
            {
                client[foundIndex].months += months_func2;
                client[foundIndex].end_month += months_func2;

                if (client[foundIndex].end_month > 12)
                {
                    client[foundIndex].end_year += 1;
                    client[foundIndex].end_month -= 12;
                }

                client[foundIndex].remainingDays = calculateRemaingDays(client, foundIndex, 0);

                // 파일에 업데이트된 정보 저장
                for (i = 0; i < k; i++)
                {
                    if (client[i].delete != 1)
                    {
                        fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);
                    }
                }
            }
            else // 클라이언트가 이미 만료된 경우
            {
                printf("expired client reapply\n");

                client[foundIndex].months = months_func2;
                client[foundIndex].start_year = timeInfo->tm_year + 1900;
                client[foundIndex].start_month = timeInfo->tm_mon + 1;
                client[foundIndex].start_day = timeInfo->tm_mday;
                client[foundIndex].start_hour = timeInfo->tm_hour;
                client[foundIndex].start_min = timeInfo->tm_min;

                // 클라이언트의 종료 시간 업데이트
                calculateEndTime(client, foundIndex, timeInfo);

                client[foundIndex].remainingDays = calculateRemaingDays(client, foundIndex, 0);

                // 파일에 업데이트된 정보 저장
                for (i = 0; i < k; i++)
                {
                    if (client[i].delete != 1)
                    {
                        fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[i].name, client[i].age, client[i].months, client[i].start_year, client[i].start_month, client[i].start_day, client[i].start_hour, client[i].start_min, client[i].end_year, client[i].end_month, client[i].end_day, client[i].end_hour, client[i].end_min, client[i].remainingDays);
                    }
                }
            }
            fclose(file);
            return 0;
        }
        else
        {
            printf("Client is marked as deleted.\n");
        }
    }
    else
    {
        printf("Client not found.\n");
    }

    fclose(file);
    return 2;
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
    int foundIndex;
    
    if (checksamename(client, k, name_receiver, &foundIndex) == 1)
    {
        samecount_receiver++;
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
	

	//
	if (checksamename(client, k, name_giver, &foundIndex) == 1)
	{
		client[foundIndex].delete = 1;
		delete_months = client[foundIndex].months;
		printf("delete_months is %d\n", delete_months);
		samecount_giver++;
		printf("samecount_giver is %d\n", samecount_giver);
	}
	//
	
	//foundindex = i 역할
	if (checksamename(client, k, name_receiver, &foundIndex) == 1)
	{
		if (samecount_giver == 1)
		{
			client[foundIndex].months += delete_months;
			client[foundIndex].end_month += delete_months;

			if (client[foundIndex].end_month > 12)
			{
				client[foundIndex].end_month -= 12;
				client[foundIndex].end_year += 1;
			}
			client[foundIndex].remainingDays = calculateRemaingDays(client, foundIndex, 0);
			samecount_receiver++;
		}

		if (client[foundIndex].delete != 1)
		{
			fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[foundIndex].name, client[foundIndex].age, client[foundIndex].months, client[foundIndex].start_year, client[foundIndex].start_month, client[foundIndex].start_day, client[foundIndex].start_hour, client[foundIndex].start_min, client[foundIndex].end_year, client[foundIndex].end_month, client[foundIndex].end_day, client[foundIndex].end_hour, client[foundIndex].end_min, client[foundIndex].remainingDays);
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
    int foundIndex;

    if (checksamename(client, k, name_delete, &foundIndex) == 1)
    {
        samecount++;
    }

	if(samecount == 0)
	{
		printf("name is not in list\n");
		return 2;
	}
	

    if (checksamename(client, k, name_delete, &foundIndex) == 1)
    {
        client[foundIndex].delete = 1;
        samecount++;

        if (client[foundIndex].delete != 1)
        {
            fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[foundIndex].name, client[foundIndex].age, client[foundIndex].months, client[foundIndex].start_year, client[foundIndex].start_month, client[foundIndex].start_day, client[foundIndex].start_hour, client[foundIndex].start_min, client[foundIndex].end_year, client[foundIndex].end_month, client[foundIndex].end_day, client[foundIndex].end_hour, client[foundIndex].end_min, client[foundIndex].remainingDays);
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
    
	int foundIndex;
	if (checksamename(client, k, name_search, &foundIndex) == 1)
	{
		if (client[foundIndex].delete != 1)
		{
			printf("%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[foundIndex].name, client[foundIndex].age, client[foundIndex].months, client[foundIndex].start_year, client[foundIndex].start_month, client[foundIndex].start_day, client[foundIndex].start_hour, client[foundIndex].start_min, client[foundIndex].end_year, client[foundIndex].end_month, client[foundIndex].end_day, client[foundIndex].end_hour, client[foundIndex].end_min, client[foundIndex].remainingDays);
		}
	}
	else
	{
		printf("Name not found.\n");
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
    	client[i].remainingDays = calculateRemaingDays(client, i, 1);

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
