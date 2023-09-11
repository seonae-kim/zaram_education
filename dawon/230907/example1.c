#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cal.h"


int main()
{
	char c[20];
	char s[20];
	float a=0, b=0;
	char op;
	int i=0, j=0, h=0, k=0, m=0, x=0;
	char n[20];
	int index1=0;
	int p=0;
	int d=0;
	float out=0;

	while(1)
	{	
		printf("formula: ");
		fgets(c,sizeof(c),stdin);
		m=0;		
		n[0]='\0';

		if(c[1] == '\n' && c[0] == 'q')
		{
			printf("program exit\n");
			break;
		}
		else if(c[1] == '\n' && c[0] != 'q')
		{
			printf("try again1\n");
			continue;
		}
	
		for(i = 0; i < 20; i++)
		{
			if(c[i] == ' ' && index1 == 0)
			{	
				index1++;
				a=atof(c);

				op = c[i+1];

				if(c[i+2] != ' ')
				{		
				    printf("try again2\n");
				    m=1;
				}
			
			}    
		    	else if(c[i] == ' ' && index1 == 1)
			{
			    for(h = i + 1; h <= 20; h++)
		      	    {
		    		if(c[h] == '\0')
				    break;

                                s[p] = c[h];
                                p++;
			    }

			    b=atof(s);
			    p=0;
			    s[0]='\0';
			    index1=0;
			    break;
			}
		      
		}

		if(isInt(a) == 0)
    		{
		    printf("try again 5\n");
		    continue;
    		}

		if(isInt(b) == 0)
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
			x=isInt(out);

			if(x != 1)
			{
			    printf("%.0f\n\n",out);
			    continue;		
	       	        }

			printf("%.3f\n",out);
		}
		else if(op == '-')
		{
			out=sub(a,b);
			x=isInt(out);
			
                        if(x != 1)
                        {
                            printf("%.0f\n\n",out);
                            continue;
                        }             

			printf("%.3f\n",out);
                }
		else if(op == '*')
		{
                        out=mul(a,b);
			x=isInt(out);

                        if(x != 1)
                        {
                            printf("%.0f\n\n",out);
                            continue;
                        }
	

                        printf("%.3f\n",out);
		}
		else if(op == '/')
		{
                        out=divs(a,b);
			x=isInt(out);

                        if(x != 1)
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
	}

	return 0;
}

