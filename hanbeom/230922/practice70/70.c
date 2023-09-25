#include <stdio.h>

int solution(int *arr, int p, int size);


int main()
{
	int i, n, k;
	int answer;
	int numlist[50] = {0,};

	printf("input n:\n");
	scanf("%d", &n);								

	printf("input numlist:\n");
	for(i = 0; i <n; i++)
	{
		scanf("%d", &numlist[i]);							
	}
	printf("input k:\n");
	scanf("%d", &k);			

	answer = solution(numlist, k, n);			
	printf("%d", answer);
}

int solution(int *arr, int p, int size)			
{
	int result =0;
	int i;
	for(i = 0; i < p; i++)		
	{
		int index = 2 * i;
		if(index >= size)
		{	
			index -= size; 	
		}
		result = arr[index];
	}
	return result;
}
