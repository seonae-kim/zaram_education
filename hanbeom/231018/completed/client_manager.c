#define _CRT_SECURE_NO_WARNINGS
#include "client_manager.h"

struct ClientNode							
{
	struct Client data;
	struct ClientNode* next;
};

// create newnode and return				
struct ClientNode* createNode(const struct Client newClient)
{
	struct ClientNode* newNode = (struct ClientNode*)malloc(sizeof(struct ClientNode));
	newNode->data = newClient;
	newNode->next = NULL;
	return newNode;
}

// add node to linkedlist					
struct ClientNode* append(struct ClientNode** head, const struct Client newClient)	
{
	struct ClientNode* newNode = createNode(newClient);
	if (*head == NULL)
	{
		*head = newNode;			
		return newNode;
	}
	struct ClientNode* current = *head;		
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newNode;
	return newNode;
}

//print linkedlist							
void printList(struct ClientNode* head)
{
	struct ClientNode* current = head;
	while (current != NULL)
	{
		if(current->data.delete != 1)
		{
		printf("%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", current->data.name, current->data.age, current->data.months, current->data.start_year, current->data.start_month, current->data.start_day, current->data.start_hour, current->data.start_min, current->data.end_year, current->data.end_month, current->data.end_day, current->data.end_hour, current->data.end_min, current->data.remainingDays);
		}
		current = current->next;
	}
}

int checksamename(struct ClientNode* current, const char* name, int* foundIndex, int selectFunction)	//current is started from 'head'
{																	
	int i = 0;
	int exitwhen_2 = 0; //1030 
	
	//when use 1
	if(selectFunction == 1)
	{
		while (current != NULL)
		{		
			if (strcmp(current->data.name, name) == 0 && current->data.delete != 1)
			{
				exitwhen_2++;
			}
		
			if(exitwhen_2 ==2)
			{
				*foundIndex = i;
				return 1;
			}
			current = current->next;		
			i++;
		}
	}

	//when use 2
	if(selectFunction == 2)
	{
		while (current != NULL)
		{		
			if (strcmp(current->data.name, name) == 0 && current->data.delete != 1)
			{
				*foundIndex = i;
				return 1;
			}
			current = current->next;		
			i++;
		}
	}
	return 0;
}

