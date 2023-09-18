#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct member 
{
	char name[20];
	int age;
	char start[20];
	int end;
	int remain;
};

int main()
{
	struct tm *t;
	time_t now = time(NULL);
//	printf("%d\n", now);
	char datetime[20];
//	strftime(datetime, sizeof(datetime), "%Y%m%d%H%M", localtime(&now));
//	printf("%s \n", datetime);
//	t = localtime(&base);

//	printf("%d %d %d %d %d\n", 
//			t -> tm_year + 1900, t -> tm_mon + 1, t -> tm_mday, t -> tm_hour, t -> tm_min);
	
	printf("\n");
	printf("\n");
	
	FILE *fp;
	int num = 0;
	char mode = 0;
	int i = 0;
	int period = 0, month = 0, year = 0, date = 0, cal_date = 0;
	char date_c[10] = {0};
	struct member new[100];

	int remain = 0;
	
	printf("\t\t __________________________________________ \n");
	printf("\t\t| MEMBERSHIP PROGRAM                       |\n");
	printf("\t\t| 1. Register a new member                 |\n");		   
	printf("\t\t| 2. Extension of membership period        |\n");
	printf("\t\t| 3. NOT SUPPORTED                         |\n");
	printf("\t\t| 4. Remove member INFO                    |\n");
	printf("\t\t| 5. Find member's INFO                    |\n");
	printf("\t\t| 6. All member's INFO                     |\n");
	printf("\t\t| 7. Renew All member's period             |\n");
	printf("\t\t|__________________________________________|\n");
	printf("\n\n");

	printf("If you want to exit this prgram, Press q \n");
	while(1)
	{	
		printf("Choose the mode : ");
		scanf(" %c", &mode);	
		if (mode == 'q')
		{
			printf("Bye !~!\n");
			break;
		}
		
		switch(mode)
		{
			case '1' :
	
				printf("Please enter the NEW member's INFO \n");
				printf("NAME : ");
				scanf("%s", new[i].name);
				printf("AGE : ");
				scanf("%d", &new[i].age);

				printf("Registration Period : ");
				scanf("%d", &period);

				strftime(new[i].start, sizeof(new[i].start), "%Y%m%d%H%M", localtime(&now));
				strftime(date_c, sizeof(date_c), "%Y%m%d", localtime(&now));
				date = atoi(date_c);

				date = date + (100 * period);
				if (date % 10000 > 1300)
				{	
					month = (date % 10000) % 1200;
					year = (date / 10000) + (date % 10000) / 1200;
				}
				else
				{
					month = date % 10000;
					year = date / 10000;
				}
				
				cal_date = year * 10000 + month;

				new[i].end = cal_date;
				new[i].remain = period;
				
				i++;

				fp = fopen("member_info.txt", "a");
				if (fp == NULL)
				{
					printf("Fail to open file, Try again \n");
				}

				fprintf(fp, "NAME\tAGE\tstart\tend\tremain \n");
				fprintf(fp, "%s\t%d\t%s\t%d\t%d \n", new[i].name, new[i].age, new[i].start, new[i].end, new[i].remain);

				fclose(fp);
				break;

			case '2' :
				printf("Enter the name : \n");
					
				break;
		}
		printf("\n");

		/*
		printf("Enter the  : ");
		scanf("%d", &num);
	
		fp = fopen("member_info.txt", "a");
		if (fp == NULL)
		{
			printf("Fail to open file, Try again \n");
		}
	
		fprintf(fp, "Example File\n");
		fprintf(fp, "The NUM is %d : ", num);
	
		fclose(fp);
		printf("end");
		*/

	}

	printf("%s \n", new[0].name);
	printf("%d \n", new[0].age);
	printf("%s \n", new[0].start);
//	printf("%s \n", new[1].name);
//	printf("%d \n", new[1].age);
//	printf("%s \n", new[1].start);
	printf("%d \n", new[0].end);
	printf("%d \n", new[0].remain);
	return 0;
}
