/*자연수를 입력한다. 예를 들어, 216의 계산법은 (198 + 1 + 9 + 8) = 216 이된다.
숫자 + 각자리의 숫자의 합이다.
ex) input : 216, output : 198
*/

#include <stdio.h>

int cal (int n, int x)
{
	n /= 10; 	
	if(n <= 0)
	{
		return x + 1;
	}
	
	return cal(n , x + 1);
}

int rsum(int n, int len, int x)
{
	int i;
	int nums[50];
	int rst = 0;
	int rst_1 = 0;
	int rst_2 = 0;
	int sum = 0;
	int a = 1;
	
	for(i = 0; i < len; i++)
	{
		a *= 10; 
	}
	
	for (i = 0; i < len; i++)
	{
		rst_1 = x % a;
		a /= 10;
		rst_2 = rst_1 / a;
		nums[i] = rst_2;
	}	
	
	for ( i = 0; i < len; i++)
	{
		sum += nums[i];
	}
	
	rst = x + sum;
	
	if(rst == n)
	{
		return x;
	}
	
	return rsum(n, len, x + 1);
}


int main()
{
	int num = 0;
	int rst = 0;
	int len = 0;
	int x = 0;
	scanf("%d", &num);

	len = cal(num, x);
	rst = rsum(num, len, x);
	printf("%d", rst);
	
	return 0;
}
