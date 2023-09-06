#include <stdio.h>

int main()
{

	char c;
	int n=0;
	char a[20];
	int b=0;

	printf("input: ");

	for(int i = 0 ; i < 20 ; i++)
	{
		if(c == 'a')
			break;

		scanf("%c",&c);
		a[i] = c;
		b++;
	}
	
	for(int i = 0 ; i < b ; i++)
	{
		if(a[i] == '(')
			n++;

		else if(a[i] == ')')
			n--;
	}

	if(n == 0)
		printf("output: ok\n");
	else
		printf("output: no\n");

	return 0;

}
