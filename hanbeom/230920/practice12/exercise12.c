#include <stdio.h>
#include <string.h>

int main()
{
	char str[50];
	int num[50];
	int i;
	int size;

	printf("input string:\n");
	fgets(str,sizeof(str),stdin);
	
	size_t len = strlen(str) -1;

	printf("input index list's size:\n");
	scanf("%d", &size);
	
	printf("input index list:\n");
	for(i=0; i < size; i++)
	{
		scanf("%d", &num[i]);
	}
	
	for(i = 0; i < size; i++)
	{
		printf("%c", str[num[i]]);
	}
}
