#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float add(float a, float b)
{
     printf("%.3f\n", a + b);
	
}


float sub(float a, float b)
{
     printf("%.3f\n", a - b);
}


float mul(float a, float b)
{
    printf("%.3f\n", a * b);
}


float divide(float a, float b)
{
    printf("%.3f\n", a / b);
}

float main()
{

	int i = 0, j = 0;
	char cal[20] = {0};
	char num1[20] = {0};
	char num2[20] = {0};
	char op ;		
	int space1 = 0, space2 = 0;
	float cal_num1 = 0, cal_num2 = 0;
	int length = 0;

	printf("input expression: " );
	scanf("%s", &cal);
	length = sizeof(cal);

    while(1)
    {
	if(cal[length-1] != ' ')
	{
	    printf("error\n");
	    break;
	} 
	    
	for (i = 0; cal[i]; i++)
	{
	    if(cal[i] = 'q')
	    {
                printf("end");
		break;
            }	    

	    if (cal[i] = ' ')
	    {
		space1 = i;
		for (j = 0; j < space1; j++)
                {
                    num1[j] = cal[j];		    
                }
		continue;
	    }
	    
	    if ((cal[i] = '+')||(cal[i] = '-')||(cal[i] = '*')||(cal[i] = '/'))
	    {
		op = cal[i];	
		continue;
	    }	
	   
	    if (cal[i] = ' ')
            {
		space2 = i;
                for (j = space2 ; cal[i] ; j++)
                {
                    num2[j] = cal[j];
                }                
            }
	   
	}
	

	cal_num1 = atof(num1);
	cal_num2 = atof(num2);
	
	if (cal[op] = ( '+' ))
	{
	    add(cal_num1, cal_num2);
	}
	if (cal[op] = ( '-' ))
        {
            sub(cal_num1, cal_num2);
        }
	if (cal[op] = ( '*' ))
        {
            mul(cal_num1, cal_num2);
        }
	if (cal[op] = ( '/' ))
        {
            divide(cal_num1, cal_num2);
	}  
    }	 
	return 0;	
}
