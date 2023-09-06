#include <stdio.h>

int main() {


        int N;

        int number[20000];
	int sub_number[20000];

	int temp;

	int i;

        printf("input N\n");

        scanf("%d", &N);

        printf("input number\n");

	for(i =0 ;i < N;i++) {

		scanf("%d", &number[i]);
	}

	for (i =0; i < N; i++)    
	{
		sub_number[i] = number[N - i -1];     
		printf("%d ", sub_number[i]);
	}


}



	
