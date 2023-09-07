#include <stdio.h>

int main() {


	int i,j;

	int num[4][4];

	for(i=0; i <4; i++) {
		for(j=0; j <4; j++) {
		scanf("%d", &num[i][j]);
		}


	}

	for(i=0; i <4; i++) {

	printf("\n");
		for(j=0; j < 4; j++) {

		printf("%d ", num[i][j]);
	
		}
	}

	
}
