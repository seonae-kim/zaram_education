#include<stdio.h>
#include<string.h>

int main()
{
	char input_date[100] = {0};
	char data[100] = {0};
	char white[100]= {0};
	char temp = '0';
	int cnt = 0;
	int i = 0;


	printf("Please enter the date (YYYY-MM-DD format) : ");
	scanf("%s", input_date);

	FILE *fp;
	fp = fopen("time.txt", "r+");
	if (fp == NULL)
	{
		printf("Fail to open the file, Try again!");
	}
	while (fscanf(fp, "%c", &temp) != EOF)
	{
		if (temp == '\n')
		{
			cnt++;
		}
	}
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < cnt; i++)
	{
		fseek(fp, 20 * i, SEEK_SET);
		fscanf(fp, "%s %*s", data);
		if (strcmp(input_date, data) > 0)
		{
			fseek(fp, 20 * i, SEEK_SET);
//			fputs(white, fp);
			fprintf(fp, "                   ");			
		}
	}
	fclose(fp);

	printf("Removing the date is done ! \n");
	return 0;
}
