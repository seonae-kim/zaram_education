#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cal.h"
#include "mode1.h"
#include "mode2.h"
#include "mode3.h"


int main()
{
    char mode = 0;
    int e = 0;
    char ch = 0;

    while(1)
    {
	if(e == 1)
        break;
	printf("Select mode 1-normal or 2-Hex or 3-Dec: ");
	scanf("%c", &mode);
	while (ch = getchar() != '\n' && ch != EOF);
       	
	switch (mode)
	{ 
	    case '1':
	    printf("normal mode\n");
	    mode1(1);
	    break;

	    case '2':
	    printf("Hex mode\n");
	    mode2(1);    
	    break;

	    case '3':
	    printf("Dec mode\n");
	    mode3(1);
	    break;

	    case 'q' :
	    printf("end\n");
	    e++;
	    break;
    	}
    }
    return 0;	
}
