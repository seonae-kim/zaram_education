#include <stdio.h>

int main()
{
	int arr[30] ={0,};
	int i;
	int n;
	int num;
	int count =0;

	printf("input n: \n");
	scanf("%d", &n); 
	
	printf("input many number: \n");

	for(i =0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("input num: \n");
	scanf("%d", &num); 

	for(i = 0; i <n; i++)
	{
		if(arr[i] > num)
		{
			count++;
		}
	}
	printf("%d", count);
}
