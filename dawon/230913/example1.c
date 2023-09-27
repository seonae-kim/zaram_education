#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int main()
{
	FILE *f;
	FILE *fout;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char *file;
	int n;
	int i=0,j=0,k=0;
	int pnum=0, flag_name=0, date=0, period =0,total=0,regnum=0, f_flag=0, p=0,flag = 0;
	int age=0;
	int year, day;
	int word;
	char name[10]={0, };
	char arr[200]={0, };
	char buf[100]={0, };
	char age_ch[5]={0, };
	char period_ch[5]={0, };
	char array_inquire[200]={0, };
	char *n_temp;
	struct node *head = NULL;
	struct node *prev = NULL;
	struct node  *current = NULL;
	M a[20];
	
	printf("start \n");
	
	f=fopen("program.txt","r");
	if(f==NULL)
	{
		printf("no file to read\n");
	}
	
	else
	{
		while(EOF !=fscanf(f,"%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", a[i].name, &a[i].age,&a[i].start.year,&a[i].start.mon,&a[i].start.mday,&a[i].start.hour,&a[i].start.min,&a[i].end.year,&a[i].end.mon,&a[i].end.mday,&a[i].end.hour,&a[i].end.min,&a[i].remain.year,&a[i].remain.mon,&a[i].remain.mday,&a[i].remain.hour,&a[i].remain.min))
		{	
		
			if(head == NULL)
			{
				head=insertatbegin(head,a[i]);
				printf("\n\n");
			}
			else
			{
				head=insertatend(head,a[i]);
			}

			i++;		
		}
		
		regnum=i;
		total = regnum;

	}
	printList(head);	
	
	while(1)
	{
		flag = 0;
		flag_name = 0;
		printf("\n1: register 2: extend 3: transfer 4: delete 5: inquire 6: inquire all 7: renew 8: quit >> ");

		scanf("%d",&n);
		while (getchar() != '\n');
		
		if(!(n > 0 && n < 9))
		{
			continue;
		}

		if(n==8)
		{
			printf("program exit\n");
			free(head);
			break;
		}

		if(n == 1)
		{	
				flag = 0;
				flag_name = 0;
				memset(name,'\0',100);
				f=fopen("program.txt","a");
				if(f == NULL)
				{
					printf("no file");
					exit(0);
				}

				printf("\npnum to register: ");
				scanf("%d",&pnum);
				printf("Name, Age, Period: ");
				scanf("%s %s %s",name,age_ch,period_ch);	
				age = atoi(age_ch);
				period = atoi(period_ch);

				for(i = 0; i < strlen(name); i++)
				{
					if(!(name[i] >= 'a' && name[i] <= 'z') && !(name[i] >= 'A' && name[i] <= 'Z'))
					{
						printf("name error\n");
						flag=1;
						break;
					}
				}
				for(i = 0; i < strlen(age_ch); i++)
				{
					if(!(age_ch[i] >= '0' && age_ch[i] <= '9') 
						|| ((age_ch[i] >= 'a' && age_ch[i] <= 'z') 
						&& (age_ch[i] >= 'A' && age_ch[i] <= 'Z')))
					{
						printf("age error\n");
						flag=1;
						break;
					}
				}
				for(i = 0; i < strlen(period_ch); i++)
				{
					if((!age_ch[i] >= '0' && age_ch[i] <= '9') 
						|| ((period_ch[i] >= 'a' && period_ch[i] <= 'z') 
						&& (period_ch[i] >= 'A' && period_ch[i] <= 'Z')))
					{
						printf("period error\n");
						flag=1;
						break;
					}
				}
				if(strlen(name) > 10)
				{
					printf("strlen name error > 10\n");
					continue;
				}
				if(strlen(age_ch) > 5)
				{
					printf("strlen age error > 5\n");
					continue;
				}
				if(strlen(period_ch) > 5)
				{
					printf("strlen period error > 5\n");
					continue;
				}

				if(flag == 1)
					continue;

				if(regnum == 0)
				{
					total = pnum;
					printf("TOTAL1: %d\n",total);
					for(i=0; i < pnum; i++)
					{				
						for(int j = 0; j < i; j++)
						{	
							if(strcmp(name,a[j].name) == 0)
							{
								printf("same name1");
								flag_name = 1;
								memset(name,'\0',100);
								break;
							}
						}
						if(flag_name == 1)
							break;

						else
						{
							strcpy(a[i].name,name);
							a[i].age = age;
							a[i].start.year = tm.tm_year + 1900;
							a[i].start.mon = tm.tm_mon + 1;
							a[i].start.mday = tm.tm_mday;
							a[i].start.hour = tm.tm_hour;
							a[i].start.min = tm.tm_min;
							a[i].start.year = tm.tm_year + 1900;
							a[i].end.year = a[i].start.year + period / 12;
							a[i].end.mon = a[i].start.mon+period % 12;
							a[i].end.mday = tm.tm_mday;
							a[i].end.hour = tm.tm_hour;
							a[i].end.min = tm.tm_min;
							a[i].remain.year = period / 12;
							a[i].remain.mon = period % 12;
							a[i].remain.mday = 0;
							a[i].remain.hour = 0;
							a[i].remain.min = 0;
							if(a[i].end.mon > 12)
							{
								a[i].end.year += 1;
								a[i].end.mon -= 12;
							}
				
							fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",
										a[i].name,a[i].age,a[i].start.year,a[i].start.mon,a[i].start.mday,a[i].start.hour,a[i].start.min,
										a[i].end.year,a[i].end.mon,a[i].end.mday,a[i].end.hour,a[i].end.min,
										a[i].remain.year,a[i].remain.mon,a[i].remain.mday,a[i].remain.hour,a[i].remain.min);
							if(head == NULL)
							{
								head=insertatbegin(head,a[i]);
							}
							else
							{
								head=insertatend(head,a[i]);
							}	
							regnum = pnum;
						}

					}
					if(flag_name == 1)
						continue;
				}
				else
				{
					total += pnum;
					printf("TOTAL2: %d\n",total);
					for(i = regnum; i < total; i++)
					{
						for(int j = 0; j < i; j++)
						{	
							if(strcmp(name,a[j].name) == 0)
							{
								printf("same name2");
								flag_name = 1;
								memset(name,'\0',100);
								break;
							}
						}
						if(flag_name == 1)
							break;

						else
						{
							strcpy(a[i].name,name);
							a[i].age = age;
							a[i].start.year = tm.tm_year + 1900;
							a[i].start.mon = tm.tm_mon + 1;
							a[i].start.mday = tm.tm_mday;
							a[i].start.hour = tm.tm_hour;
							a[i].start.min = tm.tm_min;
							a[i].start.year = tm.tm_year + 1900;
							a[i].end.year = a[i].start.year + period / 12;
							a[i].end.mon = a[i].start.mon + period % 12;
							a[i].end.mday = tm.tm_mday;
							a[i].end.hour = tm.tm_hour;
							a[i].end.min = tm.tm_min;
							a[i].remain.year = period / 12;
							a[i].remain.mon = period % 12;
							a[i].remain.mday = 0;
							a[i].remain.hour = 0;
							a[i].remain.min = 0;
							if(a[i].end.mon > 12)
							{
								a[i].end.year += 1;
								a[i].end.mon -= 12;
							}
				
							fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",
										a[i].name,a[i].age,a[i].start.year,a[i].start.mon,a[i].start.mday,a[i].start.hour,a[i].start.min,
										a[i].end.year,a[i].end.mon,a[i].end.mday,a[i].end.hour,a[i].end.min,
										a[i].remain.year,a[i].remain.mon,a[i].remain.mday,a[i].remain.hour,a[i].remain.min);
							if(head == NULL)
							{
								head=insertatbegin(head,a[i]);
							}
							else
							{
								head=insertatend(head,a[i]);
							}							

						}
						regnum += pnum;

					}
					if(flag_name == 1)
						continue;
				}
			
				printf("TOTAL: %d\n",total);
				printList(head);
				fclose(f);		
		}
	
		else if(n==2)
		{
			char *tmp;
			char update_year[10], update_mon[10];
			char date_ch[5] = {0, };
			int i=0, search_name=0;
			struct node *temp=NULL;
			flag = 0;
			memset(date_ch,'\0',5);	
			
			f=fopen("program.txt","r+");
	
			if(f == NULL)
			{
				printf("no file");
				exit(0);
			}	
			
			printf("name: ");
			scanf("%s",name);
			for(i = 0; i < strlen(name); i++)
			{	
				if(!(name[i] >= 'a' && name[i] <= 'z') && !(name[i] >= 'A' && name[i] <= 'Z'))
				{
						printf("name error\n");
						flag=1;
						break;
				}
			}
		
			printf("extend:");
			scanf("%s",date_ch);
			date = atoi(date_ch);			
			for(i = 0; i < strlen(date_ch); i++)
			{
				if(!(date_ch[i] >= '0' && date_ch[i] <= '9') 
					|| ((date_ch[i] >= 'a' && date_ch[i] <= 'z') 
					&& (date_ch[i] >= 'A' && date_ch[i] <= 'Z')))
					{
						printf("age error\n");
						flag=1;
						break;
					}
			}
			if(flag == 1)
				continue;

			if(strlen(date_ch) > 5)
			{
				printf("strlen date error\n");
				continue;
			}	
		
			temp=searchlist_name(head,name);
			if(temp == NULL)
			{
				printf("No such name1\n");
				continue;
			}

			temp->data.end.year += date / 12;
			temp->data.end.mon += date % 12;
			if(temp->data.end.mon > 12)
			{
				temp->data.end.year += 1;
				temp->data.end.mon -=12;
			}
			temp->data.remain.year += date / 12;
			temp->data.remain.mon += date % 12;
			if(temp->data.remain.mon > 12)
			{
				temp->data.remain.year += 1;
				a[i].remain.mon -=12;
			}
			printList(head);

			for(i = 0; i < total; i++)
			{
				if(strcmp(name,a[i].name) == 0)
				{
					a[i].end.year += date / 12;
					a[i].end.mon  += date % 12;
					if(a[i].end.mon > 12)
					{
						a[i].end.year += 1;
						a[i].end.mon -=12;
					}
					a[i].remain.year += date / 12;
					a[i].remain.mon += date % 12;
					if(a[i].remain.mon > 12)
					{
						a[i].remain.year += 1;
						a[i].remain.mon -= 12;
					}

					flag_name = 1;
				}

			}

			if(flag_name == 0)
			{
				printf("No such name2\n");
				continue;
			}
			for(i = 0; i < total; i++)
			{
				fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",
						a[i].name,a[i].age,a[i].start.year,a[i].start.mon,a[i].start.mday,a[i].start.hour,a[i].start.min,
						a[i].end.year,a[i].end.mon,a[i].end.mday,a[i].end.hour,a[i].end.min,
						a[i].remain.year,a[i].remain.mon,a[i].remain.mday,a[i].remain.hour,a[i].remain.min);
			}
			fclose(f);
					
		}
	
		else if(n==3)
		{
			char from_name[10], to_name[10];
			int i=0;
			int from_index=0, to_index=0, from_flag=0, to_flag=0;
			int n_flag=0;
			struct node *from;
			struct node	*to;
			struct node *temp;

			f_flag = 0;
			flag = 0;
			printf("From name: ");
			scanf("%s",from_name);
			printf("To name: ");
			scanf("%s",to_name);

			for(i = 0; i < strlen(from_name); i++)
			{
				if(!(from_name[i] >= 'a' && from_name[i] <= 'z') && !(from_name[i] >= 'A' && from_name[i] <= 'Z'))
				{
					printf("from name error\n");
					flag=1;
					break;
				}
			}

			for(i = 0; i < strlen(to_name); i++)
			{
				if(!(to_name[i] >= 'a' && to_name[i] <= 'z') && !(to_name[i] >= 'A' && to_name[i] <= 'Z'))
				{
					printf("to name error\n");
					flag=1;
					break;
				}
			}

			if(flag == 1)
				continue;
			
			from=searchlist_name(head,from_name);
			to=searchlist_name(head,to_name);

			if(from==NULL)
			{
				printf("No from name\n");
				continue;
			}
			
			if(to==NULL)
			{
				printf("No to name\n");
				continue;
			}


			to->data.remain.year += from->data.remain.year;
			to->data.remain.mon += from->data.remain.mon;

			if(to->data.remain.mon > 12)
			{
				to->data.remain.year += (to->data.remain.mon / 12);
				to->data.remain.mon -= 12;
			}

			to->data.end.year += from->data.remain.year;
			to->data.end.mon += from->data.remain.mon;

			if(to->data.end.mon > 12)
			{
				to->data.end.year += (to->data.end.mon / 12);
				to->data.end.mon -= 12;
			}
			
			temp = deletenode_name(head,from_name,&f_flag);
			if(temp == NULL && f_flag == 0)
			{
				printf("No such name\n");
				continue;
			}	
			
			head = temp;
			printList(head);											//linked

			for(i = 0; i < total; i++)
			{
				if(strcmp(from_name,a[i].name) == 0)
				{
					from_index=i;
					from_flag=1;
				}
				if(strcmp(to_name,a[i].name) == 0)
				{
					to_index = i;
					to_flag = 1;
				}
			}
			
			if(from_flag == 0)
			{
				printf("No from name\n");
				continue;
			}

			if(to_flag == 0)
			{
				printf("No to name\n");
				continue;
			}
			
			f=fopen("program.txt","w");

			a[to_index].remain.year += a[from_index].remain.year;
			a[to_index].remain.mon += a[from_index].remain.mon;
	

			if(a[to_index].remain.mon > 12)
			{
				a[to_index].remain.year += (a[to_index].remain.mon / 12);
				a[to_index].remain.mon -= 12;
			}

			a[to_index].end.year += a[from_index].remain.year;
			a[to_index].end.mon += a[from_index].remain.mon;
		
			if(a[to_index].end.mon > 12)
			{
				a[to_index].end.year += (a[to_index].end.mon / 12);
				a[to_index].end.mon -= 12;
			}
			

			for(i = 0; i < total; i++)
			{			
				if(i == from_index)
					continue;
				fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",
						a[i].name,a[i].age,a[i].start.year,a[i].start.mon,a[i].start.mday,a[i].start.hour,a[i].start.min,
						a[i].end.year,a[i].end.mon,a[i].end.mday,a[i].end.hour,a[i].end.min,
					a[i].remain.year,a[i].remain.mon,a[i].remain.mday,a[i].remain.hour,a[i].remain.min);
			}
			
			for(i = 0; i < total; i++)
			{	
				if(i > from_index)
				{
					strcpy(a[i-1].name,a[i].name);
					a[i-1].age = a[i].age;
					a[i-1].start.year = a[i].start.year;
					a[i-1].start.mon = a[i].start.mon;
					a[i-1].start.mday = a[i].start.mday;
					a[i-1].start.hour = a[i].start.hour;
					a[i-1].start.min = a[i].start.min;
					a[i-1].end.year = a[i].end.year;
					a[i-1].end.mon = a[i].end.mon;
					a[i-1].end.mday =a[i].end.mday;
					a[i-1].end.hour = a[i].end.hour;
					a[i-1].end.min = a[i].end.min;
					a[i-1].remain.year = a[i].remain.year;
					a[i-1].remain.mon = a[i].remain.mon;
					a[i-1].remain.mday = a[i].remain.mday;
					a[i-1].remain.hour = a[i].remain.hour;
					a[i-1].remain.min = a[i].remain.min;
				}
			}
			memset(a[total-1].name,'\0',100);
			total--;
			regnum--;
			fclose(f);
		}
		
	
		else if(n==4)
		{
			struct node *node = NULL;
			struct node *temp=NULL;
			int i=0;
			int n_flag=0, f_flag=0;
			int index_name=0;
			
			flag = 0;
			node = head;
			if(f==NULL)
			{
				printf("no file\n");
				exit(0);
			}

			printf("Name to find: ");
			scanf("%s",name);
			for(i = 0; i < strlen(name); i++)
			{
				if(!(name[i] >= 'a' && name[i] <= 'z') && !(name[i] >= 'A' && name[i] <= 'Z'))
				{
					printf("name error\n");
					flag=1;
					break;
				}
			}
			if(flag == 1)
				continue;

			temp=deletenode_name(head,name,&f_flag);

			if(temp == NULL && f_flag == 0)
			{
				printf("No such name\n");
				head = node;
				continue;
			}
			else
			{
				head=temp;
			}
			printList(head);

			for(i = 0; i < total; i++)
			{
				printf("strcmp: %d\n",strcmp(name,a[i].name));
				if(strcmp(name,a[i].name) == 0)
				{
					index_name = i;
					n_flag=1;
					break;
				}
			}
			

			if(n_flag == 0)
			{
				printf("No such name2\n");
				continue;
			}
			
			f=fopen("program.txt","w");
			if(f == NULL)
			{
				printf("No file\n");
				exit(0);
			}

			for(i = 0; i < total; i++)
			{			
				if(i == index_name)
					continue;
				fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",
						a[i].name,a[i].age,a[i].start.year,a[i].start.mon,a[i].start.mday,a[i].start.hour,a[i].start.min,
						a[i].end.year,a[i].end.mon,a[i].end.mday,a[i].end.hour,a[i].end.min,
					a[i].remain.year,a[i].remain.mon,a[i].remain.mday,a[i].remain.hour,a[i].remain.min);
			}
			
			for(i = 0; i < total; i++)
			{	
				if(i > index_name)
				{
					strcpy(a[i-1].name,a[i].name);
					a[i-1].age = a[i].age;
					a[i-1].start.year = a[i].start.year;
					a[i-1].start.mon = a[i].start.mon;
					a[i-1].start.mday = a[i].start.mday;
					a[i-1].start.hour = a[i].start.hour;
					a[i-1].start.min = a[i].start.min;
					a[i-1].end.year = a[i].end.year;
					a[i-1].end.mon = a[i].end.mon;
					a[i-1].end.mday =a[i].end.mday;
					a[i-1].end.hour = a[i].end.hour;
					a[i-1].end.min = a[i].end.min;
					a[i-1].remain.year = a[i].remain.year;
					a[i-1].remain.mon = a[i].remain.mon;
					a[i-1].remain.mday = a[i].remain.mday;
					a[i-1].remain.hour = a[i].remain.hour;
					a[i-1].remain.min = a[i].remain.min;
				}
			}
			memset(a[total-1].name,'\0',100);
			memset(name,'\0',10);
			total--;
			regnum--;

			fclose(f);
		}
	
	
	
		else if(n==5)
		{
			struct node *temp;
			flag = 0;
		
			printf("Name to find: ");
			scanf("%s",name);
			for(i = 0; i < strlen(name); i++)
			{
				if(!(name[i] >= 'a' && name[i] <= 'z') && !(name[i] >= 'A' && name[i] <= 'Z'))
				{
					printf("name error\n");
					flag=1;
					break;
				}
			}
			if(flag == 1)
				continue;

			temp=searchlist_name(head,name);
			if(temp == NULL)
			{
				printf("No such name\n");
				continue;
			}
			
			printf("Name: %s\n",temp->data.name);
			printf("Age: %d\n",temp->data.age);
			printf("Start date: %d/%d/%d/%d/%d \n",temp->data.start.year,temp->data.start.mon,temp->data.start.mday,temp->data.start.hour,temp->data.start.min);
			printf("End date: %d/%d/%d/%d/%d \n",temp->data.end.year,temp->data.end.mon,temp->data.end.mday,temp->data.end.hour,temp->data.end.min);
			printf("Remain: %d/%d/%d/%d/%d \n",temp->data.remain.year,temp->data.remain.mon,temp->data.remain.mday,temp->data.remain.hour,temp->data.remain.min);


			printf("\n");
		}

		else if(n==6)
		{			
			printList(head);

		}

		else if(n==7)
		{
			struct node* temp;
			f=fopen("program.txt","w");
			if(f == NULL)
			{
				printf("no file");
				exit(0);
			}
			temp=head;
			while(temp != NULL)
			{
				temp->data.remain.year = temp->data.end.year-(tm.tm_year+1900);
				temp->data.remain.mon = temp->data.end.mon-(tm.tm_mon+1);
				temp->data.remain.mday = temp->data.end.mday-tm.tm_mday;
				temp->data.remain.hour = temp->data.end.hour-tm.tm_hour;
				temp->data.remain.min = temp->data.end.min-tm.tm_min;

				if(temp->data.remain.mon < 0)
				{
					temp->data.remain.year -= 1;
					temp->data.remain.mon = 12 + temp->data.remain.mon;
				}
				temp=temp->next;
			}
			printList(head);											//linked list

			for(i = 0; i < total; i++)
			{				
				printf("remain1: %d\n",a[i].remain.year); 
				printf("tm: %d\n",tm.tm_year+1900);

				a[i].remain.year = a[i].end.year-(tm.tm_year+1900);
				a[i].remain.mon = a[i].end.mon-(tm.tm_mon+1);
				a[i].remain.mday = a[i].end.mday-tm.tm_mday;
				a[i].remain.hour = a[i].end.hour-tm.tm_hour;
				a[i].remain.min = a[i].end.min-tm.tm_min;
				if(a[i].remain.mday < 0)
				{
					a[i].remain.mon -= 1;
					a[i].remain.mday = 30 + a[i].remain.mday;
				}

				if(a[i].remain.mon < 0)
				{
					a[i].remain.year -= 1;
					a[i].remain.mon = 12 + a[i].remain.mon;
				}

				fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",
						a[i].name,a[i].age,a[i].start.year,a[i].start.mon,a[i].start.mday,a[i].start.hour,a[i].start.min,
						a[i].end.year,a[i].end.mon,a[i].end.mday,a[i].end.hour,a[i].end.min,
						a[i].remain.year,a[i].remain.mon,a[i].remain.mday,a[i].remain.hour,a[i].remain.min);


			}
			fclose(f);

		}

	}

	return 0;
}



					






