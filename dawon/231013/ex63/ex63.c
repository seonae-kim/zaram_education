#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i,j,m,p,count = 0;
	char k;
	char carr[10] = {0, };

	printf("i: ");
	scanf("%d",&i);
	

	printf("j: ");
	scanf("%d",&j);
	while(getchar() != '\n');

	printf("k: ");
	scanf("%c",&k);

	for(m = i; m <= j; m++)
	{
		sprintf(carr,"%d",m);
		
		for(p = 0; p < strlen(carr); p++)
		{
			if(carr[p] == k)
				count++;
		}
	}

	printf("result: %d\n",count);

	return 0;
}


		
