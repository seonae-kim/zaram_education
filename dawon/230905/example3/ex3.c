#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct
{
	char temp[MAX];
	int top;
}STACK;

STACK init_stack(STACK* s_tmp)
{
	s_tmp -> top =-1;
}

int isFull(STACK* s_tmp)
{
	if(s_tmp -> top == MAX -1)
		return 1;
	else 
		return 0;
}

int isEmpty(STACK* s_tmp)
{
	if(s_tmp -> top == -1)
		return 1;
	else 
		return 0;
}

STACK push(STACK* s_tmp, char a)
{
	if(isFull(s_tmp) == 1)
	{
		printf("Stack Full");

	}
	else
	{
		s_tmp -> top++;
		s_tmp -> temp[s_tmp -> top]  = a;
	}
}

int pop(STACK* s_tmp)
{
	if(isEmpty(s_tmp) == 1)
	{
		return 0;
	}
	else	
	{
		s_tmp -> top--;
	}
}

int main()
{
	STACK s;

	int i=0;
	char c;
	int a=0;

	printf("input: ");	
	scanf("%s",s.temp);
	init_stack(&s);

	while(s.temp[i] != '\0')
	{

		if(s.temp[i] == '(')
		{
			push(&s,s.temp[i]);
		}
		else if(s.temp[i] == ')')
		{
			a = pop(&s);
			
			if(a == 0)
			{
				printf("output: no");
				exit(0);
			}
		}
	}

	printf("output: ok");

	printf("\n");

	return 0;
}


		
		









