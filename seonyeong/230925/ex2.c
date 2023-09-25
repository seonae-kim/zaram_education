#include <stdio.h>
#include <math.h>


int main()
{
	int num = 0;
	int sum = 0;
	double i = 0;

	printf(" input number: ");
	scanf("%d", &num);
	int q = sizeof(num)-2 ;

		sum = num;
	for(i = q ; i >= 0; i--)
	{
		double  k = pow( 10, i);
		 
		sum += (int)(num / k) ; 
		num -=(int)( num / k ) * k;

	}

	printf("%d\n", sum);

}
