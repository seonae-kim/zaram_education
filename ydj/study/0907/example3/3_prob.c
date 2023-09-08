#include<stdio.h>

int main()
{
	int N = 0;
	int i = 0, j = 0;
	printf("Enter the # of words : ");
	scanf("%d", &N);

	char arr[N][999];

	for(i = 0; i < N; i++)
	{
		scanf("%s", arr[i]);
//		scanf("%c", &arr[0][0]);		
	}
//	printf("%c",arr[0][0]);
	
	int count = 0;
	for(i = 0; i < N; i++)
	{
		while(arr[i][j] != '\0')
		{
			count++;
			j++;
		}
		printf("%d", count);
		count = 0;
		j=0;
	}
	return 0;
}
