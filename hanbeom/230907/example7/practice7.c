#include <stdio.h>

int main() {


	int i,j,t;
	int num[2][4];
	int g=0;

	for(i=0; i <2; i++) {
		for(j=0; j <4; j++) {
		scanf("%d", &num[i][j]);
		}
	}		


	for(t=0; t <4; t++) {

		for(j=0; j < 4; j++) {
		printf("(%d, %d) ", num[g][t], num[g+1][j]);  
		}
	}
}
