#include<stdio.h>

int main()
{
	int a,b;
	char op;
	
	printf("Welcome to calculator ! \n");
	printf("If you want << or >> operation, enter < , > instead of <<, >> \n");

	printf("Slect the operation what you want (+,-,*,/,<<,>>) : ");
	scanf("%c", &op);

	printf("Enter the num1, num2 : ");
	scanf("%d %d", &a, &b);

	if(op == '+')
	{
		printf("%d \n", a+b);	
	}
	else if(op == '-')
	{
		printf("%d \n", a-b);
	}
	else if(op == '*')
	{
		printf("%d \n", a*b);
	}
	else if(op == '/')
	{
		printf("%d \n", a/b);
	}
	else if(op == '<')
	{	
		printf("%d %d \n", a<<1, b<<1);
	}
	else if(op == '>')
	{
		printf("%d %d \n", a>>1, b>>1);
	}
}
