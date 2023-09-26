#include <stdio.h>

int main()
{
	int N = 0;
    int i = 0, j = 0, num = 1;
    int arr[20][20] = {0};

    printf(" input N:");
    scanf("%d", &N);

	for(i = 0; i < N; i++)
	{  
		if( i % 2 == 0)
		{
			for( j = 0; j < N; j++)
			{
				arr[i][j] = num++;
			}
		}

		if(i % 2 == 1)
		{
			for (j = N-1; j >= 0; j--) 
			{
				arr[i][j] = num++;
			}

		}
	}

	for(i = 0; i < N; i++)
        {
            for(j = 0; j < N; j++)
            {
                printf("%2d ", arr[i][j]);
            }
            printf("\n");
        }

    return 0;

}
