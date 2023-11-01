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
    char line[500];
	char func2_name[100];
	int func2_month = 0;
	char func3_name1[100];
	char func3_name2[100];
	char func4_name[100];
	char func5_name[100];
	

    FILE* file = fopen("current_time.txt", "r");

    if (file != NULL)
    {
        while (fgets(line, sizeof(line), file) != NULL)
        {
			struct Client newClient; //2		//client[k].name == newClient.name

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

		struct Client newClient2;

        switch (command)
        {
        case cmd_addClient:
            addClient(&head, newClient2);   
			break;
		case cmd_update_months:
			updateMonths(&head, func2_name, func2_month);
			break;
		case cmd_transfer_months:
			transferMonths(&head, func3_name1, func3_name2);
			break;
		case cmd_delete_client:
			deleteClient(&head, func4_name);
			break;
		case cmd_search_client:
			searchClient(&head, func5_name);
			break;
		case cmd_print_all:
			printList(head);
			break;
		case cmd_update_remaining_days:
			updateRemainingDays(&head);
			break;
		default:
            printf("Invalid command. Please enter a number between 1 and 7.\n");
            break;
        }
    }

	//linkedlist memory exit
	while (head != NULL)
	{
		struct ClientNode* temp = head;
		head = head->next;
		free(temp);
	}

    return 0;
}
