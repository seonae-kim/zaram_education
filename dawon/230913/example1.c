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
	char arr[100]={0, };
	char buf[100]={0, };
	char array_inquire[200]={0, };
	char *n_temp;
	
	M a[20];


		
	printf("1: register 2: extend 3:transfer 4:delete 5:inquire 6:renew >> ");
	scanf("%d",&n);
	if(n == 1)
	{

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

		fclose(f);
	}
	

	else if(n==2)
	{
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
		

		fscanf(f,"%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", a[0].name, &a[0].age,&a[0].start.year,&a[0].start.mon,&a[0].start.mday,&a[0].start.hour,&a[0].start.min,&a[0].end.year,&a[0].end.mon,&a[0].end.mday,&a[0].end.hour,&a[0].end.min,&a[0].remain.year,&a[0].remain.mon,&a[0].remain.mday,&a[0].remain.hour,&a[0].remain.min);

		a[0].end.year += date / 12;
		a[0].end.mon  += date % 12;

		if(a[0].end.mon > 12)
		{
			a[0].end.year += 1;
			a[0].end.mon -=12;
		}

		word = strlen(arr) - (n_temp+68-arr) + 1;
		fseek(f,-1 * word+1, SEEK_CUR);
		fwrite(&a[0].end.year,1,3,f);

		if(a[0].end.mon > 9)
		{
			fseek(f,8,SEEK_CUR);
			fwrite(&a[0].end.mon,4,1,f);
		}
		else
		{
			fseek(f,9,SEEK_CUR);
			fwrite(&a[0].end.mon,4,1,f);
		}

		fclose(f);
				
	}
/*
	else if(n==3)
	{




	}
	else if(n==4)
	{
		for(i = 0; i < pum; i++)
		{


*/
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
		

		fclose(f);
	}
/*	else if(n==6)
	{
	    
	}

*/
	return 0;
}












