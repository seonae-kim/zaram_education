#include <stdio.h>

int main() {

	int num1, num2;

	char op;

	printf("input two numbers: ");
	scanf("%d %d", &num1, &num2);

	printf("input operator: ");
	scanf(" %c", &op);

	if (op == '+') {
		printf("%d", num1 + num2);
	}

	else if (op == '-') {
		printf("%d", num1 - num2);
	}

	else if (op == '*') {
		printf("%d", num1 * num2);
	}
	else if (op == '/') {
		printf("%d", num1 / num2);
	}

	else if (op == '%') {
		printf("%d", num1 % num2);
	}

}	







 
