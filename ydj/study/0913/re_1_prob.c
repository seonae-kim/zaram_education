#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

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
	int i = 0, j = 0, x = 0, flag = 0;
	int period = 0, month = 0, year = 0, date = 0, cal_date = 0;
	char date_c[10] = {0};
	struct member new[100];
	int remain = 0;

	char temp = '0';
	int cnt_line = 0;
	int ext_period = 0;
	char find_name[10] = {0};
	char comp_name[10] = {0};
	char origin[1000] = {0};
	
	// 3. hand over membership period
	char lev_name[20] = {0};
	char add_name[20] = {0};

	// 4. remove member
	char rm_name[20] = {0};

	// 5. search member
	char search_name[20] = {0};
	
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
	
	fp = fopen("member_info.txt", "a");
	fprintf(fp, "  \tNAME\t\tAGE\t\t   start\t\t  end\t\tremain \n");
	fclose(fp);

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
					
				fp = fopen("member_info.txt", "a+");
				if (fp == NULL)
				{
					printf("Fail to open file, Try again \n");
				}

				printf("Please enter the NEW member's INFO \n");
				printf("NAME : ");
				scanf("%s", new[i].name);

				for (j = 0; j < i; j++)
				{
					if (strcmp(new[i].name, new[j].name) == 0)
					{
						printf("\n");
						printf("Oops~ The name is same!!\n");
						printf("Back to the start menu\n\n");
						flag++;
					}
				}
				if (flag == 1)
				{
					flag = 0;
					break;
				}

				printf("AGE : ");
				scanf("%d", &new[i].age);

				printf("Registration Period : ");
				scanf("%d", &new[i].remain);

				strftime(new[i].start, sizeof(new[i].start), "%Y%m%d%H%M", localtime(&now));
				strftime(date_c, sizeof(date_c), "%Y%m%d", localtime(&now));
				date = atoi(date_c);

				date = date + (100 * new[i].remain);
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
//				new[i].remain = period;
				
				fprintf(fp, "%10s\t\t%2d\t\t%12s\t%8d\t%-2d \n", new[i].name, new[i].age, new[i].start, new[i].end, new[i].remain);

				fclose(fp);
				flag = 0;
				i++;
				break;

			case '2' :
				printf("Enter the name : ");
				scanf("%s", find_name);

				fp = fopen("member_info.txt", "r+");
				if (fp == NULL)
				{
					printf("Fail to open file, Try again \n");
				}
				fseek(fp, 0, SEEK_SET);

				while (fscanf(fp, "%c", &temp) != EOF)
				{
					if (temp == '\n')
					{
						cnt_line++;
					}
				}
				
				fseek(fp, 39, SEEK_SET);
				for (i = 0; i < cnt_line - 1; i++)
				{
					fscanf(fp, "%s%*d%*s%*d%*d", comp_name);
					if (strcmp(find_name, comp_name) == 0)
					{
						printf("\n");
						x = i;
						break;
					}
				}

				printf("Enter the extension period : ");
				scanf("%d", &ext_period);

				month = 0;
				year = 0;

				new[x].remain = new[x].remain + ext_period;
				new[x].end = new[x].end + (100 * ext_period);

				if (new[x].end % 10000 > 1300)
				{
					month = (new[x].end % 10000) % 1200;
					year = (new[x].end / 10000) + (new[x].end % 10000) / 1200;
				}
				else
				{
					month = new[x].end % 10000;
					year = new[x].end / 10000;
				}

				new[x].end = year * 10000 + month;
				
				fseek(fp, 42 * x + 68, SEEK_SET);
				fprintf(fp, "%d", new[x].end);
				fseek(fp, 1, SEEK_CUR);
				fprintf(fp, "%d", new[x].remain);

				printf("MEMEBERSHIP period sucessfully changed!! \n");

				fclose(fp);
				cnt_line = 0;
				x = 0;
				break;

			case '3' :
				printf("Please enter member's name to leave : ");
				scanf("%s", lev_name);

				printf("Please enter member's name to add membership period : ");
				scanf("%s", add_name);

			case '4' :

				fp = fopen("member_info.txt", "r+");
				if (fp == NULL)
				{
					printf("Fail to open file, Try again \n");
				}
				fseek(fp, 0, SEEK_SET);

				printf("Please enter the name you want to remove : ");
				scanf("%s", rm_name);

				while (fscanf(fp, "%c", &temp) != EOF)
				{
					if (temp == '\n')
					{
						cnt_line++;
					}
				}

				fseek(fp, 39, SEEK_SET);
				for (i = 0; i < cnt_line - 1; i++)
				{
					fscanf(fp, "%s%*d%*s%*d%*d", comp_name);
					if (strcmp(rm_name, comp_name) == 0)
					{
						printf("\n");
						x = i;
						break;
					}
				}

				fseek(fp, 42 * x + 39, SEEK_SET);
				for (i = x; i < cnt_line - 1; i++)
				{
					fprintf(fp, "%10s\t\t%2d\t\t%12s\t%8d\t%-2d \n", new[i + 1].name, new[i + 1].age, new[i + 1].start, new[i + 1].end, new[i + 1].remain);
				}

				fclose(fp);

				printf("\n");
				printf("Successfully removed!!  \n");
				cnt_line = 0;
				x = 0;
				break;

			case '5' :
				
				fp = fopen("member_info.txt", "r+");
				if (fp == NULL)
				{
					printf("Fail to open file, Try again \n");
				}
				fseek(fp, 0, SEEK_SET);

				printf("Please enter the name you want to search : ");
				scanf("%s", search_name);

				while (fscanf(fp, "%c", &temp) != EOF)
				{
					if (temp == '\n')
					{
						cnt_line++;
					}
				}

				fseek(fp, 39, SEEK_SET);
				for (i = 0; i < cnt_line - 1; i++)
				{
					fscanf(fp, "%s%*d%*s%*d%*d", comp_name);
					if (strcmp(search_name, comp_name) == 0)
					{
						printf("\n");
						x = i;
						break;
					}
				}

				printf("  ---->    \tNAME\t\tAGE\t\t   start\t  end\t\tremain \n");
				printf("  ---->  %10s\t\t%2d\t\t%12s\t%8d\t%-2d \n", new[x].name, new[x].age, new[x].start, new[x].end, new[x].remain);

				fclose(fp);

				cnt_line = 0;
				x = 0;

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


