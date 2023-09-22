#include<stdio.h>

int main()
{
	int num_list[100] = {0};
	int rtn_list[2] = {0};
	int i = 0, x = 0; 
	int even = 0, odd = 0;
	printf("Please enter the number of list : ");
	scanf("%d", &x);
	printf("Please enter the num : ");
	

	for (i = 0; i < x; i++)
	{
		scanf("%d", &num_list[i]);

		while (num_list[i] > 1000)
		{
			printf("Wrong!\n");
			printf("Enter under 1000 num again : ");
			scanf("%d", &num_list[i]);
		}
	}
	
	for (i = 0; i < x; i++)
	{
		if (num_list[i] % 2 == 0)
		{
			even++;
		}
		else if (num_list[i] % 2 == 1)
		{
			odd++;
		}
	}

	rtn_list[0] = even;
	rtn_list[1] = odd;
	printf("[%d, %d] \n", rtn_list[0], rtn_list[1]);

	return 0;
}
