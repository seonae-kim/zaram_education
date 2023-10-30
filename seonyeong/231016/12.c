#include <stdio.h>

int main()
{
	int N = 0, i = 0;
	int num[100] = {0};
	int output[100] = {0};

	printf("insert N:");
	scanf("%d", &N);

	printf("%d numbers : ", N);
	
	for(i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}
	
	printf("output: ");
	for(i=0; i < N; i++)
	{
		output[i] = num[i] * 2;
		printf("%d ",output[i]); 
	}
	printf("\n");
	return 0;
}
