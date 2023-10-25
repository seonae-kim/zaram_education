#define _CRT_SECURE_NO_WARNINGS
#include "client_manager.h"

struct ClientNode 
{
	struct Client data;
	struct ClientNode* next;
};

int main()
{
    char inputnumber[100]; 
    struct ClientNode* head = NULL;  //linkedlist's head pointer // like k    
    char func2_name[100];
    int func2_month = 0;
    char func3_name1[100];
    char func3_name2[100];
    char func4_name[100];
    char func5_name[100];
    char func6_name[100];
    char line[500];

    FILE* file = fopen("current_time.txt", "r");

    if (file != NULL)
    {
        while (fgets(line, sizeof(line), file) != NULL)
        {
			struct Client newClient //2		//client[k].name == newClient.name

            sscanf(line, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d", newClient.name, &newClient.age, &newClient.months, &newClient.start_year, &newClient.start_month, &newClient.start_day, &newClient.start_hour, &newClient.start_min, &newClient.end_year, &newClient.end_month, &newClient.end_day, &newClient.end_hour, &newClient.end_min, &newClient.remainingDays); 		//3 store txt file contents to node
			
			//4 add node to linked list
			append(&head, newClient);
        }
        fclose(file);
    }

    while (1)
    {
        printf("input number 1~7:");
        fgets(inputnumber, sizeof(inputnumber), stdin);

        size_t len = strlen(inputnumber);
        if (len > 0 && inputnumber[len - 1] == '\n')
        {
            inputnumber[len - 1] = '\0'; 
        }

        if (strcmp(inputnumber, "q") == 0) 
            break;

        int command = atoi(inputnumber);

        switch (command)
        {
        case cmd_addClient:
            head = addClient(head);
			//5 addClient(client, k);
			break;
        case cmd_updateMonths:
           	updatemonths(func2_name, func2_months, head); 
			//6 updateMonths(func2_name, func2_month, client, k);
            break;
        case cmd_transferMonths:
			head = transferMonths(func3_name1, func3_name2, head);
            // 7 transferMonths(func3_name1, func3_name2, client, k);
            break;
        case cmd_deleteClient:
			head = deleteClient(func4_name ,head);
            // 8 deleteClient(func4_name, client, k);
            break;
        case cmd_searchClient:
			searchClient(func5_name, head);
            // 9 searchClient(func5_name, client, k);
            break;
        case cmd_printAll:
			printAll(head);
            // 10 printAll(client, k);
            break;
        case cmd_updateRemainingDays:
			head = updateRemainingDays(head);
            // 11 updateRemainingDays(client, k);
            break;
        default:
            printf("Invalid command. Please enter a number between 1 and 7.\n");
            break;
        }
    }
	
	//12 linkedlist memory exit
	while (head != NULL)
	{
		struct ClientNode* temp = head;
		head = head ->next;
		free(temp);
	}

    return 0;
}
