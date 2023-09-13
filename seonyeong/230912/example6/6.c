#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char arr[50] = {0};
    int length = 0;
    char new_arr[50] = {0};
    int i = 0; 
    int j = 0;
    char num_arr[5] = {0};
    int num = 0;
    int count = 0;
    int min_num = 0;
    int x = 0;

    printf("input:");
    fgets(arr, sizeof(arr),stdin);
    length = strlen(arr);

    printf("output: ");

    
    for (i = 0; i < length; i++)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
	    if(arr[i+1] >= '0' && arr[i+1] <= '9')
	    {
		if(arr[i+2] >= '0' && arr[i+2] <= '9')
		{
		    num_arr[0] = arr[i];
                    num_arr[1] = arr[i+1];
		    num_arr[2] = arr[i+2];
	            num = atof(num_arr);
	            arr[i+1] = 'a';
		    arr[i+2] = 'a';

		}
		else
		{
		    num_arr[0] = arr[i];
		    num_arr[1] = arr[i+1];
		    num = atof(num_arr);
		    arr[i+1] = 'a';
		}
	    }

	    else
	    {
		num = arr[i] - '0';
	    }
            count = 0;
                        
	    for (j = 0; j < i; j++)
            {
                if (new_arr[j] == num)
                {
                    count = 1;
                    break;
                }
            }

            if (count != 1)
            {
		new_arr[j++] = num;
            }
        }
     }

	for (i = 0; i < length ; i++)
	{
	    min_num = i;

	    for ( j = i + 1; j < length; j++)
	    {
		 if (new_arr[j] < new_arr[min_num])
		{
		     min_num= j;
		}
	    }

	    x = new_arr[i];
	    new_arr[i]= new_arr[min_num];
	    new_arr[min_num]= x;
	}

	for(i= 0; i< length ;i++)
	{
	    if( new_arr[i] != 0)
	    {
		printf("%d ",new_arr[i]);
	    }
	}
    
    printf("\n");
    return 0; 
}
