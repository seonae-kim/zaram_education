#include<stdio.h>

int main()
{
	int num = 0;
	int n = 0;
	int i = 0;
	printf("Please enter the # of element : ");
	scanf("%d", &num);
	int arr[num];
	printf("Please enter the arr : ");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Please enter the n : ");
	scanf("%d", &n);

	for (i = 0; i < num; i = i + n)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
