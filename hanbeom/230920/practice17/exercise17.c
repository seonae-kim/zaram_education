#include <stdio.h>
#include <string.h>

int main()
{
	char str[50] ={0,};
	int num1;
	int num2;
	int num1_store;
	int i;

	printf("input str:\n");
	fgets(str,sizeof(str),stdin);	//hello

	printf("input num1:\n");
	scanf("%d", &num1);

	printf("input num2:\n");
	scanf("%d", &num2);
	
	size_t len = strlen(str) -1;

	for(i = 0; i < len; i++)
	{
		if(i==num1)				
		{
			num1_store = str[i];	
			str[num1] = str[num2];	
			str[num2] = num1_store;	
		}
	}
	for(i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}

}

