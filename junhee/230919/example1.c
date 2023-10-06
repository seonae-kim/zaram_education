/*문자열을 입력받는다. 숫자만 출력하시오.
조건 : 값이 작은 순서대로 입력하세요. (중복 된 경우 1개만 출력한다)
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 50

int check_num(int *num, int k, int a)
{
	int i = 0;
	for (i = 0; i < a; i++)
	{
		if (num[i] == k)
		{
			return 0;
		}
	}
	return 1;
}
void sort_num(int *num, int a)
{
	int tmp = 0;
	int i = 0, j = 0;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a; j++)
		{
			if ( num[i] < num[j] )
			{
				tmp = num[i];
				num [i] = num[j];
				num [j] = tmp;
			}
		}
	}
}
int main()
{
	char str[SIZE];
	int num[SIZE] = {0};
	int i = 0,j = 0,k = 0, a = 0, tmp = 0;	
	fgets(str,sizeof(str),stdin);
	
	for ( i = 0; str[i] != '\0'; i++)
	{	
		if(isdigit(str[i]))
		{
				tmp =((str[i - 1] -'0') * 10) + (str[i] - '0');
		}	
		else
            	{
            		if(tmp != 0)
	            	{
        	    		if(check_num(num,tmp,a) > 0)
            			{
	            			num[a] = tmp;
            				++a;
        	    		}
            			tmp = 0;
	            	}
        	}
	}
	sort_num(num,a);
	printf("output:");
	for( k = 0; k < a; k++)
	{
		printf(" %d",num[k]);
	}

	return 0;	
}
