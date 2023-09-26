#include <stdio.h>
#include <math.h>

int P(int x)
{
	if(x < 10)
		return x; 

	else
		return x % 10 + P(x / 10);
}


int main()
{
	int num = 0;
	int A = 0;

	printf("input number: ");
	scanf("%d", &A);
	
	for ( num = A; num > 0; num--)
	{
		P(num--);
		
		if( num + P(num) == A)
		{
			printf( "%d\n" , num );
			break;
		}
		
	}
	

	
}
