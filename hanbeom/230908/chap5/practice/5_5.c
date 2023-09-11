#include <stdio.h>

int main()
{
    int month = 0;
    int day = 0;  
    
    scanf("%d", &month);  
    switch(month)
    {
	    case 1 :
		day = 31;
		break;
	    case 2 :
		day = 29;
                break;
	    case 3 :
		day = 31;
               break;		
	    case 4 :
		day = 30;
               break;
	    case 5 :
		day = 31;
               break;
            case 6 :
                day = 30;
               break;
            case 7 :
                day = 31;
               break;
            case 8 :
                day = 30;
               break;
            case 9 :
                day = 31;
               break;
            case 10 :
                day = 30;
               break;
            case 11 :
                day = 31;
               break;
	    case 12 :
                day = 30;
               break;
    }
    printf("%d", &day);
}
