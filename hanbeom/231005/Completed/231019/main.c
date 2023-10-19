#define _CRT_SECURE_NO_WARNINGS
#include "client_manager.h"

int main()
{
    char inputnumber[100]; 
    int k = 0;             
    struct Client client[100]; 
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
            sscanf(line, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d", client[k].name, &client[k].age, &client[k].months, &client[k].start_year, &client[k].start_month, &client[k].start_day, &client[k].start_hour, &client[k].start_min, &client[k].end_year, &client[k].end_month, &client[k].end_day, &client[k].end_hour, &client[k].end_min, &client[k].remainingDays); 

            printf("%d is %s\n", k, client[k].name);
            k++;
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
        case CMD_ADD_CLIENT:
            ADD_CLIENT(client, k);
            k++;
            break;
        case CMD_UPDATE_MONTHS:
            UPDATE_MONTHS(func2_name, func2_month, client, k);
            break;
        case CMD_TRANSFER_MONTHS:
            TRANSFER_MONTHS(func3_name1, func3_name2, client, k);
            break;
        case CMD_DELETE_CLIENT:
            DELETE_CLIENT(func4_name, client, k);
            break;
        case CMD_SEARCH_CLIENT:
            SEARCH_CLIENT(func5_name, client, k);
            break;
        case CMD_PRINT_ALL:
            PRINT_ALL(client, k);
            break;
        case CMD_UPDATE_REMAINING_DAYS:
            UPDATE_REMAINING_DAYS(client, k);
            break;
        default:
            printf("Invalid command. Please enter a number between 1 and 7.\n");
            break;
        }
    }

    return 0;
}
