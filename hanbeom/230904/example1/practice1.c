#include <stdio.h>

int main()
{
	int input[10];

	int max =0; 	
	int min = 10000;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &input[i]);
	
		if (max <= input[i]) {
			max = input[i];	
		}

		if (min >= input[i]) {
			min = input[i];
		}
	}

	printf("Max: %d\n", max);	
	printf("Min: %d\n", min);
} 



