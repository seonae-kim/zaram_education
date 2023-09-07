#include <stdio.h>

int main()
{
	int n=0;
	int arry[5][5];
	
	printf("input: ");
        for(int  i = 0 ; i < 4 ; i++)
        {
                for(int j = 0 ; j < 4 ; j++)
                {
                        scanf("%d",&n);
                        arry[i][j] = n;
                }
        }
	
	printf("output: ");
	for(int i = 0 ; i < 4 ; i++)
	{
		for(int j = 0 ; j < 4 ; j++)
		{
			printf(" %d",arry[i][j]);
		}
	}
	printf("\n");
	return 0;
}
