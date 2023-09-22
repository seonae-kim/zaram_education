#include <stdio.h>
#include <string.h>

int main()
{
	char str[50]= {0,};
	int count = 0;
	int i, j;
	int countarr[50] = {0,};
	int indexarr[50] = {0,};
	char chararr[50] = {0,};
	fgets(str,sizeof(str),stdin);

	size_t len = strlen(str) - 1;

	for(i = 0; i < len; i++)
	{
		for(j =0; j < len; j++)
		{
			if(str[i] == str[j])
			{
				count++;
			}
		}
		countarr[i] = count;
		count =0;
	}
	int k=0;
	for(i = 0; i <len; i++)
	{
		if( countarr[i] == 1)
		{
			chararr[k] = str[i];
			k++;
		}
	}
	
	for(i =0; i <k -1; i++)
	{
		int min = chararr[i];
		int min_index = i;

		for(j = i+1; j < k; j++)
		{
			if (min > chararr[j])
			{
				min = chararr[j];
				min_index = j;
			}
		}
		chararr[min_index] = chararr[i];
		chararr[i] = min;
	}

	for (i =0; i < k; i++)
	{
		printf("%c", chararr[i]);
	}

}