int calculateRemaingDays(struct ClientNode* current, int isUpdate)  //isUpdate =0, calculateremainingdays, ispudate=1 , updateremainingdays
{
	struct Client* currentClient = &(current->data);	

	struct tm endTime;
    time_t endTimestamp;

	time_t currentTime;
    time(&currentTime);
    struct tm* timeInfo;
    timeInfo = localtime(&currentTime);

    struct tm startTime;
    time_t startTimestamp;
	
	endTime.tm_year = currentClient->end_year - 1900;
	endTime.tm_mon = currentClient->end_month - 1;
	endTime.tm_mday = currentClient->end_day;
	endTime.tm_hour = currentClient->end_hour;
	endTime.tm_min = currentClient->end_min;
	endTime.tm_sec = 0;
	endTime.tm_isdst = -1;
		
    if (isUpdate) 
	{		
    	startTime = *timeInfo;
    } 
	else 		 
	{
		startTime.tm_year = currentClient->start_year - 1900;
		startTime.tm_mon = currentClient->start_month - 1;
		startTime.tm_mday = currentClient->start_day;
		startTime.tm_hour = currentClient->start_hour;
		startTime.tm_min = currentClient->start_min;
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

void calculateEndTime(struct ClientNode* current, struct tm* timeInfo)
{

	current->data.end_year = timeInfo->tm_year + 1900;
	current->data.end_month = timeInfo->tm_mon + 1 + (current->data.months);
	

	if (current->data.end_month > 12)
	{
		current->data.end_year += 1;
		current->data.end_month -= 12;
	}

	current->data.end_day = timeInfo->tm_mday;
	current->data.end_hour = timeInfo->tm_hour;
	current->data.end_min = timeInfo->tm_min;
}

int addClient(struct ClientNode** head, struct Client newClient)		 
{
	struct ClientNode* client = append(head,newClient);	
	
	printf("Enter name:");
    scanf("%s", client->data.name);		

    printf("Enter age:");
    scanf("%d", &client->data.age);

    printf("Enter months:");
    scanf("%d", &client->data.months);

    while (getchar() != '\n'); 

	//
	int foundIndex; // 중복 검사에서 찾은 인덱스
	if (checksamename(*head, client->data.name, &foundIndex, 1) == 1)
	{
		printf("existed client\n");
		client->data.delete = 1;
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
	
	client->data.start_year = timeInfo->tm_year + 1900;

	client->data.start_month = timeInfo->tm_mon + 1;

	client->data.start_day = timeInfo->tm_mday;

	client->data.start_hour = timeInfo->tm_hour;

	client->data.start_min = timeInfo->tm_min;

	calculateEndTime(client, timeInfo);					

	client->data.remainingDays = calculateRemaingDays(client,0);				

    fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client->data.name, client->data.age, client->data.months, client->data.start_year, client->data.start_month, client->data.start_day, client->data.start_hour, client->data.start_min, client->data.end_year, client->data.end_month, client->data.end_day, client->data.end_hour, client->data.end_min, client->data.remainingDays);
    fclose(file);
    return 0;
}

int updateMonths(struct ClientNode** head, char* name_func2, int months_func2)
{
    printf("Enter name:");
    scanf("%s", name_func2);

    printf("Enter months:");
    scanf("%d", &months_func2);

    while (getchar() != '\n'); 

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
	struct ClientNode* client = *head; 

    if (checksamename(client, name_func2, &foundIndex, 2) == 1)		
    {
		for(i =0; i < foundIndex; i++)
		{
			client = client->next;
		}

        if (client->data.delete != 1)			
        {
            // 현재 시간과 클라이언트의 종료 시간을 비교하여 처리
            time_t currentTime;
            time(&currentTime);
            struct tm* timeInfo = localtime(&currentTime);

            struct tm endTime;
            time_t endTimestamp;
            endTime.tm_year = client->data.end_year - 1900;			
            endTime.tm_mon = client->data.end_month - 1;				
            endTime.tm_mday = client->data.end_day;
            endTime.tm_hour = client->data.end_hour;
            endTime.tm_min = client->data.end_min;
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
                client->data.months += months_func2;
                client->data.end_month += months_func2;

                if (client->data.end_month > 12)
                {
                    client->data.end_year += 1;
                    client->data.end_month -= 12;
                }

                client->data.remainingDays = calculateRemaingDays(client, 0);		

                // 파일에 업데이트된 정보 저장
				struct ClientNode* current_like_i = *head;							
				while (current_like_i != NULL)
				{
					if(current_like_i->data.delete != 1)
					{
						fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", current_like_i->data.name, current_like_i->data.age, current_like_i->data.months, current_like_i->data.start_year, current_like_i->data.start_month, current_like_i->data.start_day, current_like_i->data.start_hour, current_like_i->data.start_min, current_like_i->data.end_year, current_like_i->data.end_month, current_like_i->data.end_day, current_like_i->data.end_hour, current_like_i->data.end_min, current_like_i->data.remainingDays);
					}
					current_like_i = current_like_i->next;
				}
            }
            else // 클라이언트가 이미 만료된 경우
            {
                printf("expired client reapply\n");

                client->data.months = months_func2;
                client->data.start_year = timeInfo->tm_year + 1900;
                client->data.start_month = timeInfo->tm_mon + 1;
                client->data.start_day = timeInfo->tm_mday;
                client->data.start_hour = timeInfo->tm_hour;
                client->data.start_min = timeInfo->tm_min;

                // 클라이언트의 종료 시간 업데이트
                calculateEndTime(client, timeInfo);				
                client->data.remainingDays = calculateRemaingDays(client, 0);		

                // 파일에 업데이트된 정보 저장
				struct ClientNode* current_like_i = *head;				
				while (current_like_i != NULL)
				{
					if(current_like_i->data.delete != 1)
					{
						fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", current_like_i->data.name, current_like_i->data.age, current_like_i->data.months, current_like_i->data.start_year, current_like_i->data.start_month, current_like_i->data.start_day, current_like_i->data.start_hour, current_like_i->data.start_min, current_like_i->data.end_year, current_like_i->data.end_month, current_like_i->data.end_day, current_like_i->data.end_hour, current_like_i->data.end_min, current_like_i->data.remainingDays);
					}
					current_like_i = current_like_i->next;
				}
            }
            fclose(file);
            return 0;
        }
        else
        {
            printf("Client is marked as deleted.\n");
        }
		printf("testtest: foundIndex is %d\n", foundIndex);
    }
    else
    {
        printf("Client not found.\n");					
    }

    fclose(file);
    return 2;
}

int transferMonths(struct ClientNode** head, char* name_giver, char* name_receiver)
{     
	printf("Enter giver name:");
    scanf("%s", name_giver);

	printf("Enter receiver name:");
    scanf("%s", name_receiver);

    while (getchar() != '\n'); 
    
	int i;
	int samecount_receiver = 0;
    int foundIndex;
    
	struct ClientNode* client = *head; // client start from head
									   
    if (checksamename(client, name_receiver, &foundIndex, 2) == 1)		
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
	
	client = *head;

	if (checksamename(client, name_giver, &foundIndex, 2) == 1)
	{
		for(i =0; i < foundIndex; i++)
		{
			client = client->next;
		}
		client->data.delete = 1;
		delete_months = client->data.months;
		//printf("delete_months is %d\n", delete_months);					//test
		samecount_giver++;
		//printf("samecount_giver is %d\n", samecount_giver);			//test
	}
	//foundindex = i 역할
	
	client = *head;

	if (checksamename(client, name_receiver, &foundIndex, 2) == 1)
	{
		for(i =0; i < foundIndex; i++)
		{
			client = client->next;
		}

		if (samecount_giver == 1)
		{
			client->data.months += delete_months;
			client->data.end_month += delete_months;

			if (client->data.end_month > 12)
			{
				client->data.end_month -= 12;
				client->data.end_year += 1;
			}
			client->data.remainingDays = calculateRemaingDays(client, 0);
			samecount_receiver++;
		}

		client = *head;
		while(client != NULL)
		{
			if (client->data.delete != 1)					
			{
				fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client->data.name, client->data.age, client->data.months, client->data.start_year, client->data.start_month, client->data.start_day, client->data.start_hour, client->data.start_min, client->data.end_year, client->data.end_month, client->data.end_day, client->data.end_hour, client->data.end_min, client->data.remainingDays);
			}
			client = client->next;
		}	
		
	}

	if(samecount_giver ==0)
	{
		printf("giver is not in list\n"); 
	}

    fclose(file); 
	//printf("foundIndex is %d\n", foundIndex);		//test
    return 0;
}

