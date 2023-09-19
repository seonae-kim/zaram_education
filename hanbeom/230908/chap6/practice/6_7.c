#include <stdio.h>

int main()
{

	int k;
	int sum = 2;		//2 is sosu
	int i =3;
	int count = 0;

	while(sum < 2000)			//sum =2
	{
		for(k = 2; k< i; k++)		//    
		{
			if( (i % k) == 0)	// skajwl 0
			{
				count++;
			}
		}

		if(count == 0)
		{
			sum += i;
		}
		i++;
		count = 0;
	}

	printf("sum is %d\n", sum - (i-1));
	printf("last prime number is %d", (i-1));
}
