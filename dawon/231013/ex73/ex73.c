#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n = 0, p = 1, i = 0;
	int slicer[3] = {1, 5, 2};
	int numlist[9];

	for(i = 0; i < 9; i++)
	{
		numlist[i] = p++;
	}

	printf("n: ");
	scanf("%d",&n);

		switch (n){
			
			case 1:
				{
					for(i = 0; i <= 5; i++)
					{
						printf("%d ",numlist[i]);
					}
					break;
				}

			case 2:
				{
					for(i = 1; i <= 9; i++)
					{
						printf("%d ",numlist[i]);
					}
					break;
				}

			case 3:
				{
					for(i = 1; i <= 5; i++)
					{
						printf("%d ",numlist[i]);
					}
					break;
				}

			case 4:
				{
					for(i = 1; i <= 5; i += 2)
					{
						printf("%d ",numlist[i]);
					}
					break;
				}
		
			}
		printf("\n");
		return 0;

}


