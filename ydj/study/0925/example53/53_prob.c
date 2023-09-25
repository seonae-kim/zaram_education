#include<stdio.h>

int main()
{
	char str[20] = {0};
	char temp = '0';
	int num1 = 0, num2 =0;
	printf("Please enter the string : ");
	fgets(str, 20, stdin);

	printf("Please enter the num1 : ");
	scanf("%d", &num1);
	printf("Please enter the num2 : ");
	scanf("%d", &num2);

	temp = str[num1];
	str[num1] = str[num2];
	str[num2] = temp;

	printf("%s\n", str);
	return 0;
}
