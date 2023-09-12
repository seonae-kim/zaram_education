#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


float add(float a, float b)
{
    float c = a + b;
    return c;
}

float sub(float a, float b)
{
    float c = a - b;
    return c;
}

float mul(float a, float b)
{
    float c = a * b;
    return c;
}

float divide(float a, float b)
{
    float c = a / b;
    return c;
}

int main()
{
    int i = 0, j = 0;
    char cal[20] = {0};
    char num1[20] = {0};
    char num2[20] = {0};
    char op ;
    float result = 0;
    int count = 0, p = 0;
    float cal_num1 = 0, cal_num2 = 0;
    int length = 0;
    char mode = 0;
    int e = 0;
    char ch;

    while(1)
    {
	if(e == 1)
        break;
	printf("Select mode 1-normal or 2-Hex or 3-Dec: ");
	scanf("%c", &mode);
	while (ch = getchar() != '\n' && ch != EOF);
       	
	switch (mode)
	{ 
	    case '1'://normal
	    printf("normal mode\n");
	   
	    while(1)
	    {

		char cal[20] = {0};
		char num1[20] = {0};
		char num2[20] = {0};
		printf("input expression: " );
		fgets(cal, sizeof(cal), stdin);
		length = strlen(cal);
		 
		cal_num1 = 0;
		cal_num2 = 0;	
		count = 0;
		int p = 0;
		float result = 0;
		char op = '0';
		
		for(i = 0; i < 20; i ++)
		{
		    if((cal[i] == 'q')&&(length == 2))
		    {	
			p++;
			printf("end\n");			
		    }	      
		}

		if(p == 1)
		 break;	
	    
		for(i = 0; i < 20; i++)
		{
		    if(cal[i] == ' ')
		    {
			count++;
		
			if(count < 2)
			{
			    for(j = 0; j < i; j++)
			    {
				num1[j] = cal[j];
				cal_num1 = atof(num1);
			    }
			}
		
			if(count == 2)
			{
			    for(j = i + 1 ; j < length - 1 ; j++)
			    {			
				num2[j - (i + 1)] = cal[j];
				cal_num2 = atof(num2);
			    }
			}
		    }    
			if(((cal[i] == '+')||(cal[i] == '-')||(cal[i] == '*')||(cal[i] == '/'))&&(count == 1))
			    {	
				op = cal[i];		
			    }
		}
    
		if(((cal_num1 < -100000) || (cal_num1 > 100000)) || ((cal_num2 < -100000) || (cal_num2 > 100000)))
		{
		    printf("wrong numbers\n");
		    continue;	   
		}
		
		if(op == ( '+' ))
		{
		    float result = add(cal_num1, cal_num2);
	
		    if( add(cal_num1, cal_num2) == (int)result)
		    {
			printf("result : %d\n", (int)result);
		    }
		    else
		    {
			printf("result : %.3f\n", result);
		    }
		}	 

		else if(op == ( '-' ))
		{
		    float result = sub(cal_num1, cal_num2);
		    if( sub(cal_num1, cal_num2) == (int)result)
		    {
			printf("result : %d\n", (int)result);
		    }
		 else
		    {
			printf("result : %.3f\n", result);
		    }
	    	    	    
		}	 

		else if(op == ( '*' ))
		{
		    float result = mul(cal_num1, cal_num2);
		    if( mul(cal_num1, cal_num2) == (int)result)
		    {
			printf("result : %d\n", (int)result);
		    }
		else
		    {
			printf("result : %.3f\n", result);
		    }	    
		}       

		else if(op == ( '/' ))
		{
		    float result = divide(cal_num1, cal_num2);
		    if( divide(cal_num1, cal_num2) == (int)result)
		    {
			printf("result : %d\n", (int)result);
		    }
		    else
		    {
			printf("result : %.3f\n", result);
		    } 	    
		}
		
		else
		{ 
		    	printf ("error\n");
		}	  	
	}	   
	 break;

	case '2': //HEX
	printf("Hex mode\n");
	while(1)
	{	    
		char cal[20] = {0};
		char num1[20] = {0};
		char num2[20] = {0};
	        long long cal_num1 = 0;
	        long long cal_num2 = 0;	
	        int p = 0;
	        int result = 0;
	        char op = '0';
	        count = 0;
	        char *ptr = NULL;
		
	       printf("input expression: " );
	       fgets(cal, sizeof(cal), stdin);
	       length = strlen(cal);

	       for(i = 0; i < 20; i ++)
		{   
		    if((cal[i] == 'q')&&(length == 2))
		    {	
			p++;
			printf("end\n");			
		    }	      
		}

		if(p == 1)
		 break;	
		 
		for(i = 0; i < 20; i++)
		{
		    if(cal[i] == ' ')
		    {
			count++;
		
			if(count < 2)
			{
			    for(j = 0; j < i; j++)
			    {
				num1[j] = cal[j];
				cal_num1 = strtoll(num1, &ptr,16);
			    }
			}
		
			if(count == 2)
			{
			    for(j = i + 1 ; j < length - 1 ; j++)
			    {
				num2[j - (i + 1)] = cal[j];
				cal_num2 = strtoll(num2, &ptr,16);
			    }
			}
		    } 
			if(((cal[i] == '+')||(cal[i] == '-')||(cal[i] == '*')||(cal[i] == '/')||(cal[i] == '>')||(cal[i] == '<')) && (count == 1))
			{
			   op = cal[i];		
			}
		}
	    
		if(op == '+')
		{
		    int result = add(cal_num1, cal_num2);
		    printf("result :%x\n", result);	    
		}

		else if(op == '-')
		{
		    int result = sub(cal_num1, cal_num2);
		    printf("result : %x\n", result);	    
		}	   

		else if(op == '*')
		{
		    int result = mul(cal_num1, cal_num2);
		    printf("result : %x\n", result);	    
		}

		else if(op == '/')
		{
		    int result = divide(cal_num1, cal_num2);
		    printf("result : %x\n", result);	    
		}

		else if(op == '<')
		{
		    int result = cal_num1 << cal_num2;
		    printf("result : %x\n", result);	    
		}

		else if(op == '>')
		{
		    int result = cal_num1 >> cal_num2;
		    printf("result : %x\n", result);	    
		}
		else printf("error\n");
	}
	    break;

	case '3': //Dec
	printf("Dec mode\n");

	while(1)
	{
		char cal[20] = {0};
		char num1[20] = {0};
		char num2[20] = {0};

	       printf("input expression: " );
	       fgets(cal, sizeof(cal), stdin);
	       length = strlen(cal);
	
	       int cal_num1 = 0;
	       int cal_num2 = 0;	
	       int p = 0;
	       int result = 0;
	       char op = '0';
	       count = 0;

	       for(i = 0; i < 20; i ++)
		{   
		    if((cal[i] == 'q')&&(length == 2))
		    {	
			p++;
			printf("end\n");			
		    }	      
		}

		if(p == 1)
		 break;	
		 
	    for(i = 0; i < 20; i++)
	    {
		if(cal[i] == ' ')
		{
		    count++;
		
		    if(count < 2)
		    {
			for(j = 0; j < i; j++)
			{
			    num1[j] = cal[j];
			    cal_num1 = atof(num1);
			}
		    }
		
		    if(count == 2)
		    {
			for(j = i + 1 ; j < length - 1 ; j++)
			{			
			    num2[j - (i + 1)] = cal[j];
			    cal_num2 = atof(num2);
			}
		    }
		} 
		    if(((cal[i] == '+')||(cal[i] == '-')||(cal[i] == '*')||(cal[i] == '/')||(cal[i] == '<') ||(cal[i] == '>'))&&(count == 1))
		    {
			op = cal[i];		
		    } 
	    }
	    
	    if(op == '+')
	    {
		int result = add(cal_num1, cal_num2);
		printf("result = %d\n", result);
	    }
	    else if(op == '-')
	    {
		int result = sub(cal_num1, cal_num2);
		printf("result = %d\n", result);
	    }

	    else if(op == '*')
	    {
		int result = mul(cal_num1, cal_num2);
		printf("result = %d\n", result);
	    }
	    else if(op == '/')
	    {
		int result = divide(cal_num1, cal_num2);
		printf("result = %d\n", result);
	    }
	    else if(op == '<')
	    {
		int result = cal_num1 << cal_num2;
		printf("result = %d\n", result);
	    }
	    else if(op == '>')
            {
                int result = cal_num1 >> cal_num2;
                printf("result = %d\n", result);
	    }
	    else 
		printf("error\n");
	} 
	break;

    case 'q' :
	printf("end\n");
	e++;
	break;
   

    	}//switch
}// big while
    return 0;	
}//main
