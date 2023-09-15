#include <stdio.h>
#include "mode1.h"
#include "mode4.h"
#include "mode5.h"
#include "mode6.h"
#include "mode7.h"

int main()
{
	int mode = 0;
	int e = 0;

	while(1)
	{
		if(e == 1)
			break;

		printf("\n # MEMBERSHIP PROGRAM #\n Select Mode\n 1-Registration\n 2-Extension of the period\n 3-Transfer of membership\n 4-Delete membership\n 5-Search membership \n 6-View all information \n 7-Update all membership \n 8-exit\n");

		scanf("%d", &mode);


		switch(mode)
		{
			case 1:
				mode1(1);
				break;
		
			case 2:
				break;

			case 3:
		        break;
	
			case 4:
				mode4(1);
				break;

			case 5:
				mode5(1);
				break;

			case 6:
				mode6(1);
				break;

			case 7:
				mode7(1);
				break;

			case 8:
				printf(" FINISH\n");
				e++;
				break;	

			default :
				e++;
				break;
		}

	}


	return 0;
}
