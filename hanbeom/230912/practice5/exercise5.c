#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int k = 0;
    int i, j;
    int manyarray[100];
    int nomanyarray[100];
    int num[100];
    int n;

    printf("input N: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)            
        {
            if (num[i] == num[j])             
            {
                manyarray[k] = num[j];      
                k++;
            }
        }
    }

    int countnum = 0;
    for (i = 0; i < k; i++)
    {

    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < 100; j++)            
        {
            if (manyarray[i] == manyarray[j])             
            {                                                                       
                manyarray[j] = 0;            
            }
        }
    }
    for (i = 0; i < k; i++)
    {
      
    }
  
    int size = sizeof(manyarray) / sizeof(manyarray[0]);      

    int newArr[100];
    int newSize = 0; 

    for (int i = 0; i < k; i++) {                 
        if (manyarray[i] != 0)
        {
            newArr[newSize] = manyarray[i];    
            newSize++;
        }
    }
    printf("k is %d", k);

    for (i = 0; i < k; i++)             
    {
       printf("%d ", newArr[i]);            
    }

    int min = newArr[0];
    int index = 0;
    int newArr2[100];

    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            if (newArr[j] < min)
            {
                min = newArr[j];
                index = j;
            }
        }
        newArr2[i] = min;
        newArr[index] = 999;
        min = 1000;         
    }

    for (i = 0; i < 100; i++)
    {

    }
}




 