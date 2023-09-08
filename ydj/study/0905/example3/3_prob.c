#include<stdio.h>
#define N 10

int main()
{
	char order[N];
	int i = 0;
	int flag = 0;
	printf("This program will confirm your bracket\n");
	printf("Enter the ')' or '(' : ");
	scanf("%s", order);
	
	for(i = 0; i < N; i++)
	{
		if(order[i] == '(')
		{
			flag++;	
		}
		else if(order[i] == ')')
		{
			flag--;	
		}

		if(flag < 0)
		{
			printf("no \n");
			break;
		}
	}
	if(flag == 0)
	{
		printf("ok \n");
	}
	return 0;
}
