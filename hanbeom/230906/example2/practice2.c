#include <stdio.h>

int main() {


        int N;

        int number[20000];

	int temp;

	int i;

        printf("input N\n");

        scanf("%d", &N);

        printf("input number\n");

	for(i =0 ;i < N;i++) {

		scanf("%d", &number[i]);
				
	}

	for (i = 0; i < N/2; i++)   				//3
	{ 						
		temp = number[i];                                        
		number[i] = number[N -i -1];		//		[0] = [4] >> [4] =[0]       
		number[N - i -1] = temp;		//		[1] = [3] >> [3] =[1]        
		printf("%d ", number[i]);		//		[2] = [2] >> [2] =[2]
	}						//		[3] = [1]     
							//		[4] = [0]

	for (i = N/2; i <N; i++)
	{
		printf("%d ", number[i]);

	}
}



	
