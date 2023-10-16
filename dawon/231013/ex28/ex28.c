#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* numlist_n(int *numlist);

int main()
{
	int numlist[101] = {'\0', };
	int *numi;
	int *numn;
	int i = 0, n = 0;

	
	scanf("%d",&n);

	numi = (int*)malloc(sizeof(int) * n);

	for(i = 0; i < n; i++)
	{
		scanf("%d",(numi +i));
	}
	
	numn = numlist_n(numi);

	for(i = 0; i < 2; i++)
	{
		printf("%d ",*(numn + i));
	}

	return 0;

}


int* numlist_n(int *numlist)
{
	int i = 0, even = 0, odd = 0;
	int *rnum;

	rnum = (int *)malloc(sizeof(int) * 3);

	printf("numlist : ");
	for( i = 0; i < 5; i++)
	{
		printf("%d\n",*(numlist + i));
	}

	for(i = 0; i < 101; i++)
	{
		if(*(numlist + i) == 0)
			break;
		if(*(numlist + i) % 2 == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}
	*(rnum) = even;
	*(rnum + 1) = odd;
	return rnum;
}


