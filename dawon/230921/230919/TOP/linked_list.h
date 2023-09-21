#include <stdio.h>
struct member
{
    char name[NAME];
    int age;
    char start_date[DAY];
    char end_date[DAY];
    int remain_period;
};

struct node{
    struct member data;
    struct node *next;
};

void insertbegin(char name[50], int age, char start_date[20], char end_date[20], int remain_period );

void insertend(char name[50], int age, char start_date[20], char end_date[20], int remain_period);

int deletenode(char* data);

void deletebegin();

void deleteend();

int searchlist(char* data);

int extension(char* data, int period);

int transfer(char *data1, char *data2);

void printList();

void updateall();

void savefile();



