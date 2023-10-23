#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

enum CommandType
{
	CMD_ADD_CLIENT = 1,
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
    int delete; 
    int inputnum;
};

int checksamename(const struct Client* client, int k, const char* name);
int calculateRemaingDays(struct Client* client, int k, int isUpdate);
void calculateEndTime(struct Client* client, int k, struct tm* timeInfo);
int ADD_CLIENT(struct Client* client, int k);
int UPDATE_MONTHS(char* name_func2, int months_func2, struct Client* client, int k);
int TRANSFER_MONTHS(char* name_giver, char* name_receiver, struct Client* client, int k);
int DELETE_CLIENT(char* name_delete, struct Client* client, int k);
int SEARCH_CLIENT(char* name_search, struct Client* client, int k);
int PRINT_ALL(struct Client* client, int k);
int UPDATE_REMAINING_DAYS(struct Client* client, int k);

#endif 
