/*2행 4열로 이루어진 배열에 숫자를 입력받는다.
 모든 조합을 출력하세요*/
#include <stdio.h>
#define COLUMN 2
#define	ROW 4

int main()
{
	int arr[COLUMN][ROW] = {0,};
   	int i,j,k,o = 0; 
	for(i = 0; i < COLUMN; i++)
	{
		for(j = 0; j < ROW; j++)
		{
            		scanf("%d", &arr[i][j]);
		}
	}
	for(k = 0; k < ROW; k++)
	{
		for(o = 0; o < ROW; o++)
		{
			printf("(%d,%d)",arr[0][k],arr[1][o]);
		}
	}

	return 0;	
}
