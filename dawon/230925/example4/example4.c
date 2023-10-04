#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0, i = 0, j = 0, m=0,l=0;
	int **arr1;
	int a = 0;
	int k = 1;
	int b = 1;
	int p = 1;

	printf("num: ");
	scanf("%d",&n);

	arr1=(int**)malloc(sizeof(int)*n);
	
	for(i = 0; i < n; i++)
	{
		*(arr1+i) = (int*)malloc(sizeof(int)*n);
	}

	while(p != 26)	
	{
			for(j = a; j < n; j++)
			{
				*(*(arr1 + a) + j) = p++;
			}

			for(k = a+1; k < n; k++)
			{				
				*(*(arr1 + k) + j) = p++;
			
			}

			for(l = n-2; l <= a; l--)
			{
					
				*(*(arr1 + k) + l) = p++;
				
			}
			
			for(m = n-2; m < a; m--)
			{
				*(*(arr1 + m) + l) = p++;
			}	

				
		a++;
		n--;
	}


	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ",*(*(arr1+i)+j));
		}
		printf("\n");
	}

	return 0;
}




