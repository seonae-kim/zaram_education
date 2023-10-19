#include "sevenFunction.h"

int addClient(struct Client* client, int k)
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
