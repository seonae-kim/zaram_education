#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void *print_lott(void*);
void *get_str(void*);

int main(void)
{
    pthread_t p_thread[2]; // 스레드 식별자
    int thr_id;
    char *string = NULL;

    thr_id = pthread_create(&p_thread[0], NULL, get_str, (void*)&string);
 	if (thr_id < 0)
    	{
    	    perror("get_str 스레드 생성 실패\n");
        	exit(0);
		}
 	   
    while (1)
    {
        print_lott(NULL);
        sleep(3);

        if (string != NULL && strcmp(string, "q") == 0)
        {
            free(string);
            break;
        }
    }

    return 0;
}

void *print_lott(void *data)
{
    int i, j, o;
    int a = 0;
    int random[5][5];
    int tmp[50];
    int fail_flag = 0;

    srand(time(NULL));

    for (i = 0; i < 5; i++)
    {
        a = 0;
        memset(tmp, '\0', sizeof(tmp));

        for (j = 0; j < 5; j++)
        {

            random[i][j] = rand() % 45 + 1;
            tmp[a] = random[i][j];
            for (o = 0; o < a; o++)
            {
                if (a == 0)
                {
                    break;
                }
                if (tmp[o] == tmp[a])
                {
                    fail_flag = 1;
                    break;
                }
            }
            if (fail_flag == 1)
            {
                --j;
                srand(time(NULL));
                fail_flag = 0;
            }
            else
            {
                ++a;
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", random[i][j]);
        }
        printf("\n");
    }
}

void *get_str(void *data)
{
    char str[1000];

    while (1)
    {
        fgets(str, sizeof(str), stdin);

        str[strcspn(str, "\n")] = '\0'; // "\n의 str에서의 위치 -> '\0'으로 교체

        char *string = (char *)malloc(strlen(str) + 1); // '\0'까지 공간+1
        strcpy(string, str);

        if (data != NULL)
        {
            free(*(char **)data);
        }
		printf("%s\n",string);
        *(char **)data = string;
    }
}

