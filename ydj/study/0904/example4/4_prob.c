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

	switch(op)
	{
		case '+' :
			printf("%d \n", a + b);
			break;

		case '-' :
			printf("%d \n", a - b);
			break;

		case '*' :
			printf("%d \n", a * b);
			break;

		case '/' :
			printf("%d \n", a / b);
			break;

		case '<' :
			printf("%d \n", a << b);
			break;

		case '>' :
			printf("%d \n", a >> b);
			break;
	}

	return 0;
}
