#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = 0; 
	int n = 0, m = 0;
	int result = 0;

	printf("number: ");
	scanf("%d",&num);

	printf("n: ");
	scanf("%d",&n);

	printf("m: ");
	scanf("%d",&m);

	if(num % n == 0 && num % m == 0)
		result = 1;
	else 
		result = 0;

	printf("result : %d\n",result);

	return 0;
}
