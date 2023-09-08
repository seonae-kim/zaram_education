#include <stdio.h>

int main() {


	int N;

	int number[20000];

	printf("input N\n");
	
	scanf("%d", &N);


	printf("input number\n");

	

	for(int i = 0; i < N ;i++) {
	
	scanf("%d", &number[i]);
	
	printf("%d ", 2 * number[i]);

	}





}
	

