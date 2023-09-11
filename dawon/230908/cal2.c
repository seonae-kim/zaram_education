#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cal.h"

#define A 10
#define B 11
#define C 12
#define D 13
#define E 14
#define F 15

int main()
{
	char cal[20];
	char arrayb[20];
	float a=0, b=0;
	int hex1, hex2;
	int dec1, dec2;
	char op;
	int i=0, j=0, h=0, k=0, m=0, x=0;
	char n[20];
	int index=0;
	int p=0;
	int d=0;
	int modenum=0;
	float out=0;

	while(1)
	{	
		printf("1: standard, 2: oct, 3: dec >> ");
		scanf("%d", &modenum);
		printf("calculate formula: ");

		switch(modenum)
		{
		    case 1:
			fgets(cal,sizeof(cal),stdin);
			m=0;		
			n[0]='\0';
	
			if(cal[1] == '\n' && cal[0] == 'q')
			{
				printf("program exit\n");
				break;
			}
			else if(cal[1] == '\n' && cal[0] != 'q')
			{
				printf("try again1\n");
				continue;
			}
			
			for(i = 0; i < 20; i++)
			{
				if(cal[i] == ' ' && index == 0)
				{	
					index++;
					a=atof(cal);
					if  
			    		op = cal[i+1];
	
					if(cal[i+2] != ' ')
					{		
					    printf("try again2\n");
					    m=1;
					}
				
				}    
			    	else if(cal[i] == ' ' && index == 1)
				{
				    for(h = i + 1; h <= 20; h++)
			      	    {
			    		if(cal[h] == '\0')
					    break;
	
	                                arrayb[p] = cal[h];
	                                p++;
				    }
	
				    b=atof(arrayb);
				    p=0;
				    arrayb[0]='\0';
				    index=0;
				    break;
				}
			      
			}
			


			
			if((modenum == 2 || modenum == 3) && (isIntHexDec(a) == 0 || isIntHexDec(b) == 0))
			{
				printf("not integer \n");
				continue;
			}


		    	
			if(isNum(a) == 0)
	    		{
			    printf("try again 5\n");
			    continue;
	    		}
	
			if(isNum(b) == 0)
			{
			    printf("try agian 6\n");
			    continue;
			}
	
			if(m==1)
			{
			    printf("op error\n");
			    continue;
			}
	
			if(((a < -100000) || (a > 100000)) && ((b < -100000) || (b > 100000)))
	      		{
			    printf("try again 4\n\n");
			    continue;
		        }
	
			printf("output: ");
			if(op == '+')
			{	
				out=add(a,b);
	
				if(isInt(out) != 1)
				{
				    printf("%.0f\n\n",out);
				    continue;		
		       	        }
	
				printf("%.3f\n",out);
			}
			else if(op == '-')
			{
				out=sub(a,b);
				
	                        if(inInt(out) != 1)
	                        {
	                            printf("%.0f\n\n",out);
	                            continue;
	                        }             
	
				printf("%.3f\n",out);
	                }
			else if(op == '*')
			{
	                        out=mul(a,b);
	
	                        if(isInt(out) != 1)
	                        {
	                            printf("%.0f\n\n",out);
	                            continue;
	                        }
		
	
	                        printf("%.3f\n",out);
			}
			else if(op == '/')
			{
	                        out=divs(a,b);
	
	                        if(isInt(out) != 1)
	                        {
	                            printf("%.0f\n\n",out);
	                            continue;
	                        }
	                        printf("%.3f\n",out);
	                }
			else 
			        printf("try again3\n");
			
			c[0]='\0';
			printf("\n");
			
			break;
		
		
		    case 2:
			
			fgets(c,sizeof(cal),stdin);
			m=0;		
			k=0;
		        	
			if(cal[1] == '\n' && cal[0] == 'q')
			{
				printf("program exit\n");
				break;
			}
			else if(cal[1] == '\n' && cal[0] != 'q')
			{
				printf("try again1\n");
				continue;
			}
		
			for(i = 0; i < 20; i++)
			{
				if(cal[i] == ' ' && index == 0)
				{	
					index++;
					char hexa[20];
					
					for(j=0; j<i; j++)
					{
					    hexa[j] = cal[j];
					    
					}    
					    
					hex1=strtol(hexa,NULL,16);
					op = cal[i+1];
	
					if(cal[i+2] != ' ')
					{		
					    printf("try again2\n");
					    m=1;
					}				
				}    
			    	else if(cal[i] == ' ' && index == 1)
				{
				    for(h = i + 1; h <= 20; h++)
			      	    {
			    		if(cal[h] == '\0')
					    break;
	
	                                arrayb[p] = cal[h];
	                                p++;
				    }
	
				    hex2=strtol(arrayb);
				    p=0;
				    arrayb[0]='\0';
				    index=0;
				    break;
				}    
			
		
		}

		





	}	
    	return 0;
}

