#include <stdio.h>

int main()
{

	char c;
	int n=0;
	char a[20];
	int b=0;

	printf("input: ");	

	scanf("%s",a);

	for(int i = 0 ; i < 20 ; i++)
	{
	
		if(a[i] == '(')
			n++;

		else if(a[i] == ')')
			n--;
		else if(a[i] == '\0')
			break;
	}

	if(a[0] != '(')
		printf("n: %d output: no\n",n);

	else if(n == 0)
		printf("n:%d output: ok\n",n);
	else
		printf("n:%d output: no\n",n);

	return 0;

}
