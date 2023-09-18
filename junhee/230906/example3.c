/*괄호가 올바르게 구성되었는지 검사받는다. 맞으면 ok, 틀리면 no로 출력한다*/
#include <stdio.h>
#define SIZE 20

int examine(char *input)
{
	int i = 0;
	int count = 0;
	for( i = 0; input[i] != '\0'; i++)
	{
		if (count < 0)
		{
			return 0;
		}
		
		if(input[i] == '(')
		{
			count++;
		}
		else if(input[i] == ')')
		{
			count--;
		}	
		printf("count = %d\n", count);
	}
	if (count == 0)
	return 1;
	else
	return 0;
}

int main()
{
	char input[SIZE];
	
	scanf("%s",input);
	
	int result = examine(input);	
	if(result){
		printf("ok\n");
	}
	else{
		printf("no\n");
	}
    return 0;
}
