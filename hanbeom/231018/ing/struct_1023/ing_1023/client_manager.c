#define _CRT_SECURE_NO_WARNINGS
#include "client_manager.h"

//1
struct ClientNode
{
	struct Client data;
	struct ClientNode* next;
};

//////////////////////////////////////////////////////////////

// create newnode and return
struct ClientNode* createNode(const struct Client newClient)
{
	struct ClientNode* newNode = (struct ClientNode*)malloc(sizeof(struct ClientNode));
	newNode->data = newClient;
	newNode->next = NULL;
	return newNode;
}

// add node to linkedlist
void append(struct Node** head, const struct Client newClinet)
{
	struct ClientNode* newNode = createNode(newClient);
	if (*head == NULL)
	{
		*head = newNode;
		return ;
	}
	struct ClientNode* current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newNode;
}

//print linkedlist
void printList(struct ClientNode* head)
{
	struct ClientNode* current = head;
	while (current != NULL)
	{
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("finish\n");
}


/////////////////////////////////////////////////////////////

//int k deleted
int checksamename(const struct ClientNode* current, const char* name, int* foundIndex)
{
	//2
	struct ClientNode* current = head;	//add		
	int i = 0;

	while (current != NULL)
	{		//client[i].name = current->data.name
		if (strcmp(current->data.name, name) == 0 && current->data.delete != 1)
		{
			*foundIndex = i;
			return 1;
		}
		current = current->next;		// like i++ (for loop)
		i++;
	}
	return 0;
}

//need to check						//struct Client* client deleted, k deleted 
int calculateRemaingDays(const struct ClientNode* current, int isUpdate)  //plus
{
	//struct ClientNode* current = head;	//add
	
	struct Client* currentClient = &(current->data);	//add

	//time
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

//
void calculateEndTime(struct ClientNode* current, struct tm* timeInfo)
{
	/*
	client[k].end_year = timeInfo->tm_year + 1900;
	client[k].end_month = timeInfo->tm_mon + 1 + (client[k].months);
	*/

	current->data.end_year = timeInfo->tm_year + 1900;
	curent->data.end_month = timeInfo->tm_mon + 1 + (current.data->months);
	
	/*
	if (client[k].end_month > 12)
	{
		client[k].end_year += 1;
		client[k].end_month -= 12;
	}
	*/

	if (current->data.end_month > 12)
	{
		current->data.end_year += 1;
		current->data.end_month -= 12;
	}

	/*
	client[k].end_day = timeInfo->tm_mday;
	client[k].end_hour = timeInfo->tm_hour;
	client[k].end_min = timeInfo->tm_min;
	*/

	current->data.end_day = timeInfo->tm_mday;
	current->data.end_hour = timeInfo->tm_hour;
	current->data.end_min = timeInfo->tm_min;
}

/*
void appendToLinkedList(struct Client* newClient)
{
	struct ClientNode* newNode = (struct ClientNode*)malloc(sizeof(struct ClientNode));
	newNode->data = *newClient;
	newNode->next = head;
	head= newNode;
}
*/
int addClient(struct ClientNode* client)
{
	printf("Enter name:");
    scanf("%s", client->data.name);		

    printf("Enter age:");
    scanf("%d", &client->data.age);

    printf("Enter months:");
    scanf("%d", &client->data.months);

    while (getchar() != '\n'); 
	
	int foundIndex; // 중복 검사에서 찾은 인덱스
	if (checksamename(client, client->data.name, &foundIndex) == 1)
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
	
    //client[k].start_year = timeInfo->tm_year + 1900;
	client->data.start_year = timeInfo->tm_year + 1900;

	//client[k].start_month = timeInfo->tm_mon +1;
	client->data.start_month = timeInfo->tm_mon + 1;

	//client[k].start_day = timeInfo->tm_mday;
	client->data.start_day = timeInfo->tm_mday;

	//client[k].start_hour = timeInfo->tm_hour;
	client->data.start_hour = timeInfo->tm_hour;

	//client[k].start_min = timeInfo->tm_min;
	client->data.start_min = timeInfo->tm_min;

	//calculateEndTime(client, k, timeInfo);
	calculateEndTime(client);					//need to change

    //client[k].remainingDays = calculateRemaingDays(client, k, 0);
	client->data.remainingDays = calculateRemainingDays(client,0);			//need to change	

    fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client->data.name, client->data.age, client->data.months, client->data.start_year, client->data.start_month, client->data.start_day, client->data.start_hour, client->data.start_min, client->data.end_year, client->data.end_month, client->data.end_day, client->data.end_hour, client->data.end_min, client->data.remainingDays);
    fclose(file);
    return 0;
}

int updateMonths(char* name_func2, int months_func2, struct Client* client)
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

	struct ClientNode* current = head;	//add
	
	while(current != NULL)	//add
	{
		if(checksamename(&(current->data), name_func2, &foundIndex) ==1)	//add
		{
			if(current->data.delete != 1)		//add
			{
				time_t currentTime;
            	time(&currentTime);
            	struct tm* timeInfo = localtime(&currentTime);

            	struct tm endTime;
            	time_t endTimestamp;
			}

			endTime.tm_year = current->data.end_year - 1900;
			endTime.tm_mon = current->data.end_month - 1;
			endTime.tm_mday = current->data.end_day;
			endTime.tm_hour = current->data.end_hour;
			endTime.tm_min = current->data.end_min;
			endTime.tm_sec = 0;
			endTime.tm_isdst = -1;
			endTimestamp = mktime(&endTime);

			if (endTimestamp == -1)
            {
                printf("it is error");
                return -1;
            }

            double diffInSeconds = difftime(endTimestamp, currentTime);

			if (diffInSecnds > 0) 
			{
				current->data.months += months_func2;
				current->data.end_months += months_func2;

				if(current->data.end_month > 12)
				{
					current->data.end_year += 1;
					current->data.end_month -= 12;
				}


				current->data.remainingDays = calculateRemainingDays(0);	//?????
				
				struct ClientNode* currentNode = head;
				while (currentNode != NULL)
				{
					if (currentNode->data.delete != 1)
					{
						fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", currentNode->data.name, currentNode->data.age, currentNode->data.months, currentNode->data.start_year, currentNode->data.start_month, currentNode->data.start_day, currentNode->data.start_hour, currentNode->data.start_min, currentNode->data.end_year, currentNode->data.end_month, currentNode->data.end_day, currentNode->data.end_hour, currentNode->data.end_min, currentNode->data.remainingDays);
 					}
					currentNode = currentNode->next;
				}
			}	
			
			else
			{
				printf("expired client reapply\n");

				current->data.months = months_func2;
				current->data.start_year = timeInfo->tm_year + 1900;
				current->data.start_month = timeInfo->tm_mon + 1;
				current->data.start_day = timeInfo->tm_mday;
				current->data.start_hour = timeInfo->tm_hour;
				current->data.start_min = timeInfo->tm_min;

				calculateEndTime(&(current->date));

				current->data.remainingDays = calculateRemainingDays(0);	// ?????

				struct ClientNode* curentNode = head;
				while (currentNode != NULL)
				{
					if(currentNode->data.delete != 1)
					{
						fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", currentNode->data.name, currentNode->data.age, currentNode->data.months, currentNode->data.start_year, currentNode->data.start_month, currentNode->data.start_day, currentNode->data.start_hour, currentNode->data.start_min, currentNode->data.end_year, currentNode->data.end_month, currentNode->data.end_day, currentNode->data.end_hour, currentNode->data.end_min, currentNode->data.remainingDays);
 					}
					currentNode = currentNode->next;
				}
			}
			fclose(file);
			return 0;
		}
		else
		{
			printf("Client is marked as deleted\n");
		}
	}
	else
	{
		printf("Client not found.\n");
	}
	current = current->next;
}
fclose(file);
return 2;	
}

