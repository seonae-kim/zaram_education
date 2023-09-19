#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
typedef struct date
{
	int year;
	int mon;
	int mday;
	int hour;
	int min;
}D;
typedef struct member
{
	char name[30];
	int age;
	D start;
	D end;
	D remain;
}M;

typedef struct node {
	M data;
	struct node *next;
}L;

struct node *head = NULL;
struct node *prev = NULL;
struct node *cur = NULL;

int main()
{
	FILE *f;
	FILE *fout;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char *file;
	int n;
	int i,j,k;
	int pnum=0, flag_name=0, date=0, period =0;
	int age=0;
	int year, day;
	int word;
	char name[10]={0, };
	char arr[200]={0, };
	char buf[100]={0, };
	char array_inquire[200]={0, };
	char *n_temp;
	
	M a[20];
	L *lk;

	lk=(L*)malloc(sizeof(L));
	if(lk == NULL)
	{
		printf("malloc error\n");
		exit(0);
	}
	
	while(1)
	{
		printf("1: register 2: extend 3: transfer 4: delete 5: inquire 6: inquire all 7: renew 8: quit >> ");

		scanf("%d",&n);
		while (getchar() != '\n');

		
		if(!(n > 0 && n < 9))
		{
			continue;
		}

		if(n==8)
		{
			printf("program exit\n");
			break;
		}

		if(n == 1)
		{
			
				char* tmp;
				tmp=file;
				file=(char *)malloc(sizeof(char)*400);
				lk=(L*)malloc(sizeof(L));
				if(lk == NULL)
				{
					printf("malloc error\n");
					exit(0);
				}

				if(file == NULL)
				{
					printf("malloc error\n");
					exit(0);
				}
	
				f=fopen("program.txt","w");
	
				if(f == NULL)
				{
					printf("no file");
					exit(0);
				}

				printf("pnum to register: ");
				scanf("%d",&pnum);
				for(int i=0; i < pnum; i++)
				{
					printf("name, age period: ");
					scanf("%s %d %d",a[i].name,&a[i].age,&period);
					for(int j = 0; j < i; j++)
					{	
						if(strcmp(a[i].name,a[j].name) == 0)
						{
							printf("same name");
							i--;
							flag_name = 1;
							break;
						}
					}
					if(flag_name ==1)
						break;

					a[i].start.year = tm.tm_year+1900;
					a[i].start.mon = tm.tm_mon+1;
					a[i].start.mday = tm.tm_mday;
					a[i].start.hour = tm.tm_hour;
					a[i].start.min = tm.tm_min;
					a[i].start.year = tm.tm_year+1900;
					a[i].end.year = a[0].start.year + period/12;
					a[i].end.mon = a[0].start.mon+period%12;
					a[i].end.mday = tm.tm_mday;
					a[i].end.hour = tm.tm_hour;
					a[i].end.min = tm.tm_min;
					a[i].remain.year = period/12;
					a[i].remain.mon = period%12;
					a[i].remain.mday = 0;
					a[i].remain.hour = 0;
					a[i].remain.min = 0;
					
					if(a[i].end.mon > 12)
					{
						a[i].end.year += 1;
						a[i].end.mon -=12;
					}
				
					fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",
								a[i].name,a[i].age,a[i].start.year,a[i].start.mon,a[i].start.mday,a[i].start.hour,a[i].start.min,
								a[i].end.year,a[i].end.mon,a[i].end.mday,a[i].end.hour,a[i].end.min,
								a[i].remain.year,a[i].remain.mon,a[i].remain.mday,a[i].remain.hour,a[i].remain.min);

					if(head == NULL)
					{
						insertatbegin(a[i]);
					}
					else
						insertatend(a[i]);

				}
				
				printList(head);
				if(flag_name ==1)
					continue;	
								
	
				file=tmp;
				fclose(f);
				free(file);
			
		}
	
		else if(n==2)
		{
			char *tmp;
			char update_year[10], update_mon[10];
			int i=0, search_name=0;
			L *temp=NULL;
			tmp=file;
			f=fopen("program.txt","r+");
			file=(char *)malloc(sizeof(char)*400);
			if(file == NULL)
			{
				printf("malloc error\n");
				exit(0);
			}
	
			if(f == NULL)
			{
				printf("no file");
				exit(0);
			}	
			
			printf("name: ");
			scanf("%s",name);
			printf("extend:");
			scanf("%d",&date);
	
/*			while(!(feof(f)))
			{
				file=fgets(arr,100,f);
				n_temp=strstr(arr,name);
				if(n_temp != NULL)
					break;
			}
*/
		
			temp=searchlist_name(name);
			if(temp == NULL)
			{
				printf("no such name\n");
				continue;
			}

			temp->data.end.year += date / 12;
			temp->data.end.year += date % 12;
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
			printf("year update: %d\n",temp->data.end.year);
			printf("mon update: %d\n",temp->data.end.mon);



/*			for(i = 0; i < pnum; i++)
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
						a[i].remain.mon -=12;
					}

					printf("year update: %d\n", a[i].end.year);
					printf("mon update: %d\n",a[i].end.mon);
					flag_name=1;
				}

			}

			if(flag_name == 0)
			{
				printf("no such name\n");
				continue;
			}


			printf("start point: %d\n",ftell(f));	
			if(n_temp == NULL)
			{
				printf("no name\n");
				exit(0);
			}
	
			word = strlen(arr) - (n_temp-arr) + 1;
			fseek(f,-1 * word, SEEK_CUR);

	
			fscanf(f,"%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", a[0].name, &a[0].age,&a[0].start.year,&a[0].start.mon,&a[0].start.mday,&a[0].start.hour,&a[0].start.min,&a[0].end.year,&a[0].end.mon,&a[0].end.mday,&a[0].end.hour,&a[0].end.min,&a[0].remain.year,&a[0].remain.mon,&a[0].remain.mday,&a[0].remain.hour,&a[0].remain.min);


			printf("from file: %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",a[0].name, a[0].age,a[0].start.year,a[0].start.mon,a[0].start.mday,a[0].start.hour,a[0].start.min,a[0].end.year,a[0].end.mon,a[0].end.mday,a[0].end.hour,a[0].end.min,a[0].remain.year,a[0].remain.mon,a[0].remain.mday,a[0].remain.hour,a[0].remain.min);
	
	
			a[0].end.year += date / 12;
			a[0].end.mon  += date % 12;
	
			if(a[0].end.mon > 12)
			{
				a[0].end.year += 1;
				a[0].end.mon -=12;
			}
			
		
			for(i = 0; i < pnum; i++)
			{
				fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",
						a[i].name,a[i].age,a[i].start.year,a[i].start.mon,a[i].start.mday,a[i].start.hour,a[i].start.min,
						a[i].end.year,a[i].end.mon,a[i].end.mday,a[i].end.hour,a[i].end.min,
						a[i].remain.year,a[i].remain.mon,a[i].remain.mday,a[i].remain.hour,a[i].remain.min);
			}

	
	//		word = strlen(arr) - (n_temp+3-arr) + 1;
	//		fseek(f, -1 * word, SEEK_CUR);
//			fwrite(update_year,1,4,f);
	
			if(a[0].end.mon > 9)
			{
				fseek(f,4,SEEK_CUR);
				fwrite(update_mon,1,2,f);
			}
			else
			{
				fseek(f,4,SEEK_CUR);
				fwrite(update_mon,1,1,f);
			}
	*/
			file=tmp;
			fclose(f);
			free(file);
					
		}
	
		else if(n==3)
		{
			char from_name[10], to_name[10];
			int i=0;
			int from_index=0, to_index=0, from_flag=0, to_flag=0;
			int n_flag=0;

			printf("from name: ");
			scanf("%s",from_name);
			printf("to name: ");
			scanf("%s",to_name);
			
			for(i = 0; i < pnum; i++)
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
				
			
			if(from_flag==0)
			{
				printf("no from name\n");
				continue;
			}
			
			if(to_flag==0)
			{
				printf("no to name\n");
				continue;
			}

			a[to_index].remain.year += a[from_index].remain.year;
			a[to_index].remain.mon += a[from_index].remain.mon;
			a[to_index].remain.mday += a[from_index].remain.mday;
			a[to_index].remain.hour += a[from_index].remain.hour;
			a[to_index].remain.min += a[from_index].remain.min;
			a[to_index].end.year += a[to_index].remain.year;
			a[to_index].end.mon += a[to_index].remain.mon;
			a[to_index].end.mday += a[to_index].remain.mday; 
			a[to_index].end.hour += a[to_index].end.hour;
			a[to_index].end.min += a[to_index].end.min;

			if(a[to_index].remain.min > 60)
			{
				a[to_index].remain.hour += (a[to_index].remain.hour / 60);
				a[to_index].remain.min %= 60;
			}

			if(a[to_index].remain.hour > 24)
			{	
				a[to_index].remain.mday += (a[to_index].remain.mday / 24);
				a[to_index].remain.hour %= 24;
			}

			
			if(a[to_index].remain.mday > 30)
			{
				a[to_index].remain.mon += (a[to_index].remain.mon / 30);
				a[to_index].remain.mday %= a[to_index].remain.mday;
			}

			if(a[to_index].remain.mon > 12)
			{
				a[to_index].remain.year += (a[to_index].remain.year / 12);
				a[to_index].remain.mon -= 12;
			}
			
			for(i = 0; i < pnum; i++)
			{			
				if(i == from_index)
					continue;
				fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",
						a[i].name,a[i].age,a[i].start.year,a[i].start.mon,a[i].start.mday,a[i].start.hour,a[i].start.min,
						a[i].end.year,a[i].end.mon,a[i].end.mday,a[i].end.hour,a[i].end.min,
					a[i].remain.year,a[i].remain.mon,a[i].remain.mday,a[i].remain.hour,a[i].remain.min);
			}
			
			for(i = 0; i < pnum; i++)
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
			pnum--;	
	
	
		}
		
	
		else if(n==4)
		{
			int i=0;
			int n_flag=0;
			char *tmp;
			int index_name=0;
			int p=0;
	
			f=fopen("program.txt","r");
//			fout=fopen("newfile.txt","w");

			file=(char *)malloc(sizeof(char)*400);
			if(file == NULL)
			{
				printf("malloc error\n");
				exit(0);
			}
			tmp=file;
	
			if(f==NULL)
			{
				printf("no file\n");
				exit(0);
			}
/*			if(fout==NULL)
			{
				printf("no file\n");
				exit(0);
			}
*/	
			printf("name to find: ");
			scanf("%s",name);

/*			while(!feof(f))
			{
				memset(arr,0,200);
				file=fgets(arr,200,f);
				n_temp=strstr(arr,name);
				if(n_temp != NULL)
				{	
					n_flag=1;
					n_temp=NULL;
					continue;
				}
				for(i = 0; i < strlen(arr); i++)
				{			
					printf("%c",arr[i]);
				}
				fputs(arr,fout);
				printf("\n");
				printf("\n");
			}
*/	

			p=deletenode(name);
			if(p == 0)
			{
				printf("no such name\n");
				continue;
			}			
			if(i > (p-1))
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

/*			for(i = 0; i < 2; i++)
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
				printf("no such name\n");
				continue;
			}

			fclose(f);

			f=fopen("program.txt","w");
			if(f == NULL)
			{
				printf("no file\n");
				exit(0);
			}

			for(i = 0; i < pnum; i++)
			{			
				if(i == index_name)
					continue;
				fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",
						a[i].name,a[i].age,a[i].start.year,a[i].start.mon,a[i].start.mday,a[i].start.hour,a[i].start.min,
						a[i].end.year,a[i].end.mon,a[i].end.mday,a[i].end.hour,a[i].end.min,
					a[i].remain.year,a[i].remain.mon,a[i].remain.mday,a[i].remain.hour,a[i].remain.min);
			}
			
			for(i = 0; i < pnum; i++)
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
*/			pnum--;

/*			if(n_flag == 1)
			{
				remove("program.txt");
				rename("newfile.txt","program.txt");
			}
*/	
			file=tmp;
			fclose(f);
			free(file);
		}
	
	
	
		else if(n==5)
		{
			char* tmp;
			L* temp;

			file=(char *)malloc(sizeof(char)*400);
			if(file == NULL)
			{
				printf("malloc error\n");
				exit(0);
			}
			tmp=file;
			f=fopen("program.txt","r");
			if(f==NULL)
			{
				printf("no file");
				exit(0);
			}
		
			printf("name to find: ");
			scanf("%s",name);

			data=searchlist(name);
			
			printf("name: %s\n",temp->data.name);
			printf("age: %d\n",temp->data.age);
			printf("start: %d %d %d %d %d \n",temp->data.start.year,temp->data.start.mon,temp->data.start.mday,temp->data.start.hour,temp->data.start.min);
			printf("end: %d %d %d %d %d \n",temp->data.end.year,temp->data.end.mon,temp->data.end.mday,temp->data.end.hour,temp->data.end.min);
			printf("remain: %d %d %d %d %d \n",temp->data.remain.year,temp->data.remain.mon,temp->data.remain.mday,temp->data.remain.hour,temp->data.remain.min);

/*			while(!feof(f))
			{
				file=fgets(arr,200,f);
				n_temp=strstr(arr,name);
				if(n_temp != NULL)
					break;
			}
			if(n_temp == NULL)
			{
				printf("%d",ftell(f));
				printf("no such name\n");
				continue;
			}
	
			fseek(f,-1 * strlen(arr),SEEK_CUR);
	
			fgets(array_inquire,200,f);
			for(int i = 0; i < strlen(array_inquire); i++)
			{
				printf("%c",array_inquire[i]);
			}
*/

			printf("\n");
			file=tmp;
			free(file);
			fclose(f);
		}

		else if(n==6)
		{			
			char *tmp;

			file=(char *)malloc(sizeof(char)*400);
			if(file == NULL)
			{
				printf("malloc error\n");
				exit(0);
			}
			tmp=file;
			f=fopen("program.txt","r");

			if(f==NULL)
			{
				printf("no file");
				exit(0);
			}

			printlist(head);


/*			while(!feof(f))
			{
				file=fgets(arr,200,f);
				if(file == NULL)
					break;
				for(int i=0; i < strlen(arr); i++)
				{
					printf("%c",arr[i]);
				}
				printf("\n");
				memset(arr,0,200);
			}

*/			file=tmp;
			free(file);
			fclose(f);
		}

		else if(n==7)
		{
			int i=0;
			char* tmp;
/*			file=(char *)malloc(sizeof(char)*400);
			if(file == NULL)
			{
				printf("malloc error\n");
				exit(0);
			}
			tmp=file;
*/			
			f=fopen("program.txt","w");
			if(f == NULL)
			{
				printf("no file");
				exit(0);
			}

			for(i = 0; i < pnum; i++)
			{
				
				printf("remain1: %d\n",a[i].remain.year); 
				printf("tm: %d\n",tm.tm_year+1900);

				a[i].remain.year = a[i].end.year-(tm.tm_year+1900);
				a[i].remain.mon = a[i].end.mon-(tm.tm_mon+1);
				a[i].remain.mday = a[i].end.mday-tm.tm_mday;
				a[i].remain.hour = a[i].end.hour-tm.tm_hour;
				a[i].remain.min = a[i].end.min-tm.tm_min;

				if(a[i].remain.mon < 0)
				{
					a[i].remain.year -= 1;
					a[i].remain.mon = 12 + a[i].remain.mon;
				}


				printf("remain2: %d\n",a[i].remain.year); 


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



					






