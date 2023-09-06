#include <stdio.h>
#include <string.h>

int main() {

	int N;

	char word[10][100];    // 10 words, 100 chracter

	int i, j;

	int length = 0;

	printf("input N\n");

	scanf("%d", &N);

	printf("input number\n");

	for(i=0;i < N;i++) {
					//N=3
		scanf("%s", word[i]);   

		printf("%s ",word[i]);		//create  word = {cat, dog, fihh}
	}
	
	for(i=0; i< N;i++) {
		for(j=0; word[i][j]!= 0; j++) {
		length += 1;
		}
	printf("%d ", length);
	length =0;
}		
		
}
	

