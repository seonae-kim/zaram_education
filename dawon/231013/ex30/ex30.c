#include <stdio.h>
#include <stdlib.h>
int *numarr(int * arr, int num1, int num2, int n);
int main()
{
	int n = 0, i = 0;
	int *arr;
	int *re;
	int num1 = 0, num2 = 0;

	printf("n: ");
	scanf("%d",&n);

	arr = (int *)malloc(sizeof(int) * n);
	printf("arr: ");

	for(i = 0; i < n; i++)
	{
		scanf("%d",arr+i);
	}

	printf("num1: ");
	scanf("%d",&num1);
	printf("num2: ");
	scanf("%d",&num2);

	re = numarr(arr,num1,num2,n);
	printf("return: ");
	for(i = 0; i < num2 - num1 + 1; i++)
	{
		printf("%d ",*(re + i));
	}

	
	return 0;
}


int *numarr(int * arr, int num1, int num2, int n)
{
	int* arrn;
	int i = 0, index = 0;

	arrn = (int*)malloc(sizeof(int) * n);
	for(i = num1; i <= num2; i++)
	{
		*(arrn + index++) = *(arr + i);
	}

	return arrn;
}

