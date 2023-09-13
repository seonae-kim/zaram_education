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
        for (j = i + 1; j < n; j++)            //    j= 1 > 2 > 3 > 4 > ..9    j=2 > 3 > ....9     
        {
            if (num[i] == num[j])             //[0] == [1] [2] [3] ...        [1] = [2] [3] [4] ... [9]
            {
                manyarray[k] = num[j];      //print 1             같은 원소 찾는거  
                k++;
            }
        }
    }

    int countnum = 0;

    for (i = 0; i < k; i++)
    {
      // printf("%d ", manyarray[i]);             //ok
    }
    //printf("countnum is %d", countnum);
    //printf("k is %d", k);         //k= 14 나옴


    //k = 0; //reset
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < 100; j++)            //    j= 1 > 2 > 3 > 4 > ..9    j=2 > 3 > ....9     
        {
            if (manyarray[i] == manyarray[j])             //[0] == [1] [2] [3] ...        [1] = [2] [3] [4] ... [9]
            {                                                                       //같은 원소들을 0으로 만듦
                manyarray[j] = 0;            
            }
        }

    }

    for (i = 0; i < k; i++)
    {
       // printf("%d ", manyarray[i]);             //ok       //5
    }
    //printf("k is %d", k);

    int size = sizeof(manyarray) / sizeof(manyarray[0]);       //배열 크기계산       == size = 100

   // printf("size is %d", size);


    int newArr[100];
    int newSize = 0; // 새로운 배열의 크기를 나타내는 변수

    for (int i = 0; i < k; i++) {                   // i< ?? 구해야함           k=14
        if (manyarray[i] != 0)
        {
            newArr[newSize] = manyarray[i];    //newArr[0] =2 ...  [1] [2]  3개만 생겨야함. 
            newSize++;
        }
    }
    printf("k is %d", k);

    for (i = 0; i < k; i++)             
    {
       printf("%d ", newArr[i]);             //ok    {2, 1, 3} 만 남음 근데 뒤에꺼 제거해야함     
    }

    int min = newArr[0];
    int index = 0;
    int newArr2[100];

    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            if (newArr[j] < min)        // 
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
     //printf("%d ", newArr2[i]);             //ok    {쓰레기값 .. . .. . . ..  1 2 3} 남음
    }

}
/*
  //For루프한번더해야할듯
  {
     For(p = 0; p < k; p++)
     {
         If(nexarr에 같은원소없으면)
              Nexarr[k] = num[i] //같은원소 새 배열에 담기
          else //Nexarr에 같은원소있으면
              아무것도안함
      }
   }
      indexarr[k] = j //같은원소인덱스 저장
      K++
    }

}
num[in

// For루프로 한줄돌려서(원소 0일때는 제외)
같은원소로 된거 0으로 만든다(인덱스저장)

 따로담은거 오름차순정렬함

*/



 