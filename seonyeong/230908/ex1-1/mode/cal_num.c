#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cal.h"


int cal_num( char *pa)
{
    char num1[20] = {0};
    char num2[20] = {0};
    int cal_num1 = 0;
    int cal_num2 = 0;
    int count = 0;
    int i = 0, j = 0;
    char op = '0';
    int length = 0;
    int op_num = 0;
    int result = 0;    

   for(i = 0; i < 20; i++)
   {
      printf("cal[i] : %c\n", pa[i]);//check

	if(pa[i] == ' ')
	{
	    count++;
	
	    if(count < 2)
	    {
		for(j = 0; j < i; j++)
		{
		    num1[j] = pa[j];
		}
	    
		cal_num1 = atof(num1);
		printf("cal_num1 : %d\n", cal_num1);//check
		if((num1 != '0') && (atof(num1) ==0 ) )
		{
		    cal_num1 = 0;
		    cal_num2 = 0;
		    op = '0';
		    count = 3;
		}

	    }
        
	    if(count == 2)
	    {
		for(j = i + 1 ; j < length - 1 ; j++)
		{
		    num2[j - (i + 1)] = pa[j];
		    cal_num2 = atof(num2);
		}
		if((num2 != '0') && (atof(num2) == 0))
		{
		    cal_num1 = 0;
		    cal_num2 = 0;
		    op = '0';
		}
	    }
	}

	if(((pa[i] == '+')||(pa[i] == '-')||(pa[i] == '*')||(pa[i] == '/')||(pa[i] == '<') ||(pa[i] == '>')) && (count==1))
                    {
                        op_num = i;
                        op = pa[i];
			printf("op : %c\n", op);//check
                        if((pa[op_num + 1] != ' ')&&((pa[i] == '+')||(pa[i] == '-')||(pa[i] == '*')||(pa[i] == '/')))
                            {
                                count = 3;
                                cal_num1 = 0;
                                cal_num2 = 0;
                                op = '0';
                            }
                    }
   }
    
	    if (count == 3)
            {
                printf("error\n");
            }
            if(op == '+')
            {
                result = add(cal_num1, cal_num2);
                printf("result = %d\n", result);
            }
            else if(op == '-')
            {
                result = sub(cal_num1, cal_num2);
                printf("result = %d\n", result);
            }

            else if(op == '*')
            {
                result = mul(cal_num1, cal_num2);
                printf("result = %d\n", result);
            }
            else if(op == '/')
            {
                result = divide(cal_num1, cal_num2);
                printf("result = %d\n", result);
            }
            else if(op == '<')
            {
                result = cal_num1 << cal_num2;
                printf("result = %d\n", result);
            }
            else if(op == '>')
            {
                result = cal_num1 >> cal_num2;
                printf("result = %d\n", result);
            }
            else
                printf("error\n");


    printf("cal_num : %d %d %c\n", cal_num1, cal_num2, op);//check
    return result;
}

