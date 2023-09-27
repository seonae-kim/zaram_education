#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cal.h"
#include "cal_num.h"


int mode3()
{

	while(1)
	{
		char cal[20] = {0};
		char num1[20] = {0};
		char num2[20] = {0};
		int cal_num1 = 0;
		int cal_num2 = 0;
		int p = 0; 
		char op = '0';
		int count = 0;
		int result = 0;
		int op_num = 0;
		int i = 0, j = 0;
		int length = 0;
		int e = 0;
		char ch;


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


		cal_num(cal);
	}
}
