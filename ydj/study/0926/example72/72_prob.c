#include<stdio.h>
#include<string.h>

int main()
{
    int num = 0;
    int i = 0, j = 0;
    int flag = 1;
    int max = 0;
    printf("Please enter the # of element : ");
    scanf("%d", &num);

    char str[num];
    int arr[num];
    for (int i = 0; i < num; i++) 
    {
        scanf("%s", str);
        arr[i] = strlen(str);
    }

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            if(arr[i] == arr[j])
            {
                flag++;
            }
        }
        if (max < flag)
        {
            max = flag;
        }
        flag = 1;
    }

    if (max != 1)
    {
        max = max - 1;
    }

    printf("%d\n", max);
    return 0;
}