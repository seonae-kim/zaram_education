#include <stdio.h>

int main() {


        int N;

        int number[20000];

	int temp;

	int i;

        printf("input N\n");

        scanf("%d", &N);

        printf("input number\n");

	for(i =N-1 ;i >= 0;i--) {   
		scanf("%d", &number[i]);  			
								
	}

	for(i = 0 ; i < N; i ++) {        
		printf("%d ", number[i]);
	}


}
    

