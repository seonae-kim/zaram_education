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

float div(float a, float b)
{
	return a / b;
}

int main()
{
	char str[N];
	char op = 0;
	int i = 0;
	float a = 0, b = 0;
	float result = 0;
	while(1)
	{
		printf("Please enter the formula : ");
		fgets(str, sizeof(str), stdin);
		
		if(str[0] == 'q')
		{
			break;
		}

		sscanf(str, "%f %c %f", &a, &op, &b);

		if(a < -100000 || a > 100000 || b < -10000 || b > 10000)
		{
			printf("wrong \n");
			continue;
		}

		switch(op)
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
				result = div(a,b);
				break;	
		}

		if(result == (int)result)
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