int transferMonths(char* name_giver, char* name_receiver, struct Client* client)
{     
	printf("Enter giver name:");
    scanf("%s", name_giver);

	printf("Enter receiver name:");
    scanf("%s", name_receiver);

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
	int samecount_receiver = 0;
    int foundIndex_receiver;
    
    if (checksamename(head, name_receiver, &foundIndex_receiver) == 1)
    {
        samecount_receiver++;
    }

	if(samecount_receiver != 1)
	{
		printf("receiver is not in list\n");
		fclose(file);
		return 2;
	}


	int delete_months;
	int samecount_giver = 0;
	int foundIndex_giver;

	
	if (checksamename(head, name_giver, &foundIndex_giver) == 1)
	{
		//client[foundIndex].delete = 1;  delete here????
		delete_months = foundIndex_giver->data.months;
		printf("delete_months is %d\n", delete_months);
		samecount_giver++;
		printf("samecount_giver is %d\n", samecount_giver);
	}
	//
	
	struct ClientNode* current = head;

	while (current != NULL)
	{
		if(checksamename(head, name_giver, &foundIndex_giver) ==1)
		{
			foundIndex_giver->data.delete = 1;
			samecount_giver++;
			delete_months = foundIndex_giver->data.months;
			printf("delete_month is %d\n", delete_months);
		}
		current = current->next;
	}

	
	//foundindex = i 역할
	if (checksamename(head, name_receiver, &foundIndex_receiver) == 1)
	{
		if (samecount_giver == 1)
		{
			foundIndex_receiver->data.months += delete_months;
			foundIndex_receiver->data.end_months += delete_months;
			
			if (foundIndex_receiver->data.end_month > 12)
			{
				foundIndex_receiver->data.end_month -= 12;
				foundIndex_receiver->data.end_month += 1;
			}

			foundIndex_receiver->data.remainingDays = calculateRemainingDays(0);
			samecount_receiver++;
		}

		if (foundIndex_receiver->data.delete != 1)
		{
			fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", foundIndex_receiver->data.name, foundIndex_receiver->data.age, foundIndex_receiver->data.months, foundIndex_receiver->data.start_year, foundIndex_receiver->data.start_month, foundIndex_receiver->data.start_day, foundIndex_receiver->data.start_hour, foundIndex_receiver->data.start_min, foundIndex_receiver->data.end_year, foundIndex_receiver->data.end_month, foundIndex_receiver->data.end_day, foundIndex_receiver->data.end_hour, foundIndex_receiver->data.end_min, foundIndex_receiver->data.remainingDays);
		}
	}

	if(samecount_giver ==0)
	{
		printf("giver is not in list\n"); 
	}

    fclose(file); 
    return 0;
}

