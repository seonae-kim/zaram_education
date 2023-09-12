#include <stdio.h>
#include <string.h>

int sum(char ch[])
{
    int answer = 0;
    int len = strlen(ch);
    int i;
    for(i = 0; i < len; i++)
    {
        if(ch[i] > '0' && ch[i] < '9')
		answer += (ch[i] - 48);	//real number
    }
    return answer;
}

int minus(char ch[])
{
    int answer = 0;
    int len = strlen(ch);
    int i;
    for(i = 0; i < len; i++)
    {
	if(ch[i] > '0' && ch[i] < '9')
	{	
	    if(answer == 0)
		answer = (ch[i] - 48);    	
	    else
		answer -= (ch[i] - 48);
	}

     }
    return answer;
}

int multiple(char ch[])
{
    int answer = 0;
    int len = strlen(ch);
    int i;
    for(i = 0; i < len; i++)
    {
        if(ch[i] > '0' && ch[i] < '9')
	{
	   if(answer == 0)
	       answer = (ch[i] - 48);
           else
	       answer *= (ch[i] - 48);
	}
    }
    return answer;
}

int divide(char ch[])
{
    int answer = 0;
    int len = strlen(ch);
    int i;

    for(i = 0; i < len; i++)
    {
	if(ch[i] > '0' && ch[i] < '9')
        {
           if(answer == 0)
               answer = (ch[i] - 48);
           else
               answer /= (ch[i] - 48);
        }
    }
    return answer;
}

int main()
{
    char str[500];
    char operator = 'a';
    int result = 0;
    int i;
    
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);

    for(i = 0; i < len; i++)
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
    printf("%d\n",result);
}
