#include<stdio.h>
#define N 10

// + define N
// + revise logic 
// + reset index


int main()
{
	char order[N];
	int index = 0;
	int num_L = 0 ,num_R = 0;
	int flag;
	printf("This program will confirm your bracket\n");
	printf("Enter the ')' or '(' : ");
	scanf("%s", order);
	
	for (index = 0; index < N; index++)
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
	
	int no = 0;
	int i;
	// num of '(' == num of ')'
	if(num_L == num_R)
	{
		if( (order[0] == ')') || (order[num_L + num_R - 1] == '(') )
		{
			printf("no \n");
			no++;
		}
		else
		{
			flag = 1;
		}
	}

	else
	{
		printf("no\n");
	}



	// order
	for(i = 0; i <= 9; i++)
	{
		if(order[i] == '(')
		{
			num_L -= 1;
		}
		else if(order[i] == ')')
		{
			num_R -= 1;
		}
		if (num_L > num_R && no == 0)
		{
			printf("no \n");
			flag = 0;
			break;
		}
		else if(no == 0)
		{
			flag = 1;
		}
	}
	if(flag == 1)
	{
		printf("ok \n");
	}
	return 0;
}
