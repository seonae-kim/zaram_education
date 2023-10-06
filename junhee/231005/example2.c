/*자연수를 입력한다. 예를 들어, 216의 계산법은 (198 + 1 + 9 + 8) = 216 이된다.
숫자 + 각자리의 숫자의 합이다.
ex) input : 216, output : 198
*/
#include <stdio.h>

int main()
{
	int i,j,k,o;
	int num = 0;
	int rst = 0;
	int tmp = 0;
	scanf("%d", &num);
	for(k = 0; k < 10; k++)
	{
		for(i = 0; i < 10; i++)
		{
			for( j = 0; j < 10; j++)
			{
				for (o = 0; o < 10; o++)
				{
					tmp = (k*1000) + (i*100) + (j*10) + o + k + i + j +o;
					if(num == tmp)
					{
						rst = (k*1000) + (i*100) + (j*10) + o;
					}
				}
			}
		}	
	}
	
	
	printf("%d",rst);
	
	return 0;
}

