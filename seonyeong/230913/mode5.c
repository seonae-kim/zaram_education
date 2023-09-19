#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct member
{
    char name[20];
    int age;
    char start_date[50];
    char end_date[50];
    int remain_period;

};

int mode5()
{
	FILE *fp;
    struct member m[50];
	char buffer[255] = {0};
	char user[20] = {0};
	int line = 0;

	printf(" < Search Member >\n user name : ");
	scanf("%s", user);

	if((fp = fopen("member_info.txt", "r")) == NULL)
	{
		printf("fail\n");
	}
	
	while(fgets(buffer, 255, fp) != NULL)
	{
		char *ptr = strstr(buffer, user);
		
		if( ptr != NULL)
		{
			printf("%s", ptr);
		}
	}
    

	fclose(fp);
}



