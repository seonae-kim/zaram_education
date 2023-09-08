#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float add(float a, float b)
{
    float c = a + b;
    return c;
}

float sub(float a, float b)
{
    float c = a - b;
    return c;
}

float mul(float a, float b)
{
    float c = a * b;
    return c;
}

float divide(float a, float b)
{
    float c = a / b;
    return c;
}

int main()
{
    int i = 0, j = 0;
    char cal[20] = {0};
    char num1[20] = {0};
    char num2[20] = {0};
    char op ;
    float result = 0;
    int space1 = 0, space2 = 0;
    float cal_num1 = 0, cal_num2 = 0;

    printf("input expression: " );
    fgets(cal, sizeof(cal), stdin);

    while(1)
    {
	for(i = 0; i < 20; i ++)
	{
	    if(cal[i] == 'q')
	    {
		printf("end\n");
		break;		
	    }   
	}
		 
	for(i = 0; i < 20; i++)
	{
	    if(cal[i] == ' ')
	    {
		space1 = i;
		for(j = 0; j < space1; j++)
                {
                    num1[j] = cal[j];
		    cal_num1 = atof(num1);
                }				
	    } continue; 

	    if((cal[i] == '+')||(cal[i] == '-')||(cal[i] == '*')||(cal[i] == '/'))
	    {
		op = cal[i];
		continue;		
	    } 
	   
	    if(cal[i] == ' ')
            {
		space2 = i;
                for(j = space2 + 1 ; j < 20 ; j++)
                {
                    num2[j] = cal[j];
		    cal_num2 = atof(num2);
                }				
            }    
	}

	printf("result : ");

	if(op == ( '+' ))
	{
	    float result = add(cal_num1, cal_num2);
	    printf("%.3f\n", result);
	    break;
	}

	else if(op == ( '-' ))
        {
            float result = sub(cal_num1, cal_num2);
	    printf("%.3f\n", result);
	    break;	    
        }

	else if(op == ( '*' ))
        {
            float result = mul(cal_num1, cal_num2);
	    printf("%.3f\n", result);
	    break;	    
        }

	else if(op == ( '/' ))
        {
            float result = divide(cal_num1, cal_num2);
	    printf("%.3f\n", result);
	    break;	    
	}
	else 
	{
	    printf ("error\n");
	    break;
	}	
    } 
    return 0;	
}
