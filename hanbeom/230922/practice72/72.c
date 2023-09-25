#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void main()
{
	char strArr[6][50] = { "a", "bc", "d", "efg", "hi" };
	
	size_t numRows = sizeof(strArr) / sizeof(strArr[0]);	

	int len = 1;
	int lenarr[50] = { 0, };
	int i, j;
	
	for (i = 0; i < numRows -1 ; i++)
	{
		for (j = 0; j < strlen(strArr[i]) - 1; j++)
		{
			if (strArr[i][j] != NULL)
			{
				len++;
			}
			else if (strArr[i][j] == NULL)
			{
				break;
			}
		}
		lenarr[i] = len;
		len = 1;
	}
	
	int sizearr[50] = { 0, };
	int sizecount = 0;

	for (i = 0; i < numRows - 1; i++)
	{
		for (j = 0; j < numRows - 1; j++)
		{
			if (lenarr[i] == lenarr[j])
			{
				sizecount++;
			}
		}
		sizearr[i] = sizecount;
		sizecount = 0;
	}
	
	for (i = 0; i < numRows - 1; i++)
	{
		int max = sizearr[i];
		int max_index = i;

		for (j = i + 1; j < numRows; j++)
		{
			if (max < sizearr[j])
			{
				max = sizearr[j];
				max_index = j;
			}
		}
		sizearr[max_index] = sizearr[i];
		sizearr[i] = max;
	}

	printf("%d", sizearr[0]);
}





