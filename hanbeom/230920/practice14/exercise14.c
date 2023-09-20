#include <stdio.h>

int main()
{
	int arr[30] ={0,};
	int i;
	int N;
	int n;

	printf("input N:\n");
	scanf("%d", &N);

	printf("input many number:\n");
	for(i =0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("input n:\n");
	scanf("%d", &n);
	
	for(i =0; i < N; i += n)		
	{
		printf("%d ", arr[i]);
	}
}