int deleteClient(struct ClientNode** head, char* name_delete)
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

	struct ClientNode* client = *head; // client start from head
    
	if (checksamename(client, name_delete, &foundIndex, 2) == 1)
    {
        samecount++;
    }

	if(samecount == 0)
	{
		printf("name is not in list\n");
		return 2;
	}
	
    if (checksamename(client, name_delete, &foundIndex, 2) == 1)
    {
        for(i =0; i < foundIndex; i++)
		{
			client = client->next;
		}

		client->data.delete = 1;
        samecount++;

		client = *head;
		while(client != NULL)
		{
			if (client->data.delete != 1)					
			{
				fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client->data.name, client->data.age, client->data.months, client->data.start_year, client->data.start_month, client->data.start_day, client->data.start_hour, client->data.start_min, client->data.end_year, client->data.end_month, client->data.end_day, client->data.end_hour, client->data.end_min, client->data.remainingDays);
			}
			client = client->next;
		}
    }

	fclose(file); 
    return 0;

}
int searchClient(struct ClientNode** head, char* name_search)
{
	printf("Enter name to search:");
	scanf("%s", name_search);

	while (getchar() != '\n'); 

    int foundIndex;
	int i;
	
	struct ClientNode* client = *head;

	if (client->data.delete != 1 && checksamename(client, name_search, &foundIndex, 2) == 1 )
	{
		for(i =0; i < foundIndex; i++)
		{
			client = client->next;
		}
		printf("%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client->data.name, client->data.age, client->data.months, client->data.start_year, client->data.start_month, client->data.start_day, client->data.start_hour, client->data.start_min, client->data.end_year, client->data.end_month, client->data.end_day, client->data.end_hour, client->data.end_min, client->data.remainingDays);
	}

	else
	{
		printf("Name not found.\n");
	}

	return 0;
}

int updateRemainingDays(struct ClientNode** head)
{
	FILE* file;
    file = fopen("current_time.txt", "w");

    if (file == NULL)
    {
        printf("can't open file.\n");
        fclose(file);
        return 1;
    }
	struct ClientNode* client = *head;

	while(client != NULL)	
	{
		client->data.remainingDays = calculateRemaingDays(client, 1);
	
		if(client->data.remainingDays < 0)
		{
			client->data.delete = 1;
		}

		if (client->data.delete != 1)			
		{		
			printf("%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client->data.name, client->data.age, client->data.months, client->data.start_year, client->data.start_month, client->data.start_day, client->data.start_hour, client->data.start_min, client->data.end_year, client->data.end_month, client->data.end_day, client->data.end_hour, client->data.end_min, client->data.remainingDays);
				
			fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client->data.name, client->data.age, client->data.months, client->data.start_year, client->data.start_month, client->data.start_day, client->data.start_hour, client->data.start_min, client->data.end_year, client->data.end_month, client->data.end_day, client->data.end_hour, client->data.end_min, client->data.remainingDays);
		}
			client = client->next;
	}
	fclose(file);

    return 0;
}
