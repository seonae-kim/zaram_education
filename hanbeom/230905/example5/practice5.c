#include <stdio.h>

int main() {


	int i,j;

	int num[4][4];

	int max = -5;

	int maxgroup[4];

	int maxgroupindex[4];

	for(i=0; i <4; i++) {
		for(j=0; j <4; j++) {

		scanf("%d", &num[i][j]);
		}


	}

	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			if(num[i][j] >= max){
			       	max = num[i][j];
			}

			else {
				max = max;
			}

		}
	maxgroup[i] = max;	
	maxgroupindex[i] = j;
	}


	for(i=0;i<4;i++) {
		if( (maxgroupindex[i] == maxgroupindex[i+1]) ||  (maxgroupindex[i] == maxgroupindex[i-1]) ) {
		       
		maxgroup[i] =0;				//max fnvm
		


		else {
		}

	}	

printf("%d", maxgrou [0]+  maxgroup[1] + maxgroup[2] + maxgroup[3]); 
		
/* print
	for(i=0; i <4; i++) {

	printf("\n");
		for(j=0; j < 4; j++) {

		printf("%d ", num[i][j]);
	
		}
	}
*/
	
}
