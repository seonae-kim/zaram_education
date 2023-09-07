#include <stdio.h>
#define COLUMN 2
#define	ROW 4

int main()
{
	int arr[COLUMN][ROW] = {0,};

    
	for(int i=0;i<COLUMN;i++)
	{
		for(int j=0; j<ROW;j++)
		{
            scanf("%d", &arr[i][j]);
		}
	}
	for(int i=0;i<ROW;i++)
	{
		for(int j=0; j<ROW;j++)
		{
			printf("(%d,%d)",arr[0][i],arr[1][j]);
		}
	}

	return 0;	
}
