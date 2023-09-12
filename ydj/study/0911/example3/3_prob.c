#include<stdio.h>
#define N 50

float add(float a, float b)
{
	return a + b;
}

float sub(float a, float b)
{
	return a - b;
}

float mul(float a, float b)
{
	return a * b;
}

float divd(float a, float b)
{
	return a / b;
}

int main()
{
	char str[N] = {};
	char op = 0;
	int i = 0;
	float a = 0, b = 0;
	float result = 0;
	while(1)
	{
		printf("Please enter the formula : ");
		fgets(str, sizeof(str), stdin);
		
		// not working... ??		
		if(str[0] == 'q' && str[1] == '\0')
		{
			break;
		}

		sscanf(str, "%f %c %f", &a, &op, &b);
//		printf("%f %c %f \n", a, op, b);
//		printf("%c %c \n", str[0], str[1]);

		if (op != '+' && op != '-' && op != '*' && op != '/')
		{
			printf("wrongq \n");
			continue;
		}

		if (a < -100000 || a > 100000 || b < -10000 || b > 10000)
		{
			printf("wrong");
			continue;
		}

		switch (op)
		{
			case '+' :
				result = add(a,b);
				break;
			case '-' :
				result = sub(a,b);
				break;
			case '*' :
				result = mul(a,b);
				break;
			case '/' :
				result = divd(a,b);
				break;	
		}

		if (result == (int)result)
		{
			printf("%d \n", (int)result);
		}

		else
		{
			printf("%.3f \n", result);
		}
		
		result = 0;
	}
	return 0;
}
