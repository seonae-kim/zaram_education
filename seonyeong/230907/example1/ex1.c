#include <stdio.h>
#include <math.h>
#include <string.h>


int add(int a, int b)
{
	double c = a + b;
	return c;
}


int sub(int a, int b)
{
	double c = a - b;
	return c;
}


int mul(int a, int b)
{
	double c = a * b;
	return c;
}


int div(int a, int b)
{
	double c = a / b;
	return c;
}

int main()
{
   
	int i = 0, j = 0;
	char cal[20] = {0};
	double cal_num1 = 0;
	double cal_num2 = 0;
	int op = 0;
	int length = 0;
	double result = 0;

	printf("input expression: " );
	scanf("%s", &cal);

	length = strlen(cal);

	
	
	//if (cal[0] == '-') //minus input
	//{
	//    for(i = 0; cal[i]; i++)
	//    {

	  //  }	
	//}
	

	for (i = 0; cal[i]; i++)
	{
	   if ((cal[i] = '+')||(cal[i] = '-')||(cal[i] = '*')||(cal[i] = '/'))
	   {	       
	       op = i;
	        for ( j = 0; j < op ; j++ )
		 {
		     cal_num1 += (cal[j]-'0') * pow(10, (op -1 - j));
		  }
		for ( j = op + 1; j < length; j++ )
		 {
		     cal_num2 += (cal[j]-'0') * pow(10, (length - 1 - j)) ;
	  	 }
	   }
	   //operation
	    if (cal[op] = ( '+' ))
            {
               double result = add(cal_num1, cal_num2 );
	       printf("%.2f", result);
               break;

            }
            if (cal[op] = ( '-' ))
            {
                double result =  sub(cal_num1, cal_num2 );
		printf("%.2f", result);
                break;
            }
            if (cal[op] = ( '*' )) //conflict
            {
                double result =  mul(cal_num1, cal_num2 );//conflict
		printf("%.2f", result);
                break;
            }
            if (cal[op] = ( '/' ))
            {
                double result =  div(cal_num1, cal_num2 );
		printf("%.2f", result);
                break;
            }
	   

	    if(cal[i] == 'q')
	    {
                printf("end");
            }

	    break;
	} 
 
	   
	
 
	return 0;	
}
