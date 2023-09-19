#include <stdio.h>

int main()
{
	char n[30] = {0,};
	int k;
	int i;
	int number = 0;
	int result = 0;

	printf("input k: \n");
	scanf("%d", &k);
	
	while (getchar() != '\n');		// line 10 '\n' ignore
	
	for(i = 0; i < k; i++)
	{
		scanf("%c", &n[i]);			// add &
	}

	for( i = 0 ; i < k; i++)
	{
		number = n[i] - '0';
		result += number;
	}
	printf("%d", result);
}
