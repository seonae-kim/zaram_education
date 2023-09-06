#include <stdio.h>
#define COLUMN 4
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

	for(int i=0;i<COLUMN;i++)
	{
		for(int j=0; j<ROW;j++)
		{
            printf("%d ", arr[i][j]);
		}
	}
	return 0;	
}
