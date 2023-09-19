#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int num_list[100] = {0,};
	int i= 1;
	int count = 0;
	
	while(num_list[1] != '\n')
	{
		scanf("%d", &num_list[i]);	// 3 5 6 // num_list[0] =3 
		printf("#%c\n", num_list[i]);
		count++;
		i++;
	}

	printf("%d", count / 2);			// 1 2 3 4 5 6  == print 6
	
	printf("%d", num_list[1]);


}
