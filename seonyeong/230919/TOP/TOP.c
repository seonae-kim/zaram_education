#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "mode2.h"
#include "mode7.h"

struct member
{
	char name[20];
	int age;
	char start_date[50];
	char end_date[50];
	int remain_period;
};
			
struct node{
	struct member data;
	struct node *next;
};

struct node *head = NULL;

void insertbegin(char name[50], int age, char start_date[20], char end_date[20], int remain_period )
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

void insertend(char name[50], int age, char start_date[20], char end_date[20], int remain_period)
{
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    
	sprintf(lk-> data.name , "%s",name);
	lk-> data.age = age;
	sprintf(lk-> data.start_date , "%s",start_date);
	sprintf(lk-> data.end_date , "%s",end_date);
	lk-> data.remain_period = remain_period;
    
	struct node *linkedlist = head;

    while(linkedlist->next != NULL)
    {
		linkedlist = linkedlist->next;
	}

    linkedlist->next = lk; 
}

void deletenode(char* data)
{
	struct node *temp = head, *prev;
	if (temp != NULL && strstr(temp->data.name,data) != NULL) {
		head = temp->next;
		return;
	}

	while (temp != NULL && strstr(temp->data.name,data) == NULL) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) return;

	prev->next = temp->next;
	printf(" Success\n");
}

int searchlist(char* data)
{
	struct node *temp = head;
	while(temp != NULL) 
	{
		if (strstr(temp->data.name, data) != NULL) 
		{
			printf("%s %d %s %s %d \n", 
					temp -> data.name, temp -> data.age ,temp -> data.start_date ,
					temp -> data.end_date ,temp -> data.remain_period);
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}

void printList(){
      struct node *p = head;
  
      while(p != NULL) 
	  {
          printf(" %s %d %s %s %d \n", 
				  p -> data.name, p -> data.age ,p -> data.start_date ,
				  p -> data.end_date ,p -> data.remain_period);

          p = p->next;
      }
  }


int main()
{
	int mode = 0;
	int e = 0;
	int i = 0;
	int p = 0;
	FILE *fp;
	struct member data[50] ;
	struct node node;
	char buffer[255] = {0};
	int count = 0;
	char name[50], start_date[20], end_date[20];
	int age, remain_period;
	char user[20] = {0};
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);


	
	if((fp = fopen("member_info.txt", "r")) == NULL)
	{
		printf("fail\n");
	}
	
	while(1)
    {
        if(fgets(buffer, sizeof(buffer), fp) == NULL)
            break;
		count = 0;
        char *ptr = strtok(buffer, "\t");
        while(ptr != NULL)
        {   
			if(count == 0)
            {
                sprintf(name,"%s",ptr);
                ptr = strtok(NULL, "\t");
            }
			else if(count == 1)
            {
                age =atof(ptr);
                ptr = strtok(NULL, "\t");
            }
			else if(count == 2)
            {
                sprintf(start_date,"%s",ptr);
                ptr = strtok(NULL, "\t");
            }
			else if(count == 3)
            {
                sprintf(end_date,"%s",ptr);
                ptr = strtok(NULL, "\t");
            }
			else if(count == 4)
            {
                remain_period = atof(ptr);
                ptr = strtok(NULL, "\t");
            }
			else
			{
				ptr = strtok(NULL, "\t");
			}	
			
			count++;
        }
			if(p == 0)
			{
				insertbegin(name, age, start_date, end_date, remain_period);
			}
			else
			{
				insertend(name, age, start_date, end_date, remain_period);
			}
		  
			p++;
    }

	fclose(fp);

	while(1)
	{
		if(e == 1)
			break;

		printf("\n # MEMBERSHIP PROGRAM #\n Select Mode\n 1-Registration\n 2-Extension of the period\n 3-Transfer of membership\n 4-Delete membership\n 5-Search membership \n 6-View all information \n 7-Update all membership \n 8-exit\n");

		scanf("%d", &mode);


		switch(mode)
		{
			case 1:
/*				while(1)
				{
					if(count == 1)
						break;
					if(count > 1 || count == 0|| p >= 1)
					{
						printf("\n< New member registration > \n name, age, period: ");
						scanf("%s %d %d", name, &age, &remain_period);
					}
					int k = searchlist(name);
					if(k==1)
					{
						count = 1;
						printf("\n The name is already exists\n Try Again");
						count++;
					}
					else
					{
						count = 1;
					}
				}
				sprintf(start_date,"%d-%d-%d %d:%d", 
						tm.tm_year+1900,tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);
				
				tm.tm_mon += remain_period;
				mktime(&tm);
				
				sprintf(end_date,"%d-%d-%d %d:%d",
						tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);

				insertend(name, age, start_date, end_date, remain_period);
*/
				break;
		
			case 2:
				mode2(1);
				break;

			case 3:
		        break;
	
			case 4:
				fp=fopen("member_info.txt","a");
				printf(" < Delete Membership >\n user name : ");
				scanf("%s", user);

				deletenode(user);
				
				break;

			case 5:
				printf(" < Search Member >\n user name : ");
				scanf("%s", user);

				int k = searchlist(user);
				if(k == 1)
					printf(" User is found\n");
				else 
					printf(" User is not present in the list");
				break;

			case 6:
				printList();	
				break;

			case 7:
				mode7(1);
				break;

			case 8:
				printf(" FINISH\n");
				e++;
				break;	

			default :
				e++;
				break;
		}

	}
	fclose(fp);
	return 0;
}
