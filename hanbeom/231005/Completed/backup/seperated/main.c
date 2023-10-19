#define _CRT_SECURE_NO_WARNINGS
#include "client_manager.h"

int main()
{
    char inputnumber[100]; // answer at "input number 1~7"
    int k = 0;             // struct index// update whe use func1
    struct Client client[100]; // Declare struct array
    char func2_name[100];
    int func2_month = 0;
    char func3_name1[100];
    char func3_name2[100];
    char func4_name[100];
    char func5_name[100];
    char func6_name[100];
    char line[500];

    // 파일에서 정보 읽기(프로그램 종료하고 다시 읽어오는거)   (sscanf 사용)
    FILE* file = fopen("current_time.txt", "r");

    if (file != NULL)
    {
        while (fgets(line, sizeof(line), file) != NULL)
        {
            sscanf(line, "%s %d %d %dy %dm %dd %dh %dm %dy %dm %dd %dh %dm %d", client[k].name, &client[k].age, &client[k].months, &client[k].start_year, &client[k].start_month, &client[k].start_day, &client[k].start_hour, &client[k].start_min, &client[k].end_year, &client[k].end_month, &client[k].end_day, &client[k].end_hour, &client[k].end_min, &client[k].remainingDays); // 텍스트 파일에 저장된 구조체 필드 다 저장함.
            printf("%d is %s\n", k, client[k].name);
            k++;
        }
        fclose(file);
    }

    while (1)
    {
        //get number 1~7 or q
        printf("input number 1~7:");
        fgets(inputnumber, sizeof(inputnumber), stdin);

        size_t len = strlen(inputnumber);
        if (len > 0 && inputnumber[len - 1] == '\n')
        {
            inputnumber[len - 1] = '\0'; //inputnumber = 2\0
        }

        if (strcmp(inputnumber, "q") == 0) // when inputnumber = q, exit program
            break;

        // Convert input to integer
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
