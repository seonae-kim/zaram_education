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

int main()
{
	FILE *f;
	FILE *fout;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char *file;
	int n;
	int i,j,k;
	int pnum, flag_name=0, date=0, period =0;
	int age=0;
	int year, day;
	int word;
	char name[10]={0, };
	char arr[200]={0, };
	char buf[100]={0, };
	char array_inquire[200]={0, };
	char *n_temp;
	
	M a[20];
	
	file=(char *)malloc(sizeof(char)*400);
	if(file == NULL)
	{
		printf("malloc error\n");
		exit(0);
	}
		
	while(1)
	{
		printf("1: register 2: extend 3:transfer 4:delete 5:inquire 6:inquire all 7:renew 8:quit >> ");
		scanf("%d",&n);
		if(n==8)
		{
			printf("program exit\n");
			break;
		}

		if(n == 1)
		{
			
				char* tmp;
				tmp=file;
	
				f=fopen("program.txt","w");
	
				if(f == NULL)
				{
					printf("no file");
					exit(0);
				}
					
				printf("name: ");
/*				scanf("%s %d %d",name,&age,&period);
				while(!feof(f))
				{
					file=fgets(arr,100,f);
					n_temp=strstr(arr,name);
					if(n_temp != NULL)
					{	printf("same name");
						exit(0);
					}
				}
				fclose(f);
*/	
				for(int i=0; i < 1; i++)
				{
					scanf("%s %d %d",a[i].name,&a[i].age,&period);
					for(int j = 0; j < i; j++)
					{
						if(a[i].name == a[j].name)
						{
							printf("same name");
							i--;
							flag_name = 1;
							break;
						}
					}
					if(flag_name ==1)
						continue;
						
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
				}
	
				file=tmp;
				fclose(f);
				free(file);
		}
		
	
		else if(n==2)
		{
			char *tmp;
			char update_year[10], update_mon[10];
			int i=0;
			tmp=file;
			f=fopen("program.txt","r+");
	
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
			for(i = 0; i < 5; i++)
			{
				if(name == a[i].name)
				{
					a[i].end.year += date / 12;
					a[i].end.mon  += date % 12;
					if(a[i].end.mon > 12)
					{
						a[i].end.year += 1;
						a[i].end.mon -=12;
					}
				}
			}

/*			printf("start point: %d\n",ftell(f));	
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
*/			
			printf("year update: %d\n", a[0].end.year);
			printf("mon update: %d\n",a[0].end.mon);
			sprintf(update_year,"%d",a[0].end.year);
			sprintf(update_mon,"%d",a[0].end.mon);
			printf("EOF: %d\n",ftell(f));

			for(i = 0; i < 5; i++)
			{
				fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",
						a[i].name,a[i].age,a[i].start.year,a[i].start.mon,a[i].start.mday,a[i].start.hour,a[i].start.min,
						a[i].end.year,a[i].end.mon,a[i].end.mday,a[i].end.hour,a[i].end.min,
						a[i].remain.year,a[i].remain.mon,a[i].remain.mday,a[i].remain.hour,a[i].remain.min);
			}

	
	//		word = strlen(arr) - (n_temp+3-arr) + 1;
	//		fseek(f, -1 * word, SEEK_CUR);
//			fwrite(update_year,1,4,f);
	
	/*		if(a[0].end.mon > 9)
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
	/*
		else if(n==3)
		{
	
	
	
	
		}
	*/	
	
		else if(n==4)
		{
			int i=0;
			int n_flag=0;
			char *tmp;
	
			f=fopen("program.txt","r");
			fout=fopen("newfile.txt","w");
			tmp=file;
	
			if(f==NULL)
			{
				printf("no file\n");
				exit(0);
			}
			if(fout==NULL)
			{
				printf("no file\n");
				exit(0);
			}
	
			printf("name to find: ");
			scanf("%s",name);
			while(!feof(f))
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
	
			if(n_flag == 0)
			{
				printf("%d\n",ftell(f));
				printf("no such name\n");
				exit(0);
			}
	
			if(n_flag == 1)
			{
				remove("program.txt");
				rename("newfile.txt","program.txt");
			}
	
			file=tmp;
			fclose(f);
			fclose(fout);
			free(file);
			return 0;
		}
	
	
	
		else if(n==5)
		{
			char* tmp;
			tmp=file;
			f=fopen("program.txt","r");
			if(f==NULL)
			{
				printf("no file");
				exit(0);
			}
		
			printf("name to find: ");
			scanf("%s",name);
			
			while(!feof(f))
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
				exit(0);
			}
	
			fseek(f,-1 * strlen(arr),SEEK_CUR);
	
			fgets(array_inquire,200,f);
			for(int i = 0; i < strlen(array_inquire); i++)
			{
				printf("%c",array_inquire[i]);
			}

			printf("\n");
			file=tmp;
			free(file);
			fclose(f);
		}
		else if(n==6)
		{			
			f=fopen("program.txt","r");

			if(f==NULL)
			{
				printf("no file");
				exit(0);
			}

			while(!feof(f))
			{
				file=fgets(arr,200,f);
				for(int i=0; i < strlen(arr); i++)
				{
					printf("%c",arr[i]);
				}
				printf("\n");
			}
			free(file);
			fclose(f);
		}
		else if(n==7)
		{
			int i=0;
			
			f=fopen("program.txt","w");
			if(f == NULL)
			{
				printf("no file");
				exit(0);
			}

			for(i = 0; i < 1; i++)
			{
				
				printf("remain: %d\n",a[i].remain.year); 
				printf("tm: %d\n",tm.tm_year+1900);

				a[i].remain.year = a[i].end.year-(tm.tm_year+1900);
				a[i].remain.mon = a[i].end.mon-(tm.tm_mon+1);
				a[i].remain.mday = a[i].end.mday-tm.tm_mday;
				a[i].remain.hour = a[i].end.hour-tm.tm_hour;
				a[i].remain.min = a[i].end.min-tm.tm_min;

				printf("%d",a[i].remain.year); 


/*				fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",
						a[i].name,a[i].age,a[i].start.year,a[i].start.mon,a[i].start.mday,a[i].start.hour,a[i].start.min,
						a[i].end.year,a[i].end.mon,a[i].end.mday,a[i].end.hour,a[i].end.min,
						a[i].remain.year,a[i].remain.mon,a[i].remain.mday,a[i].remain.hour,a[i].remain.min);
*/

			}
			fclose(f);

		}

	}

	return 0;
}



					






