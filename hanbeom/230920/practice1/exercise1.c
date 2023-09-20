#include <stdio.h>

int main()
{
	int arr[100] ={0,};
	int i,j;
	int n;

	printf("input n: \n");
	scanf("%d", &n);	//10

	for(i =0; i <= n; i++)	//10
	{
		arr[i] = i;		// 1 2 3 4 5 6 7 8 9 10
		if(arr[i] %2 == 1)
		{
			printf("%d ", arr[i]);
		}
	}
}
