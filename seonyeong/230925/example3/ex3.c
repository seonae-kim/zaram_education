#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int N = 0;
	int i = 0, j = 0, p = 0;
	int count = 0;
	int num = 0;
	char arr[50][50] = {0};

	printf("input N: ");
	scanf("%d", &N);
	
	printf("input words:");
	
	for(i = 0; i < N; i++)
	{
		scanf("%s", arr[i]);
	}

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < 50; j++)
		{
			if(arr[i][j] != arr[i][j+1])
			{
				for ( p = j+2; p < 50; p++)
				{
					if(arr[i][j] == arr[i][p])
					{
						goto A;
					}
				}

			}
		}
			num++;
A:
;
	}

	printf("output: %d\n",num );

	return 0;

}


