#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char arr[100] = { 0 };
    int length = 0;
    int numbers[100] = { 0 };
    int count = 0;
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
            if (arr[i + 1] >= '0' && arr[i + 1] <= '9')
            {
                while (arr[i] >= '0' && arr[i] <= '9')
                {
                    num_arr[num_idx++] = arr[i++];
		    if (arr[i] > '9' && '0' > arr[i])
			break;
                }

                num = atof(num_arr);
                numbers[p++] = num;
		arr[i+1] = 'a';
            }
            else
            {
                numbers[p++] = arr[i] - '0';
		count = 0;
            }

	    for (j = 0; j < i; j++)
            {
                if (numbers[j] == num)
                {
                    count = 1;
                    break;
                }
            }

            if (count != 1)
            {
		numbers[j++] = num;
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



/*
int main()
{
    char arr[50] = {0};
    int length = 0;
    char new_arr[50] = {0};
    int i = 0; 
    int j = 0;
    int a = 0;
    int p = 0;
    char num_arr[5] = {0};
    int num = 0;
    int count = 0;
    int min_num = 0;
    int x = 0;
    int h = 0;

    printf("input:");
    fgets(arr, sizeof(arr),stdin);
    length = strlen(arr);

    printf("output: ");

    
    for (i = 0; i < length; i++)
    {
	    if (arr[i] >= '0' && arr[i] <= '9')
         {
             p = i;
             for(a = i + 1; a < length; a++)
             {
                 if(arr[a] >= '0' && arr[a] <= '9')
                 {
                     p++;
                 }
                 else
                 break;
             }

             if(p == i)
             {
                 num_arr[h] = arr[i];
                 count = 0;
             }
             else
             {
                 for(j = 0; j <= p; j++)
                 {
                     num_arr[h] = arr[j];
                     h++;
                     count = 1;
                 }
             }

             for( j = 0; j < h; j++)
             {
                 printf("%c", num_arr[j]);
             }
             printf("\n");

          }
          num_arr[0] = 'z';
          h=0;
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
}*/
