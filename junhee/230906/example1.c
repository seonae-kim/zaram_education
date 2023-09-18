/*10개의 숫자를 배열에 입력받는다.
순서대로 읽으면서 0이 나오면 가장 최근의 숫자를 제거한다.
최종적으로 남은 숫자의 합을 출력한다.*/
#include <stdio.h>


int main()
{
	
	int num[10];
	int sum = 0;
	int i,j = 0
	for(i=0; i<=9; i++)
	{
		scanf("%d",&num[i]);
		}
	for(j=0; j<=9; j++)
		if(num[j] == 0)
		{
			sum-=num[j-1];
		}
		else
		sum+=num[j];
	}
	
	printf("%d",sum);
	return 0;	
}

