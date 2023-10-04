#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void *p_function()
{
	int i = 0, j = 0;
	int num[6] = {0};

	srand(time(NULL));
	while(1)
	{
		for(i = 0; i < 6; i++)
		{   
			num[i] = (rand() % 45) + 1;

			for(j = 0; j < i; j++)
			{
				if( num[i] == num[j] )
				{
					i = i - 1; 
					break;
				}
			}
		}   

		for( i = 0; i < 6; i++)
		{
			printf( "%3d ", num[i]);
		}

		printf("\n");
		sleep(3);
	}
}


int main(void)
{
	pthread_t pthread1;
	int thr_id;
	char input[20] = {0};

	thr_id = pthread_create(&pthread1, NULL, p_function, NULL);

	while(1)
	{
		scanf("%s", input);

		if( strstr(input , "q") != 0 )
		{
			pthread_detach(pthread1);
			break;
		}

		printf("%s\n", input);
		if(thr_id != 0)
		{
			printf("pthread create error\n"); 
		}

	}
	return 0;
}

