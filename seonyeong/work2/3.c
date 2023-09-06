#include <stdio.h>

int main() {
    char arr[100];
    int p = 0;
    int q = 0;
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
            q++;
        }
       
    }
    
    if (p == q)
    {    
        if ((arr[0]=='(') && (arr[p+q-1] == ')'))
        {            
            printf("ok\n");
        }

	else printf("no\n");	
    }	
    
    else
    {
        printf("no\n");
    }


 return 0;
}

