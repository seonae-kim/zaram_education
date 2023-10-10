#include<stdio.h>
#include<time.h>

int main()
{
	struct tm *t;
	time_t now = time(NULL);

	char now_time[20];

	strftime(now_time, sizeof(now_time), "%Y-%m-%d %H:%M:%S", localtime(&now));
	printf("%s \n", now_time);
	return 0;
}
