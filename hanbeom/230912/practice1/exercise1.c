#include <stdio.h>
#include <string.h>


int main()
{

    char word[500][500];
    int i = 0;
    

    char str[500];

    printf("input sentence\n");
    
    fgets(str, sizeof(str), stdin);	// i can you com pro
    
    char *ptr = strtok(str, " ");
    while (ptr != NULL)
    {	
	strcpy(word[i], ptr);
	ptr = strtok(NULL, " ");
	printf("strings is %s\n", word[i]);	// i can you com pro  
	i++;
    }
    for(i = 0 ; i < 5; i++)
    {   
	if( i ==4)
	{
	    printf("%ld", strlen(word[i]) -1);
	}
	else
	{
	    printf("%ld", strlen(word[i]));	    // 1 3 3 3 3
	}
    }    
    
    int min = strlen(word[0]);

    /*  find min
    for( i = 0 ; i < 5; i++)
    {
	if(strlen(word[i] >= min)
	{
	    min = strlen(word[i]);
	    // 
	}
	
    }
    */
    //printf("%s ", word[i]);
}

