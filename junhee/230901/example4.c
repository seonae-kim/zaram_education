/*계산기 프로그램을 만들어 보세요.
 더하기(+), 빼기(-), 곱하기(*), 나누기(/), 나머지(%), 비트연산자(<<, >>) 기능이 들어가야합니다.*/
#include <stdio.h>
int main(void)
{
	int num1,num2 =0;
	int fnc,result = 0;
	printf("num1과num2= ");
	scanf("%d %d",&num1,&num2);
	printf("\n");
	printf("기호를 고르세요\n"); 
	printf("1.+\n2.-\n3.*\n4./\n5.<\n6.>\n");
	scanf("%d",&fnc);
	switch (fnc)
		{
			case 1:
				result= num1 + num2;
				printf("%d + %d = %d", num1,num2,result);
			break;
						
			case 2:
				result= num1 - num2;
				printf("%d - %d = %d", num1,num2,result);
			break;			
			
			case 3:
				result= num1 * num2;
				printf("%d * %d = %d", num1,num2,result);
			break;
						
			case 4:
				result= num1 / num2;
				printf("%d / %d = %.2f", num1,num2,num1/(float)num2);
			break;
						
			case 5:
				result= num1 % num2;
				printf("%d % %d = %d", num1,num2,result);
			break;			
			
			case 6:
				result= num1 << num2;
				printf("%d << %d = %d", num1,num2,result);
			break;			
			
			case 7:
				result= num1 >> num2;
				printf("%d >> %d = %d", num1,num2,result);
			break;			
		}
	
	return 0;	
}
