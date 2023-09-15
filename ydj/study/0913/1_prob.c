#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct member 
{
	char name[20];
	int age;
	char start[20];
	int end[20];
	int remain[20];
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
	char mode = {0};
	int i = 0;
	int temp = 0;
	struct member new[100];
	
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
		scanf("%c", &mode);	
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

				strftime(new[i].start, sizeof(new[i].start), "%Y%m%d%H%M", localtime(&now));
			
				printf("END DATE : ");
//				strftime(new[i].end, sizeof(new[i].end), "%Y%m%d%H%M", localtime(&now));
				printf("Registration Period : ");
				i++;
				//
				
				break;
		}

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

	int int_time = 0;
	int_time = atoi(new[0].start);
	printf("%s \n", new[0].name);
	printf("%d \n", new[0].age);
	printf("%s \n", new[0].start);
//	printf("%s \n", new[1].name);
//	printf("%d \n", new[1].age);
//	printf("%s \n", new[1].start);
	printf("%d \n", int_time);
	return 0;
}
