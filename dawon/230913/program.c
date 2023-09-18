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
	char name[10]={0, };
	char arr[100]={0, };
	char buf[100]={0, };
	char *n_temp;
	
	M a[20];


	
	printf("1: register 2: extend 3:transfer 4:delete 5:inquire 6:renew >> ");
	scanf("%d",&n);

	
	f=fopen("program.txt","w");

	if(f == NULL)
	{
		printf("no file");
		exit(0);
	}
		
	printf("info: ");
	scanf("%s %d %d",name,&age,&period);
			
	strcpy(a[0].name,name);
	a[0].age=age;
	a[0].start.year=tm.tm_year+1900;
	a[0].start.mon=tm.tm_mon+1;
	a[0].start.mday=tm.tm_mday;
	a[0].start.hour=tm.tm_hour;
	a[0].start.min=tm.tm_min;
	a[0].start.year=tm.tm_year+1900;
	a[0].end.year=a[0].start.year + period/12;
	a[0].end.mon=a[0].start.mon + period%12;
	a[0].end.mday=tm.tm_mday;
	a[0].end.hour=tm.tm_hour;
	a[0].end.min=tm.tm_min;
	a[0].remain.year=period/12;
	a[0].remain.mon=period%12;
	a[0].remain.mday=tm.tm_mday;
	a[0].remain.hour=tm.tm_hour;
	a[0].remain.min=tm.tm_min;
	
	if(a[0].end.mon > 12)
	{
		a[0].end.year += 1;
		a[0].end.mon -= 12;
	}
	

	fputs("===============================================================================================================================================================================================\n",f);
	fprintf(f,"%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s\n","name","age","year","month","day","hour","min","year","month","day","hour","min","year","month","day","hour","min");

	fputs("===============================================================================================================================================================================================\n",f);
	fprintf(f, "%10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n",a[0].name,a[0].age,a[0].start.year,a[0].start.mon,a[0].start.mday,a[0].start.hour,a[0].start.min,a[0].end.year,a[0].end.mon,a[0].end.mday,a[0].end.hour,a[0].end.min,a[0].remain.year,a[0].remain.mon,a[0].remain.mday,a[0].remain.hour,a[0].remain.min);

	fclose(f);

	return 0;
}
