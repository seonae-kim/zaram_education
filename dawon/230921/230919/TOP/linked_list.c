#define DAY 50
#define NAME 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

struct node *head = NULL;

void insertbegin(char name[NAME], int age, char start_date[DAY], char end_date[DAY], int remain_period )
{
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    sprintf(lk-> data.name , "%s",name);
    lk-> data.age = age;
    sprintf(lk-> data.start_date , "%s",start_date);
    sprintf(lk-> data.end_date , "%s",end_date);
    lk-> data.remain_period = remain_period;

    lk->next = head;
    head = lk;
}

void insertend(char name[NAME], int age, char start_date[DAY], char end_date[DAY], int remain_period)
{
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    struct node *linkedlist = head;

    sprintf(lk-> data.name , "%s",name);
    lk-> data.age = age;
    sprintf(lk-> data.start_date , "%s",start_date);
    sprintf(lk-> data.end_date , "%s",end_date);
    lk-> data.remain_period = remain_period;


    if (head == NULL)
    {
        lk->next = head;
        head = lk;
    }
    else
    {
        while(1)
        {
            if(linkedlist->next == NULL)
                break; 
            linkedlist = linkedlist->next;
        }
        linkedlist->next = lk;
    }
}
int deletenode(char* data)
{
    struct node *temp = head, *prev;
    if (temp != NULL && strstr(temp->data.name,data) != NULL) {
        head = temp->next;
        return 1;
    }

    while (temp != NULL && strstr(temp->data.name,data) == NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return 0;

    prev->next = temp->next;
	free(temp);
    return 1;
}

void deletebegin()
{
    head = head->next;
}

void deleteend()
{
    struct node *linkedlist = head;
    while (linkedlist->next->next != NULL)
        linkedlist = linkedlist->next;
    linkedlist->next = NULL;
	free(linkedlist);
}

int searchlist(char* data)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        if (strstr(temp->data.name, data) != NULL)
        {
            printf("%s	%d	%s	%s	%d \n",
                    temp -> data.name, temp -> data.age ,temp -> data.start_date ,
                    temp -> data.end_date ,temp -> data.remain_period);
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
int extension(char* data, int period)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    struct node *temp = head;
    while (temp != NULL)
    {
        if(strstr(temp->data.name, data) != NULL)
        {
            temp->data.remain_period =  temp->data.remain_period + period;
            tm.tm_mon += temp->data.remain_period;
            mktime(&tm);

            sprintf(temp->data.end_date,"%d-%d-%d %d:%d",
                    tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);

            return 0;
        }
        temp = temp->next;
    }
}


int transfer(char *data1, char *data2)
{
    int A = 0;
    struct node *temp = head;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    while(temp != NULL)
    {
        if(strstr(temp->data.name, data1) != NULL)
        {
            A = temp->data.remain_period;
        }
        if(strstr(temp->data.name, data2) != NULL)
        {
            temp->data.remain_period = A + temp->data.remain_period;

            tm.tm_mon += temp->data.remain_period;
            mktime(&tm);

            sprintf(temp->data.end_date,"%d-%d-%d %d:%d",
                    tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);
        }
        temp = temp->next;
    }
    deletenode(data1);
    return 0;
}
void printList(){
      struct node *p = head;

      while(p != NULL)
      {
          printf(" %s	%d	%s	%s	%d \n",
                  p -> data.name, p -> data.age ,p -> data.start_date ,
                  p -> data.end_date ,p -> data.remain_period);

          p = p->next;
      }
  }

void updateall()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    struct node *p = head;
    int count = 0;
    int a = 0;
    int i = 0;
    int remainyear = 0, remainmon = 0, remainday = 0;
    int end_year = 0, end_mon = 0;
    char end_time[20] = {0};
    while(p != NULL)
    {
        count = 0;
        char *ptr = strtok(p->data.end_date , "-");
        while(ptr != NULL)
        {
            if (count == 0)
            {
                end_year =  atof(ptr);
                ptr = strtok(NULL, "-");
            }
            else if(count == 1)
            {
                end_mon = atof(ptr);
                ptr = strtok(NULL, "-");
            }

            else
            {
                ptr = strtok(NULL, "-");
            }

            if(strstr(ptr, ":") != NULL)
            {
                sprintf(end_time,"%s", ptr);
                ptr = strtok(NULL, "-");
            }

            count++;
        }

        remainyear = end_year - tm.tm_year-1900;
        remainmon = end_mon - tm.tm_mon-1;

        sprintf(p->data.end_date,"%d-%d-%s", end_year, end_mon, end_time);

                
        if(remainyear == 0 && remainday > 0)
        {
            p->data.remain_period = remainmon+1;
        }
        else if(remainyear > 0)
        {
            p->data.remain_period = remainyear * 12 + remainmon;
        }
        else if(remainyear == 0 && remainday < 0)
        {
            p->data.remain_period = remainmon-1;
        }

        p = p->next;
    }
}

void savefile()
{
    FILE *new = fopen("member_info.txt", "w");
    struct node *p = head;
    if(p != NULL)
    {
        while (p->next != NULL)
        {
            fprintf(new, "%s	%d	%s	%s	%d\n",
                 p->data.name,p->data.age ,p->data.start_date ,
                 p->data.end_date ,p->data.remain_period);

            p = p -> next;
        }
        fprintf(new, "%s	%d	%s	%s	%d\n",
                 p -> data.name, p -> data.age ,p -> data.start_date ,
                 p -> data.end_date ,p -> data.remain_period);
        p = p->next;
    }
	fclose(new);
}

/* void calculateDate()
{
    struct tm tm = *localtime(&t);


}
*/
