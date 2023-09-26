#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recur(int n);
int main()
{
	char num[10]={0, };
	int num_i=0;
	int sum=0;
	char num_s[10]={0, };
	int i = 0, j = 0, h = 0;
	int d = 0;

	printf("input: ");
	scanf("%d",&num_i);
	
	for(i = 0; i < 2000; i++)
	{
		if(i + recur(i) == num_i) 
		{
			printf("\noutput: %d\n",i);
		}
	}
	return 0;
}

int recur(int n)
{
	if(n % 10 == n)
	{
		return n;
	}

	return recur(n / 10) + (n % 10);
}





