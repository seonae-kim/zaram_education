#include <stdio.h>

int main()
{
	int arr[100] ={0,};
	int i,j;
	int n;

	printf("input n: \n");
	scanf("%d", &n);	//10

	for(i =1; i <= n; i+=2)	//10
	{
		arr[i] =i;
	}
}
