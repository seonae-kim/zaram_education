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

int main()
{
    FILE *fp;
    struct member m;
    char buffer[255] = {0};
    char user[20] = {0};
    int period = 0;
	int count = 0;
	char *ptr = {0}; 
	char *ptr2 = {0};
	int i = 0;
	char arr[10] = {0};
	char buffer2[10] = {0};
    
	printf(" < Extension of the period >\n user name, period :");
	scanf("%s %d", user, &period);
	
	if((fp = fopen("member_info.txt", "r")) == NULL)
	{
		printf("fail\n");
	}

	while(fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		fgets(buffer, sizeof(buffer), fp);
		
		char *ptr = strstr(buffer, user);

		if(ptr != NULL)
		{
			char *ptr2 = strtok(buffer, "\t");
			while(ptr2 != NULL)
			{
				count++;
				strcat(buffer2, ptr2);
				strcat(buffer2, "\t");
				ptr2 = strtok(NULL, "\t");
				if(count == 4)					
				{
					break;
				}
			}
	
			 if((fp = fopen("member_info.txt", "a")) == NULL)
			{
				printf("fail2\n");
			}

			m.remain_period = atof(ptr2) + period;
			sprintf(arr, "%d", m.remain_period);
		}
			strcat(buffer2, arr);
			//printf("%s\n",buffer2);
	}

	fclose(fp);
	printf(" Success\n");
	return 0 ;
}
