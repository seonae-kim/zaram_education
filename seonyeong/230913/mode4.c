#include <stdio.h>
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

int mode4()
{
    FILE *fin; 
	FILE *fout;
    struct member m;
	char buffer[2550] = {0};
    char user[20] = {0};
    int line = 0;
	char *ptr = 0;

    fin = fopen("member_info.txt","r+");
    fout = fopen ("exchange.txt", "w");

    printf(" < Delete Membership >\n user name : ");
    scanf("%s", user);
	
	if(fin == NULL)
    {   
        printf("fail1\n");
    }   
    
	if(fout == NULL)
    {
        printf("fail2\n");
    }
    while(1)
    {   
        fgets(buffer, 2550, fin);
        char *ptr = strstr(buffer, user);

        if( ptr == NULL)
		{
			fputs(buffer, fout);
			printf("%d %s\n", __LINE__, buffer);
		}
		else
		{
			printf("%d %s\n", __LINE__, buffer);
		}

        if( fgets(buffer, 2550, fin) == NULL)
        {
            printf(" Success\n");
            break;
        }
    }   
    	
    fclose(fin);
	fclose(fout);
	remove("member_info.txt");
	rename("exchange.txt", "member_info.txt");
}


