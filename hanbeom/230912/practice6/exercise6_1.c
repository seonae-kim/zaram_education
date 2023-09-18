#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

	char all[50][50] = { 0, };
	char str[50];
	int num[50] = { 0, };
	int i;
	int k = 0;

	fgets(str, sizeof(str), stdin);

	for (i = 0; i < strlen(str) - 1; i++)
	{
		if (str[i] >= '0' && str[i] <= '9' && str[i + 1] >= '0' && str[i + 1] <= '9')  
		{
			int p = 0;
			while (str[i + p] >= '0' && str[i + p] <= '9')
			{
				all[k][p] = str[i + p];    
				p++;	          	          
			}
			all[k][p] = '\0';         
			k++;
			i++;
		}

		else if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] < '0' || str[i + 1] >'9'))
		{
			all[k][0] = str[i]; 					
			all[k][1] = '\0';
			k++;
		}
	}


	for (i = 0; i < 50; i++)
	{
		if (i < k)
		{
			num[i] = atoi(all[i]);
		}
		else
		{
			num[i] = -999;
		}
	}

	int o;
	int newnum[50];
	int kk = 0;
	int count = 0;

	for (i = 0; i < k; i++)
	{
		for (o = i+ 1; o < k; o++)
		{
			if (num[i] == num[o])
			{
				count++;				
			}
		}
		if (count == 0)
		{
			newnum[kk] = num[i];
			kk++;
		}
		count = 0;		
	}	

	int min = newnum[0];
	int mininum[50] = { 0, };
	int index = 0; 
	int j;

	for (j = 0; j < kk; j++)
	{
		for (i = 0; i < kk; i++)
		{
			if (min > newnum[i])
			{
				min = newnum[i];	
				index = i;
			}
		}
		mininum[j] = min;			
		newnum[index] = 9999;
		min = 9999;
	}

	
	for (i = 0; i < kk; i++)		
	{
		printf("%d ", mininum[i]);
	}

}


	



