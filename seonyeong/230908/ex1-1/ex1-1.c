#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cal.h"

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
    int op_num = 0;

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
		op = '0';
		cal_num1 = 0;
		cal_num2 = 0;	
		count = 0;
		p = 0;
		float result = 0;
			
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
				cal_num1 = atof(num1);
			    }
		   			    
			     if((num1 != '0') && ( atof(num1) == 0 ) )
			    {						
                                cal_num1 = 0;
                                cal_num2 = 0;
                                op = '0';
				count = 3;
			    }	
			}
		
			if(count == 2)
			{
			    for(j = i + 1 ; j < length - 1 ; j++)
			    {	
				num2[j - (i + 1)] = cal[j];
				cal_num2 = atof(num2);
			    }
			    if((num2 != '0') && (atof(num2) == 0))
			    {
				cal_num1 = 0; 
				cal_num2 = 0;
				op = '0';
			    }
			}
		    }    
			if(((cal[i] == '+')||(cal[i] == '-')||(cal[i] == '*')||(cal[i] == '/'))&&(count == 1))
			{
			    op_num = i;
			    op = cal[i];		
		    
			    if(cal[op_num + 1] != ' ')
			    {
				count = 3;
				cal_num1 = 0;
				cal_num2 = 0;
				op = '0';	
			    }
			}
		}
	    

		if(((cal_num1 < -100000) || (cal_num1 > 100000)) || ((cal_num2 < -100000) || (cal_num2 > 100000)))
		{
		    printf("wrong numbers\n");
		    continue;	   
		}
		if (count == 3)
		{
		    printf("error\n");
		    continue;
		}

		if (op == ( '+' ))
		{
		    result = add(cal_num1, cal_num2);
	
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
		    result = sub(cal_num1, cal_num2);
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
		    result = mul(cal_num1, cal_num2);
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
		    result = divide(cal_num1, cal_num2);
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
	       p = 0;
	       op = '0';
	       count = 0;
	       char cal[20] = {0};
	       char num1[20] = {0};
	       char num2[20] = {0};
	       long long cal_num1 = 0;
	       long long cal_num2 = 0;	
	       int result = 0;
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
			    if((num1 != '0') && (strtoll(num1, &ptr, 16) ==0 ) )
			    {						
                                cal_num1 = 0;
                                cal_num2 = 0;
                                op = '0';
				count = 3;
			    }	
			}
		
			if(count == 2)
			{
			    for(j = i + 1 ; j < length - 1 ; j++)
			    {
				num2[j - (i + 1)] = cal[j];
				cal_num2 = strtoll(num2, &ptr,16);
			    }
			
			    if((num2 != '0') && (strtoll(num2,&ptr,16) == 0))
			    {
				cal_num1 = 0; 
				cal_num2 = 0;
				op = '0';
			    }
			
			}
		    } 
			if(((cal[i] == '+')||(cal[i] == '-')||(cal[i] == '*')||(cal[i] == '/')||(cal[i] == '>')||(cal[i] == '<')) && (count == 1))
			{   
			    op_num = i;
			    op = cal[i];
			}
		}
		if (count == 3)
		{
		    printf("error\n");
		    continue;
		}
	    
		if (count == 3)
		{
		    printf("error\n");
		    continue;
		}
		if(op == '+')
		{
		    result = add(cal_num1, cal_num2);
		    printf("result :%x\n", result);	    
		}

		else if(op == '-')
		{
		    result = sub(cal_num1, cal_num2);
		    printf("result : %x\n", result);	    
		}	   

		else if(op == '*')
		{
		    result = mul(cal_num1, cal_num2);
		    printf("result : %x\n", result);	    
		}

		else if(op == '/')
		{
		    result = divide(cal_num1, cal_num2);
		    printf("result : %x\n", result);	    
		}

		else if(op == '<')
		{
		    result = cal_num1 << cal_num2;
		    printf("result : %x\n", result);	    
		}

		else if(op == '>')
		{
		    result = cal_num1 >> cal_num2;
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
	       int cal_num1 = 0;
	       int cal_num2 = 0;	
	       p = 0;
	       op = '0';
	       count = 0;
	       int result = 0;

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
			}
			    cal_num1 = atof(num1);
			    if((num1 != '0') && (atof(num1) ==0 ) )
			    {						
                                cal_num1 = 0;
                                cal_num2 = 0;
                                op = '0';
				count = 3;
			    }	

		    }
		
		    if(count == 2)
		    {
			for(j = i + 1 ; j < length - 1 ; j++)
			{			
			    num2[j - (i + 1)] = cal[j];
			    cal_num2 = atof(num2);
			}
			    if((num2 != '0') && (atof(num2) == 0))
			    {
				cal_num1 = 0; 
				cal_num2 = 0;
				op = '0';
			    }
		    }
		} 
		    if(((cal[i] == '+')||(cal[i] == '-')||(cal[i] == '*')||(cal[i] == '/')||(cal[i] == '<') ||(cal[i] == '>')) && (count==1))
		    {
			op_num = i;
			op = cal[i];
		    } 
	    }
	    
	    if (count == 3)
	    {
		printf("error\n");
		continue;
	    }
	    if(op == '+')
	    {
		result = add(cal_num1, cal_num2);
		printf("result = %d\n", result);
	    }
	    else if(op == '-')
	    {
		result = sub(cal_num1, cal_num2);
		printf("result = %d\n", result);
	    }

	    else if(op == '*')
	    {
		result = mul(cal_num1, cal_num2);
		printf("result = %d\n", result);
	    }
	    else if(op == '/')
	    {
		result = divide(cal_num1, cal_num2);
		printf("result = %d\n", result);
	    }
	    else if(op == '<')
	    {
		result = cal_num1 << cal_num2;
		printf("result = %d\n", result);
	    }
	    else if(op == '>')
            {
                result = cal_num1 >> cal_num2;
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
