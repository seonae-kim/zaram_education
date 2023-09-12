#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cal.h"

int mode2()
{
    while(1)
    {
		int i = 0, j = 0;
	        char cal[20] = {0};
		char num1[20] = {0};
		char num2[20] = {0};
		char op = '0';
		int count = 0;
		long long cal_num1 = 0;
		long long cal_num2 = 0;
		int result = 0;
		char *ptr = NULL;
		int length = 0;
	        char mode = 0;
		int e = 0;
		int p = 0;
		char ch;
		int op_num = 0;

	       printf("input expression: " );
               fgets(cal, sizeof(cal), stdin);
               length = strlen(cal);

               for(i = 0; i < 20; i ++)
                {
                    if((cal[i] == 'q')&&(length == 2))
                    {
                        p++;
                        printf("end\n");
                    }
                }

                if(p == 1)
                 break;

                for(i = 0; i < 20; i++)
                {
                    if(cal[i] == ' ')
                    {
                        count++;

                        if(count < 2)
                        {
                            for(j = 0; j < i; j++)
                            {
                                num1[j] = cal[j];
                                cal_num1 = strtoll(num1, &ptr,16);
                            }
                            if((num1 != '0') && (strtoll(num1, &ptr, 16) ==0 ) )
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
                                num2[j - (i + 1)] = cal[j];
                                cal_num2 = strtoll(num2, &ptr,16);
                            }

                            if((num2 != '0') && (strtoll(num2,&ptr,16) == 0))
                            {
                                cal_num1 = 0;
                                cal_num2 = 0;
                                op = '0';
                            }

                        }
                    }
		    if(((cal[i] == '+')||(cal[i] == '-')||(cal[i] == '*')||(cal[i] == '/')||(cal[i] == '>')||(cal[i] == '<')) && (count == 1))
                        {
                            op_num = i;
                            op = cal[i];

			    if((cal[op_num + 1] != ' ')&&((cal[i] == '+')||(cal[i] == '-')||(cal[i] == '*')||(cal[i] == '/')))
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
                    continue;
                }

                if (count == 3)
                {
                    printf("error\n");
                    continue;
                }
                if(op == '+')
                {
                    result = add(cal_num1, cal_num2);
                    printf("result :%x\n", result);
                }

                else if(op == '-')
                {
                    result = sub(cal_num1, cal_num2);
                    printf("result : %x\n", result);
                }

                else if(op == '*')
                {
                    result = mul(cal_num1, cal_num2);
                    printf("result : %x\n", result);
                }

                else if(op == '/')
                {
                    result = divide(cal_num1, cal_num2);
                    printf("result : %x\n", result);
                }

                else if(op == '<')
                {
                    result = cal_num1 << cal_num2;
                    printf("result : %x\n", result);
                }

                else if(op == '>')
                {
                    result = cal_num1 >> cal_num2;
                    printf("result : %x\n", result);
                }
                else printf("error\n");

    }
}
