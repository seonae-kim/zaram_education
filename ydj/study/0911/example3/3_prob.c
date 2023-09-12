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
	int i = 0;
	while(1)
	{
		printf("Please enter the formula : ");
		fgets(str, sizeof(str), stdin);
		
		// reset -> to avoid printing previous value		
		float a = 0, b = 0;
		float result = 0;
		char op = 0;

		if(str[0] == 'q' && str[2] == '\0')
		{
			break;
		}

		// feedback 1. 4 * 45d
		// other method.? to verify a and b (int) -> present working
		sscanf(str, "%f %c %f", &a, &op, &b);
//		printf("%f %c %f \n", a, op, b);
		
		int flag = 0;
		flag = 	sscanf(str, "%f %c %f", &a, &op, &b);
		printf("%d \n", flag);

		if (op != '+' && op != '-' && op != '*' && op != '/')
		{
			printf("wrong a \n");
			continue;
		}

		if (a < -100000 || a > 100000 || b < -10000 || b > 10000)
		{
			printf("wrong b");
			continue;
		}
		
		// add default
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
			default : 
				printf("Not supported");	
		}

		if (result == (int)result)
		{
			printf("%d \n", (int)result);
		}

		else
		{
			printf("%.3f \n", result);
		}	
	}
	return 0;
}
