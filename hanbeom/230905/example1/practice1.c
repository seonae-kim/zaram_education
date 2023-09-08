#include <stdio.h>

int main()
{
	int num[10]; 	
	int sum = 0;

	for (int i = 0; i < 10; i++) {

		scanf("%d", &num[i]);
	
			sum += num[i];
	
	if ( (num[i] == 0) && (i !=0)) {

		sum = sum - num[i - 1];

	}

	}

	printf("%d", sum);


} 



