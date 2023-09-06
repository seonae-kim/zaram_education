#include<stdio.h>

int main()
{
	char order[10];
	int index;
	int num_L = 0 ,num_R = 0;
	int Y = 0, N = 0;
	printf("This program will confirm your bracket\n");
	printf("Enter the ')' or '(' : ");
	scanf("%s", order);
	while(N == 0)
	{
		for (index = 0; index <= 9; index++)
		{
			if(order[index] == '(')
			{
				num_L += 1;
			}
			else if(order[index] == ')')
			{
				num_R += 1;
			}
		}
		// LSB MSB 
		if( (order[0] == ')') || (order[num_L + num_R - 1] == '(') )
		{
			printf("no \n");
			N++;
			break;
		}
		// num of '(' == num of ')'
		if(num_L != num_R)
		{
			printf("no \n");
			N++;
			break;
		}
		// order
		for(int i = 0; i <= 9; i++)
		{
			if(order[i] == '(')
			{
				num_L -= 1;
			}
			else if(order[i] == ')')
			{
				num_R -= 1;
			}

			if (num_L > num_R)
			{
				printf("no \n");
				N++;
				break;
			}
		}
		Y++;
		break;
	}
	if(Y == 1)
	{
		printf("ok\n");
	}
	return 0;
}
