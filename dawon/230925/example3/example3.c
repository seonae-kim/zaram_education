#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n=0, i=0, j=0,index = 0,flag = 0,num=0, h=0;
	char a[20] = {0, };
	char arr[10][10] = {0, };
	char d;

	printf("num: ");
	scanf("%d", &n);
	printf("array: ");
	
		
	for(i = 0; i < n; i++)
	{
		scanf("%s",arr[i]);
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < strlen(arr[i]); j++)
		{
			if(arr[i][j] == arr[i][j+1])
			{
				for(h = 0; h < j; h++)
				{
					if(arr[i][h] == arr[i][j])
					{
						flag = 1;
						break;
					}
				}
				for(h = j+2; h < strlen(arr[i]); h++)
				{	
					if(arr[i][h] == arr[i][j])
					{
						flag = 1;
						break;
					}
				}

			}

			if(flag == 1)
				break;
		}
		if(flag == 0)
		{
			num++;
		}
		flag = 0;
	}	

	printf("output: %d\n",num);
			
	return 0;
}


	


