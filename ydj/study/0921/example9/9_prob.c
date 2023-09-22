#include<stdio.h>

int main()
{
	int n = 0;
	int ele_num = 0;
	int i = 0;
	int count = 0;

	printf("Please enter the number n : ");
	scanf("%d", &n);
	printf("\n");
	printf("Please enter the # of element : ");
	scanf("%d", &ele_num);

	int arr[ele_num];

	printf("Enter the element : ");
	for (i = 0; i < ele_num; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > n)
		{
			count++;
		}
	}

	printf("%d \n", count);


	return 0;
}
