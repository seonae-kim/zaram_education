#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char c;
	int n = 0;

	printf("n: ");
	scanf("%d",&n);
	getchar();

	printf("c: ");
	scanf("%c",&c);
	getchar();

	while(c != '\n')
	{
		if(c == 'w')
			n+=1;
		else if(c == 's')
			n-=1;
		else if(c == 'd')
			n+=10;
		else if(c == 'a')
			n-=10;
		
		printf("c: ");
		scanf("%c",&c);
		getchar();

	}

	printf("result: %d\n",n);

	return 0;

}
