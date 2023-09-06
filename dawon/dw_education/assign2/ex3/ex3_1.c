#include <stdio.h>

int main()
{
	char arry[20];
	
	printf("input: ");
	scanf("%s",arry);

	int n=0;

	for(int i = 0; i < 20; i++)
	{
		if(arry[i] == '\0')
			break;
		
		if(arry[i] == '(')
			n++;

		else if(arry[i] == ')')
		{
			if(n == 0)
			{
				printf("output: no\n");
				return 0;
			}
			n--;
		}
	}

	if(n != 0)
		printf("output: no\n");
	else
		printf("output: ok\n");

	return 0;
}
