#include<stdio.h>
#include<string.h>

struct line
{
	char move_date[20];
	char move_time[20];
};

int main()
{
	struct line move[10];
	char input_date[100] = {0};
	char data[100] = {0};
	char temp = '0';
	int cnt = 0;
	int i = 0;
	int flag = 0;

	char originfile[] = "time.txt";
	char tempfile[] = "new_time.txt";

	printf("Please enter the date (YYYY-MM-DD format) : ");
	scanf("%s", input_date);

	FILE *fp;
	FILE *newfp;
	fp = fopen(originfile, "r+");
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
			flag++;
			fseek(fp, 20 * i, SEEK_SET);
			fprintf(fp, "                   ");	
		}
	}

	for (i = 0; i < cnt - flag; i++)
	{
		if (i == 0)
		{
			fseek(fp, 0, SEEK_SET);
		}
		else
		{
			fseek(fp, 0, SEEK_CUR);
		}
		fscanf(fp, "%s %s", move[i].move_date, move[i].move_time);
	}
	
	fclose(fp);

	newfp = fopen(tempfile, "w");
	for (i = 0; i < cnt - flag; i++)
	{	
		fprintf(newfp, "%s %s\n", move[i].move_date, move[i].move_time);
	}

	fclose(newfp);

	remove(originfile);
	rename(tempfile, originfile);

	printf("Removing the date is done ! \n");
	return 0;
}
