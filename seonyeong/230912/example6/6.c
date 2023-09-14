#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char arr[100] = { 0 };
    int length = 0;
    int numbers[100] = { 0 };
    char num_arr[10] = { 0 };
    int num_idx = 0;
    int min_idx = 0;
    int num = 0;
    int i = 0;
    int j = 0;
    int x = 0;
    int p = 0;

    printf("input: ");
    fgets(arr, sizeof(arr), stdin);
    length = strlen(arr);
    printf("output: ");

    for (i = 0; i < length; i++)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
			num_idx = 0;
            char num_arr[10] = { 0 };
			if (arr[i + 1] >= '0' && arr[i + 1] <= '9')
            {
                while (arr[i] >= '0' && arr[i] <= '9')
                {
                    num_arr[num_idx++] = arr[i++];
					if (arr[i+1] > '9' && '0' > arr[i+1])
					break;
                }

                num = atof(num_arr);
                numbers[p++] = num;
			}
            else
            {
                numbers[p++] = arr[i] - '0';
				arr[i] = 'z';
            }
		}
	}
			
	for(i =0; i < length; i++)
	{
		for (j = 0; j < i; j++)
        {
            if (numbers[j] == numbers[i])
            {
				numbers[j] = '\0';
                break;
            }
        }
	}   
    
	for (i = 0; i < p - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < p; j++)
        {
            if (numbers[j] < numbers[min_idx])
            {
                min_idx = j;
            }
        }

         x  = numbers[i];
        numbers[i] = numbers[min_idx];
        numbers[min_idx] = x;
    }


    for (i = 0; i < p; i++)
    {
	if(numbers[i] != 0)
	{
	    printf("%d ", numbers[i]);
	}
    }

    printf("\n");

        return 0;

}
