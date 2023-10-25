#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

enum CommandType
{
	cmd_addClient = 1,
	cmd_updateMonths,
	cmd_transferMonths,
	cmd_deleteClient,
	cmd_searchClient,
	cmd_printAll,
	cmd_updateRemainingDays
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

int checksamename(const struct Client* client, const char* name, int* foundIndex);
int calculateRemaingDays(struct Client* client, int isUpdate);
void calculateEndTime(struct Client* client, struct tm* timeInfo);
int addClient(struct Client** head);
int updateMonths(char* name_func2, int months_func2, struct Client* head);
int transferMonths(char* name_giver, char* name_receiver, struct Client* client);
int deleteClient(char* name_delete, struct Client* head);
int searchClient(char* name_search, struct Client* head;
int printAll(struct Client* head);
int updateRemainingDays(struct Client* head;

#endif 
