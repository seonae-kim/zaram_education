#include <stdio.h>

int main()
{

	int slicer[3] = {0,};
	int numlist[50] = {0,};
	int numlistsize;
	int i, n;
	printf("input n:\n");
	scanf("%d", &n);


	printf("input slicer:\n");
	for(i =0; i <3; i++)
	{
		scanf("%d", &slicer[i]);			
	}


	printf("input numlist size:\n");
	scanf("%d", &numlistsize);				

	printf("input numlist:\n");
	for(i =0; i < numlistsize; i++)
	{
		scanf("%d", &numlist[i]);				
	}

	if (n == 1)
	{
		for(i = 0 ; i <= slicer[1]; i++)
		{
			printf("%d ", numlist[i]);
		}
	}
	else if(n == 2)
	{
		for(i = slicer[0] ; i <= slicer[numlistsize-1]; i++)
		{
			printf("%d ", numlist[i]);
		}
	}
	else if (n ==3)
	{
		for(i = slicer[0]; i <= slicer[1]; i++)		 
		{
			printf("%d ", numlist[i]);
		}
	}
	else if (n==4)
	{
		for(i = slicer[0]; i <= slicer[1]; i += 2)
		{
			printf("%d ", numlist[i]);
		}
	}
}
