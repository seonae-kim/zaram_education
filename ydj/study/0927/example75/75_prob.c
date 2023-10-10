#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num = 0;
    int i = 0, j = 0, temp_m = 0, temp_a = 0;
    int n = 0;
    int min = 0;
    printf("Please enter the # of element : ");
    scanf("%d", &num);

    int arr[num];
    int minus[num];
    printf("Please enter the numlist : ");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Please enter the number n : ");
    scanf("%d", &n);

    for (i = 0; i < num; i++)
    {
        minus[i] = abs(n - arr[i]);
    }

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (minus[i] > minus[j])
            {
                temp_m = minus[i];
                minus[i] = minus[j];
                minus[j] = temp_m;

                temp_a = arr[i];
                arr[i] = arr[j];
                arr[j] = temp_a; 
            }
        }
    }

    min = minus[0];

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (minus[i] == minus[j])
            {
                if (arr[i] < arr[j])
                {
                    temp_a = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp_a; 
                }
            }
        }
    }

    for (i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}