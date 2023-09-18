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
		
	printf("1: register 2: extend 3:transfer 4:delete 5:inquire 6:renew >> ");
	scanf("%d",&n);
	if(n == 1)
	{
		char* tmp;
		tmp=file;

		f=fopen("program.txt","r");

		if(f == NULL)
		{
			printf("no file");
			exit(0);
		}
			
		printf("name: ");
		scanf("%s %d %d",name,&age,&period);
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

		f=fopen("program.txt","a");
		if(f == NULL)
		{
			printf("no file");
			exit(0);
		}

				
		strcpy(a[0].name,name);
		a[0].age = age;
		a[0].start.year = tm.tm_year+1900;
		a[0].start.mon = tm.tm_mon+1;
		a[0].start.mday = tm.tm_mday;
		a[0].start.hour = tm.tm_hour;
		a[0].start.min = tm.tm_min;
		a[0].start.year = tm.tm_year+1900;
		a[0].end.year = a[0].start.year + period/12;
		a[0].end.mon = a[0].start.mon+period%12;
		a[0].end.mday = tm.tm_mday;
		a[0].end.hour = tm.tm_hour;
		a[0].end.min = tm.tm_min;
		a[0].remain.year = period/12;
		a[0].remain.mon = period%12;
		a[0].remain.mday = tm.tm_mday;
		a[0].remain.hour = tm.tm_hour;
		a[0].remain.min = tm.tm_min;

		if(a[0].end.mon > 12)
		{
			a[0].end.year += 1;
			a[0].end.mon -=12;
		}

		fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",a[0].name,a[0].age,a[0].start.year,a[0].start.mon,a[0].start.mday,a[0].start.hour,a[0].start.min,a[0].end.year,a[0].end.mon,a[0].end.mday,a[0].end.hour,a[0].end.min,a[0].remain.year,a[0].remain.mon,a[0].remain.mday,a[0].remain.hour,a[0].remain.min);

		file=tmp;
		fclose(f);
		free(file);
	}
	

	else if(n==2)
	{
		char *tmp;
		char update_year[10], update_mon[10];
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

		while(!(feof(f)))
		{
			file=fgets(arr,100,f);
			n_temp=strstr(arr,name);
			if(n_temp != NULL)
				break;
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
		
		printf("year update: %d\n", a[0].end.year);
		printf("mon update: %d\n",a[0].end.mon);
		sprintf(update_year,"%d",a[0].end.year);
		sprintf(update_mon,"%d",a[0].end.mon);
		printf("EOF: %d\n",ftell(f));

		word = strlen(arr) - (n_temp+9-arr) + 1;
		fseek(f, -1 * word, SEEK_CUR);
		fwrite(update_year,1,4,f);

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
		f=fopen("program.txt","r");
		if(f==NULL)
		{
			printf("no file");
			exit(0);
		}
	
		printf("name to find: ");
		scanf("%s",name);
		
		while(!feof(f) || n_temp == NULL)
		{
			file=fgets(arr,200,f);
			n_temp=strstr(arr,name);
		}
		if(n_temp == NULL)
		{
			printf("%d",ftell(f));
			printf("no such name\n");
			exit(0);
		}

		fseek(f,-1 * strlen(arr),SEEK_CUR);

		fgets(array_inquire,200,f);

		for(int i=0;i<200;i++)
		{
			printf("%c",array_inquire[i]);
		}
		printf("\n");
		
		free(file);
		fclose(f);
	}
/*	else if(n==6)
	{
	    
	}

*/
	return 0;
}












