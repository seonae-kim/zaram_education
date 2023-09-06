#include <stdio.h>

int main() 
{
    char arr[100];
    int p = 0;    
    int i;
    

    printf("input: ");
    scanf("%s", arr);

    for (i = 0; arr[i]; i++) 
    {
        if (arr[i] == '(')
        {
            p++;
        }

        else if (arr[i] == ')')
        {
            p--;
        }
         
    	if (p < 0)
	{
		printf("no\n");
		break;	
	}
    }   

    if (p == 0 && arr[0] == '(')
    {
        printf("ok\n");
    }

    else printf("no\n");

	
 return 0;
}

