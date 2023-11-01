#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

enum CommandType
{
	cmd_addClient = 1,
	cmd_update_months,
	cmd_transfer_months,
	cmd_delete_client,
	cmd_search_client,
	cmd_print_all,
	cmd_update_remaining_days
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
    int inputnum;
};

struct ClientNode* createNode(const struct Client newClient);
struct ClientNode* append(struct ClientNode** head, const struct Client newClient);
void printList(struct ClientNode* head);
void deleteNode(struct ClientNode** head, char* name_giver);
void deleteCurrentNode(struct ClientNode** head, struct ClientNode* current);
int checksamename(struct ClientNode* current, const char* name, int* foundIndex, int selectFunction);
int calculateRemaingDays(struct ClientNode* current, int isUpdate);
void calculateEndTime(struct ClientNode* current, struct tm* timeInfo);
int addClient(struct ClientNode** head, struct Client newClient);
int updateMonths(struct ClientNode** head, char* name_func2, int months_func2);
int transferMonths(struct ClientNode** head, char* name_giver, char* name_receiver);
int deleteClient(struct ClientNode** head, char* name_delete);
int searchClient(struct ClientNode** head, char* name_search);
int updateRemainingDays(struct ClientNode** head);


#endif 
