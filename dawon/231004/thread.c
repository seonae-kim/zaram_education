#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void *rannum();

void *rannum()
{
	int random[5] = {0, };
	int i = 0, j = 0, m=0,flag =0;
	pthread_t tid;
	
	srand(time(NULL));
	
	while(1)
	{
		for(m = 0; m < 5; m++)
		{
			for(i = 0; i < 5; i++)
			{
				random[i] = rand() % 45 + 1;
				for(j = 0; j < i; j++)
				{
					if(random[i] == random[j])
					{
						i--;
						break;
					}
				}
			}

			for(i = 0; i < 5; i++)
			{
				printf("%d ",random[i]);
			}

			
			printf("\n");
		}

		sleep(3);
	}

}

int main()
{
	pthread_t tid;
	int t,i;
	char a;
	void **re;
	t=pthread_create(&tid,NULL,rannum,NULL);

	
	scanf(" %c",&a);

	while(1)
	{	

		if(a != 'q')
		{
			printf("input : %c\n",a);
			printf("output: %c\n",a);
		}
		if(a == 'q')
			break;
		scanf(" %c",&a);

			
	}

	return 0;
}



