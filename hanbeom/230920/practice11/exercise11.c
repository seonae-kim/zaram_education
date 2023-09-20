#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	char str[30] = {0,};
	int i;

	printf("input n:\n");
	scanf("%d", &n);

	printf("input control:\n");

	while (getchar() != '\n');
	fgets(str,sizeof(str),stdin);		

	size_t len = strlen(str) -1;		
	
	for(i =0; i <len; i++)
	{
		if(str[i] == 'w')
		{
			n += 1;
		}
		else if(str[i] == 's')
		{
			n -= 1;
		}
		else if(str[i] == 'd')
		{
			n += 10;
		}
		else if(str[i] == 'a')
		{
			n -= 10;
		}
	}

	printf("%d", n);
}
