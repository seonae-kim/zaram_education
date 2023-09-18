/*10개의 숫자를 입력받고, 최소값과 최대값을 출력하세요*/
#include <stdio.h>



int main()
{
	
	int num[10];
	int i,j = 0;	
	for (i=0; i<10; i++)
	{
		printf("%d번째\n",i+1); 
		scanf("%d",&num[i]);
		printf("\n");
	}
	
	int maxnum = num[0];
	int minnum = num[0];
	
	for (j=1; j<10; j++)
	{
		if (num[j]>maxnum)
		maxnum=num[j];
		if (num[j]<minnum)
		minnum=num[j];
	}
	
	printf("maxnum= %d, minnum= %d",maxnum,minnum);

	
	return 0;	
}