int deleteClient(char* name_delete, struct Client* client)
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

	/*
    if (checksamename(client, k, name_delete, &foundIndex) == 1)
    {
        samecount++;
    }
	*/
	
	while(current != NULL)
	{
		if(checksamename(current, name_delete, &foundIndex) ==1)
		{
			samecount++;
		}
		current = current->next;
	}


	if(samecount == 0)
	{
		printf("name is not in list\n");
		return 2;
	}
	
	current = head;
	/*
    if (checksamename(client, k, name_delete, &foundIndex) == 1)
    {
        client[foundIndex].delete = 1;
        samecount++;

        if (client[foundIndex].delete != 1)
        {
            fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", client[foundIndex].name, client[foundIndex].age, client[foundIndex].months, client[foundIndex].start_year, client[foundIndex].start_month, client[foundIndex].start_day, client[foundIndex].start_hour, client[foundIndex].start_min, client[foundIndex].end_year, client[foundIndex].end_month, client[foundIndex].end_day, client[foundIndex].end_hour, client[foundIndex].end_min, client[foundIndex].remainingDays);
        }
    }
	*/
	
	while (current != NULL)
	{
		if(checksamename(current, name_delete, &foundIndex) == 1)
		{
			current->data.delete = 1;
			samecount++;

			if(current->data.delete != 1)
			{
				fprintf(file, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d\n", current->data.name, current->data.age, current->data.months, current->data.start_year, current->data.start_month, current->data.start_day, current->data.start_hour, current->data.start_min, current->data.end_year, current->data.end_month, current->data.end_day, current->data.end_hour, current->data.end_min, current->.remainingDays);
 			}
		}
		current = current->next;	
	}
	fclose(file); 
    return 0;

}

int searchClient(char* name_search, struct Client* client, int k)
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

int printAll(struct Client* client, int k)
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

int updateRemainingDays(struct Client* client, int k)
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
