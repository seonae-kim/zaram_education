#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void *p_function()
{
	int i = 0, j = 0;
	int num[6] = {0};

	srand(time(NULL));

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

	for(i = 0; i < 6; i++)
	{
		printf( "%3d ", num[i]);
	}
	printf("\n");

}


int main(void)
{
	pthread_t pthread[5];
	int thr_id;
	int i;

	for(i = 0; i < 5; i++)
	{
		thr_id = pthread_create(&pthread[i], NULL, p_function, NULL);
		sleep(1);

		if(thr_id != 0)
		{
			printf("pthread[%d] create error\n", i);
		}
	}

	for(i = 0; i < 5; i++)
	{
		pthread_detach(pthread[i]);
	}

	return 0;

}
