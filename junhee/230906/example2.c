/*15개의 숫자를 배열에 입력받는다.
순서대로 읽으면서 0이 나오면 그 전까지 최대치의 숫자를 출력하고, 그 숫자는 제거한다.
(만약 값이 업는경우 0으로 출력한다.)*/
#include <stdio.h>
#define arrSIZE 15
int main()
{
	
	int num[arrSIZE] = {0};
	int maxnum = 0;
	int history [arrSIZE]={0}; 
	int s = 0;
	int count = 0;
	int i,j,k,u = 0;		
	for(i = 0; i < arrSIZE; i++)
	{
		scanf("%d",&num[i]);
	}
	
	for(j = 0; j < arrSIZE; j++)
	{	
		if(num[j] == 0)
		{
			for(k = 0; k < j; k++)
			{
				if(num[k] > maxnum)
				{
					maxnum = num[k];
					s=j;
				}
			}
			num[s]=0;
			history[count]=maxnum;
			maxnum=0;
			count++;
		
		}
	}
	for(u = 0; u < count; u++)
	{
		printf("%d", history[u]); 
	}
	return 0;	
}
