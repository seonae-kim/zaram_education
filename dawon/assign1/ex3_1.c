#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n=0,k=0;
	int i=0;
	int p=0;
	int b=1;

	scanf("%d %d", &n, &k);

	int *a;

	a=(int*)malloc(sizeof(int) *n);

	if(a==NULL)
	{
		printf("Error");
		exit(0);
	}

	printf("input: %d &d  ",n,k);

	for(i;i<n;i++)
		*(a+i)=i+1;

	while(1)
	{
		if(b==n)
			break;

		for(int j=1;j<=n;j++)
		{
			if(*(a+j)==0)
				continue;

			p++;

			if(p==k)
			{
				printf("output: %d :",*(a+j));
				*(a+j)=0;
				p=0;
			}
		}

		b++;

	}

	free(a);
	return 0;

}





