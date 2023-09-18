#include <stdio.h>

void SwapArray(int*p1, int*p2, int size);

int main()
{
	int a[5] = {1, 3, 5, 7, 9};
	int b[5] = {2, 4, 6, 8, 10};
	int i;
	
	printf("before swap\n");
	
	printf("a: ");
	for(i =0; i < 5; i++)
	{	
		printf("%d ", a[i]);	
	}

	printf("b: ");
	for(i =0; i < 5; i++)
	{	
		printf("%d ", b[i]);	
	}

	printf("\n");

	SwapArray(a, b, 5);
	
	printf("after swap\n");
	
	printf("a: ");
	for(i =0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	
	printf("b: ");
	for(i =0; i < 5; i++)
	{
		printf("%d ", b[i]);
	}

}

void SwapArray(int*p1, int*p2, int size)	//use pointer only here
{
	/*
	int temp;
	temp = *p2;
	*p2 = *p1;
	*p1 = temp;
	*/
	
	/*
	int* temp;
	temp = p1;
	p2 = p1;			
	p1 = temp;
	*/

	int temp =0;
	int i;
	for(i = 0 ; i < size; i++)
	{
		temp = p1[i];
		p1[i] = p2[i];
		p2[i] = temp;
	}

}
