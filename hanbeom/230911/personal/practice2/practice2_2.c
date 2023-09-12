#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    char str[500];
    int i =0;
    double num[2] = {0, 0};
    
    printf("input number and op ex(43 + 27): ");
    fgets(str, sizeof(str), stdin);	//input the chracter. ex) 4 + 3
    
    char *token = strtok(str, "+");  // blank	    43 + 27
    while (token != NULL)
    {
	num[i] = atof(token);
	printf("%lf\n", num[i]);
	token = strtok(NULL, "+");
        i++;	
    }

    printf("%lf", num[0] + num[1]);    
    //printf("%f", num2);
    
    /*
    while (token != NULL)	    // address = null = 0 
    {
	if
    */
    
    /*
    for(i =0; i < len; i++)	// + 
    {
	str =  	
    }
    */
   // printf("%s", str);		

   // printf("%d", (int)num1);	    //front number
    

       

   // for(i = 0; str[i];		    //  43 + 54
    
/*
    for(i = 0; i < len; i++)	// if find '+', define operator = '+'
    {
        switch(str[i])
	{
	    case '+' :
	    operator = '+';		 
	    break;   
		
	    case '-' :
	    operator = '-';
	    break;

	    case '*' :
	    operator = '*';
	    break;
	
	    case '/' :
	    operator = '/';
	    break;  
	}
    }
    
    switch(operator)
    {
        case '+' :
	    result = sum(str);
	    break;
	case '-' :
	    result = minus(str);
	    break;
	case '*' :
	    result = multiple(str);
	    break;
	case '/' :
	    result = divide(str);
	    break;    
    }
*/

   // printf("%d\n",result);
}
