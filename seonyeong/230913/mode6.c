#include <stdio.h>


struct member
{
    char name[20];
    int age;
    char start_date[50];
    char end_date[50];
    int remain_period;

};

int mode6()
{

	FILE *fp;
	struct member m;
	int c = 0;
	
	
	fp = fopen("member_info.txt", "r");

    if(fp == NULL)
    {   
        printf("fail2\n");
    }
	printf("\n");

     while((c = fgetc(fp)) != EOF)  
     {   
         putchar(c);
     }
	printf("\n");

    fclose(fp);
}
