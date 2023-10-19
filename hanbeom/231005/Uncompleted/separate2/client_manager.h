#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

enum CommandType
{
	CMD_EXIT = 1,
	CMD_ADD_CLIENT,
	CMD_UPDATE_MONTHS,
	CMD_TRANSFER_MONTHS,
	CMD_DELETE_CLIENT,
	CMD_SEARCH_CLIENT,
	CMD_PRINT_ALL,
	CMD_UPDATE_REMAINING_DAYS
};

struct Client
{
    char name[100];
    int age;
    int months;
    int start_year;
    int start_month;
    int start_day;
    int start_hour;
    int start_min;
    int end_year;
    int end_month;
    int end_day;
    int end_hour;
    int end_min;
    int remainingDays;
    int delete; // = 0; //for func3
    int inputnum;
};

int calculateRemaingDays(struct Client* client, int k);
int updateRemaingDays(struct Client* client, int k);
void calculateEndTime(struct Client* client, int k, struct tm* timeInfo);
int func1(struct Client* client, int k);
int func2(char* name_func2, int months_func2, struct Client* client, int k);
int func3(char* name_giver, char* name_receiver, struct Client* client, int k);
int func4(char* name_delete, struct Client* client, int k);
int func5(char* name_search, struct Client* client, int k);
int func6(struct Client* client, int k);
int func7(struct Client* client, int k);

#endif // CLIENT_MANAGER_H
