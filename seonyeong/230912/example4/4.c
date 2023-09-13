#include <stdio.h>


int main()
{
    int N = 0;
    int arr[50] = {0};
    int i = 0, j = 0;
    int count[50] = { 0 };
    int max_count = 0;
    int max_num = -1;

    printf("size : ");
    scanf("%d", &N);

    printf("num: ");
    
    for (i = 0; i < N; i++)
    {
	scanf("%d", &arr[i]); 
    }

     for ( i = 0; i < N; i++)
    {
        count[arr[i]]++;
	if (count[arr[i]] > max_count)
        {
            max_count = count[arr[i]];
            max_num = arr[i];
        }
        else if (count[arr[i]] == max_count && arr[i] != max_num)
        {           
            max_num = -1;
        }
    }
    
     printf("output : %d\n", max_num);
}
