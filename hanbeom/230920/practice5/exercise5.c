#include <stdio.h>

int main()
{
	int i,j;
	int num[50];
	char str[50];
	int n;
	int count = 0;
	int k= 0;
	
	printf("input N: \n");
	scanf("%d", &n);	

	int fix_n = n;
	int copy_n = n;
	while(copy_n > 10)			
	{
		copy_n = copy_n / 10;
		count++;
	}

	for(i = 0; i < count + 1; i++)		
	{
		for(j = count-i ;j >0 ; j--)
		{
			n = n /10;		
		}
		num[i] = n % 10;			
		n = fix_n;
	}
	
	for(i = 0; i < count + 1; i++)			
	{
		str[i] = num[i] + 48;
		printf("%c", str[i]);
	}

	


}
