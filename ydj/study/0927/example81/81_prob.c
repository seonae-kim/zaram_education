#include<stdio.h>
#include<time.h>

int main()
{
	struct tm *t;
	time_t now = time(NULL);

	char now_time[20];

	strftime(now_time, sizeof(now_time), "%Y-%m-%d %H:%M:%S", localtime(&now));

	FILE *fp;
	fp = fopen("time.txt", "a+");
	if (fp == NULL)
	{
		printf("Fail to open the file, Please try again");
	}
	fprintf(fp, "%s", now_time);

	fclose(fp);

	printf("DONE! Please check the file !\n");
	return 0;
}
