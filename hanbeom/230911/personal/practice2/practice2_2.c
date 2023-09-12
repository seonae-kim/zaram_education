#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    char str[500];
    int i =0;
    char num[6] = {0,};
    
    printf("input number and op ex(43 + 27): ");
    fgets(str, sizeof(str), stdin);	//input the chracter. ex) 4 + 3
    
    char *token = strtok(str, " ");  // blank	    43 + 27
    while (token != NULL)
    {
	num[i] = atof(token);		    //  
	
	token = strtok(NULL, " ");
	i++;
	/*
	if(num[1] == '+')
	{
	    //num[1] = token[0];
	    token = strtok(NULL, " ");
	    i++;
	}

	else
	{
	    token = strtok(NULL, " ");
	    i++;
	}
	*/
    }
      printf("%d ", num[0]);		// -27
      printf("%c ", num[1]);		// blank
      printf("%d ", num[2]);		// -43
}

