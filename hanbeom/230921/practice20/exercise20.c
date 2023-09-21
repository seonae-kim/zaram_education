#include <stdio.h>
#include <string.h>
int main()
{

	char numstr[50] = {0,};
	int N;
	int i;

	printf("input N:\n");
	scanf("%d",&N);

	while (getchar() != '\n');

	printf("input: number\n");
	fgets(numstr,sizeof(numstr),stdin);	//23

	size_t len = strlen(numstr) - 1;

	
	for(i = 0; i < len; i++)
	{
		printf("%c", numstr[i] + 49);
	}




}
