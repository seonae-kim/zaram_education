#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int hp = 0, a, b, c;
	int min = 100, sum = 0;

	printf("hp: ");
	scanf("%d",&hp);
	
	for(a = 0; a < 300; a++)
	{
		for(b = 0; b < 300; b++)
		{
			for(c = 0; c < 300; c++)
			{
				if(5 * a + 3 * b + c == hp)
				{
					sum = a + b + c;
					if(sum < min)
						min = sum;
				}
			}
		}
	}

	printf("result: %d\n",sum);

	return 0;

}

	
