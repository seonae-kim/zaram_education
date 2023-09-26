#include <stdio.h>

int main()
{
    int N = 0;
    int i = 0, j = 0, num = 1;
    int arr[20][20] = {0};

    printf(" input N:");
    scanf("%d", &N);


	for(j = 0; j < N; j++)
    {
        if( j % 2 == 0)
        {
            for( i = 0; i < N; i++)
            {
                arr[i][j] = num++;
            }
        }

        if(j % 2 == 1)
        {
            for (i = N-1; i >= 0; i--)
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

