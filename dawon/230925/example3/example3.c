#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n=0, i=0, j=0, h=0, index = 0,flag_1 = 0,flag_2 = 0,num=0, h=0, index1=0, index2=0;
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


	for(i = 0; i < num; i++)
	{
		for(j = 0; j < num; j++)
		{
			for(h = 0; h < num; h++)
			{
				if(arr[i][j] != arr[i][h])
				{
					for(int k = h; k < strlen(arr[i]); k++)
					{
						if(arr[i][j] == arr[j][k])
						{
							flag = 1;
							break;
						}
					}
				}
				if(flag == 1)
					break;			
			}

			if(flag == 1)
				break;	

			n++;
		}
	}
		
		
								
	return 0;
}


	


