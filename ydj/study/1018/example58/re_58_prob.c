#include<stdio.h>
#include<string.h>

int main()
{
	char date_1[8] = {0};
	char date_2[8] = {0};
	// for loop
	int i = 0;
	int result = 0;

	printf("Please enter the date 1 (YYYYMMDD format): ");
	scanf("%s", date_1);

	printf("Please enter the date 2 (YYYYMMDD format): ");
	scanf("%s", date_2);

	result = strcmp(date_1, date_2);

    if (result < 0)
	{
		printf("1\n");
	}

	else if (result > 0)
	{
		printf("0\n");
	}

	return 0;
}
