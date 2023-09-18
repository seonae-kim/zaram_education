/*4행 4열로 이루어진 배열에 숫자를 입력받는다.
숫자를 모두 출력하세요*/
#include <stdio.h>
#define COLUMN 4
#define	ROW 4

int main()
{
	int arr[COLUMN][ROW] = {0,};
	int i,j k,o = 0;
    
	for(i = 0; i < COLUMN; i++)
	{
		for(j = 0; j < ROW; j++)
		{
            		scanf("%d", &arr[i][j]);
		}
	}

	for(k = 0; k < COLUMN; k++)
	{
		for(o = 0; o < ROW; o++)
		{
	            printf("%d ", arr[k][o]);
		}
	}
	return 0;	
}
