#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main()
{

    char word[500][500];
    int i = 0;


    char str[500];
    printf("input sentence\n");

    fgets(str, sizeof(str), stdin);	// i can you com pro

    char* ptr = strtok(str, " ");
    while (ptr != NULL)
    {
        strcpy(word[i], ptr);

        printf("strings is %s\n", ptr);	// ptr = i >> can >> you >> com >> pro (중요) //strtok함수때문에 pro뒤에 개행문자있어서 pro 출력시 한줄더뜀
        printf("word is %s\n", word[i]); //word[0] =i, word[1]= can, word[2] = you ... (중요)
        ptr = strtok(NULL, " ");

        i++;
    }


    int strlengroup[5];


    for (i = 0; i < 5; i++)
    {
        if (i == 4)
        {
            strlengroup[i] = strlen(word[i]) - 1;   //word[i] 마지막은 \n떄문에 하나뺴줘야함
        }
        else
        {
            strlengroup[i] = strlen(word[i]);
        }
        //printf("%ld", strlengroup[i]);      //OK       
    }

    int min = strlengroup[0];
    int miniindex = 0;
    int indexgroup[5] = { 0, };
    int j;

    // find min
    /*
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < i; j++)             // 0 0          0 1   0 2 1 2     0 3 1 3 2 3  0 4 1 4 2 4 3 4
        {
            if (strlengroup[j] <= min)          // 2 4 1 5 3       // 2 4 100000 5 3      
            {                                  // 1 2 3 4 5
                min = strlengroup[j];
                strlengroup[j] = 100000;
            }
        }                                          //j=0/ j=0 j=1/ j=0 j=1 j=2/ j=0 j=1 j=2 j=3/ j=0 j=1 j=2 j=3 j=4
        printf("%d ", min);             //2 3 1 3 1       
        strlengroup2[i] = min;
        min = 100000;
    }
    */
    ////

    for (int i = 0; i < 5 - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < 5; j++) 
        {           
            if (strlengroup[j] < strlengroup[minIndex]) {       //
                minIndex = j;
            }
        }
        // 최솟값을 현재 위치로 이동
        int temp = strlengroup[i];          
        strlengroup[i] = strlengroup[minIndex];
        indexgroup[i] = minIndex;  //내가넣은거
        strlengroup[minIndex] = temp;
    }

    printf("\n오름차순 정렬된 배열: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", strlengroup[i]);
    }

    printf("\n인덱스: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", indexgroup[i]);
    }

}

