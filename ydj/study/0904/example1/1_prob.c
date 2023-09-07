#include<stdio.h>
int main()
{
	int a1, max, min;
	printf("Enter the first num : ");
	scanf("%d",&a1);

	max = a1;
	min = a1;
	
	int i, num;	
	for(i = 2; i<=10; i++)
	{
		printf("Enter the %dth num : ", i);
		scanf("%d", &num);

		{
			max = num;
		}
		else if(min > num)
		{
			min = num;
		}	
	}
	printf("%d, %d \n" ,max,min);
}
