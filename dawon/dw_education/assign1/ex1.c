#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a[9]={0};
	int input=0;
	int max=0;
	int min=0;



	for(int i=0;i<10;i++)
	{
		scanf("%d",&input);
		a[i]=input;
	}
	
	min=a[0];
	printf("input:");

	for(int i=0;i<10;i++)
	{
		printf(" %d ",a[i]);

		if(max<a[i])
			max=a[i];
		if(min>a[i])
			min=a[i];
	}

	printf("   output: Max: %d, Min: %d",max,min);
	printf("\n");
return 0;
}
